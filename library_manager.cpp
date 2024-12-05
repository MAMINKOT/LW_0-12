#include "library_manager.h"

LibraryManager::LibraryManager() {}

LibraryManager::~LibraryManager() {
    for (auto& edition : editions) {
        delete edition;
    }
}

void LibraryManager::addEdition(PrintedEdition* edition) {
    editions.push_back(edition);
}

void LibraryManager::displayAll() const {
    for (const auto& edition : editions) {
        edition->display();
        std::cout << "---------------------------\n";
    }
}

double LibraryManager::calculateTotalPrice() const {
    double total = 0.0;
    for (const auto& edition : editions) {
        total += edition->getPrice();
    }
    return total;
}
