#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "[IN]: \n";
    //Ввод пользователем размера массива данных
    int size;
    std::cin >> size;
    std::cout << std::endl;

    //Инициализация std::list с фиксированным размером данных
    std::list<int> data(size);

    //Ввод данных пользователем
    for (auto& i : data)
    {
        std::cin >> i;
    }
    std::cout << std::endl;

    //Удаление дубликатов в std::list
    data.unique();

    // Создание временного вектора из элементов data
    std::vector<int> temp_vector(data.begin(), data.end());
    
    // Сортировка с использованием лямбда-функции
    std::sort(temp_vector.begin(), temp_vector.end(), [](const auto& a, const auto& b) {
        return a > b;
        });

    //Вывод данных в консоль
    std::cout << "[OUT]: \n";
    for (const auto& i : temp_vector) {
        std::cout << i << std::endl;
    }
    return 0;
}