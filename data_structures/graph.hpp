/**
 * @author      Vaibhav Jindal
 *              B.Tech CSE Core, VIT Bhopal
 * 
 * @details     Modular, templated C++ library for 
 *              educational, research, and production use.
 * 
 * 📦 Namespace: data_structures
 * 📧 Contact  : jindalvaibhav63@gmail.com
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <limits>
#include <functional>

// Using declarations to avoid repeating std::
using std::vector;
using std::queue;
using std::stack;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::endl;
using std::function;
using std::numeric_limits;

const int INF = numeric_limits<int>::max();

namespace data_structures{
/**
 * @brief Graph class supporting weighted edges for various algorithms.
 */
class Graph {
private:
    int V; ///< Number of vertices
    vector<vector<pair<int, int>>> adjList; ///< Adjacency list: {neighbor, weight}
    vector<vector<int>> adjMatrix; ///< Adjacency matrix: stores weights

    /**
     * @brief Utility function for DFS.
     * @param v Current vertex
     * @param visited Visited status array
     */
    void dfsUtil(int v, vector<bool>& visited);

public:
    /**
     * @brief Constructor to initialize the graph.
     * @param vertices Number of vertices
     */
    Graph(int vertices);

    /**
     * @brief Adds a weighted edge from u to v.
     * @param u Source vertex
     * @param v Destination vertex
     * @param weight Weight of the edge
     */
    void addEdge(int u, int v, int weight);

    /**
     * @brief Performs Breadth-First Search from a given vertex (ignores weights).
     * @param start Starting vertex
     */
    void BFS(int start);

    /**
     * @brief Performs Depth-First Search from a given vertex (ignores weights).
     * @param start Starting vertex
     */
    void DFS(int start);

    /**
     * @brief Prints the adjacency list of the graph.
     */
    void printAdjList();

    /**
     * @brief Prints the adjacency matrix of the graph.
     */
    void printAdjMatrix();
    
    /**
     * @brief Performs Topological Sort (only valid for DAGs).
     * @return A vector with topological order or empty if cycle detected.
     */
    vector<int> topologicalSort();

    /**
     * @brief Detects cycle in a directed graph using DFS.
     * @return True if a cycle is found.
     */
    bool hasCycleDirected();

    /**
     * @brief Detects cycle in an undirected graph using DFS.
     * @return True if a cycle is found.
     */
    bool hasCycleUndirected();

    /**
     * @brief Counts the number of connected components.
     * @return Count of connected components.
     */
    int countConnectedComponents();

    /**
     * @brief Checks whether the graph is bipartite using BFS.
     * @return True if bipartite.
     */
    bool isBipartite();

    /**
     * @brief Computes shortest path from start using Dijkstra's algorithm.
     * @param start Source vertex.
     * @return Vector of shortest distances.
     */
    vector<int> dijkstra(int start);
    
    /**
     * @brief Bellman-Ford algorithm to find shortest path from source.
     * @param start Starting vertex
     * @return Pair: distances vector and boolean (true if negative weight cycle exists)
     */
    std::pair<std::vector<int>, bool> bellmanFord(int start);

    /**
     * @brief Computes MST total weight using Prim's algorithm.
     * @return Total weight of MST
     */
    int primMST();

    /**
     * @brief Finds all Strongly Connected Components (SCCs) using Kosaraju's algorithm.
     * @return Vector of components (each as vector<int>)
     */
    std::vector<std::vector<int>> getSCCs();

    /**
     * @brief Floyd-Warshall all-pairs shortest paths algorithm.
     * @return 2D vector of distances between all pairs
     */
    std::vector<std::vector<int>> floydWarshall();

    /**
     * @brief Removes the edge from u to v (one-way).
     * @param u Source vertex
     * @param v Destination vertex
     */
    void removeEdge(int u, int v);

    /**
     * @brief Removes all edges to/from a vertex.
     * @param v Vertex to remove
     */
    void removeVertex(int v);

    /**
     * @brief Checks if an edge exists from u to v.
     * @return True if edge exists, false otherwise
     */
    bool edgeExists(int u, int v);

    /**
     * @brief Returns neighbors of a vertex.
     * @param u Vertex
     * @return Vector of neighbor vertex indices
     */
    std::vector<int> getNeighbors(int u) const;

    /**
     * @brief Returns the out-degree of a vertex.
     * @param u Vertex
     * @return Number of outgoing edges
     */
    int outDegree(int u);

    /**
     * @brief Returns a new graph which is the transpose (reverse) of current graph.
     * @return Transposed Graph object
     */
    Graph getTranspose();

    /**
     * @brief Clears the graph structure (adjacency list and matrix).
     */
    void clear();

    /**
     * @brief Adds reverse edges to make the graph undirected. Assumes symmetric weights.
     */
    void makeUndirected();

};

// --- Method Implementations ---

Graph::Graph(int vertices) {
    V = vertices;
    adjList.resize(V);
    adjMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    if (u >= V || v >= V) return;
    adjList[u].push_back({v, weight});
    adjMatrix[u][v] = weight;
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal from " << start << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

void Graph::dfsUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (const auto& edge : adjList[v]) {
        int u = edge.first;
        if (!visited[u])
            dfsUtil(u, visited);
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal from " << start << ": ";
    dfsUtil(start, visited);
    cout << "\n";
}

void Graph::printAdjList() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (const auto& edge : adjList[i])
            cout << edge.first << "(w:" << edge.second << ") ";
        cout << "\n";
    }
}

void Graph::printAdjMatrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}

vector<int> Graph::topologicalSort() {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            inDegree[edge.first]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }

    return topo.size() == V ? topo : vector<int>(); // Return empty vector if cycle exists
}

