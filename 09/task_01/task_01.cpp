#include <vector>
#include <string>

template <typename T>
void move_vectors(std::vector<T>& a, std::vector<T>& b) {
    
    b.clear();

    for (auto&& i : a) {
        b.push_back(std::move(i));
    }

    a.clear();
}

int main() {
    std::vector<std::string> one = { "test_string1", "test_string2" };
    std::vector<std::string> two;

    move_vectors(one, two); // one теперь пуст, а two содержит перемещенные строки.

    return 0;
}
