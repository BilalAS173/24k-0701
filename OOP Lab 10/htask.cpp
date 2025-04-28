#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Logger {
private:
    string logfile = "todo_log.txt";
    size_t maxSize = 1024 * 1024; // 1MB

    bool needsRotation() {
        ifstream file(logfile, ios::ate);
        return file.tellg() >= maxSize;
    }

    void rotateLog() {
        ifstream src(logfile);
        if (!src) return;

        string content((istreambuf_iterator<char>(src)), 
                    istreambuf_iterator<char>());
        src.close();

        ofstream dest("todo_log_old.txt");
        dest << content;
    }

public:
    void log(const string& message) {
        if (needsRotation()) {
            rotateLog();
            ofstream(logfile).close(); // Clear current log
        }

        ofstream file(logfile, ios::app);
        if (file) {
            file << message << "\n";
        }
    }
};

class TodoList {
private:
    string filename = "todo_list.txt";
    Logger logger;

    vector<string> readTasks() {
        vector<string> tasks;
        ifstream file(filename);
        string task;
        while (getline(file, task)) {
            tasks.push_back(task);
        }
        return tasks;
    }

    void saveTasks(const vector<string>& tasks) {
        ofstream file(filename);
        for (const auto& task : tasks) {
            file << task << "\n";
        }
    }

public:
    void addTask(const string& description) {
        ofstream file(filename, ios::app);
        if (file) {
            file << "[ ] " << description << "\n";
            logger.log("Added: " + description);
        }
    }

    void viewTasks() {
        vector<string> tasks = readTasks();
        if (tasks.empty()) {
            cout << "No tasks found.\n";
            return;
        }

        cout << "Your Tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i+1 << ". " << tasks[i] << "\n";
        }
        logger.log("Viewed tasks");
    }

    void markDone(int taskNum) {
        auto tasks = readTasks();
        if (taskNum < 1 || taskNum > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        string& task = tasks[taskNum-1];
        if (task.substr(0, 4) == "[ ] ") {
            task.replace(0, 4, "[X] ");
            saveTasks(tasks);
            logger.log("Completed: " + task.substr(4));
            cout << "Marked as done!\n";
        } else {
            cout << "Task already completed.\n";
        }
    }
};

int main() {
    TodoList todo;
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task Done\n"
             << "4. Exit\n"
             << "Choose: ";
        
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task: ";
                getline(cin, task);
                todo.addTask(task);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int num;
                cout << "Task number to mark done: ";
                cin >> num;
                todo.markDone(num);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}