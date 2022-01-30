/*
    Problem => Generate random point in a circle
    Problem Link => https://leetcode.com/problems/generate-random-point-in-a-circle/
*/


class Solution {
public:
    double radius, cx, cy;
    Solution(double rad, double x_center, double y_center) {
        radius = rad;
        cx = x_center;
        cy = y_center;
    }
    
    //the main trick is u=to use sqrt for generating random numbers for the r(radius)
    
    vector<double> randPoint() {
        double theta = (double)rand()/RAND_MAX*2*M_PI;
        double r = sqrt((double)rand()/RAND_MAX)*(radius);
        double pt_x = r*cos(theta) + cx; 
        double pt_y = r*sin(theta) + cy;
        return vector<double>{pt_x , pt_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */