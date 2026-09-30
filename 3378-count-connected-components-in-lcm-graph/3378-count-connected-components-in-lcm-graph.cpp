class Solution {
public:
    vector<int> parent;

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unite(int a,int b) {
        int parent1 = findParent(a);
        int parent2 = findParent(b);
        if(parent1!=parent2) {
            parent[parent1] = parent2;
        }
    }


    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b,a%b);
    }

    bool areConnected(int a,int b,int threshold) {
        long long c = (1LL*a*b) / gcd(a,b);
        return c<=threshold;
    }

    int countComponents(vector<int>& nums, int threshold) {
        parent = vector<int>(nums.size(),-1);
        unordered_map<int,int> mp;
        vector<int> representative(threshold+1,-1);
        for(int i = 0; i < nums.size(); i++) {
            parent[i] = i;
            mp[nums[i]] = i;
        }
        for(int v:nums) {
            for(int x = v;x<=threshold;x+=v) {
                if(representative[x] == -1) {
                    representative[x] = mp[v];
                } else {
                    unite(representative[x], mp[v]);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<parent.size();i++){
            if(parent[i] == i) count++;
        } 
        return count;
    }               
};