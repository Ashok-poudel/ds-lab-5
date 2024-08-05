#include <iostream>
using namespace std;

bool isPrime(int n, int iterations) {
    if (n < 2) {
        return false;
    }
    for (int i = 0; i < iterations; i++) {
        int a = rand() % (n - 1) + 1;
        if (powerMod(a, n - 1, n)!= 1) {
            return false;
        }
    }
    return true;
}

int powerMod(int base, int exponent, int mod) {
    int x = 1;
    int y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        exponent /= 2;
    }
    return x % mod;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int iterations = 5;
    if (isPrime(num, iterations)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    return 0;
}
