//takes in user input to fill an array, then output a histogram of bins of 10 [0,9], [10,19] etc. 
#include <iostream>
using namespace std;
void fillArray(int a[], int size){
    int value;
     //creating array with user input
    for (int i=0; i<size;i++){
        cout<< "give input (+integer) ->"<<endl;
        cin>>value;
        while(value<0){
            cout<<"Invalid input, try again. ->"<<endl;
            cin >> value;
        }
        a[i] = value;

    }
    
}
//max value
int findMax(int a[], int size){
    int maxVal = a[0];
    for (int i = 1; i < size; i++){
        if (a[i] > maxVal){
            maxVal = a[i];
        }
    }
    return maxVal;
}
//function to create histogram
void histogram(int a[], int size){
    int numberOfBins;
    int maxVal = findMax(a, size);
    numberOfBins = (maxVal/10)+1;
    
    for(int i = 0; i<numberOfBins; i++){
        cout <<"Bin [" << i*10 << "-" << i*10 + 9 << "]: ";
        int count = 0;
        for(int j=0; j<size; j++){
            if(a[j]>=i*10 && a[j]<=(i*10)+9){
                count++;
            }
        }
        for (int k=0; k<count; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}


int main(){
    const int MAX_SIZE=1000;
    int size1;
    char response = 'Y';
    while(response=='Y' || response=='y'){
    cout<<"What is the size of the array? -> "<<endl;
    cin>>size1;
    while(size1<=0 || size1>MAX_SIZE){
        cout<<"Invalid input for size, try again."<<endl;
        cin >> size1;
    }
    int a1[MAX_SIZE];
    //creating array with user input
    fillArray(a1,size1);
    histogram(a1, size1);
    cout<<"Do you want to try again? (Y/N) -> "<<endl;
    cin>>response;
    }
    return 0;
}

