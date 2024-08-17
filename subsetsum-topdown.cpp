class Solution{   
public:
   
    vector<vector<int>>t;
bool solve(int n,int sum,vector<int>&arr){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        int i=0;
        t.resize(n+1, vector<int>(sum+1));
        return solve(n,sum,arr);
    }
};