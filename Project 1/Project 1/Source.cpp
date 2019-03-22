// -------------------------
// CS 215-402 - Project 1
//Author: Tyler Patrick
//Date: 2/7/2019
//Description: Gas Pump control Code
//Assitance: I received assistance from the following:
// I recieved assistance from Josiah Jaddock
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
int main()
{
	cout << fixed << setprecision(2);
	ifstream s;
	ofstream d;
	double highprice;
	double medprice;
	double lowprice;
	double hightank;
	double medtank;
	double lowtank;
	double gallons;
	double gasprice;
	string reward, octanechoice, gastype;
	char octchar;
	double disc;
	int rewardnum;
	const double flowRate = 0.5;
	const int time = 2000;
	s.open("pumpin.txt");
	if (s.fail())
	{
		cout << " File failed to open";
		system("pause");
		return(0);
	}
	// Get data from text
	s >> hightank >> medtank >> lowtank >> highprice >> medprice >> lowprice;
	s.close();
	while (1)
	{
		//Print Logo and Name
		cout << "+-------------------------------------------------+" << endl;
		cout << "|              Welcome to Tyler's Self Serve      |" << endl;
		cout << "|                  Tyler Patrick , Owner          |" << endl;
		cout << "|                                                 |" << endl;
		cout << "+-------------------------------------------------+" << endl;

		//Check if customer has reward status
		while (1)
		{
			cout << "Are you a rewards customer? (Y/N): ";
			cin >> reward;
			if ((reward == "Y") || (reward == "y") || (reward == "N") || (reward == "n"))
				break;
			if (reward == "shutdown")
			{
				//Shutdown
				cout << "Tank Reading: Hi=" << hightank << " Med=" << medtank << " Low=" << lowtank << endl;
				cout << "pump shut down" << endl;
				// Open pumpout.txt
				d.open("pumpout.txt");
				if (d.fail())
				{
					cout << " File failed to open";
					system("pause");
					return(0);
				}
				d << hightank << " " << medtank << " " << lowtank << endl;
				d << highprice << " " << medprice << " " << lowprice;
				d.close();
				system("pause");
				return(0);
			}
			cout << "Please Enter Y/N " << endl;
		}


		//Find out rewards status
		if ((reward == "Y") || (reward == "y"))
		{
			cout << "Enter your rewards number ";
			cin >> rewardnum;
			// Discount
			disc = ((rewardnum % 10) + 1.0) / 100.0;
		}
		//Show Discount
		cout << "Price per gallon Discount:    $" << disc << endl << endl;
		// Display Prices
		cout << "Price Per Gallon " << endl;
		cout << "High Octane:    $" << (highprice - disc) << endl;
		cout << "Medium Octane:  $" << (medprice - disc) << endl;
		cout << "Low Ocante:     $" << (lowprice - disc) << endl;

		// Select Octane
		while (1)
		{
			cout << "Select Octane (H/M/L): ";
			cin >> octanechoice;
			if ((octanechoice == "H") || (octanechoice == "h") || (octanechoice == "M") || (octanechoice == "m") || (octanechoice == "L") || (octanechoice == "l"))
				break;
			cout << "Error. Please Enter another choice ";
		}
		cout << endl;
		cout << " Enter Number of gallons (-1 to fill up) ";
		// Find gallons to fill
		cin >> gallons;
		//Ask to fill up
		if (gallons < 0)
		{
			gallons = 1 + (rand() % (8 - 1 + 1));
			cout << "sensor reports " << gallons << " gallons needed to fill up." << endl;
		}
		// Assign Characters
		octchar = octanechoice[0];
		octchar = toupper(octchar);
		switch (octchar)
		{
			// Check tank
		case 'H':
			if (hightank < gallons)
			{
				cout << "Sorry our Tank is empty we only have " << hightank << "gallons remaining" << endl;
				gallons = hightank;
			}
				gastype = "High";
				gasprice = highprice - disc;
				hightank = hightank - gallons;
				break;
		case 'M':
			if (medtank < gallons)
			{
				cout << "Sorry our Tank is empty we only have " << medtank << "gallons remaining" << endl;
				gallons = medtank;
			}
				gastype = "Medium";
				gasprice = medprice - disc;
				medtank = medtank - gallons;
			
		case 'L':
			if (lowtank < gallons)
			{
				cout << "Sorry our Tank is empty we only have " << lowtank << "gallons remaining" << endl;
				gallons = lowtank;
			}
				gastype = "Low";
				gasprice = lowprice - disc;
				lowtank = lowtank - gallons;
				break;
		}
		// Pump the gas
		cout << "Pumping gas..." << endl;
		for (double i = 0; i < gallons; i = i + flowRate)
		{
			cout << i << "gallons pumped..." << endl;
			Sleep(time);
		}
		cout << endl;
		cout << "------------Your Receipt-----------"  << endl;
		cout << "Octane:            " <<      gastype  << endl;
		cout << "Price per gallon: $" << setw(6) << right << gasprice << endl;
			cout << "Total             $" << setw(6) << right << (gallons * gasprice) << endl;
		cout << " Thank you for visiting Tylars Fast Gas";
		cout << "-----------------------------------"  << endl;
		disc = 0;
		system("pause");
	}
}


		