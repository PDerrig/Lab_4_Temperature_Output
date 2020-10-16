/*
Preston Derrig
C++ Fall 2020
Due: October 19 2020
Lab #4 Temperature Output
Taking Temperature values from a file and outputing the values as stars on a graph using while loops
*/

#include <iostream> // including the libraries I needed to complete the lab. 
#include <fstream>
#include <iomanip>
using namespace std;

float Temperature;  // setting up the variables I used throughout the lab
int legend = -30;
int number_of_stars;
int checker=0;

void printstars(); 

int main()
{
	ifstream infile; // creating and opening the input file for temperature values
	infile.open("TemperatureInput.dat");

	//Setting up interaction with the user so they can understand what the graph is trying to display
	cout << "This graph is to show the temperature in degrees Fahrenheit." << endl <<
		"The extremes of this graph is from -40 to 135 degrees, so please keep your number in this range!" << endl << endl;

	// Getting the top line to show where every 15 degrees is to help the user
	cout << setw(15);
		while (legend <= 120)
		{
			cout << legend << setw(5);
			legend = legend + 15;
		}
	
		cout << "      Each * eqauls a range of 3 degrees Fahrenheit"<< endl << endl;

	infile >> Temperature;

	while (infile) // a while loop that continually goes through the infile to get the next temperature value
	{
		cout << setw(8) << Temperature;
		printstars();
		cout << endl;
		infile >> Temperature;
	}
	return 0;
}

void printstars()
{
	 number_of_stars= Temperature/3;
	 checker = 0;

	 if (Temperature >= 135)  // getting the console to display warnings that a value entered is too big or too small
		 cout << "   Sorry, the number you have entered is too large.";

	 else
	 {

		 if (Temperature <= -40)
			 cout << "   Sorry, the number you have entered is too small.";

		 else
		 {

			 if (number_of_stars <= 0) //getting the program to display the correct number of stars for values less than 0
			 {

				 cout << setw(17 + number_of_stars);

				 while (number_of_stars != checker)
				 {
					 cout << "*";
					 checker = checker - 1;
				 }
				 cout << "|";
			 }

			 else  //similar to above but for when the temperature is greater than 0
			 {
				 cout << "                |";
				 while (number_of_stars != checker)
				 {
					 cout << "*";
					 checker++;
				 }
			 }
		 }
	 }
}


