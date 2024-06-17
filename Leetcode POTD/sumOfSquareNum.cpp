#include <iostream>
#include <cmath>

using namespace std;

// Function to judge if a number can be expressed as the sum of two squares
bool judgeSquareSum(int c) {
    for (int divisor = 2; divisor * divisor <= c; divisor++) {
        if (c % divisor == 0) {
            int exponentCount = 0;
            while (c % divisor == 0) {
                exponentCount++;
                c /= divisor;
            }
            if (divisor % 4 == 3 && exponentCount % 2 != 0) {
                return false;
            }
        }
    }
    return c % 4 != 3;
}

int main() {
    // Test judgeSquareSum
    int c = 5;
    bool result = judgeSquareSum(c);
    cout << "Can " << c << " be expressed as the sum of two squares? " << (result ? "Yes" : "No") << endl;

    return 0;
}
