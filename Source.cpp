#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

int const max_cols = 10;
int const max_rows = 10;
double inverse[max_rows][max_cols];              // To save the inverse matrix
double inverse_operation[max_rows][max_cols];    //Used inside inverse function
int inverse_size;
double ans[max_rows][max_cols] = {};
double product[max_rows][max_cols] = {};



void input_matrix(double v[max_rows][max_cols], int cols, int rows);
void print_matrix(double v[max_rows][max_cols], int cols, int rows);
double matrix_determinant(double a[max_rows][max_cols], int size);
void matrix_transpose(const double v[max_rows][max_cols], double t[max_rows][max_cols], int cols, int rows);
void matrix_sum(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows);
void matrix_difference(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows);
void matrix_product(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows);
void matrix_inverse(const double a[max_rows][max_cols], double c[max_rows][max_cols], double operation[max_rows][max_cols], int size);
string check_error_sum(int cols1, int rows1, int cols2, int rows2);
string check_error_product(int cols1, int rows2);
string check_error_determinant(int cols1, int rows1);
void show_menu();
void matrix();
void delay();



                                          //Main Program
int main() {

	int rows1 = 0, cols1 = 0, size1 = 0;
	int rows2 = 0, cols2 = 0, size2 = 0;
	double matrix_1[max_rows][max_cols] = {};
	double matrix_2[max_rows][max_cols] = {};
	int choice;
	string yes_no;


	// You should display a menu and make the user choose what does he want to do.

	matrix();
	cout << "Enter the Matrix:\n";

	do {                      // First Matrix Data
		cout << "Please enter the size of the Matrix A\n";
		cout << "Rows: "; cin >> rows1;
		cout << "Columns: "; cin >> cols1;
		if (rows1 == cols1) {
			size1 = rows1;
			cout << "Size: " << size1 << "\n\n";
		}
		if (rows1 != cols1) {
			cout << "Size: " << rows1 << " x " << cols1 << "\n\n";
		}
	} while (rows1 > 10 || cols1 > 10 || rows1 <= 0 || cols1 <= 0);
	cout << "Now enter the elements of the Matrix one by one\n";
	input_matrix(matrix_1, cols1, rows1);

	cout << "Do you want to enter a Second Matrix?\n" << "\t\t( y / n )\n\n";
	cout << "Your choice is => ";
	cin >> yes_no;

	if (yes_no == "y") {
		matrix();
		do {                    // Second Matrix Data
			cout << "Please enter the size of the Matrix B\n";
			cout << "Rows: "; cin >> rows2;
			cout << "Columns: "; cin >> cols2;
			if (rows2 == cols2) {
				size2 = rows2;
				cout << "Size: " << size2 << "\n\n";
			}
			if (rows2 != cols2) {
				cout << "Size: " << rows2 << " x " << cols2 << "\n\n";
			}
		} while (rows2 > 10 || cols2 > 10 || rows2 <= 0 || cols2 <= 0);
		cout << "Now enter the elements of the Matrix one by one\n";
		input_matrix(matrix_2, cols2, rows2);
		matrix();
		show_menu();
	}
	if (yes_no == "n") {
		matrix();
		show_menu();
	}


	do {
		matrix();
		show_menu();
		cin >> choice;
		switch (choice) {
		case 1: // Edit the matrix
			matrix();
			cout << "Which Matrix do you want to edit?\n";
			cout << "( 1.Matrix A / 2.Matrix B )\n";
			int mat;
			cin >> mat;
			matrix();
			if (mat == 1) {
				do {                      // First Matrix Data
					cout << "Please enter the size of the Matrix A\n";
					cout << "Rows: "; cin >> rows1;
					cout << "Columns: "; cin >> cols1;
					if (rows1 == cols1) {
						size1 = rows1;
						cout << "Size: " << size1 << "\n\n";
					}
					if (rows1 != cols1) {
						cout << "Size: " << rows1 << " x " << cols1 << "\n\n";
					}
				} while (rows1 > 10 || cols1 > 10 || rows1 <= 0 || cols1 <= 0);
				cout << "Now enter the elements of the Matrix one by one\n";
				input_matrix(matrix_1, cols1, rows1);
			}

			if (mat == 2) {
				do {                    // Second Matrix Data
					cout << "Please enter the size of the Matrix B\n";
					cout << "Rows: "; cin >> rows2;
					cout << "Columns: "; cin >> cols2;
					if (rows2 == cols2) {
						size2 = rows2;
						cout << "Size: " << size2 << "\n\n";
					}
					if (rows2 != cols2) {
						cout << "Size: " << rows2 << " x " << cols2 << "\n\n";
					}
				} while (rows2 > 10 || cols2 > 10 || rows2 <= 0 || cols2 <= 0);
				cout << "Now enter the elements of the Matrix one by one\n";
				input_matrix(matrix_2, cols2, rows2);
			}
			break;

		case 2:
			matrix();
			if (rows1 == 0 || cols1 == 0) {
				cout << "You chose not to enter Matrix A so you cannot perform this Operation.";
				delay();
			}
			else {
				cout << "\tMatrix A\n\n";
				print_matrix(matrix_1, cols1, rows1);
				delay();
			}
			break;

		case 3:
			matrix();
			if (rows2 == 0 || cols2 == 0) {
				cout << "You chose not to enter Matrix B so you cannot perform this Operation.";
				delay();
			}
			else {
				cout << "\tMatrix B\n\n";
				print_matrix(matrix_2, cols2, rows2);
				delay();
			}
			break;

		case 4:
			matrix();
			if (rows1 != cols1) {
				cout << check_error_determinant(cols1, rows1);
				delay();
			}
			else {
				print_matrix(matrix_1, cols1, rows1);
				cout << "\n\nDeterminant of Matrix A = " << matrix_determinant(matrix_1, size1);
				delay();
			}
			break;

		case 5:
			matrix();
			if (rows2 == 0 || cols2 == 0) {
				cout << "You chose not to enter Matrix B so you cannot perform this Operation.";
				delay();
			}
			else if (rows2 != cols2) {
				cout << check_error_determinant(cols2, rows2);
				delay();
			}
			else {
				print_matrix(matrix_2, cols2, rows2);
				cout << "\n\nDeterminant of Matrix B = " << matrix_determinant(matrix_2, size2);
				delay();
			}
			break;

		case 6:
			matrix();
			matrix_transpose(matrix_1, ans, cols1, rows1);
			delay();
			break;

		case 7:
			matrix();
			if (rows2 == 0 || cols2 == 0) {
				cout << "You chose not to enter Matrix B so you cannot perform this Operation.";
				delay();
			}
			else {
				matrix_transpose(matrix_2, ans, cols2, rows2);
				delay();
			}
			break;


		case 8:
			matrix();
			if (rows1 != rows2 || cols1 != cols2) {
				cout << check_error_sum(cols1, rows1, cols2, rows2);
				delay();
			}
			else {
				matrix_sum(matrix_1, matrix_2, ans, rows1, cols1);
				delay();
			}
			break;

		case 9:
			matrix();
			if (rows1 != rows2 || cols1 != cols2) {
				cout << check_error_sum(cols1, rows1, cols2, rows2);
				delay();
			}
			else {
				matrix_difference(matrix_1, matrix_2, ans, rows1, cols1);
				delay();
			}
			break;

		case 10:
			matrix();
			if (cols1 != rows2) {
				cout << check_error_product(cols1, rows2);
				delay();
			}
			else {
				matrix_product(matrix_1, matrix_2, product, cols2, rows1);
				delay();
			}
			break;

		case 11:
			matrix();
			matrix_inverse(matrix_2, ans, inverse_operation, size2);
			matrix_product(matrix_1, inverse, product, inverse_size, rows1);
			
			delay();
			break;
			
		case 12:
			matrix();
			cout << "Are you sure you want to Quit the Program?\n";
			cout << "\t( y / n )\n\n";
			cout << "Your choice is => ";
			cin >> yes_no;
			if (yes_no == "y") {
				matrix();
				cout << "Quitting.....\n";
				Sleep(3000);
				return 0;
			}
			else if (yes_no == "n") {
				break;
			}
		}
	} while (1 <= choice < 12);
	return 0;
}


                                    //Function Definitions


