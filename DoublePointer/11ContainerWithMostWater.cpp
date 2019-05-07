/**
 Solution:
 Two pointers
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int rev = 0;
        int i = 0, j = height.size()-1;
        while(j>i){
            rev = max(rev, min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return rev;
    }
};