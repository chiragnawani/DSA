class Solution {
public:
    bool isValid(string s) {
        string str = s;
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
                st.push(str[i]);
            }
            else{
                if(st.size()==0){
                    return false;
                }
                
                if((st.top() == '(' && str[i] == ')')||(st.top() == '{' && str[i] == '}')||(st.top() == '[' && str[i] == ']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
    
};