//input of difficulty, array of 7 judges scores betweeon 0-10, highest and lowest scores are discared, the rest are summed togeteher and multiplied by difficulty then multiplied by .6
#include <iostream>

using namespace std;   

int main(){
    double difficulty;
    cout <<"What is the difficulty of the dive? between [1.2, 3.8] -> "<<endl;
    cin>>difficulty;
    while(difficulty<1.2 || difficulty>3.8){
        cout<<"invalid input for difficulty, try again."<<endl;
        cin >> difficulty;
    }
    const int size=7;
    double scores[size];

    //fill array with user input
    for(int i=0; i<size; i++){
        cout<<"What is the score of judge "<<i+1<<"? between [0,10] -> "<<endl;
        cin>>scores[i];
        while(scores[i]<0 || scores[i]>10){
            cout<<"invalid input for score, try again."<<endl;
            cin >> scores[i];
        }
    }

    double maxScore=scores[0];
    double minScore=scores[0];
    int maxIndex=0;
    int minIndex=0;
    //find the throw away values and their indices
    for(int j=1; j<size; j++){
        if(scores[j]>maxScore){
            maxScore=scores[j];
            maxIndex=j;
        }
        if(scores[j]<minScore){
            minScore=scores[j];
            minIndex=j;
        }
    }

    //calculate score by summing the remaining scores and multiplying by difficulty and .6 and skipping max and min indices
    double sum=0;
    bool maxRemoved = false;
    bool minRemoved = false;

    for(int i = 0; i < size; i++){
        if(scores[i] == maxScore && !maxRemoved){
            maxRemoved = true;
            continue;
        }
        if(scores[i] == minScore && !minRemoved){
            minRemoved = true;
            continue;
        }
        sum += scores[i];
    }

    double total=sum*difficulty*.6;
    cout<<"The total score for the dive is: "<<total<<endl;

    return 0;
}