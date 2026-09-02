class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> a = height;
        int n = a.size();
        int i = 0;
        int j = n-1;
        int maxarea = 0;
        while(i<j){
            int area;
            if(a[i]<=a[j]){
                area = a[i]*(j-i);
                i++;
            }
            else{
                area = a[j]*(j-i);
                j--;
            }
            if(area>maxarea){
                maxarea =area;
            }
        }
        return maxarea;
    }
};