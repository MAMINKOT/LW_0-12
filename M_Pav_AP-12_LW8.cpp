#include "book.h"
#include "magazine.h"
#include <vector>

void start_LW_8(void) {
    std::vector<PrintedEdition*> editions;

    std::cout << "=== ¬веденн€ книги ===\n";
    Book* book = new Book();
    book->input();
    editions.push_back(book);

    std::cout << "\n=== ¬веденн€ журналу ===\n";
    Magazine* magazine = new Magazine();
    magazine->input();
    editions.push_back(magazine);

    std::cout << "\n=== —писок друкованих видань ===\n";
    for (const auto& edition : editions) {
        edition->display();
        std::cout << "---------------------------\n";
    }

    for (auto& edition : editions) {
        delete edition;
    }
}