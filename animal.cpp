#include "animal.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Конструктори
Animal::Animal() : name("Невідомо"), order("Невідомо"), family("Невідомо") {}

Animal::Animal(const std::string& name, const std::string& order, const std::string& family) {
    this->setName(name);
    this->setOrder(order);
    this->setFamily(family);
}

// Деструктор
Animal::~Animal() {
    std::cout << "Об'єкт тварини \"" << name << "\" видалено.\n";
}

// Методи для введення даних
void Animal::input() {
    std::string temp;

    std::cout << "Введіть назву тварини: ";
    std::getline(std::cin, temp);
    setName(temp);

    std::cout << "Введіть ряд тварини: ";
    std::getline(std::cin, temp);
    setOrder(temp);

    std::cout << "Введіть родину тварини: ";
    std::getline(std::cin, temp);
    setFamily(temp);
}

void Animal::display() const {
    std::cout << "----------------------------------------\n";
    std::cout << "| Назва   : " << std::setw(30) << std::left << name << "|\n";
    std::cout << "| Ряд     : " << std::setw(30) << std::left << order << "|\n";
    std::cout << "| Родина  : " << std::setw(30) << std::left << family << "|\n";
    std::cout << "----------------------------------------\n";
}

// Сеттери з валідацією
void Animal::setName(const std::string& name) {
    if (name.empty()) {
        std::cerr << "Помилка: назва не може бути порожньою.\n";
        this->name = "Невідомо";
    }
    else {
        this->name = name;
    }
}

void Animal::setOrder(const std::string& order) {
    if (order.empty()) {
        std::cerr << "Помилка: ряд не може бути порожнім.\n";
        this->order = "Невідомо";
    }
    else {
        this->order = order;
    }
}

void Animal::setFamily(const std::string& family) {
    if (family.empty()) {
        std::cerr << "Помилка: родина не може бути порожньою.\n";
        this->family = "Невідомо";
    }
    else {
        this->family = family;
    }
}

// Геттери
std::string Animal::getName() const { return name; }
std::string Animal::getOrder() const { return order; }
std::string Animal::getFamily() const { return family; }

void Animal::findByFamily(const Animal animals[], int size, const std::string & targetFamily) {
    bool found = false;
    std::cout << "\n========== Результати пошуку ==========\n";
    std::cout << "Критерій: Родина \"" << targetFamily << "\"\n";
    std::cout << "----------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        if (animals[i].getFamily() == targetFamily) {
            animals[i].display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Жодна тварина не належить до цієї родини.\n";
    }

    std::cout << "========================================\n";
}
