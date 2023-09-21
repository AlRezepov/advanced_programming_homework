#include <iostream>
#include <string>

class big_integer {
private:
    std::string num;

public:
 
    //Конструктор
    big_integer(const std::string& s) : num(s) {}

    //Конструктор копирования
    big_integer(const big_integer& other) : num(other.num) {}

    //Оператор присваивания
    big_integer& operator=(const big_integer& other) {
        if (this != &other) {
            num = other.num;
        }
        return *this;
    }

    // Конструктор перемещения, принимающий аргумент типа big_integer
    big_integer(big_integer&& other) : num(std::move(other.num)) {}

    // Конструктор перемещения
    big_integer(std::string&& other) : num(std::move(other)) {}

    // Перемещающий оператор присваивания
    big_integer& operator=(big_integer&& other) {
        if (this != &other) {
            num = std::move(other.num);
        }
        return *this;
    }

    // Оператор сложения двух больших чисел
    big_integer operator+(const big_integer& other) const {
        std::string result;
        int i = num.length() - 1;
        int j = other.num.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += other.num[j] - '0';
                j--;
            }

            carry = sum / 10;
            sum %= 10;
            result.insert(result.begin(), sum + '0');
        }

        return big_integer(result);
    }

    // Оператор умножения на число
    big_integer operator*(int x) const {
        std::string result;
        int i = num.length() - 1;
        int carry = 0;

        while (i >= 0 || carry > 0) {
            int multi = carry;
            if (i >= 0) {
                multi += (num[i] - '0') * x;
                i--;
            }

            result.insert(result.begin(), (multi % 10) + '0');
            carry = multi / 10;
        }

        return big_integer(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& a) {
        os << a.num;
        return os;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << "\n";

    auto multiplied = number1 * 5;
    std::cout << multiplied;

    return 0;
}
