#include "printed_edition.h"

PrintedEdition::PrintedEdition() : title("Невідомо"), pages(0), price(0.0) {}

PrintedEdition::PrintedEdition(const std::string& title, int pages, double price)
    : title(title), pages(pages), price(price) {}

PrintedEdition::~PrintedEdition() {
    std::cout << "Об'єкт друкованого видання \"" << title << "\" видалено.\n";
}

void PrintedEdition::input() {
    std::cout << "Введіть назву видання: ";
    std::getline(std::cin, title);
    do {
        std::cout << "Введіть кількість сторінок: ";
        std::cin >> pages;
        if (pages <= 0) {
            std::cerr << "Кількість сторінок повинна бути додатною!\n";
        }
    } while (pages <= 0);

    do {
        std::cout << "Введіть вартість: ";
        std::cin >> price;
        if (price <= 0) {
            std::cerr << "Вартість повинна бути додатною!\n";
        }
    } while (price <= 0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PrintedEdition::display() const {
    std::cout << "Назва: " << title << "\n"
        << "Кількість сторінок: " << pages << "\n"
        << "Вартість: " << price << " грн\n";
}
