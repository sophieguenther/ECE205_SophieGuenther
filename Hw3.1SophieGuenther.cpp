//call by reference
#include <iostream>


using namespace std;

void get_input(int& h1, int& m1)
{
	cout << "What is the hour -> "<<endl;
	cin>>h1;
    while(h1<0||h1>23)
    {
        cout<<"Invalid hour input, try again -> "<<endl;
        cin>>h1;
    }
	cout << "What is the minute -> "<<endl;
	cin>>m1;
    while(m1<0||m1>59)
    {
        cout<<"Invalid minute input, try again -> "<<endl;
        cin>>m1;
    }	
}

char convert(int& h, int& m)

{
	char x;
	if(h>=12)
		{
			x='P';
			if(h==12)	
				{h=12;}
				else
				{
					h=h-12;
				}
		}	
		else
		{
			x='A';
		}
	
	return x;
}

int main()
{
	int h;
	int m;
	char x; //A or P
	char response;
	
	do {
		//get input
		get_input(h,m);
		//convertion
		x=convert(h,m);
		if(h==0)
		{
			h=12;
		}
	
	//show results
	if(m<10)
	{
		cout <<"The time is: "<<h<<":0"<<m<<" "<<x<<"M"<<endl;
	}
	else
	{
	cout <<"The time is: "<<h<<":"<<m<<" "<<x<<"M"<<endl;
	}
	cout<<"Do you want to give another input?"<<endl;
	cin>>response;
	
	}while(response=='Y'||response=='y');
	
	return 0;
}