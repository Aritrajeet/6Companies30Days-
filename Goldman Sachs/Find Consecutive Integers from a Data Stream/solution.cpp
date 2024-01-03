class DataStream {
public:
    int value;
    int k;
    int count = 0;
    DataStream(int value1, int k1) {
        value = value1;
        k = k1;
    }
    // We store the count of consecutive numbers that is equal to value. If there are more than k consecutive no with val k, we return true. Whenever, there is a diff no. make count 0 and return false.
    bool consec(int num) {
        if(num == value){
            count++;
        }
        else{
            count = 0;
            return false;
        }

        if(count >= k)
            return true;
        else{
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
