class TrieNode {
public:
    int value;
    TrieNode* children[26];
    TrieNode(int value){
        this->value = value;
        for(int i = 0;i<26;i++) children[i] = nullptr;
    } 
};
class Solution {
public:
    TrieNode* root;
    void add(string& s) {
        TrieNode* temp = root;
        for(int i = 0;i<s.size();i++) {
            if(temp->children[s[i] - 'a'] == nullptr) {
                TrieNode* newnode = new TrieNode(1);
                temp->children[s[i] - 'a'] = newnode;
                temp = newnode;
            } else {
                temp = temp->children[s[i]-'a'];
                temp->value++;
            }
        }
    } 
    int calc(string& s) {
        int ans = 0;
        TrieNode* temp = root;
        for(int i = 0;i<s.size();i++) {
            temp = temp->children[s[i]-'a'];
            ans+=temp->value;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        root = new TrieNode(0);
        for(string& s:words) {
            add(s);
        }
        for(string& s:words) {
            ans.push_back(calc(s));
        }
        return ans;
    }
};