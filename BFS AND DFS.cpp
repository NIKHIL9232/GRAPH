=================BFS=====================================================

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int size=adj.size();
        vector<bool> vis(size,false);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        
        vis[0]=true;
        
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                if(!vis[adj[curr][i]]){
                    vis[adj[curr][i]]=true;
                    q.push(adj[curr][i]);
                }
            }
        }
        return ans;
    }
===========================DFS====================================================


void dfs(vector<vector<int>>& adj,vector<int> &ans,vector<bool> &vis,int src){
      ans.push_back(src);
      vis[src]=true;
      
      for(int i=0;i<adj[src].size();i++){
          if(!vis[adj[src][i]]){
              dfs(adj,ans,vis,adj[src][i]);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans;
        
        vector<bool> vis(adj.size(),false);
        dfs(adj,ans,vis,0);
        
        return ans;
        
    }
