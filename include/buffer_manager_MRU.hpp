#ifndef BUFFER_MANAGER_MRU_HPP
#define BUFFER_MANAGER_MRU_HPP

#include "buffer_manager.hpp"

class BufferManagerMRU : public BufferManager
{
private:
    void updateBuffer(size_t pageId) override;

public:
    BufferManagerMRU(std::string archivePath);

    void evict() override;
    std::string getNome() const override { return "MRU"; }
};

#endif // BUFFER_MANAGER_MRU_HPP