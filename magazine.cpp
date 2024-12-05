#include "magazine.h"

Magazine::Magazine() : PrintedEdition(), issueNumber(0) {}

Magazine::Magazine(const std::string& title, int pages, double price, int issueNumber)
    : PrintedEdition(title, pages, price), issueNumber(issueNumber) {}

void Magazine::input() {
    PrintedEdition::input();
    do {
        std::cout << "Введіть номер випуску: ";
        std::cin >> issueNumber;
        if (issueNumber <= 0) {
            std::cerr << "Номер випуску повинен бути додатним!\n";
        }
    } while (issueNumber <= 0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Magazine::display() const {
    PrintedEdition::display();
    std::cout << "Номер випуску: " << issueNumber << "\n";
}
