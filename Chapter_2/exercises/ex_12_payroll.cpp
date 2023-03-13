/*
 * File: ex_12_payroll.cpp
 * -----------------------
 * This program solves exercise #12.
 * 
 * Design a new type called payrollT that is capable of holding the data 
 * for a list of employees, each of which is represented using the employeeT type.
 * 
 */

#include <iostream>
#include <string>

using namespace std;

struct employeeRecordT {
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
};

struct payrollT {
    int size;
    employeeRecordT **list;
};

// Prototypes
employeeRecordT *getEmployee();
void printEmployeeRecord(employeeRecordT *employee);
void printPayroll(payrollT *payroll);
payrollT getPayroll();

// Main
int main() {
    payrollT my_payroll;
    // my_payroll = getPayroll();
    my_payroll = getPayroll();
    printPayroll(&my_payroll);

    delete[] my_payroll.list;   
    return 0;
}

// Auxiliary Functions

employeeRecordT *getEmployee() {
    employeeRecordT *employee = new employeeRecordT;
    string input;

    cout << "Enter info" << endl;
    
    cout << "Name: "; 
    cin >> input;
    employee->name = input;
    
    cout << "Title: ";
    cin >> input;
    employee->title = input;
    
    cout << "ssnum: ";
    cin >> input;
    employee->ssnum = input;

    cout << "Salary: ";
    cin >> input;
    employee->salary = stod(input);
    
    cout << "withholding: ";
    cin >> input;
    employee->withholding = stoi(input);

    return employee;
}

void printEmployeeRecord(employeeRecordT *employee) {
    cout << endl;
    cout << "Employee Record" << endl;
    cout << "---------------" << endl;
    cout << "Name        : "<< employee->name << endl;
    cout << "Title       : "<< employee->title << endl;
    cout << "SSNum       : "<< employee->ssnum << endl;
    cout << "Salary      : "<< employee->salary << endl;
    cout << "withholding : "<< employee->withholding << endl;
}

void printPayroll(payrollT *payroll);

payrollT getPayroll() {
    payrollT my_payroll;

    string input;
    cout << "How many employees: ";
    cin >> input;
    
    my_payroll.size = stoi(input);

    // int size = 2;
    // employeeRecordT **list = new employeeRecordT*[size];
    my_payroll.list = new employeeRecordT*[my_payroll.size];
    employeeRecordT *employee;
    
    for (int i = 0; i < my_payroll.size; i++) {
        employee = getEmployee();
        my_payroll.list[i] = employee;
    }

    delete employee;
    return my_payroll;
}

void printPayroll(payrollT *payroll) {
    for (int i = 0; i < payroll->size; i++) {
        printEmployeeRecord(payroll->list[i]);   
    }
}
