#include <iostream>
#include <vector>
#include <algorithm>


void removeDuplicates(std::vector<int>& a) {
    
    // Сортировка вектора
    std::sort(a.begin(), a.end());

    // Использование std::unique
    auto it = std::unique(a.begin(), a.end());

    //Удаление дубликатов с конца вектора
    a.erase(it, a.end());
}

int main() {

    std::vector<int> a = { 1, 1, 2, 5, 6, 1, 2, 4 };

    // Вывод элементов вектора
    std::cout << "[IN]: \n";
    for (const auto& i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Удаление дубликатов
    removeDuplicates(a);

    // Вывод уникальных элементов
    std::cout << "[OUT]: \n";
    for (const auto& i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
