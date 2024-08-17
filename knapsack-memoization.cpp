class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W
    
    // int knapSack(int W, int wt[], int val[], int n) 
   // { 
       // Your code here
//

int t[1000][1000];  // Adjust the size based on your constraints

int solve(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (t[W][n] != -1) {
        return t[W][n];
    }

    if (wt[n - 1] <= W) {
        return t[W][n] = max(
            val[n - 1] + solve(wt, val, n - 1, W - wt[n - 1]),
            solve(wt, val, n - 1, W)
        );
    } else {
        return t[W][n] = solve(wt, val, n - 1, W);
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    memset(t, -1, sizeof(t));  // Initialize DP table with -1
    return solve(wt, val, n, W);  // Get the answer using the solve function
}
       
       
    
};