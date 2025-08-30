#include <iostream> 																		// Easy Access to Input and Output Operations

using namespace std; 																		// So we don't have to write "std::" before every library feature (like cout, cin, endl, etc.)

class TwoDMatrix { 																			// Defining the TwoDMatrix Class
private:
    int** matrix; 																			// Data Member to hold the 2D array (matrix)
    int row; 																				// Number of rows in the matrix
    int col; 																				// Number of columns in the matrix

public:
    // Constructor to initialize the matrix
    TwoDMatrix(int row, int col) : row(row), col(col) { 									// Parameterized Constructor
        cout << "Matrix Initialized!" << endl; 												// Print message when matrix is initialized
        matrix = new int*[row]; 															// Allocate memory for the rows
        for (int i = 0; i < row; ++i) { 													// Loop through rows
            matrix[i] = new int[col]{0}; 													// Initialize each column with 0
        }
    }

    // Destructor to deallocate memory
    ~TwoDMatrix() { 																		// Destructor to free up memory when the object is destroyed
        for (int i = 0; i < row; i++) { 													// Loop through each row
            delete[] matrix[i]; 															// Deallocate memory for each row
        }
        delete[] matrix; 																	// Deallocate the memory for the matrix itself
    }

    // Function to resize the matrix
    void ResizingMatrix(int newRow, int newCol, int value) { 								// Resizes the matrix to new dimensions
        if (row == newRow && col == newCol) return; 										// No resizing needed if the dimensions are the same
        else {
            // Resize when the new size is smaller
            if (row > newRow || col > newCol) { 											// If the new size is smaller, resize accordingly
                int** temp = new int*[newRow]; 												// Allocate memory for the new matrix
                for (int i = 0; i < newRow; i++) { 											// Loop through the rows
                    temp[i] = new int[newCol]; 												// Allocate memory for the columns
                }
                // Copy the old matrix to the new matrix
                for (int i = 0; i < newRow; i++) { 											// Loop through the rows of the new matrix
                    for (int j = 0; j < newCol; j++) { 										// Loop through the columns of the new matrix
                        temp[i][j] = matrix[i][j]; 											// Copy each element
                    }
                }
                // Deallocate old matrix
                for (int i = 0; i < row; i++) { 											// Loop through the rows
                    delete[] matrix[i]; 													// Free the memory for each row
                }
                delete[] matrix; 															// Free the memory for the entire matrix
                // Update matrix pointer and sizes
                row = newRow; 																// Update row size
                col = newCol; 																// Update column size
                matrix = temp; 																// Update the matrix pointer to the new matrix
                return; 																	// End of function
            }
            // Resize when the new size is larger, initialize with the given value
            if (row < newRow || col < newCol) { 											// If the new size is larger, initialize new cells with a given value
                int** temp = new int*[newRow]; 												// Allocate memory for the new matrix
                for (int i = 0; i < newRow; i++) { 											// Loop through the rows
                    temp[i] = new int[newCol]; 												// Allocate memory for the columns
                    // Initialize new cells with the given value
                    for (int j = 0; j < newCol; j++) { 										// Loop through the columns
                        temp[i][j] = value; 												// Set the value for the new cell
                    }
                }
                // Copy the old matrix to the new matrix
                for (int i = 0; i < row; i++) { 											// Loop through the rows of the old matrix
                    for (int j = 0; j < col; j++) { 										// Loop through the columns of the old matrix
                        temp[i][j] = matrix[i][j]; 											// Copy each element
                    }
                }
                // Deallocate old matrix
                for (int i = 0; i < row; i++) { 											// Loop through the rows
                    delete[] matrix[i]; 													// Free the memory for each row
                }
                delete[] matrix; 															// Free the memory for the entire matrix
                // Update matrix pointer and sizes
                row = newRow; 																// Update row size
                col = newCol; 																// Update column size
                matrix = temp; 																// Update the matrix pointer to the new matrix
                return; 																	// End of function
            }
        }
    }

    // Function to transpose the matrix
    void Transpose() { 																		// Transpose the matrix (rows become columns and vice versa)
        int** transposed = new int*[col]; 													// Allocate memory for the transposed matrix
        for (int i = 0; i < col; i++) { 													// Loop through the columns of the original matrix
            transposed[i] = new int[row]; 													// Allocate memory for the rows of the transposed matrix
        }

        // Transpose the matrix
        for (int i = 0; i < row; i++) { 													// Loop through the rows of the original matrix
            for (int j = 0; j < col; j++) { 												// Loop through the columns of the original matrix
                transposed[j][i] = matrix[i][j]; 											// Swap the elements (i,j) with (j,i)
            }
        }

        // Deallocate old matrix
        for (int i = 0; i < row; i++) { 													// Loop through the rows
            delete[] matrix[i]; 															// Free the memory for each row
        }
        delete[] matrix; 																	// Free the memory for the entire matrix

        // Update matrix and row/col sizes
        matrix = transposed; 																// Update the matrix pointer to the transposed matrix
        int temp = row; 																	// Swap the row and column sizes
        row = col;
        col = temp; 																		// Swap rows and columns for the transposed matrix
    }

