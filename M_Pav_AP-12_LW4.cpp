#include "animal.h"
#include "M_Pav_AP-12_LW4.h"
#include <iostream>

void start_LW_4(void) {
    Animal animal1;
    std::cout << "������ ��� ��� ����� �������:\n";
    animal1.input();

    Animal animal2("���", "���", "�����");

    std::cout << "\n��� ��� ����� �������:\n";
    animal1.display();

    std::cout << "\n��� ��� ����� �������:\n";
    animal2.display();

    std::cout << "\n���� ����� ����� ������� ����� �������.\n";
    animal2.setName("����");
    animal2.setOrder("���");
    animal2.setFamily("�����");

    std::cout << "������� ��� ��� ����� �������:\n";
    animal2.display();
}
