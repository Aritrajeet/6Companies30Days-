class Solution {
public:
    vector<string> ans;
    // Try all possibilities using the given nos.
    void solve(string digits,string letters[], int idx,string temp){
        if(idx == digits.length()){
            ans.push_back(temp);
            return;
        }
        int n = (digits[idx]-'0');
        
        for (int i=0; i< letters[n].length(); i++){           
            temp.push_back(letters[n][i]);
            solve(digits,letters,idx+1,temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0);
        string letters[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;  
        string temp;
        solve(digits,letters,0,temp);
        if (ans[0] == "")
            ans.pop_back();
        return ans;
    }
};
