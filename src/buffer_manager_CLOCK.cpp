#include "buffer_manager_CLOCK.hpp"

BufferManagerCLOCK::BufferManagerCLOCK(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerCLOCK::updateBuffer(size_t pageId)
{
    while (refBits.size() < buffer.size())
    {
        refBits.push_back(false);
    }

    for (size_t i = 0; i < buffer.size(); i++)
    {
        if (buffer[i].getPageId() == pageId)
        {
            refBits[i] = true;
            return;
        }
    }
}

void BufferManagerCLOCK::evict()
{
    size_t maxIterations = buffer.size() + 1;

    for (size_t i = 0; i < maxIterations; i++)
    {
        clockHand = clockHand % buffer.size();

        if (refBits[clockHand] == false)
        {
            Page &pageToEvict = buffer[clockHand];

            std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

            if (pageToEvict.isDirty())
            {
                std::cout << " | W";
            }

            std::cout << std::endl;

            buffer.erase(buffer.begin() + clockHand);
            refBits.erase(refBits.begin() + clockHand);
            return;
        }
        else
        {
            refBits[clockHand] = false;
            clockHand++;
        }
    }
}