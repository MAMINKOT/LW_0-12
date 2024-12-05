#include "printed_edition.h"

PrintedEdition::PrintedEdition() : title("�������"), pages(0), price(0.0) {}

PrintedEdition::PrintedEdition(const std::string& title, int pages, double price)
    : title(title), pages(pages), price(price) {}

PrintedEdition::~PrintedEdition() {
    std::cout << "��'��� ����������� ������� \"" << title << "\" ��������.\n";
}

void PrintedEdition::input() {
    std::cout << "������ ����� �������: ";
    std::getline(std::cin, title);
    do {
        std::cout << "������ ������� �������: ";
        std::cin >> pages;
        if (pages <= 0) {
            std::cerr << "ʳ������ ������� ������� ���� ��������!\n";
        }
    } while (pages <= 0);

    do {
        std::cout << "������ �������: ";
        std::cin >> price;
        if (price <= 0) {
            std::cerr << "������� ������� ���� ��������!\n";
        }
    } while (price <= 0);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PrintedEdition::display() const {
    std::cout << "�����: " << title << "\n"
        << "ʳ������ �������: " << pages << "\n"
        << "�������: " << price << " ���\n";
}
