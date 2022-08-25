/*******************************************************
Ahmad Ali (804-635-447)
April 28, 2017.
HW#3

This game allows you to play Tic-Tac-Toe and the way it 
was developed was with a while loop and using the 
graphics library provided with us from the website
*******************************************************/

#include "ccc_win.h"

int ccc_win_main()
{
	string game_start = "y"; // This is the keyphrase that allows for the game to continue 

	Point a_pv(-10, -21), b_pv(-10, 21), c_pv(10, -21), d_pv(10, 21); //Points for the vertical lines 
	Point a_ph(-25, -7), b_ph(25, -7), c_ph(-25, 7), d_ph(25, 7); //Pints for Horizontal lines 

	Line a_lv(a_pv, b_pv), b_lv(c_pv, d_pv); //lines for Vertical lines 
	Line a_lh(a_ph, b_ph), b_lh(c_ph, d_ph); //Lines for the Horizontal

	while (game_start == "y") // This is the control point of the game 
	{
		cwin.clear(); //clears the screen at the start of the game 
		cwin.coord(-30, 30, 30, -30); //creates the coordinate system
		cwin << a_lv << b_lv << a_lh << b_lh; //outputs the lines for the tick tac toe board 

		int times_clicked = 1; // This is done to make use of another loop for the acctually clicking 
		while(times_clicked <= 9)//this loop makes sure that a particular game stops after 9 clicks by the user
		{
			Point click = cwin.get_mouse("Click on an empty spot!"); //records the placed clicked

			double click_x = click.get_x();
			double click_y = click.get_y();

			if (times_clicked % 2 == 0)//This Displays the O
			{
				Circle o(click, 5);
				cwin << o;
			}
			else // This displays the X
			{
				Point p1(click_x + 4, click_y + 4), p2(click_x - 4, click_y + 4), p3(click_x + 4, click_y - 4), p4(click_x - 4, click_y - 4); //forms the x 
				Line x1(p1, p4), x2(p2, p3); // draws the x
				cwin << x1 << x2; //displays the x
			}
			times_clicked++; // This adds to the click counter so the game completes 
		}
		cwin << Message(Point(-4, 2), "Game Over"); //game over screen
		game_start = cwin.get_string("Do you wish to play again? (y/n): "); //prompt for another game 
	}
	return 0;
}