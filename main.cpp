#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== CITY ROUTE FINDER =====\n";
        cout << "1. Add City\n";
        cout << "2. Add Road\n";
        cout << "3. Display Network\n";
        cout << "4. Find Shortest Route\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add City selected\n";
                break;

            case 2:
                cout << "Add Road selected\n";
                break;

            case 3:
                cout << "Display Network selected\n";
                break;

            case 4:
                cout << "Find Shortest Route selected\n";
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}