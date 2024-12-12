#include <iostream>

int main()
{
    int number = 10;

    if (number == 5)
    {
        std::cout << "The number is 5" << std::endl;
        return 0;  // Ранний выход
    }

    std::cout << "The number is not 5" << std::endl;

   
    if (number % 2 == 1) // Проверка на то, делится ли number на 2
    {
        std::cout << "The number is not divisible by 2" << std::endl;
        return 0;  // Ранний выход
    }

    std::cout << "The number is divisible by 2" << std::endl;

    if (number == 6)
    {
        std::cout << "The number is 6" << std::endl;
    }

    return 0;  // Завершается 
}
