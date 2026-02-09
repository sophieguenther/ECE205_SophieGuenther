#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double height;//inches
    double weight;//pounds
    int age;//years

    cout <<"Input your height (inches) -> ";
    cin >> height;
    cout << endl;

    cout << "Input your weight (lbs.) -> ";
    cin >> weight;
    cout << endl;

    cout << "Input your age (years) -> ";
    cin >> age;
    cout << endl;

    double hat_size = (2.9*weight)/height;
    double jacket_size=((height*weight)/288);
    double waist_size = weight/5.7;
    
    if(age>30) {
        int extra_age_thirty= age-30;
        if (extra_age_thirty>=10){
            int how_many_eighths = extra_age_thirty/10;
            jacket_size+=.125*how_many_eighths;
        }
    }
    if (age>28)
    {
        int extra_age = age-28;
        if(extra_age>=2){
            int how_many_tenths = extra_age/2;
            waist_size+=.1*how_many_tenths;
        }
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << left << setw(15) << "Hat size:" << setw(6) << hat_size << endl;
    cout << left << setw(15) << "Jacket size:" << setw(6) << jacket_size << "inches" << endl;
    cout << left << setw(15) << "Waist size:" << setw(6) << waist_size << "inches" << endl;
    
    return 0;   
}