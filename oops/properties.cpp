#include <iostream>
using namespace std;

class Student {
private:
      string _name;
      int _age;
      string _grade;

public:
       string getName() const {
        return this->_name;
       }

       void setName(const string& value) {
        this->_name = value;
       }

       int getAge() const {
        return this->_age;
       }

       void setAge(int value) {
        this->_age = value;
       }

       string getGrade() const {
        return this->_grade;
       }

       void setGrade(const string& value) {
        this->_grade = value;
       }

       void printDetails() {
        cout << this->_name << " " << this->_age << " " <<this->_grade << endl;
       }
};

int main() 
{
    Student student1;
    Student student2;

    student1.setName("Alia");
    student1.setAge(14);
    student1.setGrade("9th");

    student2.setName("Rahul");
    student2.setAge(15);
    student2.setGrade("10th");

    cout << student1.getName() << " " << student1.getAge() << " " << student1.getGrade() << endl;
    cout << student2.getName() << " " << student2.getAge() << " " << student2.getGrade() << endl;

    student1.printDetails();
    student2.printDetails();

     return 0;
}