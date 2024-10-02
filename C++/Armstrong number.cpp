#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int number) {
    int originalNumber = number;
    int sum = 0;
    int numDigits = 0;

    while (number != 0) {
        number /= 10;
        numDigits++;
    }

    number = originalNumber;

    while (number != 0) {
        int digit = number % 10;
        sum += pow(digit, numDigits);
        number /= 10;
    }

    return sum == originalNumber;
}

int main() {
    int num;
    cin >> num;

    if (isArmstrong(num)) {
        cout<<"True"<<endl;
        return 0;
    } else {
        cout<<"False"<<endl;
    }
}
