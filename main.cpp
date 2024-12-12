#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "M_Pav_AP-12_LW1.h"
#include "M_Pav_AP-12_LW2.h"
#include "M_Pav_AP-12_LW3.h"
#include "M_Pav_AP-12_LW4.h"
#include "M_Pav_AP-12_LW5.h"
#include "M_Pav_AP-12_LW6.h"
#include "M_Pav_AP-12_LW7.h"
#include "M_Pav_AP-12_LW8.h"
#include "M_Pav_AP-12_LW9.h"
#include "M_Pav_AP-12_LW10.h"

using namespace std;

void displayMenu(int selected) {
    string options[] = {
        "1. Laboratory work 1",
        "2. Laboratory work 2",
        "3. Laboratory work 3",
        "4. Laboratory work 4",
        "5. Laboratory work 5",
        "6. Laboratory work 6",
        "7. Laboratory work 7",
        "8. Laboratory work 8",
        "9. Laboratory work 9",
        "10. Laboratory work 10",
        "11. Laboratory work 11",
        "12. Laboratory work 12"
    };

    system("cls");

    for (int i = 0; i < 12; ++i) {
        if (i == selected) {
            cout << "-> ";
        }
        else {
            cout << "   ";
        }
        cout << options[i] << endl;
    }
}

void executeFunction(int choice) {
    system("cls");
    switch (choice) {
    case 0: start_LW_1(); break;
    case 1: start_LW_2(); break;
    case 2: start_LW_3(); break;
    case 3: start_LW_4(); break;
    case 4: start_LW_5(); break;
    case 5: start_LW_6(); break;
    case 6: start_LW_7(); break;
    case 7: start_LW_8(); break;
    case 8: start_LW_9(); break;
    case 9: start_LW_10(); break;
    case 10: start_LW_8(); break;
    case 11: start_LW_8(); break;
    default: cout << "An unknown choice\n"; break;
    }
    cout << "\nPress ESC to return to the menu...\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int selectedOption = 0;
    bool running = true;

    while (running) {
        displayMenu(selectedOption);

        int key = _getch();
        switch (key) {
        case 72:  // Up 
            if (selectedOption > 0) selectedOption--;
            break;
        case 80:  // Down
            if (selectedOption < 11) selectedOption++;
            break;
        case 13:  // Enter
            executeFunction(selectedOption);
            while (_getch() != 27);
            break;
        case 27:  // ESC
            running = false;
            break;
        }
    }

    cout << "Exiting from program\n";
    return 0;
}
