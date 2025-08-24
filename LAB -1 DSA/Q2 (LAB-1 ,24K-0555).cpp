#include <iostream> 																		// Easy Access to Input and Output Operations
#include <cstring>																			//  Easy Access to Built-in String operations

using namespace std; 																		// So we don't have to write "std::" before every library feature (like cout, cin, endl, etc)

class Exam { 																				// Defining the Exam Class

    private: 																				// Access Modifier: private, makes member accessible only inside the class
        char* name; 																		// Data Member: dynamically allocated memory for student name
        char* date; 																		// Data Member: dynamically allocated memory for exam date
        int score; 																			// Data Member: storing exam score

    public: 																				// Access Modifier: public, allows functions to be accessible from outside

    // Setters
    void setScore(int x ) { 																// Method to set exam score
        score = x ; 																		// Assign new score
    }

    void setDate(const char* x ) { 															// Method to set exam date
        strcpy(date, x ); 																	// Copy new date into allocated memory
    }

    void setName(const char* x) { 															// Method to set student's name
        if (name != nullptr) { 																// If memory already allocated, free it
        delete[] name; 																		// Free old memory before setting new name
        }
        name = new char[strlen( x ) + 1]; 													// Allocate memory for new name
        strcpy(name, x ); 																	// Copy new name into allocated memory
    }

    // Constructors
    Exam(const char* x, const char* y, int z) { 											// Parameterized Constructor
        name = new char[strlen( x ) + 1]; 													// Allocating memory for the student name
        strcpy(name, x ); 																	// Copying student name into the allocated memory
        date = new char[strlen( y ) + 1]; 													// Allocating memory for the exam date
        strcpy(date, y ); 																	// Copying exam date into the allocated memory
        score = z; 																			// Assigning the exam score
        cout << "Exam Initialized!" << endl<<endl;											// Message when exam is initialized
    }

    // Display Method
    void displayDetails() const { 															// Method to display student's exam details
        cout << "Student: " << name << endl << "Exam Date: " << date << endl <<"Score: " << score << endl;  // Print details of the exam
    }
    
    // Destructor
    ~Exam() { 																				// Destructor to free dynamically allocated memory
        string cleanupMessage = (name) ? name : "Unknown OR Nullptr";  						// Prepare the cleanup message
        cout << "Cleaning up memory for: " << cleanupMessage << endl;  						// Display cleanup message
        delete[] name; 																		// Free memory for name
        delete[] date; 																		// Free memory for exam date
    }

};

int main() {

    // Creating Exam Object Using Parameterized Constructor
    cout << "----------------------------------" << endl;
    cout << "Creating Exam Object student1" << endl;
    Exam student1("Sharjeel Memon", "2025-05-30", 85); 										// Creates Exam object with initial values
    student1.displayDetails(); 																// Display the details of student1
    cout << endl;

    // Creating a Shallow Copy of student1
    cout << "----------------------------------" << endl;
    cout << "Creating a Shallow Copy of student1 into student2" << endl;
    Exam student2 = student1; 																// Creates student2 as a shallow copy of student1
    student2.displayDetails(); 																// Display the details of student2
    cout << endl;

    // Case Number 1: Shallow Copy Issue - Dangling Pointer
    cout << "----------------------------------" << endl;
    cout << "Case Number 1: Dangling Pointer Issue when name is changed" << endl;
    student2.setName("Muhammad Haneef"); 													// Changing the name of student2
    student2.displayDetails(); 																// Display student2's details after name change
    cout << "Student1 Details After student2 Name Change" << endl << endl;
    student1.displayDetails(); 																// student1 shows garbage value for the name (dangling pointer)
    cout << endl;

    // Case Number 2: Shared Memory Issue - Exam Date is shared
    cout << "----------------------------------" << endl;
    cout << "Case Number 2: Both objects share the same memory for exam date" << endl;
    student2.setDate("2025-06-15"); 														// Changing the exam date of student2
    student2.displayDetails();																// Display student2's details after changing the date
    cout << endl;
    
    cout << "Student1 Details After student2 Date Change" << endl;
    student1.displayDetails(); 																// student1's exam date also changes as they share the same memory
    cout << endl << endl;

    return 0; 																				// End of Program
}

