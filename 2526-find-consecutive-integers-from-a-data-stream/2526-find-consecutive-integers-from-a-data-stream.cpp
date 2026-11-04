class DataStream {
public:
    deque<int> dq;
    int size;
    int target;
    unordered_map<int,int> freq;

    DataStream(int value, int k) {
        size = k;
        target = value;
    }

    bool consec(int num) {
        dq.push_back(num);
        freq[num]++;

        if(dq.size() > size) {
            freq[dq.front()]--;

            if(freq[dq.front()] == 0)
                freq.erase(dq.front());

            dq.pop_front();
        }

        return dq.size() == size && freq.size() == 1 && freq.count(target);
    }
};