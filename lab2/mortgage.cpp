// Patrick Soga
// Section 2 Lab 2
// Week of 9 Sep 2019
// mortgage.cpp: program to assemble ammortization table
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double interestRate, moPayment,  balance, interest;
	int months = 0;
	float sum = 0;	// Total money paid

	cout << "Enter the principal: ";
	cin >> balance;
	cout << "Enter the interest rate: ";
	cin >> interestRate;
	cout << "Enter the desired monthly payment: ";
	cin >> moPayment;
	
	// Ask for inputs again if invalid values are given
	while (moPayment < 0 || interestRate < 0 || balance < 0) {
		cout << "You have entered an invalid number for one of the fields. Try again." << endl;
		cout << "Enter the principal: ";
		cin >> balance;
		cout << "Enter the interest rate: ";
		cin >> interestRate;
		cout << "Enter the desired monthly payment: ";
		cin >> moPayment;
	}
	
	// Divide interest rate by 12 for monthly calculations
	interestRate /= 12;

	// If the monthly payment is negative, then the payment won't be able to 
	// reduce the balance
	if (moPayment - (balance*interestRate) < 0) {
		cout << "You won't be able to reduce the balance; payment too small." << endl;
	}
	else {
		cout <<  "    Month    " << "Payment    " << "Interest    " << "Balance" << endl;
		while (balance > 0) {
			months++;
			// Case for when balance is reduced to less than 0
			if (balance - moPayment + interest < 0) {
				moPayment = (interest + balance);
				interest = balance*interestRate;
				sum += moPayment;
				balance = 0;
				cout << setw(6) << months<< setw(6);
				cout <<  fixed << setprecision(2) <<  "  $" << setw(4) << moPayment  << setw(6);  
				cout << setw(4) << "     $" << setw(6) << interest << setw(6); 
				cout << "$ "  << setw(8) << balance << setw(6) << endl;
			}
			// Normal behavior 
			else {
				interest = balance*interestRate;
				balance -= (moPayment - interest);
				sum += moPayment;
				cout << setw(6) << months<< setw(6);
				cout <<  fixed << setprecision(2) <<  "  $" << setw(6) << moPayment  << setw(6);  
				cout << setw(6) << "$" << setw(6) << interest << setw(6); 
				cout << "$ " << setw(8) << balance << setw(6) << endl;
			}
		} 	// Each line of the table split up into multiple cout statements
	}

	cout << fixed << setprecision(2) << "You paid a total of $" << sum << " over " << (months/12) << " years and " << (months % 12) << " months." << endl;
	return 0;
}
