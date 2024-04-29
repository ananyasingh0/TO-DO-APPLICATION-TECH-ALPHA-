#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void markAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void displayTasks() {
        cout << "Current Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    TodoList todoList;
    char choice;
    string taskDescription;
    int taskIndex;

    do {
        cout << "\nTodo List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case '2':
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markAsCompleted(taskIndex - 1); // Adjust index to 0-based
                break;
            case '3':
                todoList.displayTasks();
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '4');

    return 0;
}
