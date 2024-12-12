#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds < 0) {
            int borrow = (abs(seconds) + 59) / 60;
            seconds += borrow * 60;
            minutes -= borrow;
        }
        if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            minutes += borrow * 60;
            hours -= borrow;
        }
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours < 0) hours = 0;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    int differenceFromStart() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    bool operator>(const Time& other) const {
        return this->differenceFromStart() > other.differenceFromStart();
    }

    Time& operator-=(int n) {
        seconds -= n;
        normalize();
        return *this;
    }

    void input() {
        std::cout << "Введіть час (години, хвилини, секунди): " << std::endl;
        std::cout << "Години: ";
        std::cin >> hours;
        std::cout << "Хвилини: ";
        std::cin >> minutes;
        std::cout << "Секунди: ";
        std::cin >> seconds;
        normalize();
    }

    void output() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;
    }
};

bool compareDescending(const Time& t1, const Time& t2) {
    return t1 > t2;
}

void start_LW_10(void) {
    int n;
    std::cout << "Введіть кількість екземплярів часу: ";
    std::cin >> n;

    std::vector<Time> times(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Час " << i + 1 << ":\n";
        times[i].input();
    }

    std::sort(times.begin(), times.end(), compareDescending);

    std::cout << "\nВідсортований масив:\n";
    for (const auto& time : times) {
        time.output();
        std::cout << " (різниця: " << time.differenceFromStart() << " секунд)\n";
    }

    int decrease;
    std::cout << "\nВведіть кількість секунд для зменшення кожного часу: ";
    std::cin >> decrease;

    for (auto& time : times) {
        time -= decrease;
    }

    std::cout << "\nМасив після зменшення:\n";
    for (const auto& time : times) {
        time.output();
        std::cout << " (різниця: " << time.differenceFromStart() << " секунд)\n";
    }
}
