#include "book.h"

Book::Book() : PrintedEdition(), author("Невідомий автор") {}

Book::Book(const std::string& title, int pages, double price, const std::string& author)
    : PrintedEdition(title, pages, price), author(author) {}

void Book::input() {

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
    }    std::cout << "Введіть автора книги: ";
    std::getline(std::cin, author);
}

void Book::display() const {
    std::cout << "Назва: " << title << "\n"
        << "Кількість сторінок: " << pages << "\n"
        << "Вартість: " << price << " грн\n";
    std::cout << "Автор: " << author << "\n";
}
