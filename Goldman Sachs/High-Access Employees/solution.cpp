class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // We store the access times of each employee mapping with their names. Then check if the emp has high access time
        unordered_map<string,vector<int>>emp_times;
        for (auto accessTime : access_times){
            string s = accessTime[1];
            string name = accessTime[0];
            int hrs = (s[0]-'0')*10 + (s[1]-'0');
            int mins = (s[2]-'0')*10 + (s[3]-'0');
            int time = hrs*60 + mins;
            emp_times[name].push_back(time);
        }
        vector<string>ans;
      // For each employee we check the time vector after sorting. We make groups of 3 . If the  diff between first n last is less than 1 hr, it has high access time
        for (auto emp_time : emp_times){
            string name = emp_time.first;
            vector<int> times = emp_time.second;
            sort(times.begin(),times.end());
            for (int i=1; i<times.size()-1; i++ ){
                if(times[i+1] - times[i-1]< 60){
                    ans.push_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};
