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
        Page p = buffer[targetIndex]; // copia a pagina do buffer para atualizar a sua posicao
        buffer.erase(buffer.begin() + targetIndex); // remove a pagina do buffer
        buffer.push_back(p); // adiciona a pagina no final do buffer, indicando que ela é a mais recentemente usada
    }
}

void BufferManagerLRU::evict()
{
    Page &pageToEvict = buffer.front(); // a pagina menos recentemente usada é a primeira do vetor

    std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

    if (pageToEvict.isDirty())
    {
        std::cout << " | W";
    }

    std::cout << std::endl;

    buffer.erase(buffer.begin()); // remove a primeira página do vetor, que é a menos recentemente usada
}