
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Display the main menu
void showMenu() {
    cout << "\n===== CITY ROUTE FINDER =====\n";
    cout << "1. Add City\n";
    cout << "2. Add Road\n";
    cout << "3. Display Network\n";
    cout << "4. Find Shortest Route\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Add a new city
void addCity(vector<string>& cities) {
    string name;

    cout << "Enter city name: ";
    cin >> name;

    // Check whether the city already exists
    auto it = find(cities.begin(), cities.end(), name);

    if (it != cities.end()) {
        cout << "City already exists!\n";
        return;
    }

    // Store the new city
    cities.push_back(name);

    cout << name << " added successfully!\n";
}

// Display cities added so far
void displayNetwork(const vector<string>& cities) {
    if (cities.empty()) {
        cout << "No cities added yet!\n";
        return;
    }

    cout << "\n===== CITY NETWORK =====\n";

    for (const string& city : cities) {
        cout << city << '\n';
    }

    cout << "========================\n";
}

int main() {
    vector<string> cities;
    int choice;

    do {
        showMenu();

        // Handle non-numeric menu input
        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addCity(cities);
                break;

            case 2:
                cout << "Add Road will be implemented next.\n";
                break;

            case 3:
                displayNetwork(cities);
                break;

            case 4:
                cout << "Shortest Route will be implemented later.\n";
                break;

            case 5:
                cout << "Exiting City Route Finder...\n";
                break;

            default:
                cout << "Invalid choice! Select 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}
