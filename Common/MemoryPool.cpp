#include "MemoryPool.hpp"

inline static int RoundUp2Power(int size)
{
	if (size == 0)
		return 0;

	int roundUp = 1;
	while (roundUp < size)
		roundUp *= 2;

	return roundUp;
}

BufferPool::BufferPool(int minBlock, int maxBlock)
	:minBlock_(RoundUp2Power(minBlock))
	, maxBlock_(RoundUp2Power(maxBlock))
{
	int64_t bytes = minBlock_;
	while (bytes <= maxBlock_)
	{
		ChunkHeader* h = (ChunkHeader*)malloc(sizeof(ChunkHeader));
		if (h) {
			h->count = 0;
			h->bytes = bytes;
			h->first = NULL;
			h->last = NULL;
			chunks_.push_back(h);
		}
		bytes <<= 1;
	}
}

BufferPool::~BufferPool()
{
	for (int i = 0; i < chunks_.size(); i++)
	{
		ChunkHeader* h = chunks_[i];
		if (!h) { continue; }
		int count = h->count;
		int bytes = h->bytes;
		int idx = 0;
		Chunk* c = h->first;
		while (c != NULL)
		{
			Chunk* n = c->next;
			free(c);
			c = n;
			idx++;
		}
		free(h);
	}
}

char* BufferPool::Allocate(int size)
{
	if (size < minBlock_ || size > maxBlock_)
	{
		char* ptr = (char*)malloc(size);
		return ptr;
	}
	else
	{
		ChunkHeader* h = GetChunkHeader(size);
		Chunk* c = ChunkRemove(h);
		if (!c) {
			return NULL;
		}
		return (&(c->data[0]));
	}
}

void BufferPool::Deallocate(char *ptr, int size)
{
	if (size < minBlock_ || size > maxBlock_)
	{
		free(ptr);
	}
	else {
		if (!ptr || size < 0)
		{
			return;
		}
		ChunkHeader* h = GetChunkHeader(size);
		Chunk* c = (Chunk*)(ptr - offsetof(Chunk, data[0]));
		ChunkInsert(h, c);
	}
}

int BufferPool::GetUsedSize()
{
	int totalSize = 0;
	for (int i = 0; i < chunks_.size(); i++)
	{
		ChunkHeader* h = chunks_[i];
		if (!h) { continue; }
		totalSize += h->count * h->bytes;
	}
	return totalSize;
}

ChunkHeader* BufferPool::GetChunkHeader(int size)
{
	int bytes = RoundUp2Power(size);
	for (int i = 0; i < chunks_.size(); i++)
	{
		ChunkHeader* h = chunks_[i];
		if (h && h->bytes == bytes)
		{
			return h;
		}
	}
	return NULL;
}

Chunk* BufferPool::ChunkRemove(ChunkHeader* h)
{
	if (!h) {
		return NULL;
	}

	Chunk* c = NULL;
	if (h->first == NULL) {
		c = (Chunk*)malloc(sizeof(Chunk) + h->bytes);
		if (!c) {
			return NULL;
		}
		c->count = 0;
	}
	else {
		c = h->first;
		h->first = c->next;
		if (h->first == NULL) {
			h->last = NULL;
		}
		else {
			h->first->prev = NULL;
		}
		h->count--;
	}

	c->prev = NULL;
	c->next = NULL;
	c->count++;
	return c;
}

void BufferPool::ChunkInsert(ChunkHeader* h, Chunk* c)
{
	if (!h || !c) {
		return;
	}
	
	if (h->last == NULL) {
		c->prev = NULL;
		c->next = NULL;
		h->first = c;
		h->last = c;
	}
	else {
		c->prev = h->last;
		c->next = NULL;
		h->last->next = c;
		h->last = c;
	}
	h->count++;
}