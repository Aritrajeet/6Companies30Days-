class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans = "";
        int n = S.length();
        stack<int> st; //used to store reverse numbers
        int num = 1;
        for (int i=0; i<n; i++){
            if (S[i] == 'D'){  // Just keep adding on stack
                st.push(num++);
            }
            else{  // for U, complete all prev D and curr U
                st.push(num++);
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
      // for all D case
            st.push(num++);
            while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
        return ans;
    }
};
