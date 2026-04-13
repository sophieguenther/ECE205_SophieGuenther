#include <iostream>

using namespace std;

class pizza
{
	public:
	
	//mutator
	void set_type(int type1)
	{  type=type1;}
	
	void set_size(int size1)
	{  size=size1;}
	
	void set_toppings(int toppings1)
	{  toppings=toppings1;}
	
	//accessor
	int get_type()
	{
		return type;
	}
	//-------------
	//---------------
	int	get_size()
	{
		return size;
	}
	int get_toppings()
	{
		return toppings;
	}
	
	void get_input();
	double compute_price();
	void output_description();
	
	private:
	
	int type; //deep_dish, hand_tossed, pan
	int size;//small, medium, bi
	int toppings;//number of cheese or pepperoni toppings	
};

void pizza::get_input()
{
	cout << "enter type of pizza (1 for Deep Dish, 2 for Hand Tossed, 3 for Pan) ->" <<endl;
	cin>> type;
	while (type!=1 && type!=2 && type!=3)
	{
		cout << "invalid input, please enter 1 for Deep Dish, 2 for Hand Tossed, 3 for Pan ->" <<endl;
	    cin>> type;
	}
	set_type(type);
	cout << "enter size of pizza (1 for Small, 2 for Medium, 3 for Large) ->" <<endl;
	cin>> size;
	while (size!=1 && size!=2 && size!=3)
	{
		cout << "invalid input, please enter 1 for Small, 2 for Medium, 3 for Large ->" <<endl;
	    cin>> size;
	}
	set_size(size);
	cout << "enter number of toppings ->" <<endl;
	cin>> toppings;
	while (toppings<0)
	{
		cout << "invalid input, please enter a non-negative number for toppings ->" <<endl;
	    cin>> toppings;
	}
	set_toppings(toppings);
	
}
double pizza::compute_price()

{
	double cost;
	if (size==1)
	{
		cost = 10+2*toppings;
		
	}
	else if (size==2)
	{
		cost = 14+2*toppings;
		
	}
	else if (size==3)
	{
		cost = 17+2*toppings;
		
	}
	
	return cost;
	
}
void pizza::output_description()

{
	if (size==1)
	{
		cout <<"pizza size is small" << endl;
		
	}
	else if (size==2)
	{
		cout <<"pizza size is medium" << endl;
		
	}
	else if (size==3)
	{
		cout <<"pizza size is large" << endl;
		
	}

	if (type==1)
		{
		cout <<"pizza type is deep dish" << endl;
		
	}
	else if (type==2)
	{
		cout <<"pizza type is hand tossed" << endl;
		
	}
	else if (type==3)
	{
		cout <<"pizza type is pan" << endl;
		
	}
	cout <<"number of toppings is " << toppings << endl;
}


int main() {
	pizza p1;
	char repeat = 'y';
	while (repeat == 'y' || repeat == 'Y'){
		p1.get_input();
	
		double cost = p1.compute_price();
		p1.output_description();
		cout <<"my total cost is "<<cost<<endl;
		cout << "Do you want to order another pizza? (y/n) -> ";
		cin >> repeat;
	}
	return 0;
}