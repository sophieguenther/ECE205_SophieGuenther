#include <iostream>
#include <string>

using namespace std;

int main() { 
    //static variables:
    double hourly_rate = 36.75;

    //inputs:
    int dependents;
    double hours;

    //output
    double gross_pay;
    double takeHome;

    //defining input variables
    cout << "How many hours did you work this week? -> ";
    cin >> hours;
    cout << endl;
    cout << "How many dependents do you have? -> ";
    cin >> dependents;
    cout << endl;

    //total pay calculations
    if (hours>=40.0)
    {
       double extraHours = hours-40.0;
       gross_pay = extraHours*1.5*hourly_rate + 40*hourly_rate; 
    }
    else
        gross_pay = hours*hourly_rate;
    cout << "gross pay: " << gross_pay << endl; 

    //deductions
    double socialDeduct = .06*gross_pay;
    double federalDeduct = .15*gross_pay;
    double stateDeduct = .04*gross_pay;
    double localDeduct = .01*gross_pay;
    int unionDeduct = 20;
    int healthDeduct = 40;
    cout << "social security deduction: " << socialDeduct<<endl;
    cout << "federal income deduction: " << federalDeduct <<endl;
    cout << "state deduction: " << stateDeduct <<endl;
    cout << "Bethlehem local deduction: " << localDeduct <<endl;
    cout << "union deduction: " << unionDeduct <<endl;
    if (dependents>=2)
    {
        cout << "heath insurance deduction from dependents: " << healthDeduct << endl;
        takeHome = gross_pay - socialDeduct- federalDeduct - stateDeduct- localDeduct - healthDeduct;
        cout << "take home pay: "<< takeHome <<endl;
    }
    else  {
        takeHome = gross_pay - socialDeduct- federalDeduct - stateDeduct- localDeduct;
        cout << "take home pay: "<< takeHome <<endl;}
    return 0;
}