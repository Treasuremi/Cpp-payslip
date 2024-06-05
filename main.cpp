#include <iostream>
#include <fstream>
#include <string>

using namespace std;
    string line;
struct Staff {
    string name;
    double salary;
};

void generatePayment(Staff rec) {
    ofstream file("payments.txt", ios::app);
    file << "Name: " << rec.name << ", Salary: " << rec.salary << endl;
    file.close();
}

void generatePayslip(Staff rec) {
    ofstream file("payslips.txt", ios::app);
    file << "Name: " << rec.name << ", Salary: " << rec.salary << endl;
    file << "-----------------------------------------" << endl;
    file << "Deductions:" << endl;
    file << "-----------------------------------------" << endl;
    file << "Net Salary: " << rec.salary << endl;
    file.close();
}


void displayPayment() {
    cout << endl;
    cout << "Payment" << endl;
    ifstream file("payments.txt", ios::app);
    if (file.is_open()) {
        while(getline(file, line)) {
            cout << line << endl;
        }
    }
    system("pause");
}

void displayPayroll() {
    cout << endl;
    cout << "Payroll" << endl;
    ifstream file("payslips.txt", ios::app);
    if (file.is_open()) {
        while(getline(file, line)) {
            cout << line << endl;
        }
    }
    system("pause");
}

int main() {
    Staff rec;
	int option;


    while(1) {
        system("cls");
		cout << "Payroll System" << endl;
        cout << "1 - Add Payment" << endl;
        cout << "2 - Display Payments" << endl;
        cout << "3 - Display Payroll" << endl;
        cout << "Enter Option: ";
        cin >> option;

        if (option == 1) {
            cout << "Add Staff" << endl;
            cout << "Enter staff name: ";
            cin >> rec.name;
            cout << "Enter staff salary: ";
            cin >> rec.salary;
            generatePayment(rec);
            generatePayslip(rec);
        } else if(option == 2) {
            displayPayment();
        } else if(option == 3) {
            displayPayroll();
        }
    }

    return 0;
}




#include <iostream>
