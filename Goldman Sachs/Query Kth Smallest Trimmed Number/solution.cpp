class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // We use priority queue (max heap) to get kth smallest element
        vector<int> ans;
        for (int i=0; i<queries.size(); i++){
            int k = queries[i][0];
            int trim = queries[i][1];
            priority_queue<pair<string,int>> pq; // {nums,idx}
            for (int i=0; i< nums.size(); i++){
                string temp = nums[i].substr(nums[i].length() - trim);
                pq.push({temp,i});
                if(pq.size()>k){
                    pq.pop();
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};

// NOTE: Optimization- Radix Sort
