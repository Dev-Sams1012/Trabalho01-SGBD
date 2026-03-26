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
