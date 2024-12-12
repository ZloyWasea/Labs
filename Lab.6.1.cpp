#include <iostream>

//Ошибка при компиляции. При компиляции этого кода вы получите ошибку "undefined reference to hello(int)", потому что функция hello объявлена, но не определена. Компилятор не может найти реализацию функции, когда она вызывается в main.

// Исправленный кодошибок нет
int hello(int number)
{
   return number * 11;
}


int main()
{
   int result = hello(5);
   std::cout << result << std::endl;
   return 0;
}