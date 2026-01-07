#include <iostream>
#include <regex>
#include <string>
#include <cstdlib>
#include <ctime>

class ValidationUtils {
public:
    static bool validateEmail(const std::string& email) {
        const std::regex emailPattern(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
        return std::regex_match(email, emailPattern);
    }

    static bool validatePhoneNumber(const std::string& phone) {
        const std::regex phonePattern(R"(\+?[0-9]{10,15})");
        return std::regex_match(phone, phonePattern);
    }

    static bool validateCreditCard(const std::string& cardNumber) {
        int nDigits = cardNumber.length();
        int sum = 0;
        bool isSecond = false;

        for (int i = nDigits - 1; i >= 0; i--) {
            int d = cardNumber[i] - '0';

            if (isSecond)
                d = d * 2;

            sum += d / 10;
            sum += d % 10;

            isSecond = !isSecond;
        }
        return (sum % 10 == 0);
    }

    static std::string generateOrderId() {
        std::srand(std::time(nullptr));
        std::string orderId = "ORD";
        for (int i = 0; i < 8; ++i) {
            orderId += std::to_string(std::rand() % 10);
        }
        return orderId;
    }
};

int main() {
    std::cout << "Email valid: " << ValidationUtils::validateEmail("example@test.com") << "\n";
    std::cout << "Phone valid: " << ValidationUtils::validatePhoneNumber("+919876543210") << "\n";
    std::cout << "Credit Card valid: " << ValidationUtils::validateCreditCard("4532015112830366") << "\n";
    std::cout << "Generated Order ID: " << ValidationUtils::generateOrderId() << "\n";

    return 0;
}