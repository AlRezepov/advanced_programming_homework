#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

class ini_parser
{
public:
    ini_parser(const std::string& name_file) : name_file(name_file) {
        load_file(name_file);
    }

    void load_file(const std::string& name_file) {
        std::ifstream ini_file(name_file); // Открываем файл для чтения
        if (!ini_file) {
            throw std::runtime_error("Failed to open the file.");
        }
        std::string line;
        std::string current_section;
        while (std::getline(ini_file, line)) {
            if (line.empty() || line[0] == ';') {
                continue; // Пропускаем пустые строки и строки-комментарии
            }
            else if (line[0] == '[' && line[line.length() - 1] == ']') {
                current_section = line.substr(1, line.length() - 2); // Записываем название секции без учета []
            }
            else {
                int equal_position = line.find('=');
                if (equal_position != std::string::npos) {
                    std::string key = line.substr(0, equal_position);
                    std::string value = line.substr(equal_position + 1);
                    ini_data[current_section][key] = value;
                }
            }
        }
        ini_file.close(); // Закрытие файла
    }

    template <typename T>
    T get_value(const std::string& section_key) const {
        int dot_pos = section_key.find('.');
        if (dot_pos == std::string::npos) {
            throw std::runtime_error("Invalid section.key format.");
        }

        std::string section = section_key.substr(0, dot_pos);
        std::string key = section_key.substr(dot_pos + 1);

        auto section_iter = ini_data.find(section);
        if (section_iter != ini_data.end()) {
            const auto& section_data = section_iter->second;
            auto key_iter = section_data.find(key);
            if (key_iter != section_data.end()) {
                T value;
                std::istringstream(key_iter->second) >> value;
                return value;
            }
        }
        throw std::runtime_error("Section.key not found in INI file.");
    }

private:
    std::string name_file;
    std::map<std::string, std::map<std::string, std::string>> ini_data;
};

int main() {
    try {
        ini_parser parser("demo_file.ini");
        auto value = parser.get_value<int>("section1.value1");
        std::cout << "Value: " << value << std::endl;
        auto value_02 = parser.get_value<std::string>("section2.value2");
        std::cout << "Value: " << value_02 << std::endl;
        value_02 = parser.get_value<std::string>("section3.value2");
        std::cout << "Value: " << value_02 << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
