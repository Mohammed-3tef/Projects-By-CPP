#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cout << "Please input a positive integer to see if prime: ";
    cin >> n;

    while (n < 0) {
        cout << "Please input a positive integer to see if prime: ";
        cin >> n;
    }
    cout << endl;

    // Cases 0 and 1 are not prime
    if (n == 0 || n == 1) {
        cout << "It's not a prime number.\n";
        return 0;
    }
    else if (n == 2) {
        cout << "It's a prime number.\n";
        return 0;
    } 
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << "It's not a prime number.\n";
                return 0;
            }
        }
        cout << "It's a prime number.\n";
    }
    return 0;
}
