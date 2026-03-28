#include "buffer_manager_MRU.hpp"

BufferManagerMRU::BufferManagerMRU(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerMRU::updateBuffer(size_t pageId)
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

void BufferManagerMRU::evict()
{
    Page &pageToEvict = buffer.back();

    std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

    if (pageToEvict.isDirty())
    {
        std::cout << " | W";
    }

    std::cout << std::endl;

    buffer.pop_back();
}