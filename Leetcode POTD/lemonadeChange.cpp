#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else {
                return false;

            }
        } else if (bill == 20) {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;

}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    bool canMakeChange = lemonadeChange(bills);

    if (canMakeChange) {
        cout << "Can make change for all bills." << endl;
    } else {
        cout << "Cannot make change for all bills." << endl;
    }

    return 0;
}