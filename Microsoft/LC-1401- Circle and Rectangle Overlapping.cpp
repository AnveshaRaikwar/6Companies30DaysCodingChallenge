class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int closest_x = max(x1,min(x2,xCenter));
        int closest_y = max(y1,min(y2,yCenter));

        return pow(xCenter-closest_x,2)+pow(yCenter-closest_y,2) <= radius*radius;
    }

};