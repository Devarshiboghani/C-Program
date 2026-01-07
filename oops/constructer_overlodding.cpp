#include <iostream>
using namespace std;

class Student {
private:

      string name;
      int age;
      string grade;

public:

      Student() {
        this->name = "";
        this->age = 0;
        this->grade = "";
      }

      Student(string name) {
        this->name = name;
        this->age = 0;
        this->grade = "";
      }

      Student(string name, int age) {
        this->name = name;
        this->age = age;
        this->grade = "";
      }

      Student(string name, int age, string grade) {
        this->name = name;
        this->age = age;
        this->grade = grade;
      }

      void printDetails() {
        cout << "Name: \"" << this->name << "\", Age: " <<this->age << ", Grade: \"" << this->grade << "\"" << endl;
      }
};

int main()
{
  Student student1;
  student1.printDetails();
  cout << endl;

  Student student2("Alia");
  student2.printDetails();
  cout << endl;

  Student student3("Alia", 15);
  student3.printDetails();
  cout << endl;

  Student student4("Alia", 15, "A+");
  student4.printDetails();
  cout << endl;
  
  return 0;
}