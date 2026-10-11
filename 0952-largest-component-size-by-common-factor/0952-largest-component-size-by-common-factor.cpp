class Solution {
public:
    vector<int> parent;
    vector<int> sizeOf;
    int findParent(int x) {
        if(parent[x]==x) return x;
        return parent[x] = findParent(parent[x]);
    }
    int merge(int parent1,int parent2) {
        if(parent1 == -1) return parent2;
        int ultimateParent1 = findParent(parent1);
        int ultimateParent2 = findParent(parent2);
        if(ultimateParent1 == ultimateParent2) return ultimateParent1;
        if(sizeOf[ultimateParent1] > sizeOf[ultimateParent2]) {
            sizeOf[ultimateParent1] += sizeOf[ultimateParent2];
            parent[ultimateParent2] = ultimateParent1;
            return ultimateParent1;
        } else {
            sizeOf[ultimateParent2] += sizeOf[ultimateParent1];
            parent[ultimateParent1] = ultimateParent2;
            return ultimateParent2;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        parent = vector<int>(nums.size());
        for(int i = 0;i<nums.size();i++) {
            parent[i] = i;
        }
        sizeOf = vector<int>(nums.size(),1);
        
        unordered_map<int, int> primeOwner;

        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            for(int p = 2; p * p <= x; p++) {
                if(x % p == 0) {

                    if(primeOwner.find(p) != primeOwner.end()) {
                        merge(i, primeOwner[p]);
                    } else {
                        primeOwner[p] = i;
                    }

                    while(x % p == 0) {
                        x /= p;
                    }
                }
            }

            if(x > 1) {
                if(primeOwner.find(x) != primeOwner.end()) {
                    merge(i, primeOwner[x]);
                } else {
                    primeOwner[x] = i;
                }
            }
        }

        int ans = 0;

        for(int i = 0;i<sizeOf.size();i++) {
            if(parent[i] == i) ans = max(ans,sizeOf[i]);
        }
        return ans;
    }
};