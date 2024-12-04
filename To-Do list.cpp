#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

void addTask(vector<Task>& tasks) {
    cout << "Enter the task description: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tasks.push_back(Task(desc));
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [completed]";
        }
        cout << endl;
    }
}

void markTaskComplete(vector<Task>& tasks) {
    cout << "Enter the task number to mark as complete: ";
    int taskNum;
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as complete." << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    cout << "Enter the task number to remove: ";
    int taskNum;
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as complete" << endl;
        cout << "4. Remove a task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskComplete(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}
