#include "page.hpp"

Page::Page(std::string cont, size_t id) : conteudo(cont), pageId(id) {}

void Page::setDirty()
{
    dirty = true;
}