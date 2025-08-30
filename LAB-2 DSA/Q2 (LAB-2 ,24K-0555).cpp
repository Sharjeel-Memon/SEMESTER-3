#include <iostream> 																		// Easy Access to Input and Output Operations

using namespace std; 																		// So we dont have to write "std::" before every library feature (like cout, cin, endl, etc.)

int main() {
	
	int row; 																				// Declare row variable to store number of students
	int col; 																				// Declare col variable to store number of subjects

	// Prompt user for input
	cout << "Enter Number of rows :"; 														// Prompt user for the number of rows (students)
	cin >> row; 																			// Store the user input in the row variable
	
	cout << "Enter Number of Columns :"; 													// Prompt user for the number of columns (subjects)
	cin >> col; 																			// Store the user input in the col variable
	
	// Dynamically allocate memory for student marks
	int** arr = new int*[row]; 																// Dynamically allocate memory for 2D array to store student marks
	int* total = new int[row]; 																// Dynamically allocate memory for total marks of each student
	int* subavg = new int[col]; 															// Dynamically allocate memory for sum of marks for each subject

	// Allocate memory for each student’s subjects
	for(int i = 0; i < row; i++) { 															// Loop through rows (students)
		arr[i] = new int[col]; 																// Dynamically allocate memory for columns (subjects) for each student
	}

	// Initialize total array to zero for each student
	for(int i = 0; i < row; i++) { 															// Initialize total marks for each student
		total[i] = 0; 																		// Set total marks of each student to 0 initially
	}

	// Initialize subavg array to zero for each subject
	for(int i = 0; i < col; i++) { 															// Initialize total for each subject
		subavg[i] = 0; 																		// Set sum of each subject's marks to 0 initially
	}
		
/*	//Only for Quick Testing
	int filler=10;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			arr[i][j] =filler;
			filler   += 10;
		}
	}
	
*/

	// Input marks for each student
	cout << "Enter the values :" << endl; 													// Prompt user to enter the marks for each student
	for(int i = 0; i < row; i++) { 															// Loop through each student (row)
		for(int j = 0; j < col; j++) { 														// Loop through each subject (column)
			cout << "Enter Value for [" << i << "][" << j << "] Term : "; 					// Prompt user to enter marks for each student in each subject
			cin >> arr[i][j]; 																// Store the entered value into the array
			if(arr[i][j]<0 ) arr[i][j]=0;
		}
		cout << endl; 																		// Move to the next line after entering marks for all subjects of a student
	}
	
	// Calculate total marks for each student
	for(int i = 0; i < row; i++) { 															// Loop through each student (row)
		for(int j = 0; j < col; j++) { 														// Loop through each subject (column)
			total[i] += arr[i][j]; 															// Add the marks for each subject to the student's total
		}
	}
	
	// Output total marks for each student
	for(int i = 0; i < row; i++) { 															// Loop through each student
		cout << "The total of " << i + 1 << " Student : " << total[i] << endl; 				// Output the total marks of each student
	}
	cout << endl; 																			// Print a newline for better readability
	
	// Find the highest total marks among students
	int highest = total[0]; 
	int topperStudent = 0;  // Variable to store the topper student
	for (int i = 0; i < row; i++) {
    if (total[i] > highest) {																// Checking for Highest
        highest = total[i];  
        topperStudent = i;  // Update the topper student
    }
}
	cout << "The Topper Student is " << topperStudent + 1 << " with the Highest Marks: " << highest << endl;


	
	// Output the average marks of each subject
	cout << "The Average Marks of each Subject are :" << endl; 								// Output header for average marks
	for(int i = 0; i < row; i++) { 															// Loop through each student (row)
		for(int j = 0; j < col; j++) { 														// Loop through each subject (column)
			subavg[j] += arr[i][j]; 														// Add each student's marks for a subject to the subject's total
		}	
	}
	
	
	// Output average marks for each subject
	for(int i = 0; i < col; i++) { 															// Loop through each subject (column)
		subavg[i] = subavg[i] / row; 														// Calculate average by dividing the total marks for a subject by the number of students
		cout << "The Average Mark of " << i + 1 << " Subject is : " << subavg[i] << endl; 	// Output the average marks for each subject
	}
	
	// Free the dynamically allocated memory
	for(int i = 0; i < row; i++) { 															// Loop through each row (student)
		delete[] arr[i]; 																	// Deallocate memory for each student's subject marks
	}
	delete[] arr; 																			// Deallocate memory for the array of student rows
	delete[] total; 																		// Deallocate memory for the total marks array
	delete[] subavg; 																		// Deallocate memory for the subject averages array

	return 0; 																				// End of program
}
