#include <iostream>
#include <string>
using namespace std;

const int maxtasks = 10;
char displayMenu() {
    cout << "\nTodo List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1 to 5): ";
    char choice;
    cin >> choice;
    return choice;
}

int main() {
    string tasks[maxtasks];
    bool completed[maxtasks] = {false}; 
    int taskNumber;
    
    int tcount = 0;

    char choice;
    do {
        choice = displayMenu();

        if (choice == '1') 
		{
            if (tcount < maxtasks)
			{
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, tasks[tcount]);
                tcount++;
                cout << "Task added!\n";
            } 
			else {
                cout << "Task list is full. Cannot add more tasks." << endl;
            }
        } 
		
		else if (choice == '2') 
		{
            if (tcount > 0)
			{
                cout << "\nTasks:" << endl;
                for (int i = 0; i < tcount; i++)
				{
                    cout << (i + 1) << ". ";
                    if (completed[i]) 
					{
                        cout << " Task Completed : ";
                    }
                    cout << tasks[i] << endl;
                }
            } 
			else 
			{
                cout << "\nNo tasks to display." << endl;
            }
        } 
		
		else if (choice == '3') 
		{
            if (tcount > 0) 
			{
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                if (taskNumber >= 1 && taskNumber <= tcount) 
				{
                    completed[taskNumber - 1] = true;
                    cout << "Task marked as completed!" << endl;
                } 
				else 
				{
                    cout << "Invalid task number." << endl;
                }
            } 
			else 
			{
                cout << "No tasks to mark as completed." << endl;
            }
        } 
		
		else if (choice == '4') 
		{
            if (tcount > 0) 
			{
                cout << "Enter the task number to remove: ";
                int taskNumber;
                cin >> taskNumber;
                if (taskNumber >= 1 && taskNumber <= tcount) 
				{
                    for (int i = taskNumber - 1; i < tcount - 1; i++) 
					{
                        tasks[i] = tasks[i + 1];
                        completed[i] = completed[i + 1];
                    }
                    tcount--;
                    cout << "Task removed!\n";
                } 
				else 
				{
                    cout << "Invalid task number.\n";
                }
            } else 
			{
                cout << "No tasks to remove.\n";
            }
        } 
		
		else if (choice != '5') 
		{
            cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != '5');

    cout << "Exiting the Todo List Manager.\n";

    return 0;
}

