class LockingTree {
private:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> lock_holder;
    int n;
    vector<pair<int,int>> locked_nei;

    void dfs(int node, bool onlyChild, int val){
        if (onlyChild){
            for (auto nei: adj[node]){
                locked_nei[nei].first += val;
                dfs(nei,true,val);
            }
        }
        else{
            int nei = parent[node];
            if (nei==-1) return;
            locked_nei[nei].second += val;
            dfs(nei,false,val);
        }
    }

    int dfs_unlock(int node, int locks){
        int own = 0;
        if (lock_holder[node]!=-1) own++;
        int val = own;
        lock_holder[node] = -1;
        locked_nei[node].first -= locks;
        locked_nei[node].second = 0;
        for (auto nei: adj[node]){
            val += dfs_unlock(nei,locks + own);
        }
        return val;
    }

public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        this->parent = parent;
        lock_holder.assign(n,-1);
        adj.assign(n,{});
        locked_nei.assign(n,{0,0});
        for (int i=0;i<n;i++){
            if (parent[i]==-1) continue;
            adj[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lock_holder[num]==-1){
            lock_holder[num] = user;
            dfs(num,true,1);
            dfs(num,false,1);
            return true;
            
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lock_holder[num]==user){
            lock_holder[num] = -1;
            dfs(num,true,-1);
            dfs(num,false,-1);
            return true;
            
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (lock_holder[num]!=-1 || locked_nei[num].first!=0 || locked_nei[num].second<1) return false;
        int val = dfs_unlock(num,0);
        lock_holder[num] = user;
        dfs(num, false, 1 - val);
        dfs(num, true, 1);
        return true;
    }
};
