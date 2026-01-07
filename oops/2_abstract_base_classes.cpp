#include <iostream>
#include <regex>
#include <stdexcept>
using namespace std;

class User {
protected:
        int userId;
        string name;
        string email;
        string registrationDate;

public:
      User(int id, const string& name, const string& email, const string& regDate) 
        : userId(id), name(name), registrationDate(regDate) {
        if (!isValidEmail(email)) {
            throw invalid_argument("Invalid email format.");
        }
        this->email = email;
    }

    // Abstract method
    virtual string getAccessLevel() const = 0; 

    // Concrete method
    void updateProfile(const string& newName, const string& newEmail) {
        if (!isValidEmail(newEmail)) {
            throw invalid_argument("Invalid email format.");
        }
        name = newName;
        email = newEmail;
        cout << "Profile updated successfully!" << endl;
    }

    // Utility method to validate email format
    static bool isValidEmail(const string& email) {
        const regex emailPattern(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
        return regex_match(email, emailPattern);
    }

    // Virtual destructor
    virtual ~User() {}
};

// Example derived class
class AdminUser : public User {
public:
    AdminUser(int id, const string& name, const string& email, const string& regDate)
        : User(id, name, email, regDate) {}

    string getAccessLevel() const override {
        return "Admin";
    }
};

int main()
{
    try
    {
        AdminUser admin(1, "John Doe", "john.doe@example.com", "2025-08-14");
        cout << "Access Level: " << admin.getAccessLevel() << endl;

        admin.updateProfile("John Updated", "john.updated@example.com");
    } 
    catch (const exception& e) 
    {
        cerr << e.what() << endl;
    }

    return 0;
}