#include <iostream>
using namespace std;

class MathUtils {
private:
    MathUtils() {}

public:
    static int add(int a, int b) {
        return a + b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    int result1 = MathUtils::add(5, 7);       
    int result2 = MathUtils::multiply(3, 4);   

    cout << result1 << " " << result2 << endl; 

    return 0;
}
