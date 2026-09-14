class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int x = -1;
        int y = -1;
        int max_quality = -1;
        for(auto& p:towers) {
            int current_x = p[0];
            int current_y = p[1];
            int quality = p[2];
            int newdist = abs(current_x - center[0]) + abs(current_y - center[1]);
            if(newdist > radius) continue;
            if(quality > max_quality) {
                x = current_x;
                y = current_y;
                max_quality = quality;
                continue;
            }
            if(quality == max_quality) {
                if(x > current_x) {
                    x = current_x;
                    y = current_y;
                    continue;
                } 
                if(x == current_x && y > current_y) {
                    x = current_x;
                    y = current_y;
                }
            }
        }
        return {x,y};
    }
};