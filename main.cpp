    while (true) {
        cout << "Enter distance in km: ";

        if (!(cin >> distance)) {
            cout << "Non-numeric input is not handled in this basic version.\n";
            return false;
        }

        if (distance > 0) {
            return true;
        }

        cout << "Distance must be greater than 0!\n";
    }
}

/*
// Improved version: use this later to handle inputs like abc and ask again.
// Comment out the basic readPositiveDistance() above before uncommenting this.
bool readPositiveDistance(double& distance) {
    while (true) {
        cout << "Enter distance in km: ";

        if (cin >> distance) {
            if (distance > 0) {
                return true;
            }
            cout << "Distance must be greater than 0!\n";
        } else {
            if (cin.eof()) {
                return false;
            }

            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
*/

void connectCities(vector<vector<Edge>>& graph, int u, int v) {
    if (u == v) {
        cout << "A city cannot be connected to itself.\n";
        return;
    }

    int edgeUV = findEdgeIndex(graph[u], v);
    int edgeVU = findEdgeIndex(graph[v], u);

    if (edgeUV != -1 || edgeVU != -1) {
        cout << "Road already exists between these cities.\n";
        return;
    }

    double distance;
    if (!readPositiveDistance(distance)) {
        return;
    }

    graph[u].push_back({v, distance});
    graph[v].push_back({u, distance});

    cout << "Road added successfully.\n";
}

void addCity(vector<string>& cities, vector<vector<Edge>>& graph) {
    string name;
    cout << "Enter city name: ";
    cin >> name;

    if (findCityIndex(cities, name) != -1) {
        cout << "City already exists!\n";
        return;
    }

    cities.push_back(name);
    graph.push_back(vector<Edge>());

    cout << "City added successfully.\n";
}

void addRoad(const vector<string>& cities, vector<vector<Edge>>& graph) {
    if (cities.size() < 2) {
        cout << "Add at least two cities first.\n";
        return;
    }

    string fromName, toName;

    cout << "Enter starting city: ";
    cin >> fromName;

    cout << "Enter destination city: ";
    cin >> toName;

    int u = findCityIndex(cities, fromName);
    int v = findCityIndex(cities, toName);

    if (u == -1 || v == -1) {
        cout << "One or both cities were not found!\n";
        return;
    }

    connectCities(graph, u, v);
}

void displayNetwork(const vector<string>& cities,
                    const vector<vector<Edge>>& graph) {
    if (cities.empty()) {
        cout << "No cities added yet.\n";
        return;
    }

    cout << "\n--- City Network ---\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << "\n";

        if (graph[i].empty()) {
            cout << "  No connected roads\n";
        }

        for (const Edge& edge : graph[i]) {
            cout << "  -> " << cities[edge.to]
                 << " (" << edge.distance << " km)\n";
        }
        cout << "\n";
    }
}

void showMenu() {
    cout << "\n===== City Route Finder =====\n";
    cout << "1. Add City\n";
    cout << "2. Add Road\n";
    cout << "3. Display Network\n";
    cout << "4. Find Shortest Route (Phase 4)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> cities;
    vector<vector<Edge>> graph;
    int choice;

    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid menu input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                addCity(cities, graph);
                break;
            case 2:
                addRoad(cities, graph);
                break;
            case 3:
                displayNetwork(cities, graph);
                break;
            case 4:
                cout << "Shortest route will be added in Phase 4.\n";
                break;
            case 5:
                cout << "Exiting City Route Finder. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select 1 to 5.\n";
        }

        if (!cin) {
            cout << "Input could not be read. Exiting.\n";
            break;
        }
    }

    return 0;
}
