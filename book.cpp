#include "book.h"

Book::Book() : PrintedEdition(), author("�������� �����") {}

Book::Book(const std::string& title, int pages, double price, const std::string& author)
    : PrintedEdition(title, pages, price), author(author) {}

void Book::input() {

    std::cout << "������ ����� �������: ";
    std::getline(std::cin, title);

    while (true) {
        try {
            std::cout << "������ ������� �������: ";
            std::cin >> pages;
            if (std::cin.fail() || pages <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("ʳ������ ������� ������� ���� ��������!");
            }
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }

    while (true) {
        try {
            std::cout << "������ �������: ";
            std::cin >> price;
            if (std::cin.fail() || price <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("������� ������� ���� ��������!");
            }
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }    std::cout << "������ ������ �����: ";
    std::getline(std::cin, author);
}

void Book::display() const {
    std::cout << "�����: " << title << "\n"
        << "ʳ������ �������: " << pages << "\n"
        << "�������: " << price << " ���\n";
    std::cout << "�����: " << author << "\n";
}
