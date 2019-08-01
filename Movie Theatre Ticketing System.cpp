//Read this after running the program

// 1) Program does save the seats after the initial purchase for the view
//available seats option
// 2) Constructors maybe needed in the classes to keep a running total after the initial purchase
//for the sales report including printing the avaialble/reserved seats 

#include <iostream>
#include <iomanip>
#include <string>
//#include "SeatStructures.h" (optional according to project)
//#include "TicketManager.h" (optional according to project)
using namespace std;

// Function prototypes
void displayMenu();
char getChoice();
const int numberOfRow = 15;
const int numberOfCol = 30;



/****************************************************************
*                        SeatStructures Class                  *
* This function displays the user's menu on the screen.        *
****************************************************************/
class SeatStructures
{
private:
	char matrix[numberOfRow][numberOfCol];
	int i, j;
	bool another = true;

public:

	// viewSeats Function
	void viewSeats()
	{
		for (i = 0; i < numberOfRow; i++)
			for (j = 0; j < numberOfCol; j++)
				matrix[i][j] = '#';

		print(matrix, numberOfRow, numberOfCol);
	}

	// print Function
	void print(char matrix[][30], int numberOfRow, int numberOfCol)
	{
		cout << "# Seats available\n";
		cout << "* Reserved Seats\n\n";
		cout << "Seats:  012345678901234567890123456789\n";

		for (int i = 0; i < numberOfRow; i++)
		{
			cout << "Row" << setw(3) << i << "  ";
			for (int j = 0; numberOfCol > j; j++)
				cout << matrix[i][j];
			cout << endl;
		}
	}
};

/****************************************************************
*                        TicketManager Class                   *
* This function displays the user's menu on the screen.        *
****************************************************************/
class TicketManager
{
private:

	const double rateAdult = 10.00;
	const double rateChild = 5.00;
	double totalAdult,
		totalChild,
		totalAmount,
		totalPaid,
		finalBalance,
		ACCtotalAdultSales,
		ACCtotalChildSales,
		ACCtotalAmount;
	int ticketAdult,
		ticketChild,
		pickSeat,
		ACCticketAdult,
		ACCtotalTicketsSold;
	int i, j, row, col;
	int ticketsold = 0;
	char matrix[numberOfRow][numberOfCol];
	int ACCticketChild = 0;

public:

	// print Function
	void print(char matrix[][30], int numberOfRow, int numberOfCol)
	{
		cout << "# Seats available\n";
		cout << "* Reserved Seats\n\n";
		cout << "Seats:  012345678901234567890123456789\n";

		for (int i = 0; i < numberOfRow; i++)
		{
			cout << "Row" << setw(3) << i << "  ";
			for (int j = 0; numberOfCol > j; j++)
				cout << matrix[i][j];

			cout << endl;
		}
	}

	// receipt Function
	void receipt()
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour total for " << ticketAdult << " adult and ";
		cout << ticketChild << " child ticket(s) is $" << totalAmount << ".\n";
		cout << "\n\n";
		cout << "        Receipt \n";
		cout << "----------------------------\n\n";
		cout << "Ticket(s):          Amount:\n";
		cout << "Adult: " << ticketAdult << " ---------- $" << totalAdult << "\n";
		cout << "Child: " << ticketChild << " ---------- $" << totalChild << "\n";
		cout << "\nTotal Due: " << "         $" << totalAmount << "\n";
		cout << "\nEnter the amount paid: $";
		cin >> totalPaid;
		finalBalance = totalPaid - totalAmount;