// To take the the input of the matrix
void input_matrix(double v[max_rows][max_cols], int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> v[row][col];
			system("CLS");
			cout << "\t\t\t\t\t\t Matrix Calculator\n";
			cout << "\t\t\t\t\t\t------------------\n\n";
		}
	}
}


// To print the matrix
void print_matrix(double v[max_rows][max_cols], int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << "\t" << v[row][col] << "\t|";
		}
		if (row < (rows - 1)) {
			cout << endl;
		}
		else {
			cout << "";
		}
		//cout << endl;
	}
}


// Transpose function
void matrix_transpose(const double v[max_rows][max_cols], double t[max_rows][max_cols],int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			t[col][row] = v[row][col];
		}
	}

	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			cout << "\t" << t[col][row] << "\t|";
		}

		cout << endl;

	}
}


// To calculate the sum
void matrix_sum(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			c[row][col] = a[row][col] + b[row][col];
			cout << "\t" << c[row][col] << "\t|";
		}
		if (row < (rows - 1)) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}


// To calculate the difference
void matrix_difference(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			c[row][col] = a[row][col] - b[row][col];
			cout << "\t" << c[row][col] << "\t|";
		}
		cout << endl;
	}
}


// To calculate the product of 2 matrices obtained from the user.
void matrix_product(const double a[max_rows][max_cols], const double b[max_rows][max_cols], double c[max_rows][max_cols], int cols, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			for (int mult = 0; mult <= cols; mult++) {
				c[row][col] += a[row][mult] * b[mult][col];
			}
		}
	}

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << "\t\t" << setprecision(3) << c[row][col] << "\t\t|";
		}
		cout << endl;
	}

}



