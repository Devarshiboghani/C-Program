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

class Student : public Person {
private:
      string grade;

public:
      Student(string name, int age, string grade) : Person(name, age) {
            this->grade = grade;
      }

      void printDetails() override {
            Person::printDetails();
            cout << "Grade: " << this->grade << endl;
      }
};

int main() {
      Person person1("Bob", 30);
      person1.printDetails();

      cout << endl;

      Student student1("Alia", 17, "11th");
      student1.printDetails();

      return 0;
}