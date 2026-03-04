#include <iostream>

using namespace std;

void get_input(int& start, int& end, int& start_minute, int& end_minute)
{
	cout << "What is the start time? (ex: 2311) -> "<<endl;
	cin>>start;
    while(start<0||start>2359||start%100>59)
    {
        cout<<"Invalid start time input, try again -> "<<endl;
        cin>>start;
    }

	cout << "What is the end time? -> "<<endl;
	cin>>end;
    while(end<0||end>2359||end%100>59)
    {
        cout<<"Invalid end time input, try again -> "<<endl;
        cin>>end;
    }
    start_minute = start%100;
    end_minute = end%100;
    start = start/100;
    end = end/100;
}
int time_difference(int start, int end, int start_minute, int end_minute)
{
    int difference;
    if(end<start)
    {
        end = end+24;
    }
    difference = (end-start)*60 + (end_minute-start_minute);
    return difference;
}
int main (){
    int start;
	int end;
	int start_minute;
	int end_minute;
	char response;
    do {
		//get input
		get_input(start,end,start_minute,end_minute);
        //find time difference
        int difference = time_difference(start,end,start_minute,end_minute);
        cout<<"The time difference is "<<difference<<" minutes."<<endl;
        cout<<"Do you want to try again? (Y/N) -> "<<endl;
        cin>>response;
    } while(response=='Y' || response=='y');
    
    return 0;
}