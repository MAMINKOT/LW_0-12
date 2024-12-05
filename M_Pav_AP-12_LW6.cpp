#include "animals.h"
#include <iostream>

void start_LW_6(void) {
    Animals manager;

    manager.addAnimal({ 1, "Лисиця", "Хижі", "Псові" });
    manager.addAnimal({ 2, "Ведмідь", "Хижі", "Ведмежі" });
    manager.addAnimal({ 3, "Олень", "Парнокопитні", "Оленячі" });

    manager.displayAnimals();

    manager.updateAnimal(2, { 2, "Бурий ведмідь", "Хижі", "Ведмежі" });

    manager.findAnimalByFamily("Ведмежі");
}