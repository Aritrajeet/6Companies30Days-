class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // We use a trick: Since all ele should be present except one, it is sure that the array values will be nothing but the indices. 
        // So, we just mark the indices as visited. If any index is visited twice it means it is repeating no.
        // If any index is unmarked means it is missing no.
        int repeat;
        for (int i=0; i<n; i++){
            int temp = arr[i];
            if(temp < 0){
                temp = -arr[i];
            }
            if(arr[temp-1] < 0){
                repeat = temp;
            }
            else
                arr[temp-1] = -arr[temp-1];
        }
        int missing;
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                missing = i+1;
                break;
            }
        }
        return {repeat,missing};
    }
};