    // Function to print the matrix
    void PrintMatrix() { 																	// Print the matrix to the console
        for (int i = 0; i < row; i++) { 													// Loop through the rows
            for (int j = 0; j < col; j++) { 												// Loop through the columns
                cout << matrix[i][j] << " "; 												// Print each element
            }
            cout << endl; 																	// Print a new line after each row
        }
    }

    // Function to set values in the matrix
    void SetValue() { 																		// Set the value of each element in the matrix
        for (int i = 0; i < row; i++) { 													// Loop through the rows
            for (int j = 0; j < col; j++) { 												// Loop through the columns
                cout << "Enter Value for [" << i << "][" << j << "] : "; 					// Prompt user for input
                cin >> matrix[i][j]; 														// Get the input from the user
            }
            cout << endl; 																	// Print a new line after each row
        }
    }

    // Function to add 2 to each odd index element and print
    void AddTwoToOddIndex() { 																// Add 2 to elements at odd indices
        for (int i = 0; i < row; i++) { 													// Loop through the rows
            for (int j = 0; j < col; j++) { 												// Loop through the columns
                if ((i + j) % 2 != 0) { 													// Odd index position
                    matrix[i][j] += 2; 														// Add 2 to the element
                }
            }
        }
    }

//    // Filler function to initialize the matrix with increasing values
//    void Filler() { 																		// Initialize the matrix with increasing values starting from 10
//        int value = 10; 																	// Start with 10
//        for (int i = 0; i < row; i++) { 													// Loop through the rows
//            for (int j = 0; j < col; j++) { 												// Loop through the columns
//                matrix[i][j] = value; 														// Set the value for each element
//                value += 10; 																// Increase the value by 10 for the next element
//            }
//        }
//    }
};

// Function to handle input validation for row and column values
void GetValidInput(int &row, int &col) { 													// Validate the row and column input
    while (true) {
        cout << "Rows: "; 																	// Prompt user for the number of rows
        cin >> row; 																		// Get the input
        cout << "Columns: "; 																// Prompt user for the number of columns
        cin >> col; 																		// Get the input

        if (row <= 0 || col <= 0) { 														// Check if the input is invalid
            cout << "Invalid input! Rows and Columns must be positive integers." << endl;
            cout << "Please enter again!" << endl; 											// Ask user to re-enter the values
        } else {
            break; 																			// Exit the loop if the input is valid
        }
    }
}

int main() {
    int row = 0, col = 0;

    // Get valid input for rows and columns
    cout << "Enter the number of Rows and Columns:" << endl;
    GetValidInput(row, col);

    // Create the TwoDMatrix object
    TwoDMatrix matrix(row, col);
    matrix.SetValue(); 																		// Set values for the matrix

    // Menu loop for operations
    int choice;
    do {
        cout << endl<<"Menu :"<<endl;
        cout << "1. Print Matrix" <<endl;
        cout << "2. Resize Matrix "<< endl;
        cout << "3. Add 2 to each odd index element" << endl;
        cout << "4. Transpose Matrix" << endl;
        cout << "5. Exit" <<endl;
        cout << "Enter your choice (1-5): "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl << "Matrix:" << endl;
                matrix.PrintMatrix(); 														// Print the matrix
                break;

            case 2: {
                int newRow, newCol, value;
                cout << "Enter new number of rows: "; 										// Prompt user for new rows
                cin >> newRow;
                cout << "Enter new number of columns: "; 									// Prompt user for new columns
                cin >> newCol;
                cout << "Enter the value to initialize new cells: "; 						// Prompt user for value to initialize new cells
                cin >> value;
                if (newRow <= 0 || newCol <= 0) { 											// Check if the new size is invalid
                    cout << "Invalid Size!" << endl;
                    break;
                }
                matrix.ResizingMatrix(newRow, newCol, value); 								// Resize the matrix
                break;
            }

            case 3:
                matrix.AddTwoToOddIndex(); 													// Add 2 to odd index elements
                cout << "Matrix after adding 2 to odd index positions:"<<endl;
                matrix.PrintMatrix(); 														// Print the updated matrix
                break;

            case 4:
                matrix.Transpose(); 														// Transpose the matrix
                cout << "Matrix after transpose:"<<endl;
                matrix.PrintMatrix(); 														// Print the transposed matrix
                break;

            case 5:
                cout << "Exiting program..."<<endl; 										// Exit the program
                break;

            default:
                cout << "Invalid choice! Please try again."<<endl; 							// Invalid menu choice
                break;
        }
    } while (choice != 5);

    return 0;
}
