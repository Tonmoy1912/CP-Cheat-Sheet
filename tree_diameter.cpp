#include <bits/stdc++.h>
using namespace std;

//return the diameter of a tree given in adjacency list format
int getDiameter(vector<vector<int>> &adj)
{
    int n = adj.size();
    if (n <= 1)
    {
        return 0;
    }
    //to store the degree of a node
    vector<int> deg(n);
    //to store the node whose current degree is one
    queue<int> q;
    // to store the max 2 depth of node found so far 
    vector<priority_queue<int, vector<int>, greater<int>>> depth(n);
    int ans = 0;
    // to store the nodes from which the current node is expoled so far
    unordered_map<int, unordered_map<int, int>> vis;
    for (int i = 0; i < n; i++)
    {
        deg[i] = adj[i].size();
        if (deg[i] == 1)
        {
            depth[i].push(0);
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int x;
        if (depth[node].size() == 1)
        {
            x = depth[node].top();
            ans = max(ans, x);
        }
        else
        {
            int temp = depth[node].top();
            depth[node].pop();
            x = depth[node].top();
            ans = max(ans, temp + x);
        }
        for (auto it : adj[node])
        {
            if (vis[node].count(it) == 0)
            {
                vis[it][node] = 1;
                deg[it]--;
                deg[node]--;
                if (deg[it] == 1)
                {
                    q.push(it);
                }
                depth[it].push(x + 1);
                while (depth[it].size() > 2)
                {
                    depth[it].pop();
                }
            }
        }
    }
    return ans;
}