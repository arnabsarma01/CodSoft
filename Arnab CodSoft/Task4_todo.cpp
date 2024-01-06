#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "\n\nNo tasks to display." << endl;
    } else {
        cout << "\n\nTo-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "✓" : " ") << "] " << tasks[i].description << endl;
        }
    }
}

void markCompleted() {
    viewTasks();
    if (tasks.empty()) {
        return;
    }

    int taskNumber;
    cout << "\n\nEnter the task number to mark as completed (0 to cancel): ";
    cin >> taskNumber;

    if (taskNumber == 0) {
        return;
    }

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask() {
    viewTasks();
    if (tasks.empty()) {
        return;
    }

    int taskNumber;
    cout << "\n\nEnter the task number to remove (0 to cancel): ";
    cin >> taskNumber;

    if (taskNumber == 0) {
        return;
    }

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
