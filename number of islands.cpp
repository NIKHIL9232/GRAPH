int r,c;
  bool valid(int r1,int c1){
      return r1>=0 && r1<r && c1>=0 && c1<c;
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        r=grid.size();
        c=grid[0].size();
        
        queue<pair<int,int>> q;
        int total=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    total++;
                    q.push(make_pair(i,j));
                    grid[i][j]='0';
                    while(!q.empty())
                    {
                        int l1=q.front().first;
                        int l2=q.front().second;
                        q.pop();
                        
                        int r1[]={-1,-1,-1,1,1,1,0,0};
                        int c1[]={-1,0,1,-1,0,1,-1,1};
                        
                        for(int i=0;i<8;i++){
                            int q11=l1+r1[i];
                            int q22=l2+c1[i];
                            if(valid(q11,q22) && grid[q11][q22]=='1'){
                                grid[q11][q22]='0';
                                q.push(make_pair(q11,q22));
                            }
                        }
                    }
                }
            }
        }
        return total;
