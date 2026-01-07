#include <iostream>
using namespace std;

class Student{
 public:
    string name;
    int age;
    string grade;
};

int main() {

    Student student1;
    Student student2;

    student1.name = "Alia";
    student1.age = 14;
    student1.grade = "9th";

    student2.name = "Rahul";
    student2.age = 15;
    student2.grade = "10th";
    
    cout << student1.name << " " << student1.age << " " << student1.grade  << endl;
    cout << student2.name << " " << student2.age << " " << student2.grade << endl;
    
    return 0;
}