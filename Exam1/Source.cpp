/*
Name: Peter Grieve
Date: 3/13/2014
Instructor: Professor Gitlitz
Assignment: CP125 Exam (Exam 1)
Purpose: This program manages an array of arrays. It allows a user to:
1. Add a number to any  of the arrays
2. Get the total count of numbers in all the arrays
3. Get the total of numbers in all the arrays
4. Print all arrays
*/

using namespace std;
#include <iostream>;



// Function Prototypes
void addNumber(int[8][8]);
int getNumberCount(int[8][8]);
int totalOfNumbers(int[8][8]);
void printArray(int[8][8]);
int getCounters(int[8][8]);


int main()
{

	int data[8][8];
	int choice; // the number that the user inputs to command the program.
	bool running = true;


	//sets all array values to NULL for easier use in getCounters function
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			data[i][j] = NULL;
		}
	}

	// First array default values
	data[0][1] = 100;
	data[0][2] = 101;
	data[0][3] = 7;

	//Second array default values
	data[1][1] = 55;
	data[1][2] = 66;

	// Fifth array default values
	data[4][1] = 44;

	// Sixth array default values
	data[5][1] = 999;
	data[5][2] = 1234;

	//Seventh array default values
	data[6][1] = 88;
	data[6][2] = 77;
	data[6][3] = 44;
	data[6][4] = 2;
	data[6][5] = 50;


	// the while loop allows the user to perform multiple actions without closing the program
	while (running)
	{

		getCounters(data);// recalculates counter values

		cout << endl; // I output many blank lines to make the interface look organized and easy to read.

		cout << " Welcome to the Two - Dimensional Array!" << endl;

		cout << endl;

		cout << " What would you like to do?" << endl;

		cout << endl;

		cout << " 1. Add a number to any of the arrays" << endl;

		cout << endl;

		cout << " 2. Get the total count of numbers in all the arrays." << endl;

		cout << endl;

		cout << " 3. Get the total of all numbers in all the arrays." << endl;

		cout << endl;

		cout << " 4. Print all arrays." << endl;

		cout << endl;

		cout << " 5. Quit." << endl;

		cout << endl;

		cout << " Enter the number of the task you would like to perform." << endl;

		cin >> choice;


		if (choice == 1)
		{
			addNumber(data);

			getCounters(data);
		}

		else if (choice == 2)
		{
			getCounters(data);

			cout << "the total number of values in the array is " << getNumberCount(data) << endl;

			cout << endl;

			system("pause");
		}

		else if (choice == 3)
		{
			cout << "The sum of all values in the array is " << totalOfNumbers(data) << endl;

			cout << endl;

		}

		else if (choice == 4)
		{
			printArray(data);
		}

		else if (choice == 5)
		{
			running = false;
		}


		else
		{
			cout << " invalid choice, please try again." << endl;

			cout << endl;
		}

	}

	return 0;

}

// adds a value to the array
void addNumber(int data[8][8])
{
	int row;
	int counter;
	int value;

	cout << " Enter which array you would like to add a number to." << endl;
	cin >> row;

	if (row <= 1 || row > 8)
	{
		cout << " Invalid number. Please re-enter." << endl;

		cin >> row;
	}

	counter = data[row][0];

	if (counter < 7 && counter >= 0)
	{
		cout << " An index is available. What value would you like to add?" << endl;

		cin >> value;

		data[row][counter + 1] = value;
		data[row][0]++;
	}

	else
	{
		cout << " Array is full" << endl;
	}

	cout << "Action complete." << endl;

	cout << endl;

	system("pause");

	return;

}

// gets the count of values in the array
int getNumberCount(int data[8][8])
{
	int total;

	total = 0;

	for (int i = 0; i < 7; i++)
	{
		total = data[i][0] + total;
	}

	return total;


}


// returns the sum of all values in the array (except for the counter values in the first column)
int totalOfNumbers(int data[8][8])
{

	int total;

	total = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			total = data[i][j] + total;
		}
	}


	return total;
}


// allows the user to see the current values stored in the array
void printArray(int data[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		cout << endl;

		cout << " [" << i << "] ";

		for (int j = 0; j < 8; j++)
		{
			cout << " [" << data[i][j] << "] ";
		}
	}
}


// recalculates the counter values in the first column of the 2D array
int getCounters(int data[8][8])
{

	int count;

	count = 0;

	for (int i = 0; i < 8; i++)
	{
		count = 0;

		for (int j = 1; j < 8; j++)
		{

			if (data[i][j] != NULL)
			{
				count++;

				data[i][0] = count;

			}
		}
	}

	return data[8][8];
}

/* Proof
Welcome to the Two - Dimensional Array!

What would you like to do?

1. Add a number to any of the arrays

2. Get the total count of numbers in all the arrays.

3. Get the total of all numbers in all the arrays.

4. Print all arrays.

5. Quit.

Enter the number of the task you would like to perform.
1
Enter which array you would like to add a number to.
2
An index is available. What value would you like to add?
48
Action complete.

Press any key to continue . . .

Welcome to the Two - Dimensional Array!

What would you like to do?

1. Add a number to any of the arrays

2. Get the total count of numbers in all the arrays.

3. Get the total of all numbers in all the arrays.

4. Print all arrays.

5. Quit.

Enter the number of the task you would like to perform.
2
the total number of values in the array is 14

Press any key to continue . . .

Welcome to the Two - Dimensional Array!

What would you like to do?

1. Add a number to any of the arrays

2. Get the total count of numbers in all the arrays.

3. Get the total of all numbers in all the arrays.

4. Print all arrays.

5. Quit.

Enter the number of the task you would like to perform.
3
The sum of all values in the array is 2915


Welcome to the Two - Dimensional Array!

What would you like to do?

1. Add a number to any of the arrays

2. Get the total count of numbers in all the arrays.

3. Get the total of all numbers in all the arrays.

4. Print all arrays.

5. Quit.

Enter the number of the task you would like to perform.
4

[0]  [3]  [100]  [101]  [7]  [0]  [0]  [0]  [0]
[1]  [2]  [55]  [66]  [0]  [0]  [0]  [0]  [0]
[2]  [1]  [48]  [0]  [0]  [0]  [0]  [0]  [0]
[3]  [0]  [0]  [0]  [0]  [0]  [0]  [0]  [0]
[4]  [1]  [44]  [0]  [0]  [0]  [0]  [0]  [0]
[5]  [2]  [999]  [1234]  [0]  [0]  [0]  [0]  [0]
[6]  [5]  [88]  [77]  [44]  [2]  [50]  [0]  [0]
[7]  [0]  [0]  [0]  [0]  [0]  [0]  [0]  [0]
Welcome to the Two - Dimensional Array!

What would you like to do?

1. Add a number to any of the arrays

2. Get the total count of numbers in all the arrays.

3. Get the total of all numbers in all the arrays.

4. Print all arrays.

5. Quit.

Enter the number of the task you would like to perform.


*/