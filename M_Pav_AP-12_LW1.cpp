
#include "M_Pav_AP-12_LW1.h"

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void showRandomQuote(void) {
    const string quotes[] = {
        "For the King!!!!",
        "Perish you hideous Orc!!!",
        "Give me and my mate two pints of beer",
        "You can't beat me",
        "Hey!!!! don't look at me like that!!!"
    };

    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);

    random_device rd;
    mt19937 gen(rd());

    int randomIndex = gen() % numQuotes;

    cout << "NPC says: " << quotes[randomIndex] << endl;
}

void start_LW_1(void) {

    cout << "Greetings. Plunge into the world as fabulous as it is disgusting" << endl;


    auto lastTime = chrono::steady_clock::now();
    uint8_t i = 0;
    while (i < 8) {
        auto currentTime = chrono::steady_clock::now();

        if (chrono::duration_cast<chrono::seconds>(currentTime - lastTime).count() >= 1) {
            showRandomQuote();
            i++;

            lastTime = currentTime;
        }
    }
}