class TrieNode {
public:
    unordered_map<string,TrieNode*> children;
    bool isEnd = false;
    TrieNode() {

    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    string getnext(string& s,int& i) {
        string ans = "";
        for(i;i<s.size();i++) {
            if(s[i] == '/') break;
            ans.push_back(s[i]);
        }
        i++;
        return ans;
    }
    void insert(string& s) {
        TrieNode* temp = root;
        int index = 1;
        while(true) {
            string nextchar = getnext(s,index);
            if(nextchar == "") {
                temp->isEnd = true;
                break;
            }
            if(temp->children.find(nextchar) == temp->children.end()) {
                temp->children[nextchar] = new TrieNode(); 
            }
            temp = temp->children[nextchar];
        }
    }
    vector<string> ans;
    void getans(string& s,TrieNode* root) {
        if(root == NULL) return;
        if(root->isEnd == true) {
            ans.push_back(s);
            return;
        }
        s.push_back('/');
        for(auto& x: root->children) {
            for(int i = 0;i<x.first.size();i++) {
                s.push_back(x.first[i]);
            }
            getans(s,x.second);
            for(int i = 0;i<x.first.size();i++) {
                s.pop_back();
            }
        }
        s.pop_back();
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(string s: folder) {
            insert(s);
        }
        string ab = "";
        getans(ab,root);
        return ans;
        
    }
};