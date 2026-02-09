#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main ()  {

    ifstream in;//equivalant to cin works with the file
    ofstream out; //equivalant to cout
    double n1,n2,n3,n4,n5;
    //read data from text file (you also need to close it);
    in.open("score_in.txt");
    in>>n1;
    in>>n2;
    in>>n3;
    in>>n4;
    in>>n5;
    in.close();//stop inputs

    double avg = (n1+n2+n3+n4+n5)/5.0;//put formuka
    double variance = (pow(n1-avg,2)+pow(n2-avg,2)+pow(n3-avg,2)+pow(n4-avg,2)+pow(n5-avg,2))/5.0;
    double std_dev = sqrt(variance);//put std deviation formula

    //write data in text file
    out.open("output.txt");
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    out<<avg <<endl;
    out<<std_dev <<endl;
    out.close();

    //display result in console
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << avg<<endl;
    cout <<std_dev<<endl;

    return 0;
}