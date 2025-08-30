#include <iostream> 																			// Easy Access to Input and Output Operations

using namespace std; 																			// So we don't have to write "std::" before every library feature (like cout, cin, endl, etc.)

class Student { 																				// Defining the Student class
private:
    int id; 																					// Student ID
    double* marks; 																				// Pointer to store marks for subjects
    const int subjects = 5; 																			// Number of subjects (fixed to 5 as per the task)
    static int studentcount; 																	// Static variable to keep track of the student count across all instances

public:
    // Default constructor for Student class
    Student() : id(studentcount++) { 															// Initialize student ID with the static counter
        marks = new double[subjects]; 															// Dynamically allocate memory for marks array
    }

    // Destructor to deallocate memory
    ~Student() { 																				// Destructor to delete dynamically allocated marks array
        delete[] marks; 																		// Delete the dynamically allocated marks array
    }

    // Function to set marks for the student
    void setmarks() { 																			// Set the marks for the student
        cout << "Enter Marks for Student " << id  << " : " << endl; 							// Prompt user to enter marks for the student
        for (int i = 0; i < subjects; i++) { 													// Loop through each subject
            cout << "Subject [" << i + 1 << "]: "; 												// Display the subject number
            cin >> marks[i]; 																	// Take input for marks
            if (marks[i] < 0) marks[i] = 0; 													// Ensure no negative marks
        }
    }

    // Function to calculate and return the average marks of the student
    double getAverage() { 																		// Calculate average marks
        double sum = 0; 																		// Variable to store the sum of marks
        for (int i = 0; i < subjects; i++) { 													// Loop through all subjects
            sum += marks[i]; 																	// Add marks to the sum
        }
        return sum / subjects; 																	// Return the average marks
    }

    // Function to get the highest mark of the student
    double getHighest() { 																		// Get the highest mark
        double highest = marks[0]; 																// Start with the first subject's mark
        for (int i = 1; i < subjects; i++) { 													// Loop through all subjects
            if (marks[i] > highest) { 															// Update the highest mark
                highest = marks[i];
            }
        }
        return highest; 																		// Return the highest mark
    }

    // Function to get the lowest mark of the student
    double getLowest() { 																		// Get the lowest mark
        double lowest = marks[0]; 																// Start with the first subject's mark
        for (int i = 1; i < subjects; i++) { 													// Loop through all subjects
            if (marks[i] < lowest) { 															// Update the lowest mark
                lowest = marks[i];
            }
        }
        return lowest; 																			// Return the lowest mark
    }

    // Function to auto-fill marks (filler function)
    //void filler() { 																			// Auto-fill marks with dummy values
    //    double value = 10.0; 																	// Set starting mark for each subject
    //    for (int i = 0; i < subjects; i++) { 													// Loop through each subject
    //        marks[i] = value; 																	// Assign value to each subject
    //        value += 10; 																		// Increment value for the next subject
    //    }
    //}
};

// Static variable initialization
int Student::studentcount = 1; 																	// Initialize static student count to 0

class Department { 																				// Defining the Department class
private:
    int deptid; 																				// Department ID
    Student* students; 																			// Pointer to dynamically store students in the department
    int numstudent; 																			// Number of students in the department
    static int deptcount; 																		// Static variable to keep track of department count

public:
    // Constructor for Department class (no parameters)
    Department() : deptid(deptcount++) { 														// Initialize department ID with static counter
        cout << "Enter the number of students for Department " << deptid  << ": "; 				// Prompt user for number of students in this department
        cin >> numstudent; 																		// Get the number of students
        if (numstudent <= 0) { 																	// If invalid (less than or equal to 0)
            numstudent = 0; 																	// Set to 0 students
        }
        students = new Student[numstudent]; 													// Dynamically allocate memory for students in the department
    }

    // Destructor to deallocate memory
    ~Department() { 																			// Destructor to delete dynamically allocated students array
        delete[] students;																		// Delete the dynamically allocated students array
    }

