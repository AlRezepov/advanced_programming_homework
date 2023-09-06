#include <iostream>

//Шаблон-реализация простого вектора
template <typename T>
class MyVector
{
public:
	
	MyVector() : size(0), capacity(1), data(new T[capacity]) {}

	~MyVector() {
		delete[] data;
	}

	MyVector(const MyVector& other) {
		size = other.size;
		capacity = other.capacity;
		data = new T[capacity];
		for (int i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}

	MyVector& operator=(const MyVector& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	
	T at(int size) {
		return data[size];
	}
	
	void push_back(T value) {
		if (size < capacity)
		{
			data[size] = value;
			size++;
		}
		else if (size == capacity)
		{
			capacity = size * 2;
			T* temp_data = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
			data[size] = value;
			size++;
		}
	}

	void print() {
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	int get_size() {
		return size;
	}

	int get_capacity() {
		return capacity;
	}

private:
	int size;
	int capacity;
	T* data;
};

int main()
{
	MyVector<int> a;

	//Проверка базовых функций вектора
	
	a.push_back(1);
	a.push_back(2);
	a.push_back(190);
	a.push_back(55);
	a.push_back(66);
	a.push_back(66);
	a.push_back(66);
	a.push_back(66);
	a.push_back(66);

	a.print();

	std::cout << a.get_size() << std::endl;
	std::cout << a.get_capacity() << std::endl;
	std::cout << a.at(2) << std::endl;

	MyVector<int> t1;
	MyVector<int> t2;

	//Проверка конструктора копирования и оператора присвоения
	
	t2.push_back(66);
	t2.push_back(66);
	t2.push_back(66);

	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(190);

	t1.print();
	std::cout << std::endl;

	t1 = t2;

	t1.print();

	return 0;
}
