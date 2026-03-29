#ifndef BUFFER_MANAGER_LRU_HPP
#define BUFFER_MANAGER_LRU_HPP

#include "buffer_manager.hpp"

class BufferManagerLRU : public BufferManager
{
private:
    void updateBuffer(size_t pageId) override;

public:
    BufferManagerLRU(std::string archivePath);

    void evict() override;
    std::string getNome() const override { return "LRU"; }
};

#endif // BUFFER_MANAGER_LRU_HPP