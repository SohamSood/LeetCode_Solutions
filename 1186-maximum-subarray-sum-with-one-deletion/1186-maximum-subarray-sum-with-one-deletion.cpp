class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int without_deletion = arr[0];//without deletion
        int with_deletion = arr[0];//with deletion
        int ans = arr[0];
        for(int i = 1;i<arr.size();i++) {
            with_deletion = max(without_deletion,with_deletion+arr[i]); // deleted max(current element is deleted , or previously any element was deleted we are simply continuing)
            without_deletion = max(arr[i],without_deletion + arr[i]); // previous undeleted max(array starts from this element , previous undeleted + currentleement);
            ans = max(ans, max(with_deletion, without_deletion));
        }
        // for(int c:with_deletion) cout<<c<<" ";
        // cout<<endl;
        // for(int c:without_deletion) cout<<c<<" "; 
        return ans;

    }
};