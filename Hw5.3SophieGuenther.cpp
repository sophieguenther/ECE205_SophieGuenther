#include <iostream>
#include <vector>
using namespace std;
//copy in pizza class from hw5.2
class pizza
{
	public:
	
    //default constructor
    pizza() {
        type = 1;
        size = 1;
        toppings = 0;
    }

    //constructor with parameters
    pizza(int t, int s, int top) {
        type = t;
        size = s;
        toppings = top;
    }
    //mutators
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
	double compute_price() const;
	void output_description() const;
	
	private:
	
	int type; //deep_dish, hand_tossed, pan
	int size;//small, medium, large
	int toppings;//number of cheese or pepperoni toppings	
};

void pizza::get_input()
{
	cout << "enter type of pizza (1 for Deep Dish, 2 for Hand Tossed, 3 for Pan) ->";
	cin>> type;
	while (type!=1 && type!=2 && type!=3)
	{
		cout << "invalid input, please enter 1 for Deep Dish, 2 for Hand Tossed, 3 for Pan ->" ;
	    cin>> type;
	}
	set_type(type);
	cout << "enter size of pizza (1 for Small, 2 for Medium, 3 for Large) ->" ;
	cin>> size;
	while (size!=1 && size!=2 && size!=3)
	{
		cout << "invalid input, please enter 1 for Small, 2 for Medium, 3 for Large ->" ;
	    cin>> size;
	}
	set_size(size);
	cout << "enter number of toppings ->" ;
	cin>> toppings;
	while (toppings<0)
	{
		cout << "invalid input, please enter a non-negative number for toppings ->" ;
	    cin>> toppings;
	}
	set_toppings(toppings);
	
}
double pizza::compute_price() const

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
void pizza::output_description() const

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


class order {
    vector <pizza> pizzas;
public:
    void add_pizza(const pizza& p)
    {
        pizzas.push_back(p);
    }
    void add_pizza(int type, int size, int toppings)
    {
        pizza p(type, size, toppings);
        pizzas.push_back(p);
    }

    void outputOrder() const
    {
        double totalPrice = 0.0;
    if (pizzas.empty())
    {
        cout << "No pizzas in the order." << endl;
        
    }
    for (size_t i = 0; i < pizzas.size(); i++)
    {
        cout << "Pizza #" << i + 1 << ": ";
        pizzas[i].output_description();
        cout << "Price: $" << pizzas[i].compute_price() << endl << endl;
        totalPrice += pizzas[i].compute_price();
    }
    cout << "Total Order Price: $" << totalPrice << endl;
    cout << "--------------------------" << endl;
}
};

int main()
{
    // Create pizza objects
    order order1;
    int numPizzas;
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        cout << "How many pizzas would you like to order? -> ";
        cin >> numPizzas;
        while (numPizzas < 0) {
            cout << "Number of pizzas must be positive. Please enter a valid number: -> ";
            cin >> numPizzas;
        }
        for (int i = 0; i < numPizzas; i++) {
            cout << "Enter details for pizza #" << i + 1 << ":" << endl;
            pizza p;
            p.get_input();
            order1.add_pizza(p);
        }
        cout << "\nYour Order Details:\n";
        order1.outputOrder();
        cout << "Do you want to place another order? (y/n) -> ";
        cin >> repeat;
        order1 = order(); // Reset the order for the next round
    }
    return 0;
}
