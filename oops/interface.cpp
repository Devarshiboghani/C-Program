#include <iostream>
using namespace std;

class PaymentMethod {
public:
      virtual void pay(double amount) = 0;
      virtual void refund(double amount) = 0;

      virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
      string cardNumber;
      string expiryDate;

public:
     CreditCard(string cardNumber, string expiryDate) {
        this->cardNumber = cardNumber;
        this->expiryDate = expiryDate;
     }

     void pay(double amount) override {
        cout << "Charging $" << amount << "to credit card" << cardNumber << endl;
     }

     void refund(double amount) override {
        cout << "Refunding $" << amount << "to credit card" << cardNumber << endl;
     }
};

class PayPal : public PaymentMethod {
private:
     string accountEmail;

public:
      PayPal(string email) {
        this->accountEmail = email;
      }

      void pay(double amount) override {
        cout << "Charging $" << amount << "to PayPal account" << accountEmail << endl;
      }

      void refund(double amount) override {
        cout << "Refunding $" << amount << "to PayPal account" << accountEmail << endl;
      }
};

void cheakout(PaymentMethod* method, double total) {
  method->pay(total);
}

int main()
{
  CreditCard cc("1234-5678", "12/25");
  cheakout(&cc, 100.0);

  PayPal pp("user@example.com");
  cheakout(&pp, 42.5);
  
  return 0;
}