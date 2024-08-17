
class Solution{   
public:
    vector<vector<int>>t;
    Solution(){
        
    }
    bool solve(vector<int>&arr,int sum,int n,int i){
        if(sum==0){
            return true;
        }
        if(i>=n || sum<0){
            return false;
        }
        if(t[sum][i]!=-1){
            return t[sum][i];
        }
        // if(arr[n])
        
        
        bool taking=solve(arr,sum-arr[i],n,i+1);
        bool nottaking=solve(arr,sum,n,i+1);
        return t[sum][i]=taking||nottaking;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        int i=0;
        // code here 
        // int totalsum=0;
        // for(int i=0;i<n;i++){
        //     totalsum+=arr[i];
        // }
                t.resize(sum + 1, vector<int>(n, -1));

        return solve(arr,sum,n,i);
    }
};