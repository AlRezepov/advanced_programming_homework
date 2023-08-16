// 1. Синтаксическая ошибка (неправильное объявление функции)
#include <iostream>

int add_numbers(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << add_numbers(3, 4) << std::endl;
    return 0;

    //Исправление: Добавьте закрывающую фигурную скобку для функции main.

    // 2. Семантическая ошибка (неправильное условие в if)
#include <iostream>

    int main()
    {
        int num = 10;

        if (num = 5) // Некорректное условие (используется присваивание вместо сравнения)
        {
            std::cout << "Number is equal to 5" << std::endl;
        }
        else
        {
            std::cout << "Number is not equal to 5" << std::endl;
        }

        return 0;
    }

    //Исправление: Замените = на == в условии if: if (num == 5).

    // Ошибка линковки (отсутствие определения функции)
#include <iostream>

    int multiply(int x, int y); // Прототип функции multiply

    int main()
    {
        int result = multiply(3, 4);
        std::cout << "Result: " << result << std::endl;
        return 0;
    }

    //Исправление: Добавьте определение функции multiply после функции main: