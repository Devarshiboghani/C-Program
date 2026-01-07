#include <iostream>
#include <string>
using namespace std;

// Abstract class Product
class Product {
protected:
    double price;

public:
    Product(double p) : price(p) {}

    virtual double calculateDiscount() const = 0; // Pure virtual function

    virtual void display() const {
        cout << "Price: " << price << endl;
    }

    virtual ~Product() {}
};

// Concrete class Electronics inheriting from Product
class Electronics : public Product {
private:
    string warranty;
    string brand;
    double powerRatings;

public:
    Electronics(double p, const string& w, const string& b, double pr)
        : Product(p), warranty(w), brand(b), powerRatings(pr) {}

    // Override calculateDiscount
    double calculateDiscount() const override {
        return price * 0.10; // 10% discount
    }

    // Override display to include additional properties
    void display() const override {
        Product::display();
        cout << "Warranty: " << warranty << endl;
        cout << "Brand: " << brand << endl;
        cout << "Power Ratings: " << powerRatings << "W" << endl;
        cout << "Discounted Price: " << price - calculateDiscount() << endl;
    }
};

int main() {
    Electronics laptop(50000, "2 Years", "Dell", 65);
    laptop.display();

    return 0;
}