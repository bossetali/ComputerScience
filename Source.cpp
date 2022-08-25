/*******************************************************
Ahmad Bosset Ali (804635447)
June 9, 2017.
hw#8
*******************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>			//Preprocessor Files
#include <ctime>
#include <fstream>

using namespace std; 

const int row_perm = 10;
const int column_perm = 10; //Permanent Column and Row numbers

void random_matrix(int matrix[row_perm][column_perm],int rows,int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = rand() % 20 - 10;  //Random Matrix function, creates a random matrix from 1 by 1 to 10 by 10 and each number is between -10 and 10
		}
	}
}
void output_matrix(int matrix[row_perm][column_perm], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(5) << matrix[i][j] << " "; //Outputs a matrix onto console
		}
		cout << endl;
	}
}
void add_matrix(int matrix_A[row_perm][column_perm], int matrix_B[row_perm][column_perm], int rows, int columns)
{
	cout << "Equals:" << endl;
	int matrix_C[row_perm][column_perm];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix_C[i][j] = (matrix_A[i][j] + matrix_B[i][j]);
			cout << setw(5) << matrix_C[i][j] << " "; //adds and outputs a matrix 
		}
		cout << endl;
	}
}
void import_file_matrix(int matrix[row_perm][column_perm], int row, int column,ifstream &file)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			file >> matrix[i][j]; //imports a file and uses the matrices inside of it
		}
	}
}
void output_file_matrix(int matrix_A[row_perm][column_perm], int matrix_B[row_perm][column_perm], int rows, int columns, ofstream &file_output)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			file_output << matrix_A[i][j] + matrix_B[i][j] << " ";//outputs a matrix into a file
		}
		file_output << endl;
	}
}

int main()
{
	int row,column,choice; //user imputted row, column, and later choices

	do
{
	cout << "Please enter the dimensions of the matirx" << endl;
	cout << "They must be in the range of 1 to 10" << endl;
	cout << "Enter number of rows:";
	cin >> row;
	cout << "Enter number of columns:";								//This takes in the values of the rows and columns of the matrix and makes sure they are within range
	cin >> column;
} 
	while (!(row > 0 && row < 11) || !(column>0 && column < 11));

	int matrix_A[row_perm][column_perm];
	int matrix_B[row_perm][column_perm];

	do
	{
		cout << "Would you like to fill the matrices from a file or randomly" << endl;		//This is the segment that either fills a matrix from file or random
		cout << "Please enter 1 for a random matrices or 2 for matrices from a file:";
		cin >> choice;
		if (choice == 1)
		{
			random_matrix(matrix_A, row, column);
			random_matrix(matrix_B, row, column);
		}
		else if (choice == 2)
		{
			ifstream file;
			string file_import_name;
			cout << "Enter the name of the file to import:";
			cin >> file_import_name; 
			file.open(file_import_name.c_str());
			import_file_matrix(matrix_A, row, column, file);
			import_file_matrix(matrix_B, row, column, file);
			file.close();
		}
		else
		{
			cout << "Please enter a legitimate response" << endl;
		}
	} 
	while (!(choice == 1 || choice == 2));

	do //this part allows the person to show the output of the code 
	{
		cout << "Choose the output method by entering 1 or 2\n1.Console\n2.File\nResponse:";
		cin >> choice;
		if (choice == 1)
		{
			cout << "The First Matrix is\n\n\n";
			output_matrix(matrix_A, row,column);
			cout << "\n\n\n";
			cout << "The Second Matrix is\n\n\n";
			output_matrix(matrix_B, row, column);
			cout << "\n\n\n";
			cout << "The combination of these two matrices is\n\n\n";
			add_matrix(matrix_A, matrix_B, row, column);
		}
		else if (choice == 2)
		{
			ofstream file_output;
			string file_name;
			cout << "Enter the file name you are exporting to:";
			cin >> file_name;
			file_output.open(file_name.c_str());
			output_file_matrix(matrix_A, matrix_B, row, column, file_output);
			file_output.close();
		}
		else
		{
			cout << "Please enter a legitimate response" << endl;
		}
	} 
	while (!(choice == 1 || choice == 2));

	system("PAUSE");
	return 0;
}