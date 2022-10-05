class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &low,vector<int> &dist,vector<int> &parent,vector<int> adj[],vector<bool> &arti,int u)
    {
        static int time = 0;
        low[u] = dist[u] = time;
        time++;
        int child = 0;
        for(auto v : adj[u])
        {
            if(dist[v] == -1)
            {
                child++;
                parent[v] = u;

                dfs(low,dist,parent,adj,arti,v);
                low[u] = min(low[u],low[v]);

                if(parent[u] == -1 && child > 1)
                arti[u] = true;

                if(parent[u] != -1 && low[v] >= dist[u]){
                    arti[u] = true;
                }
                if(low[v] > dist[u])
                res.push_back({u,v});
            }
            else if(parent[u] != v)
            low[u] = min(low[u],dist[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(connections.size() == 1)
        return connections;
        vector<int> adj[n];
        for(auto p : connections)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> low(n,-1),dist(n,-1),parent(n,-1);
        vector<bool> arti(n,false);
        for(int i = 0;i<n;i++)
        {
            if(dist[i] == -1)
            dfs(low,dist,parent,adj,arti,i);
        }


        
        return res;
    }
};
