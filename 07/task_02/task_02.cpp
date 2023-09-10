#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename T>
void print_container(const T& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);
    
    // four one three two. помните почему такой порядок?
    // Потому что элементы в std::set автоматически сортируются в возрастающем порядке на момент добавления в контейнер. 
    // В данном случае, строки сортируются в лексикографическом порядке. 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
}
