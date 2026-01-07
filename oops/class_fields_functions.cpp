#include <iostream>
using namespace std;

class Student {
private:
        string name; 
        int age;
        string grade;

public:

    void setName(string newName){
        name = newName;
    }

    void setAge(int newAge){
        age = newAge;
    }

    void setGrade(string newGrade){
        grade = newGrade;
    }


    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getGrade() {
        return grade;
    }
};

int main() {

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

    return 0;
}