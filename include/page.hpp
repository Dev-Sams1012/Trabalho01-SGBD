#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

class Page
{
private:
    std::string conteudo;
    size_t pageId;
    bool dirty = false;

public:
    Page(std::string cont, size_t id);
    ~Page() = default;

    std::string getContent() const { return conteudo; }
    size_t getPageId() const { return pageId; }
    bool isDirty() const { return dirty; }
    void setDirty();
};

#endif // PAGE_HPP