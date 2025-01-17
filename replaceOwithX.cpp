class Solution {
    
  public:
  int r,c;
  bool check(int a,int b){
      return a>=0 && a<r && b>=0 && b<c;
  }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        r=mat.size();
        c=mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<c;i++){
            if(mat[0][i]=='O'){
                q.push(make_pair(0,i));
                mat[0][i]='T';
            }
        }
        
        for(int i=0;i<r;i++){
            if(mat[i][0]=='O'){
                q.push(make_pair(i,0));
                mat[i][0]='T';
            }
        }
        
        for(int i=0;i<r;i++){
            if(mat[i][c-1]=='O'){
                q.push(make_pair(i,c-1));
                mat[i][c-1]='T';
            }
        }
        for(int i=0;i<c;i++){
            if(mat[r-1][i]=='O'){
                q.push(make_pair(r-1,i));
                mat[r-1][i]='T';
            }
        }
        while(!q.empty()){
            int l1=q.front().first;
            int l2=q.front().second;
            
            q.pop();
            int r1[]={-1,1,0,0};
            int c1[]={0,0,-1,1};
            
            for(int i=0;i<4;i++){
                int a=l1+r1[i];
                int b=l2+c1[i];
                if(check(a,b) && mat[a][b]=='O'){
                    mat[a][b]='T';
                    q.push(make_pair(a,b));
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='T'){
                    mat[i][j]='O';
                }else if(mat[i][j]=='O'){
                    mat[i][j]=='X';
                }
            }
        }
        return mat;
        
    }
};
