#include "buffer_manager_FIFO.hpp"

BufferManagerFIFO::BufferManagerFIFO(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerFIFO::evict()
{
    Page &pageToEvict = buffer.front(); // a pagina mais antiga é a primeira do vetor

    std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

    if (pageToEvict.isDirty())
    {
        std::cout << " | W";
    }

    std::cout << std::endl;

    buffer.erase(buffer.begin()); // remove a primeira página do vetor, que é a mais antiga
}