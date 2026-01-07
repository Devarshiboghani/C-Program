#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class
class Transaction {
protected:
    string paymentMethod;

public:
    Transaction(string paymentMethod) : paymentMethod(paymentMethod) {}
    virtual void processPayment(string paymentDetails) {
        cout << "Processing payment using method: " << paymentMethod << endl;
    }
};

// Derived class
class Order : public Transaction {
private:
    int orderId;
    int customerId;
    vector<string> products;
    double totalAmount;
    string status;

public:
    // Constructor using 'super' keyword (base class constructor)
    Order(int orderId, int customerId, vector<string> products, double totalAmount, string status, string paymentMethod)
        : Transaction(paymentMethod), orderId(orderId), customerId(customerId), products(products), totalAmount(totalAmount), status(status) {}

    // Method Overloading: processPayment
    void processPayment(string paymentDetails) override {
        cout << "Processing payment for Order ID: " << orderId << " using " << paymentMethod << endl;
        cout << "Payment Details: " << paymentDetails << endl;
    }

    void processPayment(string paymentDetails, double discount) {
        double discountedAmount = totalAmount - discount;
        cout << "Processing payment for Order ID: " << orderId << " with discount. Final Amount: " << discountedAmount << endl;
        cout << "Payment Details: " << paymentDetails << endl;
    }

    // Method: updateStatus
    void updateStatus(string newStatus) {
        if ((status == "Pending" && newStatus == "Processing") || (status == "Processing" && newStatus == "Shipped") ||  (status == "Shipped" && newStatus == "Delivered")) {
            status = newStatus;
            cout << "Order status updated to: " << status << endl;
        } else {
            cout << "Invalid status transition from " << status << " to " << newStatus << endl;
        }
    }

    // Method: generateOrderSummary
    void generateOrderSummary() {
        cout << "Order Summary for Order ID: " << this->orderId << endl;
        cout << "Customer ID: " << this->customerId << endl;
        cout << "Products: ";
        for (const auto& product : this->products) {
            cout << product << " ";
        }
        cout << endl;
        cout << "Total Amount: " << this->totalAmount << endl;
        cout << "Status: " << this->status << endl;
        cout << "Payment Method: " << this->paymentMethod << endl;
    }
};

// Example usage
int main() {
    
    vector<string> products = {"Laptop", "Mouse", "Keyboard"};
    Order order(101, 202, products, 1500.0, "Pending", "Credit Card");

    order.generateOrderSummary();
    order.processPayment("Card Number: 1234-5678-9012-3456");
    order.processPayment("Card Number: 1234-5678-9012-3456", 100.0);
    order.updateStatus("Processing");
    order.updateStatus("Shipped");
    order.updateStatus("Delivered");

    return 0;
}