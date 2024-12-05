#include "library_manager.h"

void start_LW_9(void) {
    LibraryManager library;

    Book* book = new Book("Гаррі Поттер", 500, 250.0, "Джоан Роулінг");
    Magazine* magazine = new Magazine("Наука і техніка", 100, 50.0, 42);

    library.addEdition(book);
    library.addEdition(magazine);

    std::cout << "\n=== Список видань ===\n";
    library.displayAll();

    std::cout << "Загальна вартість видань: " << library.calculateTotalPrice() << " грн\n";
}