#include <iostream>
#include <string>
#include <vector>

class User {
public:
    virtual std::string getAccessLevel() const {
        return "guest";
    }
    virtual ~User() = default; // Virtual destructor for proper cleanup
};

class Customer : public User {
private:
    std::string shippingAddress;
    std::vector<std::string> orderHistory;
    int loyaltyPoints;

public:
    // Constructor
    Customer(const std::string& address, int points = 0)
        : shippingAddress(address), loyaltyPoints(points) {}

    // Override getAccessLevel
    std::string getAccessLevel() const override {
        return "standard";
    }

    // Add loyalty points
    void addLoyaltyPoints(int points) {
        if (points > 0) {
            loyaltyPoints += points;
            std::cout << points << " points added. Total: " << loyaltyPoints << " points.\n";
        } else {
            std::cout << "Invalid points value.\n";
        }
    }

    // Redeem loyalty points
    void redeemPoints(int points) {
        if (points > 0 && points <= loyaltyPoints) {
            loyaltyPoints -= points;
            std::cout << points << " points redeemed. Remaining: " << loyaltyPoints << " points.\n";
        } else {
            std::cout << "Insufficient points or invalid value.\n";
        }
    }

    // Add order to history
    void addOrder(const std::string& order) {
        orderHistory.push_back(order);
        std::cout << "Order added: " << order << "\n";
    }

    // Display order history
    void displayOrderHistory() const {
        std::cout << "Order History:\n";
        for (const auto& order : orderHistory) {
            std::cout << "- " << order << "\n";
        }
    }

    // Get shipping address
    std::string getShippingAddress() const {
        return shippingAddress;
    }

    // Set shipping address
    void setShippingAddress(const std::string& address) {
        shippingAddress = address;
    }
};

int main() {
    Customer customer("123 Main St", 50);

    std::cout << "Access Level: " << customer.getAccessLevel() << "\n";

    customer.addLoyaltyPoints(20);
    customer.redeemPoints(30);
    customer.redeemPoints(50);

    customer.addOrder("Order #1: Laptop");
    customer.addOrder("Order #2: Smartphone");

    customer.displayOrderHistory();

    std::cout << "Shipping Address: " << customer.getShippingAddress() << "\n";
    customer.setShippingAddress("456 Elm St");
    std::cout << "Updated Shipping Address: " << customer.getShippingAddress() << "\n";

    return 0;
}