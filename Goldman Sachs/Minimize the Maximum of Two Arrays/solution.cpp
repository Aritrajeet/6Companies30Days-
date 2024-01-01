class Solution {
public:
    bool isPossible(int n, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2){
        int divBy1 = n/divisor1;
        int notDivBy1 = n - divBy1;
        int divBy2 = n/divisor2;
        int notDivBy2 = n - divBy2;
        int divByBoth = n/lcm((long)divisor1, divisor2);
        int notDivByEither = n - divByBoth;
      // For a number to be a possible answer it must have follow 3 conditions:
      // 1) Has at least uniqueCnt1 elements that are not divisible by divisor1
      // 2) Has at least uniqueCnt2 elements that are not divisible by divisor2
      // 3) Since there can be common elements in both set 1) and 2) we need to check if after combining (union) both the sets, is it possible to get uniqueCnt1 + uniqueCnt2 numbers
        if(uniqueCnt1 <= notDivBy1 && uniqueCnt2 <= notDivBy2 && (uniqueCnt1 + uniqueCnt2) <= notDivByEither)
            return true;
        return false;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // Minimize the maximum hints Binary Search on answer
        // We consider a max possible int, then check whether it is possible to make unique counts for both arrays using this int.
        long long int left = 1;a
        long long int right = INT_MAX;
        long long int ans = right;
        while(left <= right){
            long long int mid= left + (right-left)/2;
            cout<<mid<<endl;
            if(isPossible(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2) ){
              // Got a possible answer: now check for better answer
                ans = mid;
                right = mid - 1;
            }
            else{
              // Not an answer, decrease the answer search range
                left = mid + 1;
            }
        }
        return ans;
    }
};
