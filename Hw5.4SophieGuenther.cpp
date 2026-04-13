#include <iostream>

using namespace std;

class primeNumber{
    private:
    int number;

    public:
    //constructors
    primeNumber(){
        number=1;
    }
    primeNumber(int n){
        number=n;
    }

    //getter
    int getNumber(){
        return number;
    }

    bool primeCheck(int n){//make sure this part is correct
        //check if n is prime
         if (n < 2) return false;
        for (int i = 2; i*i<=n; i++){
            if (n%i==0){
                //if its divisible then it will return false
                return false;
            }
        }
        //returns true if its not divisible by any number less than its square root, meaning its prime
        return true;
    }
    //find the next prime number and previous prime number
    int nextPrime(int n){
        int next=n+1;
        while(primeCheck(next)==false){
            next++;
        }
        return next;
    }
    int previousPrime(int n){
        int previous=n-1;
        if (n<=2){
            cout << "There are no prime numbers before 2." << endl;
            return n;
            //no prime number before 2
        }
        while(primeCheck(previous)==false &&previous>0){
            previous--;
        }
        return previous;
    }

    //overload operators
    //prefix ++ (++p1)
    primeNumber operator++() {
        number = nextPrime(number); 
        primeNumber temp(number);
        return temp; 
    }
    //postfix ++ (p1++)
   primeNumber operator++(int) {
        primeNumber temp(number);
        number = nextPrime(number);
        return temp;
    }

    // prefix -- (--p1)
    primeNumber operator--() {
        number = previousPrime(number);
        primeNumber temp(number);
        return temp;
    }
    //postfix -- (p1--)
    primeNumber operator--(int) {
        primeNumber temp(number);
        number = previousPrime(number);
        return temp;
    }

};
int main(){
    primeNumber p1;
    char repeat = 'y';
    int n;
    int previousPrime;
    while (repeat == 'y'  || repeat == 'Y') {
        cout << "Enter a number: -> ";
        cin >> n;
        while (n<0 || p1.primeCheck(n)==false){
            cout << "Please enter a positive prime number: -> ";
            cin >> n;
        }

        p1=primeNumber(n);
        cout << "Current prime number: " << p1.getNumber() << endl;
        ++p1;
        cout << "After prefix ++p1: " << p1.getNumber() << endl;
        p1 = primeNumber(n);
        p1++;
        cout << "After postfix p1++: " << p1.getNumber() << endl;
        p1=primeNumber(n);
        --p1;
        cout << "After prefix --p1: " << p1.getNumber() << endl;
        p1= primeNumber(n);
        p1--;
        cout << "After postfix p1--: " << p1.getNumber() << endl;
        cout << "Do you want to enter another number? (y/n) -> ";
        cin >> repeat;
    }
    return 0;
}