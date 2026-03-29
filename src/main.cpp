#include <iostream>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#include "buffer_manager_FIFO.hpp"
#include "buffer_manager_LRU.hpp"
#include "buffer_manager_MRU.hpp"
#include "buffer_manager_CLOCK.hpp"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void titulo()
{
    std::cout << YELLOW;
    std::cout << "========================================\n";
    std::cout << "   GERENCIADOR DE BUFFER - SGBD\n";
    std::cout << "========================================\n";
    std::cout << RESET;
}

int main()
{
    std::string arquivo = "bancodedados.csv";

    BufferManager *fifo = new BufferManagerFIFO(arquivo);
    BufferManager *lru = new BufferManagerLRU(arquivo);
    BufferManager *mru = new BufferManagerMRU(arquivo);
    BufferManager *clock = new BufferManagerCLOCK(arquivo);

    std::vector<size_t> keys;

    limparTela();
    titulo();

    std::cout << "Digite as chaves (pageId) (-1 para parar):\n";

    while (true)
    {
        int key;
        std::cin >> key;

        if (key == -1)
            break;

        keys.push_back(key);
    }

    int option = -1;

    while (option != 0)
    {
        limparTela();
        titulo();

        std::cout << GREEN << "Operacoes disponiveis:\n"
                  << RESET;
        std::cout << "1 - Executar FETCH nas chaves\n";
        std::cout << "2 - Mostrar CACHE de todas politicas\n";
        std::cout << "3 - Mostrar ESTATISTICAS\n";
        std::cout << "0 - Sair\n";

        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            std::cout << YELLOW << "\nExecutando FETCH...\n"
                      << RESET;
            for (size_t key : keys)
            {
                std::cout << "\n=============================\n";
                std::cout << "KEY: " << key << "\n";

                std::cout << GREEN << "\n[FIFO]\n"
                          << RESET;
                fifo->fetch(key);

                std::cout << GREEN << "\n[LRU]\n"
                          << RESET;
                lru->fetch(key);

                std::cout << GREEN << "\n[MRU]\n"
                          << RESET;
                mru->fetch(key);

                std::cout << GREEN << "\n[CLOCK]\n"
                          << RESET;
                clock->fetch(key);
            }
            std::cout << "\nFETCH concluído. Pressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 2:
        {
            std::cout << GREEN << "\n--- CACHE FIFO ---\n"
                      << RESET;
            fifo->displayCache();

            std::cout << GREEN << "\n--- CACHE LRU ---\n"
                      << RESET;
            lru->displayCache();

            std::cout << GREEN << "\n--- CACHE MRU ---\n"
                      << RESET;
            mru->displayCache();

            std::cout << GREEN << "\n--- CACHE CLOCK ---\n"
                      << RESET;
            clock->displayCache();

            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 3:
        {
            std::cout << GREEN << "\n--- STATS FIFO ---\n"
                      << RESET;
            fifo->displayStats();

            std::cout << GREEN << "\n--- STATS LRU ---\n"
                      << RESET;
            lru->displayStats();

            std::cout << GREEN << "\n--- STATS MRU ---\n"
                      << RESET;
            mru->displayStats();

            std::cout << GREEN << "\n--- STATS CLOCK ---\n"
                      << RESET;
            clock->displayStats();
            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 0:
        {
            std::cout << YELLOW << "\nEncerrando o programa...\n"
                      << RESET;
            break;
        }
        default:
        {
            std::cout << RED << "\nOpção inválida! Tente novamente.\n"
                      << RESET;
            std::cin.ignore();
            std::cin.get();
        }
        }
    }

    delete fifo;
    delete lru;
    delete mru;
    delete clock;
    
    return 0;
}