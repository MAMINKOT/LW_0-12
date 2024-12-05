#ifndef ANIMALS_H
#define ANIMALS_H

#include <array>
#include <string>
#include <vector>
#include <iostream>
#include <limits>

struct animal_s_t {
    int id;
    std::string name;
    std::string order;
    std::string family;
};

class Animals {
private:
    static const int MAX_SIZE = 10;
    std::array<animal_s_t, MAX_SIZE> animals;
    int count;

    bool validateString(const std::string& str, const std::string& fieldName) const;

    bool validateId(int id) const;

public:
    Animals();

    void addAnimal(const animal_s_t& newAnimal);

    void insertAnimal(int index, const animal_s_t& animal);
    void removeAnimalById(int id);
    void clearAnimals();
    void swapAnimals(int id1, int id2);

    void updateAnimal(int id, const animal_s_t& animal);
    void displayAnimals() const;
    void findAnimalByFamily(const std::string& family) const;
};

#endif // ANIMALS_H
