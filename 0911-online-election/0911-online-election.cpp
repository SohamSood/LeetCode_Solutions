class TopVotedCandidate {
public:
    vector<pair<int,int>> leader;
    unordered_map<int,int> freq;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        leader = vector<pair<int,int>>(times.size());
        int currleader = persons[0];
        for(int i = 0;i<times.size();i++) {
            freq[persons[i]]++;
            if(freq[persons[i]] >= freq[currleader]) currleader = persons[i];
            leader[i].second = currleader;
            leader[i].first = times[i];
        }
    }
    
    int q(int t) {
        int low = 0;
        int high = leader.size();
        while(low<high) {
            int mid = low+(high-low)/2;
            if (leader[mid].first <= t) {
                low = mid + 1;
            } else {
                high = mid;
            }
        } 
        return leader[low-1].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */