class Router {
public:
 queue<pair<pair<int,int>, int>> q;
 set<pair<pair<int,int>, int>> st;
 map<int, vector<int>> time;
 map<int, int> passed; 
 int limit = 0;

    Router(int memoryLimit) {
        limit = memoryLimit;   
    }
    
    bool addPacket(int s, int d, int t) {

        pair<pair<int,int>, int> pr = {{s,d}, t};

        int oldSize = st.size();
        st.insert(pr);

        if(oldSize == st.size())return false;

        if(q.size() == limit)
        {
            pair<pair<int,int>, int> top = q.front();
            passed[top.first.second]++;
            st.erase(top);
            q.pop();
            q.push(pr);

            time[d].push_back(t);

            return true;
        }

        q.push(pr);
        time[d].push_back(t);

        return true;
        
    }
    
    vector<int> forwardPacket() {
        if(q.size() == 0)return {};

        pair<pair<int,int>, int> pr = q.front();
        st.erase(pr);
        q.pop();

        passed[pr.first.second]++;

        return {pr.first.first, pr.first.second, pr.second};
    }
    
    int getCount(int d, int s, int e) {

        if(time.find(d) == time.end())return 0;

        // vector<int> vec = time[d];
        int removed = passed[d];

        auto st = lower_bound(time[d].begin()+removed, time[d].end(), s);
        if(st - time[d].begin() >= time[d].size())return 0;

        int start = st - time[d].begin();

        auto ed = upper_bound(time[d].begin()+removed, time[d].end(), e);
        int end = ed - time[d].begin() - 1;

        return end-start+1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */