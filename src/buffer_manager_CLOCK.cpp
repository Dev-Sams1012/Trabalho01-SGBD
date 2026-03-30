#include "buffer_manager_CLOCK.hpp"

BufferManagerCLOCK::BufferManagerCLOCK(std::string archivePath) : BufferManager(archivePath) {}

void BufferManagerCLOCK::updateBuffer(size_t pageId)
{
    while (refBits.size() < buffer.size())
    {
        refBits.push_back(false); // inicializa os bits de referencia para as paginas do buffer, false indica que a pagina nao foi referenciada recentemente
    }

    for (size_t i = 0; i < buffer.size(); i++)
    {
        if (buffer[i].getPageId() == pageId)
        {
            refBits[i] = true; // marca a pagina como referenciada, indicando que ela foi acessada recentemente
            return;
        }
    }
}

void BufferManagerCLOCK::evict()
{
    size_t maxIterations = buffer.size() + 1; // pior caso, percorre todo mundo e volta para o primeiro

    for (size_t i = 0; i < maxIterations; i++)
    {
        clockHand = clockHand % buffer.size(); // garante rotatividade

        if (refBits[clockHand] == false) // nao foi referenciada recentemente, pode ser expulsa
        {
            Page &pageToEvict = buffer[clockHand]; // a pagina a ser expulsa é a apontada pelo clockHand, que é a primeira pagina nao referenciada encontrada

            std::cout << "EVICT: " << pageToEvict.getPageId() << " | " << pageToEvict.getContent();

            if (pageToEvict.isDirty())
            {
                std::cout << " | W";
            }

            std::cout << std::endl;

            buffer.erase(buffer.begin() + clockHand); // remove a pagina do buffer
            refBits.erase(refBits.begin() + clockHand); // remove o bit de referencia da pagina expulsa
            return;
        }
        else
        {
            refBits[clockHand] = false; // segunda chance
            clockHand++;
        }
    }
}