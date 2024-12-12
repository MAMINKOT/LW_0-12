#include "magazine.h"

Magazine::Magazine() : PrintedEdition(), issueNumber(0) {}

Magazine::Magazine(const std::string& title, int pages, double price, int issueNumber)
    : PrintedEdition(title, pages, price), issueNumber(issueNumber) {}

void Magazine::input() {
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
    }

    do {
        std::cout << "������ ����� �������: ";
        std::cin >> issueNumber;
        if (issueNumber <= 0) {
            std::cerr << "����� ������� ������� ���� ��������!\n";
        }
    } while (issueNumber <= 0);


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Magazine::display() const {
    std::cout << "�����: " << title << "\n"
        << "ʳ������ �������: " << pages << "\n"
        << "�������: " << price << " ���\n";
    std::cout << "����� �������: " << issueNumber << "\n";
}
