#ifndef BUFFER_MANAGER_HPP
#define BUFFER_MANAGER_HPP

#include "page.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_CAPACITY 5

enum ReplacementPolicy
{
    LRU,
    FIFO,
    CLOCK,
    MRU
};

class BufferManager
{
private:
    std::vector<Page> buffer;
    ReplacementPolicy policy;
    int cacheHit = 0;
    int cacheMiss = 0;
    std::string archive;

    std::string readArchive(int key);

public:
    BufferManager(std::string archivePath, ReplacementPolicy policy);
    ~BufferManager() = default;
    std::string Fetch(int key);
    void Evict();
    void DisplayCache() const;
    void DisplayStats() const;
};

#endif // BUFFER_MANAGER_HPP