#include <iostream>
#include <string>
using namespace std;

// Abstract Product class
class Product {
protected:
    double price;

public:
    Product(double price) : price(price) {}
    virtual ~Product() {}

    virtual double calculateDiscount() const = 0; // Pure virtual function
    double getPrice() const { return price; }
};

// Concrete Computer class
class Computer : public Product {
private:
    string processor;
    int ram; // in GB
    int storage; // in GB
    string operatingSystem;

public:
    // Constructor
    Computer(double price, string processor, int ram, int storage, string operatingSystem)
        : Product(price), processor(processor), ram(ram), storage(storage), operatingSystem(operatingSystem) {}

    // Override calculateDiscount
    double calculateDiscount() const override {
        double baseDiscount = price * 0.10; // Assume base discount is 10%
        if (ram >= 16 && storage >= 512) { // High-end specs condition
            return price * 0.15; // 15% discount
        }
        return baseDiscount;
    }

    // Additional method: Upgrade specs
    void upgradeSpecs(const string& component, int newValue) {
        if (component == "ram") {
            ram = newValue;
        } else if (component == "storage") {
            storage = newValue;
        } else {
            cout << "Invalid component!" << endl;
        }
    }

    // Display computer details
    void displayDetails() const {
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "Operating System: " << operatingSystem << endl;
        cout << "Price: $" << price << endl;
        cout << "Discounted Price: $" << price - calculateDiscount() << endl;
    }
};

// Example usage
int main() {
    Computer myComputer(1000.0, "Intel i7", 16, 512, "Windows 11");
    myComputer.displayDetails();

    cout << "\nUpgrading RAM to 32GB...\n";
    myComputer.upgradeSpecs("ram", 32);
    myComputer.displayDetails();

    return 0;
}