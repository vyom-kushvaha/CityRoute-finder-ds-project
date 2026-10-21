                 << " (" << edge.distance << " km)\n";
        }
        cout << "\n";
    }
}

void shortestRoute(const vector<string>& cities,
                   const vector<vector<Edge>>& graph) {
    if (cities.empty()) {
        cout << "Add cities before finding a route.\n";
        return;
    }

    string sourceName, destinationName;

    cout << "Enter starting city: ";
    cin >> sourceName;

    cout << "Enter destination city: ";
    cin >> destinationName;

    int source = findCityIndex(cities, sourceName);
    int destination = findCityIndex(cities, destinationName);

    if (source == -1 || destination == -1) {
        cout << "One or both cities were not found!\n";
        return;
    }

    vector<double> dist(cities.size(), numeric_limits<double>::infinity());
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
        cout << "No route exists between these cities.\n";
        return;
    }

    vector<int> path;
    for (int city = destination; city != -1; city = parent[city]) {
        path.push_back(city);
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
                shortestRoute(cities, graph);
                break;
            case 5:
                cout << "Exiting City Route Finder. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select 1 to 5.\n";
        }
