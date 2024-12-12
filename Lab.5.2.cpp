#include <iostream>
#include <string_view>
#include <cassert>
#include <string>
#include <algorithm>

// Функция для нахождения второго слова в строке
std::string_view secondWord(std::string_view str) {
    str.remove_prefix(std::min(str.find_first_not_of(' '), str.size()));

    // Находим первое слово
    auto first_space = str.find(' ');
    if (first_space == std::string_view::npos) {
        return ""; // Если нет пробелов, значит нет второго слова
    }

    // Удаляем первое слово
    str.remove_prefix(first_space + 1);

    // Удаляем начальные пробелы после первого слова
    str.remove_prefix(std::min(str.find_first_not_of(' '), str.size()));

    // Находим второе слово
    auto second_space = str.find(' ');
    if (second_space == std::string_view::npos) {
        return str; // Если нет второго пробела, возвращаем оставшуюся часть строки
    }

    return str.substr(0, second_space); // Возвращаем второе слово
}

// Функция для запуска тестов
void runTests() {
    assert(secondWord("Hello world") == "world");              // Второе слово "world"
    assert(secondWord("Hello my dear") == "my");              // Второе слово "my"
    assert(secondWord("") == "");                              // Пустая строка
    assert(secondWord(" ") == "");                             // Пустая строка с пробелом
    assert(secondWord(" a ") == "a");                          // Второе слово "a"
    assert(secondWord("a  ") == "");                           // Нет второго слова
    assert(secondWord("a  b") == "");                          // Нет второго слова
    assert(secondWord("hello     world    dear") == "world"); // Второе слово "world"

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}