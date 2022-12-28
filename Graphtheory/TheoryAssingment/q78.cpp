Look at the following code snippet.Calculate the time and space complexity.int visited[N];
vector<int> adj_list[N];
int target_node = 5;

void dfs(int node)
{
    if (node == target_node)
    {
        BFS(node);
    }
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

void BFS(int node)
{
}