#include "buffer_manager.hpp"

BufferManager::BufferManager(std::string archivePath) : archive(archivePath) {}

std::string BufferManager::readArchive(size_t key)
{
    std::ifstream file(archive);
    if (!file.is_open())
    {
        std::cout << "Erro ao acessar: " << archive << "\n";
        return "";
    }

    int current_page = 1;
    std::string line;
    while (std::getline(file, line))
    {
        if (current_page == key)
        {
            return line;
        }
        current_page++;
    }
    return "";
}

std::string BufferManager::fetch(size_t key)
{
    for (Page &page : buffer)
    {
        if (page.getPageId() == key)
        {
            cacheHit++;
            updateBuffer(key);
            return page.getContent();
        }
    }
    cacheMiss++;
    std::string content = readArchive(key);
    if (content.empty())
    {
        std::cout << "Página " << key << "não encontrada no arquivo.";
        return "";
    }

    if (buffer.size() >= MAX_CAPACITY)
    {
        evict();
    }

    Page newPage(content, key);

    if (rand() % 2 == 1)
    {
        newPage.setDirty();
    }

    buffer.push_back(newPage);

    updateBuffer(key);

    return content;
}

void BufferManager::displayCache() const
{
    std::cout << "Cache do Buffer: " << std::endl;

    for (const Page &page : buffer)
    {
        std::cout << "Page ID: " << page.getPageId() << std::endl;
        std::cout << "Conteúdo: " << page.getContent() << std::endl;
        std::cout << "Dirty: " << (page.isDirty() ? "Sim" : "Não") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void BufferManager::displayStats() const
{
    std::cout << "Estatísticas do Buffer: " << std::endl;

    std::cout << "Cache Hits: " << cacheHit << std::endl;
    std::cout << "Cache Misses: " << cacheMiss << std::endl;
}