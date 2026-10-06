class Solution {
public:

    unordered_map<string,int> st; // email , parent
    unordered_map<int,set<string>> mp; // parent, belonging strings
    vector<int> parent; //parents

    int find_parent(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find_parent(parent[i]);
    }
    void merge(int a, int b) {
        int p1 = find_parent(a);
        int p2 = find_parent(b);

        if(p1 == p2) return;

        if(mp[p1].size() > mp[p2].size()) {
            parent[p2] = p1;

            for(string s : mp[p2]) {
                mp[p1].insert(s);
            }
            mp[p2].clear();
        }
        else {
            parent[p1] = p2;

            for(string s : mp[p1])
                mp[p2].insert(s);
            mp[p1].clear();
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent = vector<int>(accounts.size());
        for(int i = 0;i<parent.size();i++) parent[i] = i;

        for(int i = 0;i<accounts.size();i++) {
            for(int j = 1;j<accounts[i].size();j++) {
                string s = accounts[i][j];
                if(st.find(s)==st.end()) {
                    st[s] = find_parent(i);
                    mp[find_parent(i)].insert(s);
                } else {
                    merge(i,st[s]);
                }
            }
        }

        vector<vector<string>> ans;

        for(auto &[root, emails] : mp) {

            if(find_parent(root) != root)
                continue;

            vector<string> temp;
            temp.push_back(accounts[root][0]);

            for(string email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};