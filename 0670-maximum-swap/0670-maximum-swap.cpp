class Solution {
public:
    int maximumSwap(int num) {
      string s = to_string(num);
      stack<pair<int,int>> st;
      for(int i = s.size()-1;i>=0;i--) {
        if(st.empty()) {
            st.push({i,i});
            continue;
        }
        int previous_max = s[st.top().second] - '0';
        int curr = s[i]-'0';
        if(curr > previous_max) {
            st.push({i,i});
        } else {
            st.push({i,st.top().second});
        }
      }
      for(int i= 0;i<s.size();i++) {
        int current = s[st.top().first] - '0';
        int currentmax = s[st.top().second] - '0';
        if(currentmax != current) {
            swap(s[st.top().first],s[st.top().second]);
            break;
        }
        st.pop();
      } 
      return stoi(s); 
    }
};