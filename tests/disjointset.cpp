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

#include "../data_structures/DisjointSet.hpp"
using namespace data_structures;

int main() {
    DisjointSet dsu(10);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(5, 6);

    std::cout << "Is 1 connected to 3? " << (dsu.isConnected(1, 3) ? "Yes" : "No") << "\n";
    std::cout << "Is 4 connected to 6? " << (dsu.isConnected(4, 6) ? "Yes" : "No") << "\n";
    std::cout << "Set size containing 1: " << dsu.getSetSize(1) << "\n";
    std::cout << "Set size containing 4: " << dsu.getSetSize(4) << "\n";

    dsu.reset();
    std::cout << "After reset, is 1 connected to 3? " << (dsu.isConnected(1, 3) ? "Yes" : "No") << "\n";
    std::cout<<"ALL TESTS COMPLETED....";
    return 0;
}
