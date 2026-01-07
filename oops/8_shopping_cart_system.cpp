#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Product class
class Product {
public:
    int productId;
    string name;
    double price;
    double discount;

    Product(int id, string n, double p, double d) : productId(id), name(n), price(p), discount(d) {}

    virtual double calculateDiscountedPrice() const {
        return price - (price * discount / 100);
    }
};

// ShoppingCart class
class ShoppingCart {
private:
    int customerId;
    vector<pair<Product, int>> items; // Pair of Product and Quantity
    double totalAmount;

public:
    // Constructor
    ShoppingCart(int id) : customerId(id), totalAmount(0) {}

    // Method: Add Item (Overloaded)
    void addItem(const Product& product, int quantity) {
        items.push_back({product, quantity});
    }

    void addItem(const Product& product) {
        addItem(product, 1); // Default quantity is 1
    }

    // Method: Remove Item
    void removeItem(int productId) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->first.productId == productId) {
                items.erase(it);
                break;
            }
        }
    }

    // Method: Update Quantity
    void updateQuantity(int productId, int newQuantity) {
        for (auto& item : items) {
            if (item.first.productId == productId) {
                item.second = newQuantity;
                break;
            }
        }
    }

    // Method: Calculate Total (Polymorphism)
    void calculateTotal() {
        totalAmount = 0;
        for (const auto& item : items) {
            totalAmount += item.first.calculateDiscountedPrice() * item.second;
        }
    }

    // Method: Apply Coupon (Using 'this' keyword)
    void applyCoupon(const string& couponCode) {
        if (couponCode == "DISCOUNT10") {
            this->totalAmount *= 0.9; // Apply 10% discount
        }
    }

    // Display Cart
    void displayCart() const {
        cout << "Customer ID: " << customerId << "\nItems in Cart:\n";
        for (const auto& item : items) {
            cout << "Product: " << item.first.name << ", Quantity: " << item.second
                 << ", Price: " << item.first.calculateDiscountedPrice() << "\n";
        }
        cout << "Total Amount: " << totalAmount << "\n";
    }
};

// Main function to demonstrate functionality
int main() {
    Product p1(1, "Laptop", 50000, 10);
    Product p2(2, "Phone", 20000, 5);

    ShoppingCart cart(101);
    cart.addItem(p1, 2);
    cart.addItem(p2);
    cart.updateQuantity(2, 3);
    cart.calculateTotal();
    cart.applyCoupon("DISCOUNT10");
    cart.displayCart();

    cart.removeItem(1);
    cart.calculateTotal();
    cart.displayCart();

    return 0;
}