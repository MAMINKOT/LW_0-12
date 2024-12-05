#include "book.h"

// Конструктор за замовчуванням
Book::Book() : PrintedEdition(), author("Невідомий автор") {}

// Конструктор з параметрами
Book::Book(const std::string& title, int pages, double price, const std::string& author)
    : PrintedEdition(title, pages, price), author(author) {}

// Введення даних
void Book::input() {
    PrintedEdition::input();  // Виклик базового методу
    std::cout << "Введіть автора книги: ";
    std::getline(std::cin, author);
}

// Виведення даних
void Book::display() const {
    PrintedEdition::display();  // Виклик базового методу
    std::cout << "Автор: " << author << "\n";
}
