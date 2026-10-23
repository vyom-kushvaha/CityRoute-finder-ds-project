#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

struct Edge {
    int to;
    double distance;
};

int findCityIndex(const vector<string>& cities, const string& name) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == name) {
            return i;
        }
    }

    return -1;
}

int findEdgeIndex(const vector<Edge>& edges, int target) {
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].to == target) {
            return i;
        }
    }

    return -1;
}

bool readPositiveDistance(double& distance) {
    while (true) {
        cout << "Enter distance in km: ";

        if (!(cin >> distance)) {
            cout << "Invalid numeric input. Please restart the program and enter a number.\n";
            return false;
        }

        if (distance > 0) {
            return true;
        }

        cout << "Distance must be greater than 0!\n";
    }
}

/*
Future improvement: use this version instead of the basic readPositiveDistance()
above when ready to handle inputs such as "abc" without restarting.

bool readPositiveDistance(double& distance) {
    while (true) {
        cout << "Enter distance in km: ";

        if (cin >> distance) {
            if (distance > 0) {
                return true;
            }

            cout << "Distance must be greater than 0!\n";
        } else {
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
        cout << "A road between these cities already exists.\n";
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
    if (!(cin >> name)) {
        return;
    }

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

    string sourceName, destinationName;

    cout << "Enter first city: ";
    if (!(cin >> sourceName)) {
        return;
    }

    cout << "Enter second city: ";
    if (!(cin >> destinationName)) {
        return;
    }

    int u = findCityIndex(cities, sourceName);
    int v = findCityIndex(cities, destinationName);

    if (u == -1 || v == -1) {
        cout << "One or both cities were not found.\n";
        return;
    }

    connectCities(graph, u, v);
}

void displayNetwork(const vector<string>& cities, const vector<vector<Edge>>& graph) {
    if (cities.empty()) {
        cout << "No cities in the network.\n";
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

void shortestRoute(const vector<string>& cities, const vector<vector<Edge>>& graph) {
    if (cities.empty()) {
        cout << "Add cities before finding a route.\n";
        return;
    }

    string sourceName, destinationName;

    cout << "Enter starting city: ";
    if (!(cin >> sourceName)) {
        return;
    }

    cout << "Enter destination city: ";
    if (!(cin >> destinationName)) {
        return;
    }

    int source = findCityIndex(cities, sourceName);
    int destination = findCityIndex(cities, destinationName);

    if (source == -1 || destination == -1) {
        cout << "One or both cities were not found!\n";
        return;
    }

    vector<double> dist(
        cities.size(),
        numeric_limits<double>::infinity()
    );

    vector<int> parent(cities.size(), -1);

    priority_queue<
        pair<double, int>,
        vector<pair<double, int>>,
        greater<pair<double, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            double newDist = dist[u] + edge.distance;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }

    if (dist[destination] == numeric_limits<double>::infinity()) {
        cout << "No route available between these cities.\n";
        return;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest route: ";
    for (int i = 0; i < path.size(); i++) {
        cout << cities[path[i]];

        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\nTotal distance: " << dist[destination] << " km\n";
}

void loadDemoNetwork(vector<string>& cities, vector<vector<Edge>>& graph) {
    cities = {"Anand", "Nadiad", "Vadodara", "Khambhat", "Ahmedabad"};
    graph.clear();
    graph.resize(cities.size());

    // Demo roads (illustrative distances, not verified real-world distances)
    graph[0].push_back({1, 20});
    graph[1].push_back({0, 20});

    graph[1].push_back({2, 25});
    graph[2].push_back({1, 25});

    graph[0].push_back({2, 60});
    graph[2].push_back({0, 60});

    graph[0].push_back({3, 35});
    graph[3].push_back({0, 35});

    graph[3].push_back({1, 30});
    graph[1].push_back({3, 30});

    graph[1].push_back({4, 45});
    graph[4].push_back({1, 45});

    graph[2].push_back({4, 100});
    graph[4].push_back({2, 100});
}

void showMenu() {
    cout << "\n===== City Route Finder =====\n";
    cout << "1. Add City\n";
    cout << "2. Add Road\n";
    cout << "3. Display Network\n";
    cout << "4. Find Shortest Route\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> cities;
    vector<vector<Edge>> graph;

    loadDemoNetwork(cities, graph);

    cout << "Demo network loaded successfully!\n";

    int choice;

    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid menu input. Please restart the program and enter a number.\n";
            return 0;
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
                shortestRoute(cities, graph);
                break;

            case 5:
                cout << "Exiting City Route Finder. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select 1 to 5.\n";
        }
    }
}
