#include "printed_edition.h"

PrintedEdition::PrintedEdition() : title("�������"), pages(0), price(0.0) {}

PrintedEdition::PrintedEdition(const std::string& title, int pages, double price)
    : title(title), pages(pages), price(price) {}

PrintedEdition::~PrintedEdition() {
    std::cout << "��'��� ����������� ������� \"" << title << "\" ��������.\n";
}

