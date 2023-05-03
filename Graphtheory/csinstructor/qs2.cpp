#include <iostream>
#include <cmath>

using namespace std;

int compute_level(int leaf_nodes)
{
    int height = ceil(log2(leaf_nodes + 1)); // compute height of the tree
    int total_nodes = pow(2, height) - 1;    // compute total number of nodes in the tree

    if (total_nodes == leaf_nodes)
    {
        return height; // full binary tree
    }
    else
    {
        int last_level_nodes = leaf_nodes - pow(2, height - 1) + 1; // number of nodes in the last level
        if (last_level_nodes == pow(2, height - 1))
        {
            return height; // complete binary tree
        }
        else
        {
            return height - 1; // incomplete binary tree
        }
    }
}

int main()
{
    int leaf_nodes;

    while (cin >> leaf_nodes)
    {
        int level = compute_level(leaf_nodes);
        cout << level << endl;
    }

    return 0;
}
