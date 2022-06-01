#include "Phone.h"
#include <Windows.h>

#ifdef BOOK
void Phone::add() {
	cout << "Enter name\n";
	string number, name;
	cin >> name;
	cout << "Enter number for " << name << endl;
	cin >> number;
	book.push_back(AddressBook{ name,number });
}
string Phone::findNumber(string name) {
	for (int i = 0; i < book.size(); i++) {
		if (book[i].name == name) {
			return book[i].number;
		}
	}

}
void Phone::call() {
	cout << "Enter name or number\n";
	string tmp;
	cin >> tmp;
	if (tmp[0] == '+' || tmp[0] == '8') {
		cout << "CALL " << tmp << endl;
	}
	else {
		cout << "CALL " << findNumber(tmp) << endl;
	}

}

void Phone::sms() {
	cout << "Enter name or number\n";
	string tmp;
	cin >> tmp;
	if (tmp[0] == '+' || tmp[0] == '8') {
		cout << "Enter message for " << tmp << endl;
	}
	else {
		cout << "Enter message for " << findNumber(tmp) << endl;
	}
	cin.ignore(256, '\n');
	getline(cin, tmp);
	cout << "Message sent\n";

}
#endif 

#ifdef MAP


void Phone::add() {
	cout << "Enter name\n";
	string number, name;
	cin >> name;
	cout << "Enter number for " << name << endl;
	cin >> number;
	bookM[name] = number;
}

void Phone::call() {
	cout << "Enter name or number\n";
	string tmp;
	cin >> tmp;
	if (tmp[0] == '+' || tmp[0] == '8') {
		cout << "CALL " << tmp << endl;
	}
	else {
		cout << "CALL " << bookM[tmp] << endl;
	}

}

void Phone::sms() {
	cout << "Enter name or number\n";
	string tmp;
	cin >> tmp;
	if (tmp[0] == '+' || tmp[0] == '8') {
		cout << "Enter message for " << tmp << endl;
	}
	else {
		cout << "Enter message for " << bookM[tmp] << endl;
	}
	cin.ignore(256, '\n');
	getline(cin, tmp);
	cout << "Message sent\n";

}
#endif 




void Phone::engine() {
	while (true) {
		cout << "Enter command\n";
		string str;
		cin >> str;
		if (str == "add") {
			add();
		}
		else if (str == "call") {
			call();
		}
		else if (str == "sms") {
			sms();
		}
		else if (str == "exit") {
			break;
		}
	}
}