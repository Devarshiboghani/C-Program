#include <iostream>
#include <string>
using namespace std;

enum class ProductCategory {
    ELECTRONICS,
    COMPUTERS,
    ACCESSORIES,
    SOFTWARE
};

enum class OrderStatus {
    PENDING,
    PROCESSING,
    SHIPPED,
    DELIVERED,
    CANCELLED
};

enum class PaymentMethod {
    CREDIT_CARD,
    DEBIT_CARD,
    PAYPAL,
    BANK_TRANSFER
};

enum class UserRole {
    ADMIN,
    CUSTOMER,
    VENDOR
};

int main() {
    ProductCategory category = ProductCategory::ELECTRONICS;
    OrderStatus status = OrderStatus::PENDING;
    PaymentMethod payment = PaymentMethod::CREDIT_CARD;
    UserRole role = UserRole::ADMIN;

    std::cout << "Product Category: " << static_cast<int>(category) << std::endl;
    std::cout << "Order Status: " << static_cast<int>(status) << std::endl;
    std::cout << "Payment Method: " << static_cast<int>(payment) << std::endl;
    std::cout << "User Role: " << static_cast<int>(role) << std::endl;

    return 0;
}