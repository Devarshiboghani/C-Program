#include <iostream>
using namespace std;

class Person {
protected:
        string name;
        int age;

public:
     Person(string name, int age) {
        this->name = name;
        this->age = age;
     }

     virtual void printDetails() {
        cout << this->name << " " << this->age << endl;
     }
};

class Scholarship : public Person {
protected:
    string scholarship;

public:
     Scholarship(string name, int age, string scholarship) : Person(name, age) {
        this->scholarship = scholarship;
     }

     void printDetails() override {
        Person::printDetails();
        cout << "Scholarship: " << this->scholarship <<endl;
     }
};

class Student : public Scholarship {
private:
      string grade;

public:
     Student(string name, int age, string scholarship, string grade)
     : Scholarship(name, age, scholarship) {
        this->grade = grade;
     }

     void printDetails() override {
        Scholarship::printDetails();
        cout << "Grade: " << this->grade << endl;
     }
};

int main() {
    Person person1("Bob", 30);
    person1.printDetails();
    cout << endl;

    Scholarship scholar1("Cara", 22, "Merit-based");
    scholar1.printDetails();
    cout <<endl;

    Student student1("Alia", 17, "Merit-based", "11th");
    student1.printDetails();

    return 0;
}