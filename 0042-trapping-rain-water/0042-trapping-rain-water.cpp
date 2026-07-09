class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> suffMax(n);
    //     suffMax[n - 1] = height[n - 1];
    //     for(int i = n - 2; i >= 0; i--){
    //         suffMax[i] = max(suffMax[i + 1], height[i]);
    //     }
    //     int total = 0;
    //     int leftMax = height[0];
    //     for(int i = 0; i < n; i++){
    //         leftMax = max(leftMax, height[i]);
    //         int rightMax = suffMax[i];
    //         if(height[i] < leftMax && height[i] < rightMax){
    //             total += min(leftMax, rightMax) - height[i]; 
    //         }
    //     }
    //     return total;
    // }
    int trap(vector<int>& height){
        int n = height.size();
        int leftMax = -1;
        int rightMax = -1;
        int l = 0, r = n - 1;
        int total = 0;
        while(l < r){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if(leftMax < rightMax){
                total += leftMax - height[l];
                l++;
            } else {
                total += rightMax - height[r];
                r--;
            }
        }
        return total;
    }
};