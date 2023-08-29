#include <iostream>
#include <vector>

template <class T>
class table
{
public:
    table(int rows, int cols) : rows(rows), cols(cols), A(rows, std::vector<T>(cols)) {}

    std::vector<T>& operator[](int row) {
        return A[row];
    }

    const std::vector<T>& operator[](int row) const {
        return A[row];
    }

    int Size() const {
        return rows * cols;
    }

private:
    std::vector<std::vector<T>> A;
    int rows;
    int cols;
};

int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // Output: 4
    std::cout << test.Size() << std::endl; // Output: 6

    return 0;
}
