#include <iostream>
#include <fstream>
using namespace std;

// Employee class definition
class Employee {
    int id;                 // Employee ID
    char name[30];          // Employee name (up to 30 characters)
    float salary;           // Employee salary

public:
    // Function to input employee details
    void getData() {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();       // Ignore any newline character left in the input buffer
        cin.getline(name, 30);  // Get the employee's name
        cout << "Enter employee salary: ";
        cin >> salary;      // Input the salary
    }

    // Function to display employee details
    void displayData() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }

    // Function to get the employee ID (used in searching)
    int getID() {
        return id;
    }
};

// Function to write employee data to a binary file
void writeEmployee() {
    ofstream outFile;
    outFile.open("employee.dat", ios::binary | ios::app);  // Open the file in binary mode and append data

    Employee emp;
    emp.getData();   // Get employee data from the user
    outFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));  // Write employee data to the file

    outFile.close(); // Close the file
}

// Function to display all employee records from the file
void displayAll() {
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);  // Open the file in binary mode

    Employee emp;
    // Read and display each employee record
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        emp.displayData();
        cout << "-----------------------" << endl;
    }

    inFile.close();  // Close the file
}

// Function to search for an employee by their ID
void searchEmployee(int empID) {
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);  // Open the file in binary mode

    Employee emp;
    bool found = false;

    // Search for the employee by ID
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (emp.getID() == empID) {  // Check if the current employee's ID matches the searched ID
            emp.displayData();       // Display employee data if found
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found." << endl;  // Display message if employee is not found

    inFile.close();  // Close the file
}

int main() {
    int choice, empID;

    // Menu-driven system
    do {
        // Display menu options
        cout << "\n1. Add Employee\n2. Display All Employees\n3. Search Employee by ID\n4. Exit\nEnter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case 1:
                writeEmployee();  // Add a new employee
                break;
            case 2:
                displayAll();     // Display all employees
                break;
            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> empID;
                searchEmployee(empID);  // Search for an employee by ID
                break;
            case 4:
                cout << "Exiting..." << endl;  // Exit the program
                break;
            default:
                cout << "Invalid choice!" << endl;  // Handle invalid input
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}
