class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int ans = 0;
        sort(verticalCut.begin(),verticalCut.end());
        sort(horizontalCut.begin(),horizontalCut.end());
        int ptr1 = verticalCut.size()-1;
        int ptr2 = horizontalCut.size()-1;
        int used1 = 0;
        int used2 = 0;
        while(ptr1!=-1 && ptr2!=-1) {
            if(verticalCut[ptr1] > horizontalCut[ptr2]) {
                ans+=(used2+1)*verticalCut[ptr1];
                ptr1--;
                used1++;
            } else {
                ans+=(used1+1)*horizontalCut[ptr2];
                ptr2--;
                used2++;
            }
        }
        while(ptr1!=-1) {   
            ans+=(used2+1)*verticalCut[ptr1];
            ptr1--;
            used1++;
        }
        while(ptr2!=-1) {
            ans+=(used1+1)*horizontalCut[ptr2];
            ptr2--;
            used2++;
        }
        return ans;
    }
};