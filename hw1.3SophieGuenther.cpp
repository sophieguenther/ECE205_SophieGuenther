#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    //variables
    int month=0;
    double interest;
    double principal;
    double balance = 1000;
    double total_interest=0;
    double total_paid=0;
    double payment = 50.0;
    //set decimal structure
    cout << fixed << setprecision(2);
    //print column headers
    cout << setw(8) << "Month"
         << setw(12) << "Interest"
         << setw(12) << "Principal"
         << setw(12) << "Balance"
         << setw(16) << "Total Interest"
         << setw(14) << "Total Paid"
         << endl;
    //loop through balance with monthly payments and interest calculations until balance is 0
    while (balance>0) {
        month++;
        payment = 50.0;
        interest = .015*balance;
        if (balance + interest <= 50.0)
            payment = balance + interest;
        
        principal = payment-interest;
        
        balance = (balance+interest)- payment; 
        total_interest+= interest;
        total_paid+=payment;  
        if (balance < 0.005) 
            balance = 0.0; 
        //print current values
        cout << setw(8) << month
            << setw(12) << interest
            << setw(12) << principal
            << setw(12) << balance
            << setw(16) << total_interest
            << setw(14) << total_paid
            << endl;  
         
    }
    return 0;
}