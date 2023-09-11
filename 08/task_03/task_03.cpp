#include <iostream>

template <class T>
class unique_ptr
{
public:
    unique_ptr(T* ptr) : ptr(ptr) {}

    T operator*() {
        return *ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr& operator=(const unique_ptr&) = delete;

    ~unique_ptr() {
        delete ptr;
        std::cout << "ptr deleted";
    }

private:
    T* ptr;
};

int main()
{
    int* ptr = new int(50);

    unique_ptr<int> uniquePtr(ptr);

    int value = *uniquePtr;
    std::cout << value << "\n";

    int* ptr_02 = uniquePtr.release();

    delete ptr_02;

    return 0;
}
