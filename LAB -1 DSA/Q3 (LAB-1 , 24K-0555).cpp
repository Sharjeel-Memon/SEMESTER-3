#include <iostream> 																		// Easy Access to Input and Output Operations

using namespace std; 																		// So we don't have to write "std::" before every library feature (like cout, cin, endl, etc)

class Box { 																				// Defining the Box Class

	private :																				// Access Modifier, private, makes member accessible only inside the class
		int* BoxSize; 																		// Data Member: dynamically allocated memory for BoxSize

	public  :																				// Access Modifier, public, allows functions to be accessible from outside

	// Constructors

	Box() : BoxSize(new int(0)) { 															// Default Constructor - Initializes BoxSize with 0 if no parameter is passed
		cout << "Box Created with default size!" << endl;									// Message when the box is created
	}

	Box(int size) : BoxSize(new int(size)) { 												// Parameterized Constructor - Initializes BoxSize with the given size
		cout << "Box Created with size " << *BoxSize << endl;								// Message when the box is created with a specified size
	}

	Box(const Box &other, bool deepCopy = true) { 											// Copy Constructor - Used to Create a copy of another Object
		if (deepCopy) {
			BoxSize = new int(*(other.BoxSize));											// Deep copy: allocating new memory and copying the value of BoxSize
			cout << "Box Created by copying with size " << *BoxSize << endl;				// Message when a box is created by copying another box
		} else {
			BoxSize = other.BoxSize;														// Shallow copy: both objects point to the same memory
			cout << "Box Created by shallow copying with size " << *BoxSize << endl;		// Message when a box is created by shallow copying another box
		}
	}

	// Methods

	void setBoxSize(int size) { 															// Method to set the size of the Box
		*BoxSize = size; 																	// Assigning the given size to BoxSize
	}

	int getBoxSize() const { 																// Getter Method - Allows main to Access the Private Member
		return *BoxSize; 																	// Returning the size of the Box
	}

	// Copy Assignment Operator - Used to assign values from one object to another
	Box& operator=(const Box& other) { 														// Assignment operator to handle assignment between two Box objects
		bool deepCopy = true; 																// Set to true for deep copy, false for shallow copy
		if (this != &other) { 																// Check for self-assignment
			delete BoxSize; 																// Free the existing memory
			if (deepCopy) {
				BoxSize = new int(*(other.BoxSize)); 										// Perform deep copy
				cout << "Box Assigned with size " << *BoxSize << endl;						// Message after deep copy assignment
			} else {
				BoxSize = other.BoxSize; 													// Perform shallow copy
				cout << "Box Assigned by shallow copy with size " << *BoxSize << endl;		// Message after shallow copy assignment
			}
		}
		return *this; 																		// Returning the current object
	}

	// Destructor
	~Box() { 																				// Destructor to free dynamically allocated memory
		delete BoxSize; 																	// Free memory for BoxSize
		cout << "Box Destroyed" << endl; 													// Message when the box is destroyed
	}

};

int main() {

	// Deep Copy Example (Copy Constructor with deepCopy = true)
	cout << "---- Deep Copy Example ----" << endl;
	Box box1(10); 																			// Will initialize with BoxSize 10
	Box box2(box1, true); 																	// Deep copy using the flag (true for deep copy)
	box2.setBoxSize(20); 																	// Modify box2
	cout << "Box1 Size: " << box1.getBoxSize() << endl; 									// Should remain 10
	cout << "Box2 Size: " << box2.getBoxSize() << endl << endl; 							// Should be 20

	// Shallow Copy Example (Copy Constructor with deepCopy = false)
	cout << "---- Shallow Copy Example ----" << endl;
	Box box3(30);																			// Will Initialize with BoxSize 30
	Box box4(box3, false); 																	// Shallow copy using the flag (false for shallow copy)
	box4.setBoxSize(40); 																	// Modify box4
	cout << "Box3 Size: " << box3.getBoxSize() << endl; 									// Should change to 40 (shared memory)
	cout << "Box4 Size: " << box4.getBoxSize() << endl << endl; 							// Should also be 40 (shared memory)

	// Copy Assignment Example (Deep Copy)
	cout << "---- Copy Assignment Example (Deep Copy) ----" << endl;
	Box box5(50);
	box5 = box1; 																			// Deep copy using the assignment operator
	cout << "Box5 Size: " << box5.getBoxSize() << endl << endl; 							// Should be 10

	// Copy Assignment Example (Shallow Copy)
	cout << "---- Copy Assignment Example (Shallow Copy) ----" << endl;
	Box box6(60);
	box6 = box3; 																			// Shallow copy using the assignment operator (box3 and box6 will share memory)
	box6.setBoxSize(70); 																	// Modify box6
	cout << "Box3 Size: " << box3.getBoxSize() << endl; 									// Should be 70 (shared memory with box6)
	cout << "Box6 Size: " << box6.getBoxSize() << endl << endl; 							// Should be 70

	return 0; 																				// End of Program
}
