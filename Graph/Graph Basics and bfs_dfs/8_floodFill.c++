#include <bits/stdc++.h>
using namespace std;

class Solution {
    void floodfill(vector<vector<int>>& img, int color, int prev, int x, int y, int xa[], int ya[]) {
        // Only set the color if the current pixel's color matches the previous color
        if (img[x][y] != prev) return; // Exit if the color is not the previous color
        img[x][y] = color; // Set the new color

        int row = img.size();
        int col = img[0].size();

        for(int i = 0; i < 4; i++) {
            int xt = x + xa[i]; // Use the X array for x-direction
            int yt = y + ya[i]; // Use the Y array for y-direction
            // Check bounds and the previous color
            if(xt >= 0 && yt >= 0 && xt < row && yt < col && img[xt][yt] == prev) {
                floodfill(img, color, prev, xt, yt, xa, ya);
            }
        }
        return ;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        if (r == 0) return image; // Handle empty image case
        int previousColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int X[4] = {-1, 0, 1, 0}; // Directions for x-axis
        int Y[4] = {0, -1, 0, 1}; // Directions for y-axis

        // Only call floodfill if the color is different
        if(previousColor != color) {
            floodfill(ans, color, previousColor, sr, sc, X, Y); // Corrected function name and parameter
        }
        return ans;
    }
};
