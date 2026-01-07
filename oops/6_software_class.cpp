#include <iostream>
#include <string>
using namespace std;

// Abstract Product class
class Product {
public:
    virtual double calculateDiscount(int quantity) const = 0; // Pure virtual function
    virtual ~Product() {} // Virtual destructor
};

// Concrete Software class inheriting from Product
class Software : public Product {
private:
    string licenseType;
    string version;
    string compatibility;

public:
    // Constructor
    Software(const string& licenseType, const string& version, const string& compatibility)
        : licenseType(licenseType), version(version), compatibility(compatibility) {}

    // Override calculateDiscount
    double calculateDiscount(int quantity) const override {
        if (quantity > 10) {
            return 0.20; // 20% discount for bulk licenses
        }
        return 0.0; // No discount otherwise
    }

    // Method to check compatibility
    bool checkCompatibility(const string& systemSpecs) const {
        return compatibility == systemSpecs;
    }

    // Display software details
    void displayDetails() const {
        cout << "License Type: " << licenseType << endl;
        cout << "Version: " << version << endl;
        cout << "Compatibility: " << compatibility << endl;
    }
};

// Example usage
int main() {
    Software software("Enterprise", "1.2.3", "Windows 10");

    software.displayDetails();

    int quantity = 15;
    cout << "Discount for " << quantity << " licenses: " << software.calculateDiscount(quantity) * 100 << "%" << endl;

    string systemSpecs = "Windows 10";
    cout << "Compatibility with " << systemSpecs << ": "  << (software.checkCompatibility(systemSpecs) ? "Compatible" : "Not Compatible") << endl;

    return 0;
}