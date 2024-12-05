#include "animal.h"
#include "M_Pav_AP-12_LW4.h"
#include <iostream>

void start_LW_4(void) {
    Animal animal1;
    std::cout << "Введіть дані для першої тварини:\n";
    animal1.input();

    Animal animal2("Лев", "Хижі", "Котові");

    std::cout << "\nДані про першу тварину:\n";
    animal1.display();

    std::cout << "\nДані про другу тварину:\n";
    animal2.display();

    std::cout << "\nЗміна даних другої тварини через сеттери.\n";
    animal2.setName("Тигр");
    animal2.setOrder("Хижі");
    animal2.setFamily("Котові");

    std::cout << "Оновлені дані про другу тварину:\n";
    animal2.display();
}
