#include <iostream>
#include <string>
using namespace std;

enum GradeLevel {
    Junior,
    Senior,
    Master,
    Expert
};

class Student {
private:
    string name;
    GradeLevel grade;

public:
    Student(string name, GradeLevel grade) {
        this->name = name;
        this->grade = grade;
    }

    void printInfo() {
        cout << name << " is a ";

        switch (grade) {
            case Junior:
                cout << "Junior";
                break;
            case Senior:
                cout << "Senior";
                break;
            case Master:
                cout << "Master";
                break;
            case Expert:
                cout << "Expert";
                break;
            default:
                cout << "Unknown";
        }

        cout << endl;
    }
};

int main() {
    Student s1("Alia", Junior);
    Student s2("Rahul", Senior);

    s1.printInfo();  
    s2.printInfo();  

    return 0;
}