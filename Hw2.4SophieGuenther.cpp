#include <iostream>
#include <cmath>

using namespace std;

int main ()  {
    srand(time(0)); //makes it so that when you run the program it will give you different numbers each time
    int n1 =0;
    int n2=0;
    int n3=0;
    int n4=0;
    n1=rand()%25+1;;
    n2 = rand()%25+1;
    while (n2==n1)
    {
        n2=rand()%25+1;;
    }
    n3= rand()%25+1;;
    while(n3==n1|| n3==n2){
        n3 = rand()%25+1;;
     }
        
    n4 = rand()%25+1;;
    while(n4==n1|| n4==n2||n4==n3){
        n4 = rand()%25+1;;
        }
    cout << "The winners are: "<< n1<< ", "<< n2<< ", "<< n3<< ", "<< n4<< endl;
    
    return 0;
}