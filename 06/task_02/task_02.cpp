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

    //Инициализация std::list data с фиксированным размером данных
    std::list<int> data(size);

    //Ввод данных пользователем
    for (auto& i : data)
    {
        std::cin >> i;
    }
    std::cout << std::endl;

    
    //Удаление дубликатов в data
    data.unique();

    //Создание временного вектора temp_vector из элементов data
    std::vector<int> temp_vector(data.begin(), data.end());
    
    //Сортировка temp_vector с использованием лямбда-функции
    std::sort(temp_vector.begin(), temp_vector.end(), [](const auto& a, const auto& b) {
        return a > b;
        });

    //Создание std::list data_02 из элементов temp_vector
    std::list<int> data_02(temp_vector.begin(), temp_vector.end());

    //Удаление дубликатов в data_02
    data_02.unique();

    //Очищение и заполнение вектора элементами data_02
    temp_vector.clear();
    for (auto& i : data_02)
    {
        temp_vector.push_back(i);
    }

    //Вывод данных в консоль
    std::cout << "[OUT]: \n";
    for (const auto& i : temp_vector) {
        std::cout << i << std::endl;
    }
    return 0;
}