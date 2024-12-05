#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include <vector>
#include "book.h"
#include "magazine.h"

class LibraryManager {
private:
    std::vector<PrintedEdition*> editions;

public:
    LibraryManager();
    ~LibraryManager();

    void addEdition(PrintedEdition* edition);
    void displayAll() const;
    double calculateTotalPrice() const;
};

#endif // LIBRARY_MANAGER_H
