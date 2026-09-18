class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            vector<int> a = heights;
            int n = heights.size();
            int area = 0;
            int currarea = 0;
            stack<pair<int,int>> st;
            for(int i = 0; i<n; i++){
                int topfirst=i;
                if(st.empty()){
                    st.push({i,a[i]});
                    continue;
                }
                while(!st.empty() && st.top().second > heights[i]){
                        currarea = (i-st.top().first) * st.top().second;
                        if(area<currarea){
                            area = currarea;
                        }
                        topfirst = st.top().first;
                        st.pop();
                }
                if(st.empty() || st.top().second < a[i]){
                    st.push({topfirst,a[i]});
                }
            }
            if(area<currarea){
                area = currarea;
            }
            
            while(!st.empty()){
                currarea = (n-st.top().first)*st.top().second;
                if(area<currarea){
                    area = currarea;
                }
                st.pop();
            }
        return area;
    }
};