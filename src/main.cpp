#include "buffer_manager_FIFO.hpp"
#include "buffer_manager_LRU.hpp"
#include "buffer_manager_MRU.hpp"
#include "buffer_manager_CLOCK.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define MAX_DATA 30
#define DATA_PATH "../data/bancodedados.csv"

void cleanScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void divider(char c = '-')
{
    std::cout << DIM;
    for (int i = 0; i < 50; i++)
        std::cout << c;
    std::cout << RESET << "\n";
}

void title()
{
    std::cout << BOLD << CYAN << "  TRABALHO 01 - GERENCIADOR DE BUFFER - SGBD" << RESET << "\n\n";
}

void runTest(BufferManager &manager, const std::vector<size_t> &sequence)
{
    std::cout << "\n\n";
    divider('=');
    std::cout << BOLD << MAGENTA << "  Politica: " << manager.getNome() << RESET << "\n";
    divider('=');

    for (size_t pageId : sequence)
    {
        std::cout << "\n";
        std::cout << BOLD << YELLOW << "  >> Fetch(" << pageId << ")" << RESET << "\n";

        std::string content = manager.fetch(pageId);

        std::cout << DIM << "    -> " << RESET << content << "\n";
    }

    std::cout << "\n";
    divider();
    std::cout << BOLD << CYAN << "  Estado final do buffer\n" << RESET;
    divider();
    manager.displayCache();

    std::cout << "\n";
    divider();
    std::cout << BOLD << GREEN << "  Estatisticas\n" << RESET;
    divider();
    manager.displayStats();
}

int main()
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    srand((time(nullptr)));

    cleanScreen();
    title();

    std::vector<size_t> keys;

    std::cout << BOLD << "  Sequencia de acesso\n" << RESET;
    divider();
    std::cout << DIM << "  Digite pageIds de 1 a " << MAX_DATA << "  |  0 para iniciar\n\n" << RESET;

    while (true)
    {
        std::cout << CYAN << "  >> " << RESET;

        size_t key;

        if (!(std::cin >> key))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << "  Entrada invalida. Digite um numero.\n" << RESET;
            continue;
        }

        if (key == 0)
            break;

        if (key < 1 || key > MAX_DATA)
        {
            std::cout << RED << "  Fora do intervalo! Use valores entre 1 e " << MAX_DATA << ".\n" << RESET;
            continue;
        }

        keys.push_back(key);
        std::cout << GREEN << "  + Pagina " << key << " adicionada" << DIM << "  [total: " << keys.size() << "]" << RESET << "\n";
    }

    if (keys.empty())
    {
        std::cout << RED << "\n  Nenhuma chave informada. Encerrando.\n\n" << RESET;
        return 0;
    }

    BufferManager *fifo = new BufferManagerFIFO(DATA_PATH);
    BufferManager *lru = new BufferManagerLRU(DATA_PATH);
    BufferManager *mru = new BufferManagerMRU(DATA_PATH);
    BufferManager *clock = new BufferManagerCLOCK(DATA_PATH);

    runTest(*lru, keys);
    runTest(*fifo, keys);
    runTest(*clock, keys);
    runTest(*mru, keys);

    std::cout << "\n\n";
    divider('=');
    std::cout << DIM << "  Fim da execucao.\n" << RESET;
    divider('=');
    std::cout << "\n";

    delete fifo;
    delete lru;
    delete mru;
    delete clock;

    return 0;
}