#include <iostream>
#include <vector>

template <typename T>
T squaring(T a) {
    return a * a;
}

template <typename U>
std::vector<U> squaring(const std::vector<U>& a) {
    
    std::vector<U> b;
    for (auto& i : a) {
        b.push_back(i * i);
    }
    return b;
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
    A = squaring(A);
    for (auto& i : A)
    {
        std::cout << i << ", ";
    }
    return 0;
}