    // Function to set marks for all students in the department
    void setMarksForAllStudents() { 															// Set marks for all students in the department
        for (int i = 0; i < numstudent; i++) { 													// Loop through all students
			cout << "Enter Marks for Students in Department " << deptid  << " : " << endl;		// Department-wise prompt
			students[i].setmarks();
        	//students[i].filler(); 															// Auto-fill marks for each student (or replace with setmarks() for manual entry)
        }
    }

    // Function to print department results
    void printDepartmentResults() { 															// Print the results of all students in the department
        double highest = students[0].getHighest(); 												// Start with the first student's highest mark
        double lowest = students[0].getLowest(); 												// Start with the first student's lowest mark
        double totalAverage = 0; 																// Variable to store total average of the department

        for (int i = 0; i < numstudent; i++) { 													// Loop through all students
            totalAverage += students[i].getAverage(); 											// Add the average of each student to total average
            if (students[i].getHighest() > highest) { 											// Find the highest mark in the department
                highest = students[i].getHighest();
            }
            if (students[i].getLowest() < lowest) { 											// Find the lowest mark in the department
                lowest = students[i].getLowest();
            }
        }
        cout << "Department " << deptid << " Results:" << endl; 								// Display department results
        cout << "Highest Mark in Department: " << highest << endl; 								// Print highest mark in the department
        cout << "Lowest Mark in Department: " << lowest << endl; 								// Print lowest mark in the department
        cout << "Average Marks in Department: " << totalAverage / numstudent << endl; 			// Print average marks of the department
    }
};

// Static variable initialization
int Department::deptcount = 1; 																	// Initialize static department count to 0

class University { 																				// Defining the University class
private:
    Department* departments; 																	// Pointer to hold multiple departments in the university
    int numDepartments; 																		// Number of departments in the university

public:
    // Constructor to initialize the University with departments
    University(int numDepts) : numDepartments(numDepts) { 										// Initialize the number of departments
        departments = new Department[numDepts]; 												// Dynamically allocate memory for departments
        for (int i = 0; i < numDepts; i++) { 													// Loop through all departments
            cout << "Enter Students for Department " << i + 1 << " : " << endl; 				// Prompt user for students in each department
            departments[i].setMarksForAllStudents(); 											// Set marks for all students in the department
        }	
    }

    // Destructor to deallocate memory
    ~University() { 																			// Destructor to free memory for departments
        delete[] departments; 																	// Delete the dynamically allocated departments array
    }

    // Function to calculate and display results for all departments
    void displayUniversityResults() { 															// Display results of all departments in the university
        for (int i = 0; i < numDepartments; i++) { 												// Loop through all departments
            departments[i].printDepartmentResults(); 											// Print results for each department
        }
    }
};

int main() { 																					// Main function where the menu and program logic resides
    int numDepartments; 																		// Variable to store the number of departments
    cout << "Enter number of departments: "; 													// Prompt user for number of departments
    cin >> numDepartments; 																		// Get the number of departments

    University university(numDepartments); 														// Create a University object with the specified number of departments

    // Menu loop for operations
    int choice;
    do {
        cout << endl<<"Menu:"<<endl;
        cout << "1. Display University Results"<<endl;  										// Option to display results of the university
        cout << "2. Exit"<<endl;  																// Option to exit the program
        cout << "Enter your choice (1-2): ";
        cin >> choice;

        switch (choice) {  																		// Switch case for menu options
            case 1:
                university.displayUniversityResults();  										// Display results of all departments in the university
                break;

            case 2:
                cout << "Exiting program..."<<endl;  											// Exit the program
                break;

            default:
                cout << "Invalid choice! Please try again."<<endl;  							// Invalid menu choice
                break;
        }
    } while (choice != 2); 																		// Continue until the user chooses to exit

    return 0; 																					// End of program
}
