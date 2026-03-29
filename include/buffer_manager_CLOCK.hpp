#ifndef BUFFER_MANAGER_CLOCK_HPP
#define BUFFER_MANAGER_CLOCK_HPP

#include "buffer_manager.hpp"

class BufferManagerCLOCK : public BufferManager
{
private:
    size_t clockHand = 0;
    std::vector<bool> refBits;

    void updateBuffer(size_t pageId) override;

public:
    BufferManagerCLOCK(std::string archivePath);

    void evict() override;
};

#endif // BUFFER_MANAGER_CLOCK_HPP