		if (totalPaid < totalAmount)
		{
			cout << "\nRemaining total is " << finalBalance << "\nEnter the amount paid: $";
			cin >> totalPaid;
		}
		else
			cout << "\nChange due: $" << finalBalance << "\n";
	}

	// getTickets Function
	void getTickets()
	{
		// 2D Array for seats
		for (i = 0; i < numberOfRow; i++)
			for (j = 0; j < numberOfCol; j++)
				matrix[i][j] = '#';
		print(matrix, numberOfRow, numberOfCol);

		cout << "\nMenu:\n";
		cout << "Tickets are $10 for an adult and $5 for a child.\n\n";
		cout << "How many Adult tickets would you like to purchase? ";
		cin >> ticketAdult;												// Get the number of adult tickets
		cout << "How many Child tickets would you like to purchase? ";
		cin >> ticketChild;												// Get the number of child tickets

																		// Calculate the totals 
		totalAdult = ticketAdult * rateAdult;
		totalChild = ticketChild * rateChild;
		totalAmount = totalAdult + totalChild;
		pickSeat = ticketAdult + ticketChild;

		// Keeps running totals
		ticketsold = ticketsold + ticketAdult;
		ACCticketChild = ACCticketChild + ticketChild;

		for (int count = 0; count < pickSeat; count++)
		{
			cout << "\nPick your seats: \n\n";
			print(matrix, numberOfRow, numberOfCol);
			cout << "\n\nEnter row: ";
			cin >> row;								// Gets row for seats
			cout << "\nEnter seat: ";
			cin >> col;								// Gets column for seats

													// Displays sold seats
			if (matrix[row][col] == '#')
			{
				matrix[row][col] = '*';
			}
			else
			{
				cout << "*******SEAT IS NOT AVAILABLE. PLEASE PICK YOUR SEATS AGAIN******* \n";
				getTickets();				// Returns back to get tickets
			}
		}

		cout << "Here are the available seats: \n\n";
		print(matrix, numberOfRow, numberOfCol);		// Displays sold seats
		receipt();										// Displays the receipt
	}

	// finalReceipt Function
	void finalReceipt()
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour total for " << ticketAdult << " adult and ";
		cout << ticketChild << " child ticket(s) is $" << totalAmount << ".\n";
		cout << "\n\n";
		cout << "        Receipt \n";
		cout << "----------------------------\n\n";
		cout << "Ticket(s):          Amount:\n";
		cout << "Adult: " << ticketAdult << " ---------- $" << totalAdult << "\n";
		cout << "Child: " << ticketChild << " ---------- $" << totalChild << "\n";
		cout << "\nTotal Due: " << "         $" << totalAmount << "\n";
		cout << "\nThe amount paid:    $" << totalPaid << "\n";
		finalBalance = totalPaid - totalAmount;
		cout << "\nChange due:         $" << finalBalance;
	}

	// Total function
	void Total()
	{
		// Calculates the total
		ACCtotalAdultSales = ticketsold * rateAdult;
		ACCtotalChildSales = ACCticketChild * rateChild;
		ACCtotalAmount = ACCtotalAdultSales + ACCtotalChildSales;
		ACCtotalTicketsSold = ticketsold + ACCticketChild;

		// Displays the report
		cout << fixed << showpoint << setprecision(2);
		cout << "\n\n\n        Daily Sales Report \n";
		cout << "----------------------------------------------------\n\n";
		cout << "Total Ticket(s): " << ACCtotalTicketsSold << "       Amount: $" << ACCtotalAmount << "\n";
		cout << "\n\n            Report Details \n";
		cout << "----------------------------------------------------\n\n";
		cout << "Adult: " << ticketsold << " ---------- $" << ACCtotalAdultSales << "\n";
		cout << "Child: " << ACCticketChild << " ---------- $" << ACCtotalChildSales << "\n\n";
	}
};

int main()
{
	SeatStructures calculate;				// SeatStructures object
	TicketManager transaction;             // TicketManager object
	char selection;
	//cout << fixed << showpoint << setprecision(2);

	do
	{
		displayMenu();				// This displays the menu
		selection = getChoice();  // This returns only '1' - '5'
		switch (selection)
		{
		case '1':
			transaction.getTickets();
			break;

		case '2':
			cout << "\n              SEATS\n\n";
			cout << "\nHere are the available seats: \n\n";
			calculate.viewSeats();
			break;

		case '3':
			cout << "\n              FINAL RECEIPT\n\n";
			cout << "\nHere is a copy of the last receipt: \n\n";
			transaction.finalReceipt();
			break;

		case '4':
			cout << "\n              SALES REPORT\n\n";
			cout << "\nHere is the sales report: \n\n";
			transaction.Total();

		}
		cout << endl;
	} while (selection != '5');
	cout << "\nGoodbye\n";
	return 0;
}


/****************************************************************
*                        displayMenu                           *
* This function displays the user's menu on the screen.        *
****************************************************************/
void displayMenu()
{
	cout << "\n\n                MENU\n\n";
	cout << "1) Request tickets\n";
	cout << "2) Display seats\n";
	cout << "3) View the last receipt\n";
	cout << "4) Sales report\n";
	cout << "5) Exit the program\n\n";
	cout << "Enter your choice: ";
}

/*****************************************************************
*                            getChoice                          *
* This function gets, validates, and returns the user's choice. *
*****************************************************************/
char getChoice()
{
	char number;
	cin >> number;

	while (number != '1' && number != '2' && number != '3' && number != '4' && number != '5')
	{
		cout << "Enter 1, 2, 3, 4 or 5: ";
		cin >> number;
	}
	return number;
}
