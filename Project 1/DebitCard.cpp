#include "DebitCard.h"
#include <iostream>
#include <iomanip>
using namespace std;

//constructor
DebitCard::DebitCard() {
	totalTransactions = 0; // number of transactions posted for this DebitCard
	accountBalance = 0; // amount of money still in the account for this DebitCard
	totalDeposits = 0; // total amount of money added to this DebitCard
}

//destructor
DebitCard::~DebitCard() {

}

// used to add money to the DebitCard. Returns current ballance
double DebitCard::Deposit(double deposit) {
	totalDeposits += deposit;
	accountBalance += deposit;
	return accountBalance;
}

// adds a new transaction to the transactions array. Returns account balance
double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount) {
	transactions.push_back(Transaction(idNumber, date, description, amount));
	accountBalance -= amount;
	totalTransactions += 1;
	return accountBalance;
}

// marks the pending transaction in the transactions array as "cleared"
bool DebitCard::ClearTransaction(int idNumber) {
	for (int i = 0; i < transactions.size(); ++i) {
		if (transactions.at(i).idNumber == idNumber) {
			transactions.at(i).cleared = true;
			return true;
		}
	}
	return false;
}	

// properly displays the DebitCard data to the console screen
void DebitCard::DisplayActivity() {
	cout << fixed << setprecision(2);
	cout << "total transactions: " << totalTransactions << endl;
	cout << "total deposits: $" << totalDeposits << endl;
	cout << "account balance: $" << accountBalance << endl << endl;

	cout << "List of cleared transactions: " << endl;
	
	for (int i = 0; i < transactions.size(); ++i) {
		if (transactions.at(i).cleared == true) {
			cout << transactions.at(i).date << '\t' << "$" << transactions.at(i).amount << '\t' << transactions.at(i).description << endl;
		}
	}

	cout << endl << "List of pending transactions: " << endl;

	for (int i = 0; i < transactions.size(); ++i) {
		if (transactions.at(i).cleared == false) {
			cout << transactions.at(i).date << '\t' << "$" << transactions.at(i).amount << '\t' << transactions.at(i).description << endl;
		}
	}
}
