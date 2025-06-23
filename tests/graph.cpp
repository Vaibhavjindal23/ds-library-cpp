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

#include "../data_structures/Graph.hpp"
using namespace data_structures;

// ------------------------- Utility Functions ----------------------------

void printVector(const std::vector<int>& vec, const std::string& label = "") {
    if (!label.empty()) std::cout << label << ": ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\n";
}

void printMatrix(const std::vector<std::vector<int>>& matrix, const std::string& label = "") {
    if (!label.empty()) std::cout << label << ":\n";
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << (val == INF ? "INF" : std::to_string(val)) << " ";
        std::cout << "\n";
    }
}

// ------------------------- Test Functions ----------------------------

Graph initializeGraph() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);
    g.addEdge(3, 5, 11);
    return g;
}

void testPrint(Graph& g) {
    std::cout << "\n-- Adjacency List and Matrix --\n";
    g.printAdjList();
    g.printAdjMatrix();
}

void testTraversals(Graph& g) {
    std::cout << "\n-- BFS and DFS Traversals --\n";
    g.BFS(0);
    g.DFS(0);
}

void testShortestPaths(Graph& g) {
    std::cout << "\n-- Dijkstra's Algorithm --\n";
    auto dijkstraDistances = g.dijkstra(0);
    printVector(dijkstraDistances, "Shortest distances from 0");

    std::cout << "\n-- Bellman-Ford Algorithm --\n";
    std::pair<std::vector<int>, bool> bellmanResult = g.bellmanFord(0);
    std::vector<int> bellmanDistances = bellmanResult.first;
    bool hasNegCycle = bellmanResult.second;

    printVector(bellmanDistances, "Bellman-Ford distances from 0");
    std::cout << "Negative cycle present? " << (hasNegCycle ? "Yes" : "No") << "\n";
}

void testTopologicalSort(Graph& g) {
    std::cout << "\n-- Topological Sort --\n";
    auto topo = g.topologicalSort();
    if (!topo.empty()) printVector(topo, "Topological Order");
    else std::cout << "Cycle detected: Topological sort not possible.\n";
}

void testCycleDetection(Graph& g) {
    std::cout << "\n-- Checking for Cycles --\n";
    std::cout << "Directed cycle exists? " << (g.hasCycleDirected() ? "Yes" : "No") << "\n";
    std::cout << "Undirected cycle exists? " << (g.hasCycleUndirected() ? "Yes" : "No") << "\n";
}

void testConnectivity(Graph& g) {
    std::cout << "\n-- Connected Components --\n";
    std::cout << "Connected Components: " << g.countConnectedComponents() << "\n";

    std::cout << "\n-- Bipartite Check --\n";
    std::cout << "Is graph bipartite? " << (g.isBipartite() ? "Yes" : "No") << "\n";
}

void testMST(Graph& g) {
    std::cout << "\n-- Prim's MST --\n";
    std::cout << "Total MST Weight: " << g.primMST() << "\n";
}

void testAllPairsShortestPath(Graph& g) {
    std::cout << "\n-- Floyd-Warshall --\n";
    auto dist = g.floydWarshall();
    printMatrix(dist, "All-Pairs Shortest Paths");
}

void testSCC(Graph& g) {
    std::cout << "\n-- SCC Detection --\n";
    auto sccs = g.getSCCs();
    int id = 1;
    for (const auto& comp : sccs) {
        std::cout << "SCC " << id++ << ": ";
        for (int v : comp) std::cout << v << " ";
        std::cout << "\n";
    }
}

void testEdgeVertexOps(Graph& g) {
    std::cout << "\n-- Edge and Vertex Operations --\n";
    std::cout << "Edge (1->3) exists? " << (g.edgeExists(1, 3) ? "Yes" : "No") << "\n";
    g.removeEdge(1, 3);
    std::cout << "After removal, edge (1->3) exists? " << (g.edgeExists(1, 3) ? "Yes" : "No") << "\n";

    g.removeVertex(5);
    g.printAdjList();
}

void testTransposeAndUndirected(Graph& g) {
    std::cout << "\n-- Transpose and Make Undirected --\n";
    auto transpose = g.getTranspose();
    std::cout << "Transpose Adjacency List:\n";
    transpose.printAdjList();

    g.makeUndirected();
    std::cout << "After makeUndirected:\n";
    g.printAdjList();
}

// ------------------------- Main Driver ----------------------------

int main() {
    std::cout << "========== GRAPH LIBRARY TESTING ==========\n";

    Graph g = initializeGraph();

    testPrint(g);
    testTraversals(g);
    testShortestPaths(g);
    testTopologicalSort(g);
    testCycleDetection(g);
    testConnectivity(g);
    testMST(g);
    testAllPairsShortestPath(g);
    testSCC(g);
    testEdgeVertexOps(g);
    testTransposeAndUndirected(g);

    std::cout << "\n========== ALL TESTS COMPLETED SUCCESSFULLY ==========\n";
    return 0;
}
