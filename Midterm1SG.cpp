//program that calculates the time difference between a given start and end time, end time will be within 24 hours of the start time
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

char convertStart(int& start, int& start_minute)
{
	char x;
	if(start>=12)
		{
			x='P';
			if(start==12)	
				{start=0;}
				else
				{
					start=start-12;
				}
		}
		
		else
		{
			x='A';
		}
	
	return x;
}
char convertEnd(int& end, int& end_minute)
{
	char y;
	if(end>=12)
		{
			y='P';
			if(end==12)	
				{end=0;}
				else
				{
					end=end-12;
				}
		}
		
		else
		{
			y='A';
		}
	
	return y;
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
int main()
{
	int start;
	int end;
	int start_minute;
	int end_minute;
	char x; //A or P
    char y; //A or P
	char response;
	
	do {
		//get input
		get_input(start,end,start_minute,end_minute);
        //find time difference
        int difference = time_difference(start,end,start_minute,end_minute);//has to come before convertion
	
		//convertion
		x=convertStart(start,start_minute);
		y=convertEnd(end,end_minute);
	
	
	//show results
	cout <<"The start time (12 hr format) is: "<<start<<":"<<start_minute<<" "<<x<<"M"<<endl;
	cout <<"The end time (12 hr format) is: "<<end<<":"<<end_minute<<" "<<y<<"M"<<endl;
    cout<<"The time difference is: "<<difference<<" minutes"<<endl;
	
	cout<<"Do you want to give another input?"<<endl;
	cin>>response;
	
	
	}while(response=='Y'||response=='y');
	
	
	return 0;
}
