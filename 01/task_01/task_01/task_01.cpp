#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::vector <int> arr {4, 7, 9, 14, 12};
    
    //Лямбда функция вывода вектора на консоль
    auto print = [](std::vector <int> arr) {
        for (auto& i : arr)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    };

    //Вывод вектора на консоль
    std::cout << "Входные данные: ";
    print(arr);

    //Цикл for_each и анонимная лямбда функция умножения нечетного числа на 3
    std::for_each(arr.begin(), arr.end(), [](int& i) {
        if (i % 2 != 0) {
            i *= 3;
        }
    });

    //Вывод вектора на консоль
    std::cout << "Выходные данные: ";
    print(arr);

    return 0;
}



////Лямбда функция умножения нечетного числа на 3
//auto func = [](std::vector <int>& arr) {
//    for (auto& i : arr)
//    {
//        if (i % 2 != 0) {
//            i *= 3;
//        }
//    }
//};