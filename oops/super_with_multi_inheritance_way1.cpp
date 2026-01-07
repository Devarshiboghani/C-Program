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

      void printDetails() {
        cout << this->name << " " <<this->age << endl;
      }
};

class Scholarship {
protected:
       string scholarship;

public:
       Scholarship(string scholarship) {
        this->scholarship = scholarship;
       }

       void printScholarship() {
        cout << "Scholarship: " << this->scholarship << endl;
       }
};

class Student : public Person, public Scholarship {
private:
      string grade;

public:
      Student(string name, int age, string scholarship, string grade)
      : Person(name, age),
        Scholarship(scholarship)
        {
            this->grade = grade;
        }

        void printGrade() {
            cout << "Grade: " << this->grade << endl; 
        }
};

int main()
{
    Student student1("Alia", 17, "Merit-based", "11th");

    student1.printDetails();
    student1.printScholarship();
    student1.printGrade();

    return 0;
}