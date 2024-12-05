#include "animals.h"
#include <iomanip>

// ����������� �� �������������
Animals::Animals() : count(0) {}

// �������� �������� �������� ����
bool Animals::validateString(const std::string& str, const std::string& fieldName) const {
    if (str.empty()) {
        std::cerr << "�������: ���� \"" << fieldName << "\" �� ���� ���� �������.\n";
        return false;
    }
    if (str.length() > 30) {
        std::cerr << "�������: ���� \"" << fieldName << "\" �������� 30 �������.\n";
        return false;
    }
    return true;
}

bool Animals::validateId(int id) const {
    if (id <= 0) {
        std::cerr << "�������: ID ������� ���� �������� ������.\n";
        return false;
    }
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            return true;
        }
    }
    std::cerr << "�������: ������� � ID " << id << " �� ��������.\n";
    return false;
}



// ������ ���� �������
void Animals::addAnimal(const animal_s_t& newAnimal) {
    if (count >= MAX_SIZE) {
        std::cerr << "�������: ��������� ����������� ������� ������.\n";
        return;
    }

    if (!validateString(newAnimal.name, "�����") || 
        !validateString(newAnimal.order, "���") || 
        !validateString(newAnimal.family, "������")) {
        return;
    }

    animals[count++] = newAnimal;
    std::cout << "������� \"" << newAnimal.name << "\" ������ ������!\n";
}

// ������� ��� ������� �� ID
void Animals::updateAnimal(int id, const animal_s_t& animal) {
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            if (!validateString(animal.name, "�����") ||
                !validateString(animal.order, "���") ||
                !validateString(animal.family, "������")) {
                return;
            }

            animals[i] = animal;
            std::cout << "��� ������� � ID " << id << " ��������.\n";
            return;
        }
    }
    std::cerr << "�������: ������� � ID " << id << " �� ��������.\n";
}

void Animals::insertAnimal(int index, const animal_s_t& animal) {
    if (count >= MAX_SIZE) {
        std::cerr << "�������: ������ ����������.\n";
        return;
    }
    if (index < 0 || index > count) {
        std::cerr << "�������: ������ �������� �� ��� ������.\n";
        return;
    }

    for (int i = count; i > index; --i) {
        animals[i] = animals[i - 1];
    }
    animals[index] = animal;
    ++count;
    std::cout << "������� \"" << animal.name << "\" ������ ��������� �� ������� " << index << ".\n";
}

// �������� ������� �� ID
void Animals::removeAnimalById(int id) {
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            for (int j = i; j < count - 1; ++j) {
                animals[j] = animals[j + 1];
            }
            --count;
            std::cout << "������� � ID " << id << " ������ ��������.\n";
            return;
        }
    }
    std::cerr << "�������: ������� � ID " << id << " �� ��������.\n";
}

// �������� ������ ������
void Animals::clearAnimals() {
    count = 0;
    std::cout << "������ ������ ������ �������.\n";
}

// ���� ��������� �� ID
void Animals::swapAnimals(int id1, int id2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id1) index1 = i;
        if (animals[i].id == id2) index2 = i;
    }

    if (index1 == -1 || index2 == -1) {
        std::cerr << "�������: ���� ��� ������ ID �� ��������.\n";
        return;
    }

    std::swap(animals[index1], animals[index2]);
    std::cout << "������� � ID " << id1 << " �� " << id2 << " ������ ������ ������.\n";
}

// ������� �� �������
void Animals::displayAnimals() const {
    if (count == 0) {
        std::cout << "������ ������ �������.\n";
        return;
    }

    std::cout << "========== ������ ������ ==========\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "ID: " << animals[i].id << "\n"
            << "�����: " << animals[i].name << "\n"
            << "���: " << animals[i].order << "\n"
            << "������: " << animals[i].family << "\n"
            << "-----------------------------------\n";
    }
}

// ����� �� �������
void Animals::findAnimalByFamily(const std::string& family) const {
    bool found = false;
    std::cout << "========== ����� �� ������� \"" << family << "\" ==========\n";
    for (int i = 0; i < count; ++i) {
        if (animals[i].family == family) {
            std::cout << "ID: " << animals[i].id << "\n"
                << "�����: " << animals[i].name << "\n"
                << "���: " << animals[i].order << "\n"
                << "-----------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "����� ������� � ������ \"" << family << "\" �� ��������.\n";
    }
}
