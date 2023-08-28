#include <iostream>

class smart_array
{
public:
	smart_array(int size) {
		this->size = size;
		arr = new int[size];
	};

	void add_element(int element) {
		if (index >= size)
		{
			throw std::runtime_error("Arr is full");
		}
		arr[index] = element;
		index++;
	}

	int get_element(int index) {
		if (index < size && index >= 0)
		{
			return arr[index];
		}
		else {
			throw std::runtime_error("Index isn't correct");
		}
	}

	smart_array(const smart_array& other) {
		size = other.size;
		index = other.index;

		arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = other.arr[i];
		}
	}

	smart_array& operator=(const smart_array& other) {
		if (this != &other) {
			delete[] arr;
			size = other.size;
			index = other.index;

			arr = new int[size];
			for (int i = 0; i < size; ++i) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	void print() {
		for (int i = 0; i < index; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	~smart_array() {
		delete[] arr;
	};

private:
	int size;
	int* arr;
	int index = 0;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		std::cout << "Первый массив: \n";
		arr.print();

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		std::cout << "Второй массив: \n";
		new_array.print();

		arr = new_array;

		std::cout << "Arr = new_array: \n";
		arr.print();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}