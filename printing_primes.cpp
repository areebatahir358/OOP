#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void printFirstNPrimes(int n, int firstPrime) {
   static int count = 0;  // Declare count as static variable
    if (count == n) {
        return;
    } else {
        if (isPrime(firstPrime)) {
            cout << firstPrime << " ";
            count++;  // Increment count when a prime number is printed
        }
        firstPrime++;
        printFirstNPrimes(n, firstPrime);
    }
}

int main() {
    int num = 0;
    int startP = 2;
    cout << "Enter the number of prime numbers to print: ";
    cin >> num;
    while (num <= 0) {
        cout << "Invalid number. Please enter a positive integer: ";
        cin >> num;
    }
    cout << "The first " << num << " prime numbers are: ";
    printFirstNPrimes(num, startP);
    cout << endl;
    return 0;
}
