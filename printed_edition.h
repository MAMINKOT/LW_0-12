#ifndef PRINTED_EDITION_H
#define PRINTED_EDITION_H

#include <string>
#include <iostream>

class PrintedEdition {
protected:
    std::string title;
    int pages;
    double price;

public:
    PrintedEdition();
    PrintedEdition(const std::string& title, int pages, double price);
    virtual ~PrintedEdition();

    virtual void input();
    virtual void display() const;

    double getPrice() const { return price; }

    friend class LibraryManager;
};

#endif // PRINTED_EDITION_H
