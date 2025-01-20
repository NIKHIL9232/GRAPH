Course Schedule
Difficulty: MediumAccuracy: 51.77%Submissions: 76K+Points: 4
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning
anempty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 



class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> indeg(n);
        for(int i=0;i<m;i++){
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();
            ans.push_back(cur);
            q.pop();
            for(int i=0;i<adj[cur].size();i++){
                indeg[adj[cur][i]]--;
                if(indeg[adj[cur][i]]==0){
                    q.push(adj[cur][i]);
                }
            }
        }
        vector<int> temp;
        return ans.size()==n?ans:temp;
    }
};
