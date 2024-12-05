#ifndef BOOK_H
#define BOOK_H

#include "printed_edition.h"

class Book : public PrintedEdition {
private:
    std::string author;

public:
    Book();
    Book(const std::string& title, int pages, double price, const std::string& author);

    void input() override;
    void display() const override;

    friend class LibraryManager;
};

#endif // BOOK_H
