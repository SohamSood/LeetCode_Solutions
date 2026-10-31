class Solution {
public:
    unordered_map<int,unordered_set<int>> busses_on_station;
    queue<int> q; //current bus no
    vector<bool> bus_visited;
    unordered_map<int,bool> station_visited; 
    bool add(vector<vector<int>>& routes,int currentbus,int target) {
        for(int station:routes[currentbus]) {
            if(target == station) return true; 
            if(station_visited[station] == true) continue;
            station_visited[station] = true;
            // cout<<"newstation -> "<<station<<endl;
            for(int newbus: busses_on_station[station]) {
                if(bus_visited[newbus] == 0) {
                    q.push(newbus);
                    // cout<<"newbus-> " <<newbus<<endl;
                    bus_visited[newbus] = 1;
                }
            }
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        bus_visited = vector<bool>(routes.size(),false);
        for(int i = 0;i<routes.size();i++) {
            for(int j = 0;j<routes[i].size();j++) {
                busses_on_station[routes[i][j]].insert(i);
            }
        }
        int level = 1;
        for(int starting_bus:busses_on_station[source]){
            q.push(starting_bus);
        }
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0;k<size;k++) {
                int current_bus= q.front();
                q.pop();
                if(add(routes,current_bus,target)) return level;
            }
            level++;
        }
        return -1;
    }
};