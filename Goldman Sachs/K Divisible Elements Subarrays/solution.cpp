class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int>countP(n);
        set <vector<int>> s;
        int count = 0;
        // count no of ele divisible by p till index i for whole arr
        for(int i=0; i<n; i++){
            if(nums[i] % p == 0){
                count++;
            }
            countP[i] = count;
        }
        for (int i=0; i<n; i++){
            s.insert({nums[i]});  // one ele subarr          
            vector<int> temp;
            temp.push_back(nums[i]);    // keep adding the subarr elements 
            for(int j=i+1; j<n; j++){
                temp.push_back(nums[j]);
                int prev = 0;
                if(i != 0){
                    prev = countP[i-1];
                }
                if(countP[j] - prev <= k){ //correct subarr: the diff gives how many ele of the subarr(i,j) are divisible by p
                    s.insert(temp);
                }
                else{
                    break;
                }
            }
        }
        return s.size();
    }
};
