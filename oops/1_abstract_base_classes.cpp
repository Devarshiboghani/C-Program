#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
       int id;
       string name;
       double price;
       string category;
       int stock;

public:
    Product(int id, string  name, double price, string category, int stock) 
    :id(id), name(name), price(price), category(category), stock(stock) {}

    virtual double calculateDiscount() const = 0;
    virtual void getProductDetails() const = 0;

    void updateStock(int quantity) {
        stock += quantity;
        cout << "Stock updated. New stock: " << stock << endl;
    }

    virtual ~Product() {}
};

class Electronics : public Product {
public:
    Electronics(int id, string name, double price, string category, int stock)
        : Product(id, name, price, category, stock) {}

    double calculateDiscount() const override {
        return price * 0.1; // Example: 10% discount
    }

    void getProductDetails() const override {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price
             << ", Category: " << category << ", Stock: " << stock << endl;
    }
};

int main() {
    Electronics laptop(101, "Laptop", 50000.0, "Electronics", 10);

    laptop.getProductDetails();
    cout << "Discount: " << laptop.calculateDiscount() << endl;
    laptop.updateStock(5);

    return 0;
}