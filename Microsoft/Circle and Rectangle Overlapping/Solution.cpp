class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // check for all points in the rectangle whether lie on circle. 
        for (int i = x1; i <= x2; i++){
            for (int j = y1; j <= y2; j++){
                if((xCenter - i)*(xCenter - i) + (yCenter - j)*(yCenter - j) <= radius*radius){
                    return true;
                }
            }
        }
        return false;
    }
};
