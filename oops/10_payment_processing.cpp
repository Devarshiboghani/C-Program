#include <iostream>
#include <string>
using namespace std;

// Abstract class
class PaymentProcessor {
public:
    virtual void validatePayment() = 0;  // Pure virtual method
    virtual void processPayment() = 0;  // Pure virtual method
    virtual void sendConfirmation() = 0;  // Pure virtual method

    virtual ~PaymentProcessor() {}  // Virtual destructor for proper cleanup
};

// Concrete class: CreditCardProcessor
class CreditCardProcessor : public PaymentProcessor {
public:
    void validatePayment() override {
        std::cout << "Validating credit card details..." << std::endl;
    }

    void processPayment() override {
        std::cout << "Processing payment through credit card..." << std::endl;
    }

    void sendConfirmation() override {
        std::cout << "Sending confirmation for credit card payment..." << std::endl;
    }
};

// Concrete class: PayPalProcessor
class PayPalProcessor : public PaymentProcessor {
public:
    void validatePayment() override {
        std::cout << "Validating PayPal account details..." << std::endl;
    }

    void processPayment() override {
        std::cout << "Processing payment through PayPal..." << std::endl;
    }

    void sendConfirmation() override {
        std::cout << "Sending confirmation for PayPal payment..." << std::endl;
    }
};

// Demonstration
int main() {
    PaymentProcessor* processor;

    // Using CreditCardProcessor
    processor = new CreditCardProcessor();
    processor->validatePayment();
    processor->processPayment();
    processor->sendConfirmation();
    delete processor;

    std::cout << "-----------------------------" << std::endl;

    // Using PayPalProcessor
    processor = new PayPalProcessor();
    processor->validatePayment();
    processor->processPayment();
    processor->sendConfirmation();
    delete processor;

    return 0;
}