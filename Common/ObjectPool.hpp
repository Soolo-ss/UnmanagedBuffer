#pragma once

#include <memory>
#include <stack>
#include <cassert>

template<class T, class D = std::default_delete<T>, int OBJECT_POOL_ASSGIN_SIZE = 50>
class SmartObjectPool {
public:
	struct ReturnToPoolDeleter {
		explicit ReturnToPoolDeleter(std::weak_ptr<SmartObjectPool<T, D>*> pool)
			: pool_(pool) { }
		
		void operator()(T* ptr) {
			ptr->Clear();
			if (auto poolPtr = pool_.lock()) {
				(*poolPtr.get())->add(std::unique_ptr<T, D>{ ptr });
			}
			else {
				D{}(ptr);
			}
		}

		private:
			std::weak_ptr<SmartObjectPool<T, D>*> pool_;
	};

public:
	SmartObjectPool()
		: this_ptr_(new SmartObjectPool<T, D>*(this)) 
	{ }

	void add(std::unique_ptr<T, D> t) {
		pool_.push(std::move(t));
	}

	using ReturnObjectPtrType = std::unique_ptr<T, ReturnToPoolDeleter>;

	ReturnObjectPtrType acquire() {
		if (pool_.empty()) {
			assign();
		}

		assert(pool_.top() != nullptr);

		ReturnObjectPtrType tmp(pool_.top().release(), ReturnToPoolDeleter{
			std::weak_ptr<SmartObjectPool<T, D>*>{this_ptr_}
			});

		pool_.pop();

		return std::move(tmp);
	}

	bool empty() const {
		return pool_.empty();
	}

	void clear()
	{
		while (!pool_.empty())
		{
			pool_.pop();
		}
	}

private:
	void assign(int size = OBJECT_POOL_ASSGIN_SIZE)
	{
		for (int i = 0; i != size; ++i)
		{
			pool_.emplace(std::unique_ptr<T>(new T()));

		}
	}

private:
	std::shared_ptr<SmartObjectPool<T, D>*> this_ptr_;
	std::stack<std::unique_ptr<T, D>> pool_;
};
