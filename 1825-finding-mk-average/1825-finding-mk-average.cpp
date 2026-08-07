class MKAverage {
public:
    deque<int> dq;
    multiset<int> smallestk;
    multiset<int> largestk;
    multiset<int> elements;
    int m;
    int k;
    long long sum = 0;
    void insert_val(int no) {
        dq.push_back(no);
        if(smallestk.size() < k) {
            smallestk.insert(no);
            return;
        }

        if(k == smallestk.size() && elements.size() == 0 && largestk.size() != k) {
            //push the largest value in smallestk elements inside the largestk;
            smallestk.insert(no);
            largestk.insert(*smallestk.rbegin());
            smallestk.erase(prev(smallestk.end()));
            return;
        }
        if(smallestk.size() != 0 && *smallestk.rbegin() > no) {
            smallestk.insert(no);
            if(smallestk.size() > k) {
                elements.insert(*smallestk.rbegin());
                sum+=*smallestk.rbegin();
                smallestk.erase(prev(smallestk.end()));
            }
        } else if (largestk.size() !=  0 && *largestk.begin() < no) {
            largestk.insert(no);
            if(largestk.size() > k) {
                elements.insert(*largestk.begin());
                sum+=*largestk.begin();
                largestk.erase(largestk.begin());
            }
        } else {
            elements.insert(no);
            sum+=no;
        }
    }
    void remove_val(int no) {
        if(elements.find(no) != elements.end()) {
            //found the element inside the elements only then to no issue 
            sum -= no;
            elements.erase(elements.find(no));
        } else if(largestk.find(no) != largestk.end()) {
            //found the element in the largest k elements
            largestk.erase(largestk.find(no));
            //if erased from largestk it should be immidiately replaced nahh 
            if(!elements.empty()) {
                largestk.insert(*elements.rbegin());
                sum -= *elements.rbegin();
                elements.erase(prev(elements.end()));
            }
        } else if(smallestk.find(no) != smallestk.end()) {
            //found the element
            smallestk.erase(smallestk.find(no));
            //if erased from smallestk it should be immidiately replaced;
            if(!elements.empty()) {
                smallestk.insert(*elements.begin());
                sum -= *elements.begin();
                elements.erase(elements.begin());
            }
        } 
    }

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    void addElement(int num) {
        insert_val(num);
        if(dq.size() > m) {
            remove_val(dq.front());
            dq.pop_front();
        }
    }
    
    int calculateMKAverage() {
        // for(int x:smallestk) cout<<x<<" ";
        // cout<<"break ";
        // for(int x:elements) cout<<x<<" ";
        // cout<<"break ";
        // for(int x:largestk) cout<<x<<" ";
        // cout<<endl;
        if(m > dq.size()) return -1;
        return sum/(m - 2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */