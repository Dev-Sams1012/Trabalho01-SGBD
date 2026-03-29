#ifndef BUFFER_MANAGER_HPP
#define BUFFER_MANAGER_HPP

#include "page.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_CAPACITY 5

class BufferManager
{
protected:
    std::vector<Page> buffer;
    int cacheHit = 0;
    int cacheMiss = 0;
    std::string archive;

    virtual void updateBuffer(size_t pageId) {}

    std::string readArchive(size_t key);

public:
    BufferManager(std::string archivePath);
    virtual ~BufferManager() = default;

    std::string fetch(size_t key);

    virtual void evict() = 0;

    void displayCache() const;
    void displayStats() const;
    virtual std::string getNome() const = 0;
};

#endif // BUFFER_MANAGER_HPP