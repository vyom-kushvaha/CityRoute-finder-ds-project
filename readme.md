# City Route Finder

## C++ Data Structures [Mini Project]

------------------------------------------------------------------------

## Team Members

   No.  Name            Enrollment Number
  ----- --------------- -------------------
    1   Vyom Kushwaha   12502080501120
    2   Ved Prajapati   12502080501116
    3   Tirth Thakkar   12502080501114

## Project Overview

City Route Finder is a console-based C++ application that represents
cities as vertices and roads as weighted edges in a graph.

Users can add cities, connect cities with roads, display the road
network, and find the shortest route between two cities using
**Dijkstra's Algorithm**.

The project demonstrates graph representation, adjacency lists, priority
queues, shortest-path algorithms, and path reconstruction.

## Objectives

-   Represent cities and roads using a weighted, undirected graph.
-   Add cities and connect them using road distances in kilometres.
-   Display the connected road network.
-   Find the shortest route between a source city and a destination
    city.
-   Calculate and display the total distance of the shortest route.
-   Practise core Data Structures and Algorithms concepts in C++.

## Features

-   **Add City:** Add a new city to the network.
-   **Add Road:** Connect two existing cities with a distance.
-   **Display Network:** Show each city and its connected roads.
-   **Find Shortest Route:** Use Dijkstra's Algorithm to calculate the
    shortest route.
-   **Show Total Distance:** Display the shortest route's total distance
    in kilometres.
-   **Handle Unreachable Cities:** Report when no route exists between
    two cities.
-   **Distance Validation:** Reject zero and negative road distances.
-   **Duplicate Road Prevention:** Avoid duplicate direct roads between
    the same pair of cities.

> **Demo network:** A predefined network will be loaded automatically at
> startup after the `loadDemoNetwork()` function is added to the source
> code. Until that implementation is committed, the demo network is
> planned rather than an available feature.

## Technologies Used

-   **Programming Language:** C++
-   **C++ Standard:** C++17 or later
-   **Graph Representation:** Weighted Adjacency List
-   **Shortest-Path Algorithm:** Dijkstra's Algorithm
-   **STL Components:** `vector`, `pair`, `priority_queue`, `greater`
-   **Development Environment:** Visual Studio Code or any compatible
    C++ compiler

## Data Structures Used

### 1. Weighted Adjacency List

The graph is represented using:

``` cpp
vector<vector<Edge>> graph;
```

Each city has a list of connected roads. Each `Edge` stores the
destination city's index and the road distance.

### 2. Distance Array

The `dist` array stores the shortest known distance from the source city
to each city.

### 3. Priority Queue (Min-Heap)

The priority queue processes the city with the smallest currently known
distance first.

### 4. Parent Array

The `parent` array stores the previous city on the shortest path. It is
used to reconstruct the full route, including intermediate cities.

## Dijkstra's Algorithm

Dijkstra's Algorithm finds shortest paths from a source vertex in a
graph with non-negative edge weights.

The relaxation condition is:

\[ d(u) + c(u,v) \< d(v) \]

Where:

-   (d(u)) is the shortest known distance to city (u).
-   (c(u,v)) is the road distance between cities (u) and (v).
-   (d(v)) is the previously known distance to city (v).

If the new route is shorter, the distance is updated and the parent of
the neighbouring city is recorded.

## Example

Suppose the network contains these roads:

  Road                   Distance
  -------------------- ----------
  Anand -- Nadiad           20 km
  Nadiad -- Vadodara        25 km
  Anand -- Vadodara         60 km

For a route from Anand to Vadodara, the shortest route is:

**Anand → Nadiad → Vadodara**

**Total distance: 45 km**

*These distances are illustrative examples, not verified real-world road
distances.*

## How to Compile and Run

### Requirements

-   A C++17-compatible compiler
-   A terminal or command prompt

### Compile

If the source file is named `main.cpp`, run:

``` bash
g++ -std=c++17 main.cpp -o CityRouteFinder
```

### Run on Windows

``` bash
CityRouteFinder.exe
```

### Run on Linux or macOS

``` bash
./CityRouteFinder
```

## Time and Space Complexity

Let:

-   \(V\) = number of cities (vertices)
-   \(E\) = number of unique roads (edges)

  Operation                              Time Complexity
  -------------------------------------- --------------------------
  Find a city by name                    (O(V))
  Display the network                    (O(V+E))
  Dijkstra's Algorithm with a min-heap   (O((V+E)`\log `{=tex}V))

**Space Complexity:** (O(V+E)) for the graph and (O(V)) additional space
for the distance and parent arrays. The priority queue can hold multiple
entries during execution.

## Future Improvements

-   Load the predefined demo network automatically at startup.
-   Improve handling of non-numeric distance input.
-   Test invalid inputs and disconnected graphs.
-   Review and resolve compiler warnings.
-   Consider adding alternative-route functionality.

## Learning Outcomes

This project provides practical experience with:

-   Graphs and weighted edges
-   Adjacency-list representation
-   C++ Standard Template Library (STL)
-   Priority queues and min-heaps
-   Dijkstra's shortest-path algorithm
-   Path reconstruction using a parent array
-   Time and space complexity analysis

## Project Status

**Current stage:** Phase 4 --- Shortest Route Implementation

The core graph operations and Dijkstra-based shortest-route
functionality have been implemented. Additional testing,
compiler-warning cleanup, improved non-numeric input validation, and the
predefined demo network are pending.

------------------------------------------------------------------------

**Project Name:** City Route Finder\
**Project Type:** Data Structure [Mini Project]\
**Language:** C++
