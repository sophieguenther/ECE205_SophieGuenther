#include <iostream>

using namespace std;
int lbs1;
int ozs1;

void get_input(int& lbs, int& ozs){
    cout<<"Enter weight in pounds -> "<<endl;
    cin>>lbs;
    while(lbs<0)
    {
        cout<<"Invalid input, try again -> "<<endl;
        cin>>lbs;
    }
    cout<<"Enter weight in ounces -> "<<endl;
    cin>>ozs;
    while(ozs<0)
    {
        cout<<"Invalid input, try again -> "<<endl;
        cin>>ozs;
    }


}
int convert(int lbs, int ozs, int& grams){
    grams = (lbs*16+ozs)*28.3495;
    return grams;
}

int main(){
    char replay = 'Y';
    while (replay=='Y' || replay=='y')
    {
    get_input(lbs1,ozs1);
    int grams1;
    int kilograms1;
    grams1= convert(lbs1,ozs1,grams1);
    if(grams1>1000){
        kilograms1=grams1/1000;
        grams1=grams1%1000;
        cout<<"Weight: "<<kilograms1<<" kilograms and "<<grams1<<" grams"<<endl;
    }
    else
        cout<<"Weight: "<<grams1<<" grams"<<endl;
    cout<<"Press Y to convert another weight -> "<<endl;
    cin>>replay;
    }
    return 0;
}