#include <iostream>

int hello(int); // Тоже самое что и в первой


static int hello(int number) //При добавлении static к этой функции выдаст ошибку, из-за того что эта функция не втдна в этом файле, из-за чего там не будет референса
{
   return number * 1;
}

