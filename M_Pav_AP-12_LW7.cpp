#include "animals.h"
#include <iostream>

void start_LW_7(void) {
    Animals manager;

    manager.addAnimal({ 1, "������", "���", "����" });
    manager.addAnimal({ 2, "������", "���", "������" });
    manager.addAnimal({ 3, "�����", "�����������", "�������" });

    manager.displayAnimals();

    manager.insertAnimal(1, { 4, "�����", "�������", "������" });

    manager.removeAnimalById(2);

    manager.swapAnimals(1, 4);

    manager.clearAnimals();
}