#include <iostream>

//Шаблон-реализация простого вектора
template <typename T>
class MyVector
{
public:
	
	MyVector() : index(0), size(0), capacity(1), data(new T[capacity]) {}

	~MyVector() {
		delete[] data;
	}

	T at(int index) {
		return data[index];
	}
	
	void push_back(T value) {
		if (size < capacity)
		{
			data[index] = value;
			size++;
			index++;
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
			data[index] = value;
			index++;
			size++;
		}
	}

	void print() {
		for (int i = 0; i < index; i++)
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
	int index;
	int size;
	int capacity;
	T* data;
};

int main()
{
	MyVector<int> a;

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

	return 0;
}
