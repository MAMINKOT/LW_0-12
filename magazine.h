#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "printed_edition.h"

class Magazine : public PrintedEdition {
private:
    int issueNumber;

public:
    Magazine();
    Magazine(const std::string& title, int pages, double price, int issueNumber);

    void input();
    void display() const;

    friend class LibraryManager;
};

#endif // MAGAZINE_H
