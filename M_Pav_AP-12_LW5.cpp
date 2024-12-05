#include "animal.h"
#include <iostream>

void start_LW_5(void) {
    Animal animals[3];

    std::cout << "========== Введення даних ==========\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\nВведіть дані для тварини " << i + 1 << ":\n";
        animals[i].input();
    }

    std::cout << "\n========== Дані про тварин ==========\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\nТварина " << i + 1 << ":\n";
        animals[i].display();
    }

    Animal predefinedAnimal("Орел", "Хижі", "Яструбові");
    std::cout << "\n========== Заздалегідь створена тварина ==========\n";
    predefinedAnimal.display();

    std::string targetFamily;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nВведіть родину для пошуку: ";
    std::getline(std::cin, targetFamily);

    Animal::findByFamily(animals, 3, targetFamily);
}
