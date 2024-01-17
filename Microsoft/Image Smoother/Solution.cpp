class Solution {
public:
// Brute force 
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans (img.size(), vector<int> (img[0].size()));
        for (int i=0; i<img.size(); i++){
            for (int j=0; j<img[0].size(); j++){
                int sum = 0;
                int count = 0;
                for (int r=i-1; r<=i+1; r++){
                    for (int c=j-1; c<=j+1; c++){
                        if(r >= 0 && r < img.size() && c >= 0 && c < img[0].size()){
                            count++;
                            sum += img[r][c];
                        }
                    }
                }
                int avg = sum/count;
                ans[i][j] = avg;
            }
        }
        return ans;
    }
};
