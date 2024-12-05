#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
    std::string name;
    std::string order;
    std::string family;

public:
    Animal();
    Animal(const std::string& name, const std::string& order, const std::string& family);

    ~Animal();

    void input();

    void display() const;

    void setName(const std::string& name);
    void setOrder(const std::string& order);
    void setFamily(const std::string& family);

    std::string getName() const;
    std::string getOrder() const;
    std::string getFamily() const;

    static void findByFamily(const Animal animals[], int size, const std::string& targetFamily);
};

#endif // ANIMAL_H
