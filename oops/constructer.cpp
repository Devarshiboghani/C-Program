#include <iostream>
using namespace std;

class Student {
private:
      string _name;
      int _age;
      string _grade;

public:

    Student(string name, int age, string grade) {

        this->_name = name;
        this->_age = age;
        this->_grade = grade;
    }

    string getName() const {
        return this->_name;
    }

    void setName(const string& name) {
        this->_name = name;
    }

    int getAge() const {
        return this->_age;
    }

    void setAge(int age) {
        this->_age = age;
    }

    string getGrade() const {
        return this->_grade;
    }

    void setGrade(const string & grade) {
        this->_grade = grade;
    }

    void setStudentName(const string& name) {
        this->_name = name;
    }

    string getStudentName() const {
        return this->_name;
    }

     void setStudentAge(int age) {
        this->_age = age;
    }

     int getStudentAge() const {
        return this->_age;
    }

    void setStudentGrade(const string & grade) {
        this->_grade = grade;
    }

    string getStudentGrade() const {
        return this->_grade;
    }

    void printDetails() const {
        cout << this->_name << " " << this->_age << " " << this->_grade << endl;
    }
};

int main()
{
    Student student1("Alia", 14, "9th");
    Student student2("Rahul", 15, "10th");

    cout << student1.getName() << " " << student1.getAge() << " " << student1.getGrade() << endl;
    cout << student2.getStudentName() << " " << student2.getStudentAge() << " " << student2.getStudentGrade() << endl;

    student1.printDetails();
    student2.printDetails();

    student1.setAge(15);
    student1.printDetails();

    return 0;
}