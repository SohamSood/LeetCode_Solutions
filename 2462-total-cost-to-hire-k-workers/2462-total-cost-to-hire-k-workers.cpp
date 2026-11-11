class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        multiset<int> st1;
        multiset<int> st2;
        for(int i = 0;i<candidates && i<costs.size();i++) {
            st1.insert(costs[i]);
        }
        for(int i = max(candidates, (int)costs.size()-candidates);i<costs.size();i++) {
            st2.insert(costs[i]);
        }
        int endst1 = min(candidates, (int)costs.size());
        int startst2 = max(candidates, (int)costs.size()-candidates);
        while(k-- && (!st1.empty() || !st2.empty())  ) {
            if(!st1.empty() && !st2.empty()) {
                if(*st1.begin() <= *st2.begin()) {
                    ans+=*st1.begin();
                    st1.erase(st1.begin());
                    if(endst1 < startst2)  {
                        st1.insert(costs[endst1]);
                        endst1++;
                    }
                } else {
                    ans+=*st2.begin();
                    st2.erase(st2.begin());
                    if(endst1 < startst2) {
                        startst2--;
                        st2.insert(costs[startst2]);
                    }
                }
                continue;
            }
            if(st1.empty()) {
                ans+=*st2.begin();
                st2.erase(st2.begin());
                if(endst1 < startst2) {
                    startst2--;
                    st2.insert(costs[startst2]);
                }
                continue;
            }
            if(st2.empty()) {
                ans+=*st1.begin();
                st1.erase(st1.begin());
                if(endst1 < startst2)  {
                    st1.insert(costs[endst1]);
                    endst1++;
                }
            }
        }
        return ans;
    }
};