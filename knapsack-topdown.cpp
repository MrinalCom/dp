 vector<vector<int>>t;
    int solve(int W,vector<int>&wt,vector<int>&val,int n){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<W+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
              }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        
        return t[n][W];
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=val.size();
        t.resize(n+1,vector<int>(W+1,-1));
        solve(W,wt,val,n);
    }
};