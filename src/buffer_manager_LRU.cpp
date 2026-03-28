#include "buffer_manager_LRU.hpp"

BufferManagerLRU::BufferManagerLRU(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerLRU::updateBuffer(size_t pageId)
{
    int targetIndex = -1;
    int i = 0;

    for (const Page &page : buffer)
    {
        if (page.getPageId() == pageId)
        {
            targetIndex = i;
            break;
        }
        i++;
    }

    if (targetIndex != -1)
    {
        Page p = buffer[targetIndex];
        buffer.erase(buffer.begin() + targetIndex);
        buffer.push_back(p);
    }
}

void BufferManagerLRU::evict()
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