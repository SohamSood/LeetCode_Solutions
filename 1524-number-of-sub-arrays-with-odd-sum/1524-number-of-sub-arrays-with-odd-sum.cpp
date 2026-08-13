class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = arr[0]%2 == 1;
        int even = arr[0]%2 == 0;
        int mod = 1e9+7;
        long long ans = odd;
        for(int i = 1 ;i<arr.size();i++) {
            if(arr[i] % 2 == 0) {
                even++;
            } else {
                swap(odd,even);
                odd++;
            }
            
            ans = (odd + ans)%mod;
        } 
        return ans;
    }
};