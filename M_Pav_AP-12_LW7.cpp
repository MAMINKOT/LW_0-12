#include "animals.h"
#include <iostream>

void start_LW_7(void) {
    Animals manager;

    manager.addAnimal({ 1, "Лисиця", "Хижі", "Псові" });
    manager.addAnimal({ 2, "Ведмідь", "Хижі", "Ведмежі" });
    manager.addAnimal({ 3, "Олень", "Парнокопитні", "Оленячі" });

    manager.displayAnimals();

    manager.insertAnimal(1, { 4, "Бобер", "Гризуни", "Боброві" });

    manager.removeAnimalById(2);

    manager.swapAnimals(1, 4);

    manager.clearAnimals();
}