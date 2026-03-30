# Sistemas de Gerenciamento de Bancos de Dados - 2026.1

Este repositório contém o primeiro trabalho de implementação da disciplina **Sistemas de Gerenciamento de Bancos de Dados**, ministrada pelo professor **Javam Machado** no semestre **2026.1**.

## Descrição do Trabalho

O objetivo deste trabalho é implementar um **gerenciador de buffer** que simula a leitura de páginas de um arquivo .csv, utilizando diferentes **políticas de substituição**. O gerenciador deve ser capaz de ler as páginas do arquivo, armazená-las em um buffer e aplicar as políticas de substituição para gerenciar o espaço do buffer.

## Estrutura do Projeto

```plaintext
├── data/
│   └── bancodedados.csv           # Arquivo .csv com os dados a serem lidos
├── include/
│   ├── page.hpp                  # Definição da classe de página
│   ├── buffer_manager.hpp        # Classe abstrata
│   ├── buffer_manager_CLOCK.hpp
│   ├── buffer_manager_FIFO.hpp
│   ├── buffer_manager_LRU.hpp
│   └── buffer_manager_MRU.hpp
└── src/
    ├── main.cpp                  # Menu - execução do programa
    ├── page.cpp                  # Implementação da página
    ├── buffer_manager.cpp        # Lógica comum (readArchive, fetch, ...)
    ├── buffer_manager_CLOCK.cpp
    ├── buffer_manager_FIFO.cpp
    ├── buffer_manager_LRU.cpp
    └── buffer_manager_MRU.cpp
```

## Políticas de Substituição

O gerenciador suporta as seguintes políticas de substituição:

* CLOCK ("Segunda Chance"): Utiliza um bit de referência para dar uma **"segunda chance"** às páginas antes da remoção.
* FIFO (First-In First-Out): Remove a página que está **há mais tempo** no buffer.
* LRU (Lest Recently Used): Remove a página que **não é utilizada há mais tempo**.
* MRU (Most Recently Used): Remove a página que foi **utilizada mais recentemente**.

## Tecnologias Utilizadas

* Linguagem de Programação: C++
* Sistema de Build: CMake
* Versionamento: Git

## Autores

* **Jonathan Duarte Uchôa**
* **Samuel Augusto de Abreu**
