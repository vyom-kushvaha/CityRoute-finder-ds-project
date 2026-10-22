City Route Finder

C++ Data Structures [Mini Project]

---

👥 Team Members

No.| Name| Enrollment Number
1| Vyom Kushvaha | 12502080501120
2| ved prajapati | 12502080501116
3| tirth thakkar | 12502080501114


📌 Project Overview

City Route Finder is a console-based C++ application that represents cities as vertices and roads as weighted edges in a graph.

The application allows users to view a predefined demo network, add new cities, connect cities with roads, display the complete road network, and find the shortest route between two cities using Dijkstra's Algorithm.

This project demonstrates the practical implementation of graphs, adjacency lists, priority queues, and shortest-path algorithms.

🎯 Objectives

- Implement a weighted, undirected graph.
- Understand graph representation using an adjacency list.
- Find the shortest route between two cities.
- Calculate the minimum travel distance.
- Reconstruct and display the complete shortest path.
- Understand the time and space complexity of Dijkstra's Algorithm.

✨ Features

1. Preloaded Demo Network: Cities and roads are loaded automatically when the program starts.
2. Add City: Add new cities to the network.
3. Add Road: Connect existing cities and specify road distances in kilometres.
4. Display Network: View each city and its connected roads.
5. Find Shortest Route: Calculate the minimum-distance route between a source and destination.
6. Display Total Distance: Show the total distance of the shortest route.
7. Unreachable Destination Handling: Inform the user when no route exists.
8. Distance Validation: Reject zero and negative road distances.
9. Duplicate Road Prevention: Prevent duplicate direct connections between the same pair of cities.

🛠️ Technologies Used

- Language: C++
- Standard: C++17 or later
- Graph Representation: Weighted Adjacency List
- Algorithm: Dijkstra's Algorithm
- STL: "vector", "pair", "priority_queue", "greater"
- Development Environment: Visual Studio Code or another compatible C++ IDE

🧠 Data Structures

1. Weighted Adjacency List

The graph is represented using:

"vector<vector<Edge>>"

Each city maintains a list of connected roads. Each "Edge" stores the destination city's index and the road distance.

2. Priority Queue (Min-Heap)

The priority queue processes the city with the smallest currently known distance first.

3. Distance Array

The "dist" array stores the shortest known distance from the source city to every other city.

4. Parent Array

The "parent" array stores the preceding city on the shortest path and helps reconstruct the complete route.

⚙️ Dijkstra's Algorithm

Dijkstra's Algorithm finds shortest paths from a source vertex in a graph with non-negative edge weights.

The relaxation condition is:

[
d(u)+c(u,v)<d(v)
]

Where:

- (d(u)) is the shortest known distance to city (u).
- (c(u,v)) is the road distance between cities (u) and (v).
- (d(v)) is the previously known distance to city (v).

If a shorter route is found, the distance is updated and the parent of the neighbouring city is recorded.

📊 Example

Suppose the network contains the following roads:

Road| Distance
Anand – Nadiad| 20 km
Nadiad – Vadodara| 25 km
Anand – Vadodara| 60 km

For a route from Anand to Vadodara, the shortest path is:

Anand → Nadiad → Vadodara

Total Distance: 45 km

The example distances are illustrative and are not verified real-world road distances.

▶️ How to Compile and Run

Requirements

- A C++17-compatible compiler.
- A terminal or command prompt.

Compile

g++ -std=c++17 main.cpp -o CityRouteFinder

Run on Windows

CityRouteFinder.exe

Run on Linux / macOS

./CityRouteFinder

The predefined demo network will load automatically when the program starts. Users can then explore the network and use the available menu options.

⏱️ Time and Space Complexity

Let:

- (V) = Number of cities (vertices).
- (E) = Number of unique roads (edges).

Operation| Time Complexity
Find city by name| (O(V))
Display network| (O(V+E))
Dijkstra's Algorithm with a min-heap| (O((V+E)\log V))

Space Complexity: (O(V+E)) for the graph and (O(V)) additional space for distance, parent, and priority-queue storage in the standard analysis.

🚀 Future Improvements

- Improve handling of non-numeric distance input.
- Test invalid inputs and disconnected graphs.
- Resolve compiler warnings.
- Add alternative-route functionality.
- Improve the user interface.

🎓 Learning Outcomes

This project provides practical experience with:

- Graphs and weighted edges.
- Adjacency-list representation.
- C++ Standard Template Library (STL).
- Priority queues and min-heaps.
- Dijkstra's shortest-path algorithm.
- Path reconstruction using a parent array.
- Time and space complexity analysis.

📌 Project Status

Current Stage: Phase 4 — Shortest Route Implementation

The core graph operations and shortest-route functionality have been implemented. The predefined demo network is planned for automatic loading at startup. Additional testing, compiler-warning cleanup, and improved non-numeric input validation remain pending.

---

Project Name: City Route Finder
Programming Language: C++
Project Type: Data Structures [Mini Project]