#include "magazine.h"

Magazine::Magazine() : PrintedEdition(), issueNumber(0) {}

Magazine::Magazine(const std::string& title, int pages, double price, int issueNumber)
    : PrintedEdition(title, pages, price), issueNumber(issueNumber) {}

void Magazine::input() {
    std::cout << "Введіть назву видання: ";
    std::getline(std::cin, title);

    while (true) {
        try {
            std::cout << "Введіть кількість сторінок: ";
            std::cin >> pages;
            if (std::cin.fail() || pages <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Кількість сторінок повинна бути додатною!");
            }
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }

    while (true) {
        try {
            std::cout << "Введіть вартість: ";
            std::cin >> price;
            if (std::cin.fail() || price <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Вартість повинна бути додатною!");
            }
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }

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
    std::cout << "Назва: " << title << "\n"
        << "Кількість сторінок: " << pages << "\n"
        << "Вартість: " << price << " грн\n";
    std::cout << "Номер випуску: " << issueNumber << "\n";
}
