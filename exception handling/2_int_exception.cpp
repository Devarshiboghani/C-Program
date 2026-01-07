#include <iostream>
using namespace std;

int main()
{
    int age;

    try
    {
        cout << "Enter your age: ";
        cin >> age;

        if(age < 0)
        {
            throw 0;
        }
        if(age > 150)
        {
            throw 1;
        }

        cout << "Your age is: " << age << endl;
    }

    catch(int errorCode)
    {
        if(errorCode == 0)
        {
            cout << "Error: Age cannot be negative!" << endl;
        }
        else if(errorCode == 1)
        {
            cout << "Error: Age seems too high!" << endl;
        }
    }
    
    return 0;
}