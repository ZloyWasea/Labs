#include <iostream>
#include <string_view>
#include <cassert>

// Функция для подсчета количества символов "1" в строке
size_t countOnes(std::string_view str) {
    size_t count = 0;
    for (char ch : str) {
        if (ch == "1") {
            ++count;
        }
    }
    return count;
}

// Функция для запуска тестов
void runTests() {
    assert(countOnes("001100") == 2); // Два "1"
    assert(countOnes("000000") == 0); // Ни одного "1"
    assert(countOnes("111111") == 6); // Шесть "1"
    assert(countOnes("") == 0);        // Пустая строка
    assert(countOnes("101010") == 3);  // Три "1"
    assert(countOnes("100001") == 2);  // Два "1"
    assert(countOnes("1110011") == 5); // Пять "1"
    assert(countOnes("000011110000") == 4); // Четыре "1"
    
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}