#include <iostream> 																		// Easy Access to Input and Output Operations

using namespace std; 																		// So we dont have to write "std::" before every library features (like cout,cin,endl ,etc)

class BankAccount { 																		// Defining the BankAccount Class
	
	private :																				// Access Modifier , private, makes member accessible only inside the class
		
		double Balance; 																	// Data Member
		
	public  :																				// Access Modifier , public, allows functions to be accessible from outside
	
	//Constructors
		
	BankAccount () : Balance(00.00) { 														// Default Constructor - Initializes Account with $0 if no paramater is passed! 
		cout<<"Account Created!"<<endl;
	}
		
	BankAccount (double x)  { 													// Parameterized Constructor - Initializes Account's Balance with the paramater passed!
		if( x < 00.00 ) {
		Balance=00.00;
	}
		else {
			Balance=x;
		}
		cout<<"Account Created!"<<endl;
	}
	
	BankAccount(const BankAccount &other) { 												// Copy Constructor - Used to Create a copy of another Object
		cout<<"Account Created!"<<endl;
		Balance = other.Balance;
	}
	
	// Methods
	
	void withdraw(double x) { 																// Withdraw method - Deducts the parameter from the Balance
		if( Balance >= x ) { 																// Check if Balance is either greater than or equal to parameter
		Balance -= x; 																		// Deducting paramter from the Balance
		cout<< "Amount Deducted Successfully!"<<endl;
		return ; 																			// End of Function
		}
		cout<< "Insufficient Balance!"<<endl; 												// If not Sufficient Balance
		return ;
	}
	
	void deposit(double x) { 																// Deposit Method - Adds Paramter to the Balance
		if(x > 00.00) { 																	// Checks if the Parameter is Positive
		Balance+=x;
		cout<< "Amount Deposited Successfully!"<<endl;
		return ; 																			// End of Function
		}
		cout<< "Deposit can't be less than or equal to 0!"<<endl; 							// Invalid Parameter
	}
	
	double getBalance() const { 															// Getter Method - Allows main to Access the Private Members
		return Balance;
	}
	
};

int main() {
	
	// Default Constructor Usage 
	BankAccount account1; 																	// Will Initialize with $0 Balance
	cout<<"Account1 Balance : $"<<account1.getBalance()<<endl<<endl; 						// Prints Balance for Account1
	
	// Parameterized Constructor Usage
	BankAccount account2(1000.00); 															// Will Initialize with $1000 Balance
	cout<<"Account2 Balance : $"<<account2.getBalance()<<endl<<endl; 						// Prints Balance for Account2
	
	// Copy Constructor Usage
	BankAccount account3 = account2; 														// Will Initialize Balance of Account3 with the Balance of Account2
	account3.withdraw(200.00); 																// Deducting $200.00 from Account3
	cout<<"Account3 Balance : $"<<account3.getBalance()<<endl<<endl; 						// Prints Balance for Account3
	
	cout<<"Verifying to Show that the Balance of Account2 is Unchanged..."<<endl;
	cout<<"Account2 Balance : $"<<account2.getBalance()<<endl<<endl; 						// Prints Balance for Account2
	
	return 0;																				//End of Program
	
}