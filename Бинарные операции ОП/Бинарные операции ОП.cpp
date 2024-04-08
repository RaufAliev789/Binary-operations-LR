#include <iostream>

auto COUNT_1(unsigned int num) {
    int index = -1;
    int curr_length = 0;
    int max_length = 0;

    for (int i = 0; i < sizeof(num) * 8; i++) { // размер переменной в битах
        if (num & (1 << i)) {
            curr_length++;
            if (curr_length > max_length) {
                max_length = curr_length;
                index = i - max_length + 1; //индексы идут с нуля. Здесь справа налево (4 3 2 1 0)
            }
        }
        else {
            curr_length = 0;
        }
    }
    std::cout << "Самая длинная последовательность единиц начинается с индекса " << index << " и имеет длину " << max_length << std::endl;

    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");
    unsigned int num;
    std::cout << "Введите десятичное число: " << std::endl;
    std::cin >> num;

    COUNT_1(num);

    return 0;
}

