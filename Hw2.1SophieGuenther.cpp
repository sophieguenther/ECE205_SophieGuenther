#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    //defining variables
    char replay = 'r';
    const double G = 6.673*pow(10,-8);
    double m1;
    double m2;
    double d;
    double force;
    while(replay == 'r') 
    {
        //defining masses
        cout << "define mass 1 (kg): -> ";
        cin >> m1;
        cout << endl;
        cout << "define mass 2 (kg): -> ";
        cin >> m2;
        cout << endl;
        //defining d
        cout << "define the distance between the masses (cm): -> ";
        cin >> d;
        cout << endl;
        //zero check for distance
        while (d==0)
        {
            cout << "distance cannot be zero, please enter a new value for distance: -> ";
            cin >> d;
            cout << endl;
        }
        //calculate force
        cout.setf(ios::scientific);
        cout.setf(ios::showpoint);
        cout.precision(2);
        force = (G*(m1*1000)*(m2*1000))/(pow(d,2));
        cout << "your force for these values is: " << force << " dynes" << endl;
        //looping function
        cout << "would you like to restart the program? (press r to restart) ->";
        cin >> replay;
        cout << endl;
    }
    return 0;
}