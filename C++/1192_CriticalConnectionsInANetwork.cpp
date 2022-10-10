// Name : Rishabh Arya
// Date : 05/10/2022


// The problem is about to return all critical connections.
// Each node is a server.
// where A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Hint : Related to articulation points.
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &low,vector<int> &dist,vector<int> &parent,vector<int> adj[],vector<bool> &arti,int u)
    {
        static int time = 0; 
        low[u] = dist[u] = time; // Initializing the low and dist value for a node as present time.
        time++;
        int child = 0; // Denotes the no. children.
        for(auto v : adj[u])
        {
            if(dist[v] == -1)   // For an unvisited node.
            {
                child++;
                parent[v] = u;

                dfs(low,dist,parent,adj,arti,v);    // Recursively calling for child nodes.
                low[u] = min(low[u],low[v]);    // Updating the low time for this sub-graph.

                if(parent[u] == -1 && child > 1)    // Case : 1 - Current node is root node and have more than 1 children.
                arti[u] = true;

                if(parent[u] != -1 && low[v] >= dist[u]){   // Case : 2 - Current node is not a root node but still have disjoint sub-graphs.
                    arti[u] = true;
                }
                if(low[v] > dist[u])    // Found a critical connection.
                res.push_back({u,v});
            }
            else if(parent[u] != v)   // Updating the low time for this sub-graph
            low[u] = min(low[u],dist[v]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(connections.size() == 1)  // if only one connection is present just return it. 
        return connections;
        vector<int> adj[n];
        for(auto p : connections)  // Creating the adjacency list for simpler dfs traversal. 
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> low(n,-1),dist(n,-1),parent(n,-1);
        // low is vector used for storing the discovery time of a particular sub graph.
        // dist is vector used for storing the discovery time of a node.
        // parent is vector used for storing the parent of a node.
        vector<bool> arti(n,false);
        for(int i = 0;i<n;i++)
        {
            if(dist[i] == -1)  // for an unvisited node
            dfs(low,dist,parent,adj,arti,i);
        }


        
        return res;
    }
};
