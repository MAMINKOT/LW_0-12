#include "animal.h"
#include <iostream>

void start_LW_5(void) {
    Animal animals[3];

    std::cout << "========== �������� ����� ==========\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\n������ ��� ��� ������� " << i + 1 << ":\n";
        animals[i].input();
    }

    std::cout << "\n========== ��� ��� ������ ==========\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\n������� " << i + 1 << ":\n";
        animals[i].display();
    }

    Animal predefinedAnimal("����", "���", "��������");
    std::cout << "\n========== ���������� �������� ������� ==========\n";
    predefinedAnimal.display();

    std::string targetFamily;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n������ ������ ��� ������: ";
    std::getline(std::cin, targetFamily);

    Animal::findByFamily(animals, 3, targetFamily);
}
