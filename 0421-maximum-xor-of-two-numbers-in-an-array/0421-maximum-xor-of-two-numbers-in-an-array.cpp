class TrieNode {
public:
    TrieNode* zero = NULL;
    TrieNode* one = NULL;
    TrieNode() {

    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(int no) {
        TrieNode* temp = root;
        for(int i = 30;i>=0;i--) {
            if((no & (1<<i)) != 0) {
                if(temp->one == NULL) { //next element is zero;
                    TrieNode* newnode = new TrieNode();
                    temp->one = newnode;
                }
                temp = temp->one;
            } else {
                if(temp->zero == NULL) { //next element is zero;
                    TrieNode* newnode = new TrieNode();
                    temp->zero = newnode;
                }
                temp = temp->zero;
            }
        }
    }
     int getvalue(int no) {
        TrieNode* temp = root;
        int number = 0;
        for(int i = 30;i>=0;i--) {
            if((no & (1<<i)) == 0) { //bit is 0 // so try to find 1
                if(temp->one == NULL) { 
                    temp = temp->zero;
                } else {
                    temp = temp->one;
                    number = number|(1<<i);
                }
            } else { //means bit is 1 // so try to find 0;
                if(temp->zero == NULL) { 
                    temp = temp->one;
                    number = number | (1<<i);
                } else {
                    temp = temp->zero;
                }
            }
        }
        return number^no;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int x:nums) insert(x); 
        int maxval = INT_MIN;
        for(int x:nums) maxval = max(maxval,getvalue(x));
        return maxval;
    }
};