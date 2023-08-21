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

	~smart_array() {
		delete [] arr;
	};

private:
	int size;
	int* arr;
	int index = 0;
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}