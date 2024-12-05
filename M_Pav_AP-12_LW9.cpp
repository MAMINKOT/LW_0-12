#include "library_manager.h"

void start_LW_9(void) {
    LibraryManager library;

    Book* book = new Book("���� ������", 500, 250.0, "����� ������");
    Magazine* magazine = new Magazine("����� � ������", 100, 50.0, 42);

    library.addEdition(book);
    library.addEdition(magazine);

    std::cout << "\n=== ������ ������ ===\n";
    library.displayAll();

    std::cout << "�������� ������� ������: " << library.calculateTotalPrice() << " ���\n";
}