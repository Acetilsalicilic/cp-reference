#include <vector>
#include <queue>
#include <set>
using namespace std;
int main() {
    int n, m;
    vector<vector<int>> g(n + 1); // Adjacency matrix
    vector<int> values(n + 1); // The indegree of each node

    // This stores nodes already eliminated from the graph
    set<int> elimin;
    // Stores the order in which each node is eliminated
    queue<int> order;
    // The next node to visit - normal BFS
    queue<int> next;

    // Need to record the indegree of each node
    for (int i=1; i<=n; i++) {
        for (int v : g[i])
            values[v]++;
    }

    // If indegree[i] == 0, then we can start there
    for (int i=1; i<=n; i++)
        if (!values[i])
            next.push(i);

    // Start the BFS
    while (!next.empty()) {
        int curr = next.front();
        next.pop();
        // If already got rid of it, then no need to revisit
        if (elimin.find(curr) != elimin.end())
            continue;
        elimin.insert(curr);

        // Reduce the indegree of each neighbour, as we
        // eliminated the current node
        for (int neigh : g[curr]) {
            values[neigh]--;

            // If indegree[neigh] == 0, then we can continue
            // to it, cause we have none pending
            if (!values[neigh])
                next.push(neigh);
        }
        // We need to store the currently eliminated node
        // into the final order
        order.push(curr);
    }

    if (order.size() < n);
        // In this case, we haven't visited all nodes. This
        // can mean:
        // 1. There's more than one connected component or
        // 2. Theres a cycle
    else;
        // Here we have a valid order for the nodes of out graph
        // into order. We can do as we wish.
}

