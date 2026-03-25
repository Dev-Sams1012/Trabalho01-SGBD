#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

class Page
{
private:
    std::string conteudo;
    int pageId;
    bool dirty = false;

public:
    Page(std::string cont, int id);
    ~Page() = default;

    std::string getContent() const { return conteudo; }
    int getPageId() const { return pageId; }
    bool isDirty() const { return dirty; }
    void setDirty();
};

#endif // PAGE_HPP