#ifndef SUNNYMOBILE_MEMORY_POOL_H
#define SUNNYMOBILE_MEMORY_POOL_H

#include <vector>
#include <memory>
#include <thread>
#include <mutex>

struct Chunk
{
	struct Chunk* prev;
	struct Chunk* next;
	int  count;
	char data[0];
};

struct ChunkHeader
{
	struct Chunk* first;
	struct Chunk* last;
	int bytes;
	int count;
};

class BufferPool
{
public:
	BufferPool(int minBlock, int maxBlock);
	~BufferPool();
	char* Allocate(int bytes);
	void  Deallocate(char* ptr, int bytes);
	int   GetUsedSize();
private:
	ChunkHeader* GetChunkHeader(int bytes);
	Chunk* ChunkRemove(ChunkHeader* h);
	void   ChunkInsert(ChunkHeader* h, Chunk* c);
	int minBlock_;
	int maxBlock_;
	std::vector<ChunkHeader*> chunks_;
};

#endif //SUNNYMOBILE_MEMORY_POOL_H