// Helper for directed cycle detection
bool dfsDirectedCycleUtil(int v, vector<bool>& visited, vector<bool>& recStack, const vector<vector<pair<int, int>>>& adj) {
    visited[v] = true;
    recStack[v] = true;

    for (const auto& edge : adj[v]) {
        int u = edge.first;
        if (!visited[u]) {
            if (dfsDirectedCycleUtil(u, visited, recStack, adj))
                return true;
        } else if (recStack[u]) {
            return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::hasCycleDirected() {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && dfsDirectedCycleUtil(i, visited, recStack, adjList))
            return true;
    }
    return false;
}

// Helper for undirected cycle detection
bool dfsUndirectedCycleUtil(int v, int parent, vector<bool>& visited, const vector<vector<pair<int, int>>>& adj) {
    visited[v] = true;
    for (const auto& edge : adj[v]) {
        int u = edge.first;
        if (!visited[u]) {
            if (dfsUndirectedCycleUtil(u, v, visited, adj))
                return true;
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool Graph::hasCycleUndirected() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && dfsUndirectedCycleUtil(i, -1, visited, adjList))
            return true;
    }
    return false;
}

int Graph::countConnectedComponents() {
    vector<bool> visited(V, false);
    int count = 0;

    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (const auto& edge : adjList[u]) {
            if (!visited[edge.first]) {
                dfs(edge.first);
            }
        }
    };

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

bool Graph::isBipartite() {
    vector<int> color(V, -1); // -1: no color, 0: color 1, 1: color 2
    queue<int> q;

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (const auto& edge : adjList[u]) {
                    int v = edge.first;
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Not bipartite
                    }
                }
            }
        }
    }
    return true;
}

vector<int> Graph::dijkstra(int start) {
    vector<int> dist(V, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {distance, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

std::pair<std::vector<int>, bool> Graph::bellmanFord(int start) {
    std::vector<int> dist(V, INF);
    dist[start] = 0;

    for (int i = 1; i < V; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycle
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return {dist, true}; // Negative cycle exists
            }
        }
    }

    return {dist, false};
}

int Graph::primMST() {
    std::vector<int> key(V, INF);
    std::vector<bool> inMST(V, false);
    key[0] = 0;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // {key, vertex}
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return totalWeight;
}

// Helper for getSCCs: Fill stack with vertices in order of finishing times
void dfsFillOrder(int u, std::vector<bool>& visited, std::stack<int>& Stack, const std::vector<std::vector<pair<int, int>>>& adj) {
    visited[u] = true;
    for (const auto& edge : adj[u]) {
        if (!visited[edge.first]) {
            dfsFillOrder(edge.first, visited, Stack, adj);
        }
    }
    Stack.push(u);
}

// Helper for getSCCs: Collect all reachable vertices for a component
void dfsCollect(int u, std::vector<bool>& visited, std::vector<int>& component, const Graph& revGraph) {
    visited[u] = true;
    component.push_back(u);
    for (int v : revGraph.getNeighbors(u)) {
        if (!visited[v]) {
            dfsCollect(v, visited, component, revGraph);
        }
    }
}


std::vector<std::vector<int>> Graph::getSCCs() {
    std::stack<int> Stack;
    std::vector<bool> visited(V, false);

    // 1. Fill stack with vertices based on finishing times
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsFillOrder(i, visited, Stack, adjList);
        }
    }

    // 2. Get the transposed graph
    Graph transposedGraph = getTranspose();

    // 3. Process vertices in order from stack to find SCCs
    std::fill(visited.begin(), visited.end(), false);
    std::vector<std::vector<int>> sccs;

    while (!Stack.empty()) {
        int u = Stack.top(); Stack.pop();
        if (!visited[u]) {
            std::vector<int> component;
            dfsCollect(u, visited, component, transposedGraph);
            sccs.push_back(component);
        }
    }
    return sccs;
}

std::vector<std::vector<int>> Graph::floydWarshall() {
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, INF));

    for (int i = 0; i < V; ++i) {
        dist[i][i] = 0;
    }

    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            dist[u][edge.first] = edge.second;
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

void Graph::removeEdge(int u, int v) {
    if (u >= V || v >= V) return;
    adjList[u].erase(
        remove_if(adjList[u].begin(), adjList[u].end(), 
                  [v](const pair<int, int>& edge) { return edge.first == v; }),
        adjList[u].end()
    );
    adjMatrix[u][v] = 0;
}

void Graph::removeVertex(int v) {
    if (v >= V) return;
    // Remove all outgoing edges from v
    adjList[v].clear();
    fill(adjMatrix[v].begin(), adjMatrix[v].end(), 0);

    // Remove all incoming edges to v
    for (int i = 0; i < V; ++i) {
        removeEdge(i, v);
    }
}

bool Graph::edgeExists(int u, int v) {
    if (u >= V || v >= V) return false;
    return adjMatrix[u][v] != 0;
}

std::vector<int> Graph::getNeighbors(int u) const {
    if (u >= V) return {};
    vector<int> neighbors;
    for (const auto& edge : adjList[u]) {
        neighbors.push_back(edge.first);
    }
    return neighbors;
}

int Graph::outDegree(int u) {
    if (u >= V) return 0;
    return adjList[u].size();
}

Graph Graph::getTranspose() {
    Graph transposed(V);
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            transposed.addEdge(edge.first, u, edge.second);
        }
    }
    return transposed;
}

void Graph::clear() {
    for (int i = 0; i < V; ++i) {
        adjList[i].clear();
        fill(adjMatrix[i].begin(), adjMatrix[i].end(), 0);
    }
}

void Graph::makeUndirected() {
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            // Add reverse edge if it doesn't already exist
            if (!edgeExists(v, u)) {
                addEdge(v, u, weight);
            }
        }
    }
}

} // namespace data_structures
#endif // GRAPH_HPP