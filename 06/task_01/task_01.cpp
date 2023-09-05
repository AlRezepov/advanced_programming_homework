#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "[IN]: ";
    std::string arr_keys;
    
    //Ввод строки пользователем с учетом пробелов
    std::getline(std::cin, arr_keys);

    std::map<char, int> letter_frequency;

    //Определяем кол-во каждого символа в контейнере letter_frequency
    for (auto& i : arr_keys)
    {
        letter_frequency[i]++;
    }

    // Создаем временный вектор из элементов letter_frequency
    std::vector<std::pair<char, int>> temp_vector(letter_frequency.begin(), letter_frequency.end());

    // Сортировка по частотам с использованием лямбда-функции
    std::sort(temp_vector.begin(), temp_vector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    //Вывод данных в консоль
    for (const auto& i : temp_vector) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
    return 0;
}