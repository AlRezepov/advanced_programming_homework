#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

template <class T>
class ini_parser
{
public:
	//Конструктор
	ini_parser(std::string name_file) : name_file(name_file) {
		std::ifstream ini_file(name_file); // Открываем файл для чтения
		if (!ini_file) {
			std::cerr << "Failed to open the file." << std::endl;
			return 1;
		}
		std::string line;
		while (std::getline(ini_file, line)) {
			for (size_t i = 0; i < length; i++)
			{

			}
			if (true)
			{

			}
		}
	};
	
	//Конструктор копирования

	//Оператор присваивания
	
	~ini_parser() {
		ini_file.close();
	};

private:
	std::string name_file;
	std::map <std::string, std::vector<int>> ini_data;
};




int main()
{
    std::cout << "Hello World!\n";
}