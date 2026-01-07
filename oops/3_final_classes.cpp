#include <iostream>
#include <string>
using namespace std;

class SystemConfig final {
public:
    static const std::string systemVersion ;
    static const int maxOrderLimit ;

    static std::string getVersion() {
        return systemVersion;
    }

    static int getMaxOrderLimit() {
        return maxOrderLimit;
    }
};
const std::string SystemConfig::systemVersion = "1.0.0";
const int SystemConfig::maxOrderLimit = 100;

int main() {
    std::cout << "System Version: " << SystemConfig::getVersion() << std::endl;
    std::cout << "Max Order Limit: " << SystemConfig::getMaxOrderLimit() << std::endl;

    return 0;
}