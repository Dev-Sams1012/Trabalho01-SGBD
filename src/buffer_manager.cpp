#include "buffer_manager.hpp"

BufferManager::BufferManager(std::string archivePath, ReplacementPolicy policy) : archive(archivePath), policy(policy) {}

std::string BufferManager::readArchive(int key)
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

std::string BufferManager::Fetch(int key) {
    for(Page &page : buffer){
        if(page.getPageId() == key){
            cacheHit++;
            return page.getContent();
        }
    }
    cacheMiss++;
    std::string content = readArchive(key);
    if(content == ""){
        std:: cout << "Página " << key << "não encontrada no arquivo.";
        return "";
    }

    if(buffer.size() == MAX_CAPACITY){
        Evict();
    }

    Page newPage(content, key);

    if(rand() % 2 == 1){
        newPage.setDirty();
    }

    buffer.push_back(newPage);

    return content;
}
