#include "animal.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// ������������
Animal::Animal() : name("�������"), order("�������"), family("�������") {}

Animal::Animal(const std::string& name, const std::string& order, const std::string& family) {
    this->setName(name);
    this->setOrder(order);
    this->setFamily(family);
}

// ����������
Animal::~Animal() {
    std::cout << "��'��� ������� \"" << name << "\" ��������.\n";
}

// ������ ��� �������� �����
void Animal::input() {
    std::string temp;

    std::cout << "������ ����� �������: ";
    std::getline(std::cin, temp);
    setName(temp);

    std::cout << "������ ��� �������: ";
    std::getline(std::cin, temp);
    setOrder(temp);

    std::cout << "������ ������ �������: ";
    std::getline(std::cin, temp);
    setFamily(temp);
}

void Animal::display() const {
    std::cout << "----------------------------------------\n";
    std::cout << "| �����   : " << std::setw(30) << std::left << name << "|\n";
    std::cout << "| ���     : " << std::setw(30) << std::left << order << "|\n";
    std::cout << "| ������  : " << std::setw(30) << std::left << family << "|\n";
    std::cout << "----------------------------------------\n";
}

// ������� � ���������
void Animal::setName(const std::string& name) {
    if (name.empty()) {
        std::cerr << "�������: ����� �� ���� ���� ���������.\n";
        this->name = "�������";
    }
    else {
        this->name = name;
    }
}

void Animal::setOrder(const std::string& order) {
    if (order.empty()) {
        std::cerr << "�������: ��� �� ���� ���� �������.\n";
        this->order = "�������";
    }
    else {
        this->order = order;
    }
}

void Animal::setFamily(const std::string& family) {
    if (family.empty()) {
        std::cerr << "�������: ������ �� ���� ���� ���������.\n";
        this->family = "�������";
    }
    else {
        this->family = family;
    }
}

// �������
std::string Animal::getName() const { return name; }
std::string Animal::getOrder() const { return order; }
std::string Animal::getFamily() const { return family; }

void Animal::findByFamily(const Animal animals[], int size, const std::string & targetFamily) {
    bool found = false;
    std::cout << "\n========== ���������� ������ ==========\n";
    std::cout << "�������: ������ \"" << targetFamily << "\"\n";
    std::cout << "----------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        if (animals[i].getFamily() == targetFamily) {
            animals[i].display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "����� ������� �� �������� �� ���� ������.\n";
    }

    std::cout << "========================================\n";
}
