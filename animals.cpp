#include "animals.h"
#include <iomanip>

// Конструктор за замовчуванням
Animals::Animals() : count(0) {}

// Перевірка валідності рядкових полів
bool Animals::validateString(const std::string& str, const std::string& fieldName) const {
    if (str.empty()) {
        std::cerr << "Помилка: поле \"" << fieldName << "\" не може бути порожнім.\n";
        return false;
    }
    if (str.length() > 30) {
        std::cerr << "Помилка: поле \"" << fieldName << "\" перевищує 30 символів.\n";
        return false;
    }
    return true;
}

bool Animals::validateId(int id) const {
    if (id <= 0) {
        std::cerr << "Помилка: ID повинен бути додатним числом.\n";
        return false;
    }
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            return true;
        }
    }
    std::cerr << "Помилка: тварину з ID " << id << " не знайдено.\n";
    return false;
}



// Додати нову тварину
void Animals::addAnimal(const animal_s_t& newAnimal) {
    if (count >= MAX_SIZE) {
        std::cerr << "Помилка: досягнуто максимальну кількість тварин.\n";
        return;
    }

    if (!validateString(newAnimal.name, "Назва") || 
        !validateString(newAnimal.order, "Ряд") || 
        !validateString(newAnimal.family, "Родина")) {
        return;
    }

    animals[count++] = newAnimal;
    std::cout << "Тварину \"" << newAnimal.name << "\" успішно додано!\n";
}

// Оновити дані тварини за ID
void Animals::updateAnimal(int id, const animal_s_t& animal) {
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            if (!validateString(animal.name, "Назва") ||
                !validateString(animal.order, "Ряд") ||
                !validateString(animal.family, "Родина")) {
                return;
            }

            animals[i] = animal;
            std::cout << "Дані тварини з ID " << id << " оновлено.\n";
            return;
        }
    }
    std::cerr << "Помилка: тварину з ID " << id << " не знайдено.\n";
}

void Animals::insertAnimal(int index, const animal_s_t& animal) {
    if (count >= MAX_SIZE) {
        std::cerr << "Помилка: список заповнений.\n";
        return;
    }
    if (index < 0 || index > count) {
        std::cerr << "Помилка: індекс виходить за межі списку.\n";
        return;
    }

    for (int i = count; i > index; --i) {
        animals[i] = animals[i - 1];
    }
    animals[index] = animal;
    ++count;
    std::cout << "Тварину \"" << animal.name << "\" успішно вставлено на позицію " << index << ".\n";
}

// Видалити тварину за ID
void Animals::removeAnimalById(int id) {
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id) {
            for (int j = i; j < count - 1; ++j) {
                animals[j] = animals[j + 1];
            }
            --count;
            std::cout << "Тварину з ID " << id << " успішно видалено.\n";
            return;
        }
    }
    std::cerr << "Помилка: тварину з ID " << id << " не знайдено.\n";
}

// Очистити список тварин
void Animals::clearAnimals() {
    count = 0;
    std::cout << "Список тварин успішно очищено.\n";
}

// Обмін тваринами за ID
void Animals::swapAnimals(int id1, int id2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < count; ++i) {
        if (animals[i].id == id1) index1 = i;
        if (animals[i].id == id2) index2 = i;
    }

    if (index1 == -1 || index2 == -1) {
        std::cerr << "Помилка: один або обидва ID не знайдено.\n";
        return;
    }

    std::swap(animals[index1], animals[index2]);
    std::cout << "Тварини з ID " << id1 << " та " << id2 << " успішно обміняні місцями.\n";
}

// Вивести всі тварини
void Animals::displayAnimals() const {
    if (count == 0) {
        std::cout << "Список тварин порожній.\n";
        return;
    }

    std::cout << "========== Список тварин ==========\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "ID: " << animals[i].id << "\n"
            << "Назва: " << animals[i].name << "\n"
            << "Ряд: " << animals[i].order << "\n"
            << "Родина: " << animals[i].family << "\n"
            << "-----------------------------------\n";
    }
}

// Пошук за родиною
void Animals::findAnimalByFamily(const std::string& family) const {
    bool found = false;
    std::cout << "========== Пошук за родиною \"" << family << "\" ==========\n";
    for (int i = 0; i < count; ++i) {
        if (animals[i].family == family) {
            std::cout << "ID: " << animals[i].id << "\n"
                << "Назва: " << animals[i].name << "\n"
                << "Ряд: " << animals[i].order << "\n"
                << "-----------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Жодної тварини з родини \"" << family << "\" не знайдено.\n";
    }
}
