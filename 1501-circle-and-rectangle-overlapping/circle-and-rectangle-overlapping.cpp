class Solution {
public:
    bool checkOverlap(int radius, int x, int y, int x1, int y1, int x2, int y2) {
        /*if((x+radius)<x1) return false;
        if((x-radius)>x2) return false;
        if((y+radius)<y1) return false;
        if((y-radius)>y2) return false;
        return true;*/
        int closestX = max(x1, min(x, x2));
        int closestY = max(y1, min(y, y2));

        int dx = x - closestX;
        int dy = y - closestY;

        return (dx * dx + dy * dy <= radius * radius);
    }
};