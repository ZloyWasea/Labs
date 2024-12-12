#include <string.h> // Подключение библиотеки для использования функции "memset"
#include <iostream>

// Создаётся структура которая хранит два целых числа
struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4]; 
    int* someNumber; // Эта структура состоит из массива из 4 целых чисел и указателя на целое число
};

int main()
{
    // Создаём объект i2 типа TwoInts и инициализируем его переменные по умолчанию (нулём).
    TwoInts i2 = { };
    i2.a = 5; // Присваивание переменной а числа 5
    i2.b = 7; // Присваивание переменной b числа 7

    std::cout << i2.a << std::endl; // Выводим их
    std::cout << i2.b << std::endl;
    
    StructWithArray s = { }; // Создаём объект s типа StructWithArray и инициализируем массив и указатель нулями
    s.arr[0] = 10; // Присваиваем значению первого элемента массива arr[0] значение 10

    StructWithArray s1 = { }; // Создаём ещё один объект s1 той же структуры и также инициализируем его нулями
    s1.arr[0] = 15; // Присваиваем значению первого элемента массива arr[0] значение 15

    StructWithArray* sPointer = &s; // Создаём указатель sPointer, который будет указывать на объект s
    sPointer->arr[0] = 20; // Через этот указатель изменяется значение первого элемента массива из экземпляра "s"
     
    // Выводим значение после изменений
    std::cout << s.arr[0] << std::endl; // Выводит 20
    s.arr[0] = 25; 
    std::cout << s.arr[0] << std::endl; // Выводит 25
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl; // Выводит 30

    sPointer = &s1;
    sPointer->arr[0] = 35; // Указатель sPointer теперь будет указывать на объект s1
    std::cout << s.arr[0] << std::endl; // Выведет 30
    std::cout << s1.arr[0] << std::endl; // Выведет 35

    StructWithArray structArray[2] = { }; // Создаём массив из двух объектов структуры StructWithArray
    structArray[0].arr[3] = 77; // Присваиваем четвёртому элементу массива первого объекта значение 77
    structArray[1].someNumber = &structArray[0].arr[3]; // Указатель someNumber второго объекта теперь указывает на четвёртый элемент массива первого объекта

    sPointer = &s; // Возвращаем указатель обратно на объект s
    int* pointer = &sPointer->arr[3]; // Указатель на четвёртый элемент массива
    s.arr[3] = 72; // Присваиваем четвёртому элементу массива значение 72
    std::cout << *pointer; // Выведет 72, т.к. pointer указывает на s.arr[3]

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray)); // В конце используется функция memset, чтобы заполнить всю структуру нулями
    return 0;
}