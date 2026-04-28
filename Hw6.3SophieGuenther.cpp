/* A prime number is an integer greater than 1 and divisible only by itself and 1. Implement the 
Sieve of Erathosthenes algorithm to find all prime integers less than a user-entered integer N. More 
information on the algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes . Use vectors in 
your implementation and output all prime numbers calculated to the console.
*/
#include <iostream>
#include <vector>

using namespace std;
void sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N, true); // Initialize a boolean vector to track prime numbers
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    cout << "Prime numbers less than " << N << ": ";
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            cout << i << " "; // Output prime numbers
        }
    }
    cout << endl;
}

int main() {
    int N;
    char replay = 'y';
    while (replay == 'y' || replay == 'Y') {
        cout << "Enter an integer N (greater than two) ";
        cin >> N;
        while(N<=2){
            cout << "Please enter an integer greater than 2: ";
            cin >> N;
        }
        sieveOfEratosthenes(N);
        cout << "Do you want to enter another integer? (y/n): ";
        cin >> replay;
    }
}