#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
      string getName() {
        return this->name;
      }

      void setName(string value) {
        this->name = value;
      }

      int getAge() {
        return this->age;
      }

      void setAge(int value) {
        this->age = value;
      }

      void printDetails() {
        cout << this->name << " " << this->age << endl;
      }
};

class Scholarship {
private:
       string scholarship;

public:
      string getScholarship() {
        return this->scholarship;
      }

      void setScholarship(string value) {
        this->scholarship = value;
      }

      void printScholarship() {
        cout << "Scholarship: " << this->scholarship << endl;
      }
};

class Student : public Person, public Scholarship {
private:
       string grade;

public:
      string getGrade() {
        return this->grade;
      }

      void setGrade(string value) {
        this->grade = value;
      }

      void printGrade() {
         cout << "Grade: " << this->grade << endl;
      }
};

int main()
{
    Student student1;

    student1.setName("Alia");
    student1.setAge(17);
    student1.printDetails();

    student1.setScholarship("On Merit");
    student1.printScholarship();

    student1.setGrade("11th");
    student1.printGrade();

    return 0;
}