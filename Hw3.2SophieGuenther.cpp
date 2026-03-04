#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;
void area_result(double t1, double t2, double t3, double& area, double& perimeter)//triangle
{
    double result;
    double s = .5*(double(t1)+double(t2)+double(t3));
    result = sqrt(s*(s-t1)*(s-t2)*(s-t3));
    area = result;
    perimeter = t1+t2+t3;
    cout<<"Area: "<<area<<endl;
    cout<<"Perimeter: "<<perimeter<<endl;   
}

int main () {
    double t1,t2,t3;
    char response;
    do{
    cout<<"Enter the 3 sides of the triangle -> "<<endl;
    cin>>t1>>t2>>t3;
    while((t1<=0||t2<=0||t3<=0)||(t1+t2<=t3||t1+t3<=t2||t2+t3<=t1))
    {
        cout<<"Invalid input, try again -> "<<endl;
        cin>>t1>>t2>>t3;
    }
    double area, perimeter;
    area_result(t1,t2,t3,area,perimeter);
    cout<<"Do you want to calculate another triangle? (Y/N): ";
    cin>>response;
    }while(response=='Y' || response=='y');
    return 0;
}