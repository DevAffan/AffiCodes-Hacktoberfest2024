#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing an individual task in the todo list
class Todo {
    string task;  // Task description

public:
    // Constructor to initialize a task
    Todo(string t) : task(t) {}

    // Function to return the task description
    string getTask() { return task; }
};

// Class representing the todo list
class TodoList {
    vector<Todo> tasks;  // Vector to store the list of tasks

public:
    // Function to add a task to the list
    void addTask(string task) {
        tasks.push_back(Todo(task));  // Create a new Todo object and add it to the vector
        cout << "Task added: " << task << endl;
    }

    // Function to display all tasks in the list
    void viewTasks() {
        if (tasks.empty()) {
            // If there are no tasks, display a message
            cout << "No tasks available." << endl;
            return;
        }
        // Display each task in the list
        cout << "Tasks: " << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getTask() << endl;  // Display task with its index
        }
    }

    // Function to delete a task from the list
    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            // If the task number is invalid, display an error message
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);  // Remove the task from the vector
        cout << "Task deleted." << endl;
    }
};

int main() {
    TodoList todoList;  // Create an instance of TodoList
    int choice;
    string task;

    // Menu-driven system for managing the todo list
    do {
        // Display menu options
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();  // Ignore any leftover newline character in the input buffer

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Add a new task
                cout << "Enter task: ";
                getline(cin, task);  // Get the entire task description from the user
                todoList.addTask(task);  // Add the task to the list
                break;
            case 2:
                // View all tasks in the todo list
                todoList.viewTasks();
                break;
            case 3:
                // Delete a task by its number
                int taskNumber;
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                todoList.deleteTask(taskNumber);  // Remove the specified task
                break;
            case 4:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                // Handle invalid input
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}
