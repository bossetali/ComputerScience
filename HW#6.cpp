/*******************************************************
Ahmad Ali (804-635-447)
May 22, 2017
HW#6-houses

This allows you to build houses and define the address
accordingly
*******************************************************/

#include <iostream> 
#include "ccc_win.h"

using namespace std;

class House
{
public:
	House(){}
	House(int Address1, Point location1)  //constructor, all this does is initialize the Varibles Address and Location
	{
		Address = Address1;
		location = location1;
	}

	//This class function is used to draw the house 
	void draw() const 
	{
		double x = location.get_x();
		double y = location.get_y();
		// The Next 5-10 lines represent the construction of a House  
		Point TLH(x, y + 5);
		Point BRH(x + 5, y);
		Point TRH(x + 5, y + 5);
		Line bottom(location, BRH);
		Line left(location, TLH);
		Line right(BRH, TRH);
		Line top(TLH, TRH);
		Point roof(TLH.get_x() + 1.5, TLH.get_y() + 2);
		Line roofL(TLH, roof);
		Line roofR(roof, TRH);
		// This is is the Function That Draws the House 
		cwin << bottom << left << right << top;
		cwin << roofL << roofR;
		//number the house with "address"
		Point center(location.get_x() + 1.5, location.get_y() + 2);
		Message M_ssg(center, Address);
		cwin << M_ssg;
	}
	//returns location
	Point get_location() const
	{
		return location;
	}
	//returns house
	int get_num() const
	{
		return Address;
	}
	//This is where the memeber varibles are stored 
private:
	int Address;
	Point location;
};
//New Class 
class Street
{
public:
	Street(){}
	//This Constructor Stores the First and Last House aswell as a number
	Street(House first1, House last1, int num)
	{
		first = first1;
		last = last1;
		num_houses = num;
	}
	void Street::plot() const
	{
		//First we isolate our x's and y's 
		double x1 = first.get_location().get_x();
		double y1 = first.get_location().get_y();
		double x2 = last.get_location().get_x();
		double y2 = last.get_location().get_y();
		// Then we find the difference between x's and y's 
		double dx = (x2 - x1) / (num_houses - 1);
		double dy = (y2 - y1) / (num_houses - 1);
		// This allows for the labeling of the Houses 
		double Add1 = first.get_num();
		double Add2 = last.get_num();
		// This allows for the Computation of The House Numbers
		double Address = (Add2 - Add1) / (num_houses - 1);
		// This is a loop which labels the Houses 
		for (int i = 0; i < num_houses; ++i)
		{
			double new_x = x1 + dx*i;
			double new_y = y1 + dy*i;
			Point new_location(new_x, new_y);
			int new_Add = Add1 + Address*i;
			House new_house(new_Add, new_location);
			new_house.draw();
		}
		last.draw();
	}
	//This is where the member Varibles are stored
private:
	House first;
	House last;
	int num_houses;
};
int ccc_win_main()
{
	//This is the Creation of the Coordinate system that we will use throughout the Project 
	cwin.coord(-30, 30, 30, -30);
	//program runs if user chooses to continue
	string response = "yes";
	while (response == "yes"|| response== "y")
	{
		//Clears The Screen for Multiple uses
		cwin.clear();
		// This is the Creation of the two House Points and the Address System we used
		Point first_location = cwin.get_mouse("Please choose the location for the first house by clicking anywhere.");
		Point last_location = cwin.get_mouse("Please choose the location for the last house by clicking anywhere.");
		int first_Add = cwin.get_int("Enter the street number of the first house:");
		int last_Add = cwin.get_int("Enter the street number of the last house:");
		//create 2 House variables
		House first_house(first_Add, first_location);
		House last_house(last_Add, last_location);
		//Then you ask for House Amount 
		int num_houses = cwin.get_int("How many houses are on the street?");
		//Then you Draw the Street and Everything else
		Street s(first_house, last_house, num_houses);
		s.plot();
		response = cwin.get_string("Want to draw another street? (yes/no) ?");
	}
	cwin.clear();
	return 0;
}