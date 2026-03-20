//airplane seats 
#include <iostream>

using namespace std;

int main(){
    int seatindex;
    int seatletterindex;
    int row;
    char seat;
    //starting with 37 open seats
    char seats[10][4] =  {
    {'A','X','C','D'},
    {'A','B','C','D'},
    {'A','B','C','X'},
    {'A','B','C','D'},
    {'X','B','C','D'},
    {'A','B','C','D'},
    {'A','B','C','D'},
    {'A','B','C','D'},
    {'A','B','C','D'},
    {'A','B','C','D'}
    };
    int howManySeatsLeft = 37;
    char reserveAnotherSeat = 'Y';
    while((reserveAnotherSeat=='Y' || reserveAnotherSeat=='y') && howManySeatsLeft>0){
        cout << "Would you like to reserve a seat? (Y/N) -> " << endl;
        cin >> reserveAnotherSeat;
        while(reserveAnotherSeat!='Y' && reserveAnotherSeat!='y' && reserveAnotherSeat!='N' && reserveAnotherSeat!='n'){
            cout << "Invalid input, try again. (Y/N) -> " << endl;
            cin >> reserveAnotherSeat;
        }
    cout << "Here is the Seating Chart, X means the seat is taken:" << endl;
    for (int i = 0; i < 10; i++){
        cout << "Row " << i+1 << ": ";
        for (int j = 0; j < 4; j++){
            cout <<seats[i][j] << " ";
        }    
            cout << endl;
    }

    //ask user for seat choice and validate input
    //row
    while(howManySeatsLeft>0 && (reserveAnotherSeat=='Y' || reserveAnotherSeat=='y')){
    cout << "What seat would you like to reserve? Enter Row Number -> " << endl;
    cin >> row;
    while(row<1 || row>10){
        cout << "Invalid input for row, try again." << endl;
        cin >> row; 
    }

    //column
    cout << "Enter Seat Letter -> " << endl;
    cin >> seat;
    while(seat!='A' && seat!='B' && seat!='C' && seat!='D'){
        cout << "Invalid input for seat, try again." << endl;
        cin >> seat;
    }
    //convert to array index
    seatindex= row-1;
    if(seat=='A'){
        seatletterindex=0;
    }
    else if(seat=='B'){
        seatletterindex=1;
    }
    else if(seat=='C'){
        seatletterindex=2;
    }
    else if(seat=='D'){
        seatletterindex=3;
    }
   
    //check if seat is available
    if(seats[seatindex][seatletterindex]=='X'){
        cout << "Sorry, that seat is already taken." << endl;
        cout << "Would you like to try reserving a different seat? (Y/N) -> " << endl;
        cin >> reserveAnotherSeat;

    }
    else {
        seats[seatindex][seatletterindex]='X';
        cout << "Your seat has been reserved." << endl;
        howManySeatsLeft--;
        cout <<"The updated seating chart is: " << endl;
         for (int i = 0; i < 10; i++){
            cout << "Row " << i+1 << ": ";
            for (int j = 0; j < 4; j++){
                cout <<seats[i][j] << " ";
             }    
            cout << endl;
        }
        cout << "Would you like to reserve another seat? (Y/N) -> " << endl;
        cin >> reserveAnotherSeat;

    }
    }
  }
   return 0;
}