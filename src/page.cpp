#include "page.hpp"

Page::Page(std::string cont, int id) : conteudo(cont), pageId(id) {}

void Page::setDirty() {
    dirty = true;
}