//bicycle class 
#include <iostream>

using namespace std;

class BicylceSpeedometer{
    public:
        void setDistance(double distance1){
            distance=distance1;
        }
        double getDistance(){
            return distance;
        }

        void setTime(double time1){
            time=time1;
        }
        double getTime(){
            return time;
        }

        double computeSpeed(){
            time = time/60;//convert minutes to hours
            return distance/time;
        }
        void display(){
            cout << "The average speed of the bicycle is: " << computeSpeed() << " miles per hour." << endl;
        }


    private:
        double distance;//miles
        double time;//minutes

};


int main(){
    //define stuff
    BicylceSpeedometer bike1;
    double distance;
    double time;
    char repeat = 'y';
    while (repeat == 'y'  || repeat == 'Y') {
        cout << "Enter the distance traveled in miles: -> ";
        cin >> distance;
        while (distance <= 0) {
            cout << "Distance cannot be negative. Please enter a valid distance: -> ";
            cin >> distance;
        }
        bike1.setDistance(distance);
        cout<< "Distance set to: " << bike1.getDistance() << " miles." << endl;
        cout<< "How long did it take to travel that distance in minutes? -> ";
        cin>> time;
        while (time <= 0) {
            cout << "Time cannot be negative. Please enter a valid time: -> ";
            cin >> time;
        }
        bike1.setTime(time);
        cout<< "Time set to: " << bike1.getTime() << " minutes." << endl;
        bike1.display();
        cout << "Do you want to enter another distance and time? (y/n) -> ";
        cin >> repeat;
    }
    
    return 0;
}