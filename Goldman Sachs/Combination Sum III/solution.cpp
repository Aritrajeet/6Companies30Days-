class Solution {
public:
    void solve(int k, int n, int prev, vector<vector<int>>&ans, vector<int>&temp){
      //Try all possibilities and use Backtracking to eliminate the wrong paths.
        if(n<0){
            return; 
        }
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);  // meets the condition: add to answer
                return;
            }
            else{
                return;
            }
        }
      // Index will always start from the next of prev index because duplicates not allowed
        for (int i=prev+1; i<10; i++){
            temp.push_back(i);  // Include curr idx in answer
            solve(k-1,n-i,i,ans,temp);
            temp.pop_back();  // Exclude curr idx from answer
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(k,n,0,ans,temp);
        return ans;
    }
};
