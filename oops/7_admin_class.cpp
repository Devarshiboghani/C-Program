#include <iostream>
#include <string>
#include <vector>

// Base class: User
class User {
protected:
    std::string username;
    std::string email;

public:
    User(const std::string& username, const std::string& email)
        : username(username), email(email) {}

    virtual ~User() {}

    virtual std::string getAccessLevel() const {
        return "user";
    }

    void displayInfo() const {
        std::cout << "Username: " << username << "\nEmail: " << email << std::endl;
    }
};

// Derived class: Admin
class Admin : public User {
private:
    std::vector<std::string> permissions;
    std::string lastLoginTime;

public:
    Admin(const std::string& username, const std::string& email,
          const std::vector<std::string>& permissions, const std::string& lastLoginTime)
        : User(username, email), permissions(permissions), lastLoginTime(lastLoginTime) {}

    std::string getAccessLevel() const override {
        return "admin";
    }

    void manageInventory(const std::string& productId, const std::string& action) {
        std::cout << "Managing inventory for Product ID: " << productId << " with Action: " << action << std::endl;
    }

    void generateReports(const std::string& reportType) {
        std::cout << "Generating " << reportType << " report..." << std::endl;
    }

    void displayAdminInfo() const {
        displayInfo();
        std::cout << "Access Level: " << getAccessLevel() << "\nLast Login Time: " << lastLoginTime << "\nPermissions: ";
        for (const auto& permission : permissions) {
            std::cout << permission << " ";
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    Admin admin("adminUser", "admin@example.com", {"manage_users", "view_reports"}, "2025-08-15 10:00:00");

    admin.displayAdminInfo();
    admin.manageInventory("P12345", "add");
    admin.generateReports("sales");

    return 0;
}