#include <iostream> 																		// Easy Access to Input and Output Operations

using namespace std; 																		// So we don't have to write "std::" before every library feature (like cout, cin, endl, etc)

class Box { 																				// Defining the Box Class

private:																					// Access Modifier, private, makes member accessible only inside the class
    int* BoxSize; 																			// Data Member: dynamically allocated memory for BoxSize
    bool deepCopy;																			// A flag for deep copy vs shallow copy (runtime controlled)

public:																						// Access Modifier, public, allows functions to be accessible from outside

    // Constructors

    Box() : BoxSize(new int(0)), deepCopy(true) { 											// Default Constructor - Initializes BoxSize with 0 if no parameter is passed
        cout << "Box Created with default size!" << endl;									// Message when the box is created
    }

    Box(int size) : BoxSize(new int(size)), deepCopy(true) { 								// Parameterized Constructor - Initializes BoxSize with the given size
        cout << "Box Created with size " << *BoxSize << endl;								// Message when the box is created with a specified size
    }

    // Copy Constructor
    Box(const Box &other) { 																// Copy Constructor - Used to Create a copy of another Object
        if (other.deepCopy) {
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

    // Setter for deepCopy flag (to change at runtime)
    void setDeepCopy(bool value) {
        deepCopy = value;																	// Allow modification of deepCopy flag at runtime
    }

    // Copy Assignment Operator
    Box& operator=(const Box& other) { 														// Assignment operator to handle assignment between two Box objects
        if (this != &other) { 																// Check for self-assignment
            delete BoxSize; 																// Free the existing memory
            if (other.deepCopy) {
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
    cout << "---- Deep Copy Example ----" << endl;
    Box box1(10); 																			// Will initialize with BoxSize 10
    cout << "Box1 (Initial) Size: " << box1.getBoxSize() << endl;							// Prints Box1's size

    Box box2(box1); 																		// Deep copy using the copy constructor (deepCopy is true by default)
    cout << "Box2 (After Deep Copy) Size: " << box2.getBoxSize() << endl;					// Should be 10, independent from Box1

    box2.setBoxSize(20); 																	// Modify box2's size
    cout << "Box1 Size (After Box2 Change): " << box1.getBoxSize() << endl;					// Should remain 10, no effect due to deep copy
    cout << "Box2 Size (After Change): " << box2.getBoxSize() << endl;						// Should be 20 (modified)

    cout << endl; 																			// New Line for clarity

    cout << "---- Shallow Copy Example ----" << endl;
    Box box3(30);																			// Will Initialize with BoxSize 30
    cout << "Box3 (Initial) Size: " << box3.getBoxSize() << endl;							// Prints Box3's size

    // Set deepCopy to false at runtime to demonstrate shallow copy
    box3.setDeepCopy(false);																// Change to shallow copy mode at runtime
    Box box4 = box3; 																		// Shallow copy using the copy constructor
    cout << "Box4 (After Shallow Copy) Size: " << box4.getBoxSize() << endl;				// Should be 30, both Box3 and Box4 point to the same memory

    box4.setBoxSize(40); 																	// Modify box4's size
    cout << "Box3 Size (After Box4 Change): " << box3.getBoxSize() << endl;					// Should also be 40, since they share memory
    cout << "Box4 Size (After Change): " << box4.getBoxSize() << endl << endl;				// Should be 40 (modified)

    // Copy Assignment Example (Deep Copy)
    cout << "---- Copy Assignment Example (Deep Copy) ----" << endl;
    Box box5(50);
    box5 = box1; 																			// Deep copy using the assignment operator
    cout << "Box5 Size (After Deep Copy Assignment): " << box5.getBoxSize() << endl;		// Should be 10
    box1.setBoxSize(40);																	// Changing Size to 40
    cout << "Box1 Size (After Change): " << box1.getBoxSize() << endl;						// Should be 40
	cout << "Box5 Size (After Changing Box1 Size): " << box5.getBoxSize() << endl << endl;  // Should still be 10 (deep copy)

    // Copy Assignment Example (Shallow Copy)
    cout << "---- Copy Assignment Example (Shallow Copy) ----" << endl;
    Box box6(60);
    box6.setDeepCopy(false); 																// Set shallow copy mode at runtime
    box6 = box3; 																			// Shallow copy using the assignment operator (box3 and box6 will share memory)
    box6.setBoxSize(70); 																	// Modify box6
    cout << "Box3 Size (After Shallow Copy Assignment): " << box3.getBoxSize() << endl; 	// Should be 70 (shared memory with box6)
    cout << "Box6 Size (After Change): " << box6.getBoxSize() << endl << endl; 				// Should be 70 (modified)

    return 0; 																				// End of Program
}