// To calculate the determinant of a matrix.
double matrix_determinant(double a[max_rows][max_cols], int size) {


	double det = 0;
	double submatrix[max_rows][max_cols];


	if (size == 2)
		return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
	else {
		for (int x = 0; x < size; x++) {
			int subi = 0;
			for (int i = 1; i < size; i++) {
				int subj = 0;
				for (int j = 0; j < size; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}

			det = det + (pow(-1, x) * a[0][x] * matrix_determinant(submatrix, size - 1));
		}
	}

	return det;
}

// To calculate inverse matrix using Guass Jordan row operation method
void matrix_inverse(const double a[max_rows][max_cols],double c[max_rows][max_cols], double operation[max_rows][max_cols], int size) {

	double ratio = 0;
	inverse_size = size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			operation[i][j] = a[i][j];
		}
	}

	if (size == 0) {
		cout << "You cannot perform this Matematical Operation, as Matrix B isn't a square matrix.\n";
	}


	else {
		//Augmenting identity matrix
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) {
					operation[i][j + size] = 1;
				}
				else {
					operation[i][j + size] = 0;
				}
			}
		}

		//Applying Guass Jordan Elimination
		for (int i = 0; i < size; i++) {

			if (operation[i][i] == 0) {
				cout << "Mathematical Error!\n";
				delay();
				return;
			}

			for (int j = 0; j < size; j++) {
				if (i != j) {
					ratio = operation[j][i] / operation[i][i];
					for (int k = 0; k < 2 * size; k++) {
						operation[j][k] = operation[j][k] - ratio * operation[i][k];
					}
				}
			}
		}

		//Row operation to make principal diagonal equals 1
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 2 * size; j++) {
				c[i][j] = operation[i][j] / operation[i][i];
			}
		}

		//Saving the inverse in a global array to perform operations on it
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 2 * size; j++) {
				inverse[i][j] = c[i][j + size];
			}
		}

	}
}

void show_menu() {
	string menu[12];
	menu[0] = "1.Edit Matrix";
	menu[1] = "2.Show Matrix A";
	menu[2] = "3.Show Matrix B";
	menu[3] = "4.Determinant A";
	menu[4] = "5.Determinant B";
	menu[5] = "6.Transpose of A: C = A'";
	menu[6] = "7.Transpose of B: C = B'";
	menu[7] = "8.Addition: C = A + B";
	menu[8] = "9.Difference: C = A - B";
	menu[9] = "10.Multiplication: C = A * B";
	menu[10] = "11.Division: C = A/B";
	menu[11] = "12.Quit";


	for (int i = 0; i < 12; i++) {
		cout << menu[i] << "\n";
	}

	cout << endl;
	cout << "Please choose a number: ";
}

void matrix() {
	system("CLS");
	cout << "\t\t\t\t\t\t Matrix Calculator\n";
	cout << "\t\t\t\t\t\t------------------\n\n";
}

void delay() {
	cout << "\n\nYou can perform another Operation in 3 seconds.";
	Sleep(3500);

	for (int i = 0; i < max_rows; i++) {
		for (int j = 0; j < max_rows; j++) {
			ans[i][j] = 0;
		}
	}

	for (int i = 0; i < max_rows; i++) {
		for (int j = 0; j < max_rows; j++) {
			product[i][j] = 0;
		}
	}

	for (int i = 0; i < max_rows; i++) {
		for (int j = 0; j < max_rows; j++) {
			inverse[i][j] = 0;
		}
	}

	for (int i = 0; i < max_rows; i++) {
		for (int j = 0; j < max_rows; j++) {
			inverse_operation[i][j] = 0;
		}
	}
}


                                  // Error messages to be displayed.

string check_error_sum(int cols1, int rows1, int cols2, int rows2) {
	string error = "\nError. You cannot perform this Mathematical Operation.";
	if (cols1 != cols2 || rows1 != rows2)
		return error;
}


string check_error_product(int cols1, int rows2) {
	string error = "\nError. You cannot perform this Mathematical Operation.";
	if (cols1 != rows2)
		return error;
}


string check_error_determinant(int cols1, int rows1) {
	string error = "\nError. You cannot perform this Mathematical Operation because it is not a Square Matrix.";
	if (cols1 != rows1)
		return error;
}
