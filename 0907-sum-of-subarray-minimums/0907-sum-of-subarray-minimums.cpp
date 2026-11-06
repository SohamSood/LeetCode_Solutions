class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> previoussmaller(arr.size());
        vector<int> nextsmaller(arr.size());
        stack<int> st;
        const int mod = 1e9+7;
        for(int i = 0;i<arr.size();i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                previoussmaller[i] = -1;
            } else {
                previoussmaller[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i = arr.size()-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                nextsmaller[i] = -1;
            } else {
                nextsmaller[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<arr.size();i++) {
            int lefty = previoussmaller[i];
            int righty = nextsmaller[i];
            if(lefty == -1)  {
                lefty = i+1;
            } else {
                lefty = i - lefty;
            }
            if(righty == -1) {
                righty = arr.size()-i;
            } else {
                righty = righty - i;
            }
            long long contribution = 1LL * arr[i] * lefty * righty;
            ans = (ans + contribution)%mod;
        }
        return ans;
    }
};