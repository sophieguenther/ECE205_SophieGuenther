#include <iostream>
#include <string>

using namespace std;
int time_s;//input
int hour, minute, seconds;
float re_h, re_m;
int main() {
    cout << "Enter the time"<<endl;
    cin >> time_s;
    hour = time_s/3600;
    minute = (time_s%3600)/60;
    seconds = (time_s%3600)%60;
    
    cout<< hour<< " hours, ";
    cout <<minute<< " minutes, ";
    cout<<seconds << " seconds"<< endl; 
   
    //real number
    re_h = float(time_s)/3600;
    re_m= float(time_s)/60;
    cout.setf(ios::fixed);
    cout.precision(4); 
    cout<< re_h<< " hours"<<endl;
    cout<< re_m<< " minutes"<<endl;
    return 0;
}

