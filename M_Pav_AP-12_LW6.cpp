#include "animals.h"
#include <iostream>

void start_LW_6(void) {
    Animals manager;

    manager.addAnimal({ 1, "������", "���", "����" });
    manager.addAnimal({ 2, "������", "���", "������" });
    manager.addAnimal({ 3, "�����", "�����������", "�������" });

    manager.displayAnimals();

    manager.updateAnimal(2, { 2, "����� ������", "���", "������" });

    manager.findAnimalByFamily("������");
}