#include <iostream>
#include <variant>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

 
std::variant <int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::variant<int, std::string, std::vector<int>> result = get_variant();

	//Проверка входных данных на Int
	if (std::holds_alternative<int>(result))
	{
		std::get<int>(result) *= 2;
		std::cout << "Int результат = " << std::get<int>(result);
	}

	//Проверка входных данных на String
	if (std::holds_alternative<std::string>(result))
	{
		std::cout << "String результат = " << std::get<std::string>(result);
	}

	//Проверка входных данных на Vector
	if (std::holds_alternative<std::vector<int>>(result))
	{
		std::cout << "Vector результат = ";
		for (auto& i : std::get<std::vector<int>>(result))
		{
			std::cout << i << " ";
		}
	}

	return 0;
}
