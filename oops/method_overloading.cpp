#include <iostream>
using namespace std;

class Student {
private:

     string _name;
     int _age;
     string _grade;

public:

     Student() {
        this->_name = "";
        this->_age = 0;
        this->_grade = "";
     }

     void setInfo(const string& name) {
        this->_name = name;
     }

     void setInfo(const string &name, int age) {
        this->_name = name;
        this->_age = age;
     }

      void setInfo(const string &name, int age, const string& grade) {
        this->_name = name;
        this->_age = age;
        this->_grade = grade;
     }

     void printDetails() const {
        cout << this->_name << " " << this->_age << " " << this->_grade << endl;
     }

     void printDetails(const string& label) const {
        cout << label << " - " << this->_name << " " << this->_age << " " << this->_grade << endl;
     }

     string getName() const { return this->_name; }
     int getAge() const { return this->_age; }
     string getGrade() const { return this->_grade; }
};

int main()
{
    Student student1;

    student1.printDetails();

    student1.setInfo("Alia");
    student1.printDetails();

    student1.printDetails("name only");

    student1.setInfo("Alia", 20);
    student1.printDetails();

    student1.printDetails("name & age");

    student1.setInfo("Alia", 20, "A+");
    student1.printDetails();

    student1.printDetails("full info");

    Student student2;

    student2.setInfo("Rahul");
    student2.printDetails();

    student2.setInfo("Rahul", 25);
    student2.printDetails();

    student2.setInfo("Rahul", 25, "B+");
    student2.printDetails();

    student2.printDetails("Student Info");


    return 0;
}