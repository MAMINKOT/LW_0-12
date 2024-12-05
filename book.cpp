#include "book.h"

// ����������� �� �������������
Book::Book() : PrintedEdition(), author("�������� �����") {}

// ����������� � �����������
Book::Book(const std::string& title, int pages, double price, const std::string& author)
    : PrintedEdition(title, pages, price), author(author) {}

// �������� �����
void Book::input() {
    PrintedEdition::input();  // ������ �������� ������
    std::cout << "������ ������ �����: ";
    std::getline(std::cin, author);
}

// ��������� �����
void Book::display() const {
    PrintedEdition::display();  // ������ �������� ������
    std::cout << "�����: " << author << "\n";
}
