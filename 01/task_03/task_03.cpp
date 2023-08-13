#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>

int main()
{
    
    setlocale(LC_ALL, "Russian");

    std::vector <double> angles {30, 60, 90};

    //Перевод из углов в радианы
    std::for_each(angles.begin(), angles.end(), [](auto& i) {
        i = i * 3.1415926 / 180;
        });

    //Вывод массива на консоль
    std::cout << "[Входные данные]: ";
    for (auto& i : angles)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    //Создание вектора функций
    std::vector <std::function<double(double)>> functions;

    //Лямбда функции нахождения sin, cos, tan
    auto sin = [](double radian) {
        std::cout << "sin = " << std::sin(radian) << " ";
        return std::sin(radian);
    };
    auto cos = [](double radian) {
        std::cout << "cos = " << std::cos(radian) << " ";
        return std::cos(radian);
    };
    auto tan = [](double radian) {
        std::cout << "tan = " << std::tan(radian) << "\t";
        return std::tan(radian);
    };

    //Добавление функций в вектор functions
    functions.push_back(sin);
    functions.push_back(cos);
    functions.push_back(tan);

    //Вывод массива на консоль
    std::cout << "[Выходные данные]: \n";
    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }

    return 0;
}