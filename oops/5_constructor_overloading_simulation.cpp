#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Order {
private:
    int customerId;
    std::vector<std::string> productArray;
    std::string productId;
    std::string shippingAddress;

public:
    Order(int custId) : customerId(custId) {
        std::cout << "Order created with Customer ID: " << customerId << std::endl;
    }
    Order(int custId, const std::vector<std::string>& products) 
        : customerId(custId), productArray(products) {
        std::cout << "Order created with Customer ID: " << customerId << " and Products: ";
        for (const auto& product : productArray) {
            std::cout << product << " ";
        }
        std::cout << std::endl;
    }

    Order(int custId, const std::string& prodId, const std::string& address) 
        : customerId(custId), productId(prodId), shippingAddress(address) {
        std::cout << "Order created with Customer ID: " << customerId 
                  << ", Product ID: " << productId 
                  << ", Shipping Address: " << shippingAddress << std::endl;
    }

    Order(int custId, const std::vector<std::string>& products, const std::string& prodId, const std::string& address) 
        : customerId(custId), productArray(products), productId(prodId), shippingAddress(address) {
        std::cout << "Order created with Customer ID: " << customerId 
                  << ", Products: ";
        for (const auto& product : productArray) {
            std::cout << product << " ";
        }
        std::cout << ", Product ID: " << productId 
                  << ", Shipping Address: " << shippingAddress << std::endl;
    }
};

int main() {
    Order order1(101);

    std::vector<std::string> products = {"Laptop", "Mouse", "Keyboard"};
    Order order2(102, products);

    Order order3(103, "P12345", "123 Elm Street, Cityville");

    Order order4(104, products, "P67890", "456 Oak Avenue, Townsville");

    return 0;
}