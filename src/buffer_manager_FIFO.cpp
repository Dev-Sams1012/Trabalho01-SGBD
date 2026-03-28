#include "buffer_manager_FIFO.hpp"

BufferManagerFIFO::BufferManagerFIFO(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerFIFO::evict()
{
    Page &pageToEvict = buffer.front();

    std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

    if (pageToEvict.isDirty())
    {
        std::cout << " | W";
    }

    std::cout << std::endl;

    buffer.erase(buffer.begin());
}