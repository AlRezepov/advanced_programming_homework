#include <iostream>
#include <vector>

template <typename T>
T squaring(T a) {
    return a * a;
}

template <typename U>
void squaring(std::vector<U>& a) {
    for (auto& i : a) {
        i = i * i;
    }
}

int main()
{
    auto a = 0;

    std::cout << "[IN]: ";
    std::cin >> a;
    std::cout << "[OUT]: ";
    std::cout << squaring (a) << "\n";
    
    std::vector <int> A = { -1, 4, 8 };

    std::cout << "[IN]: ";
    for (auto& i : A)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
    std::cout << "[OUT]: ";
    squaring(A);
    for (auto& i : A)
    {
        std::cout << i << ", ";
    }
    return 0;
}