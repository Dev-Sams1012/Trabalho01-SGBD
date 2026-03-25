#ifndef BUFFER_MANAGER_HPP
#define BUFFER_MANAGER_HPP

#include "page.hpp"

#include <vector>
#include <string>

#define MAX_CAPACITY 5

enum ReplacementPolicy { LRU, FIFO, CLOCK, MRU };

class BufferManager
{
private:
    std::vector<Page> buffer;
    ReplacementPolicy policy;
    int cacheHit = 0;
    int cacheMiss = 0;
    std::string archive;
public:
    BufferManager(std::string archivePath, ReplacementPolicy policy);
    ~BufferManager() = default;
};

#endif // BUFFER_MANAGER_HPP