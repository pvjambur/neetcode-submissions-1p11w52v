class Solution {
private:
    vector<int> parent,size;

    int find(int x){
        if (parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a,int b){
        int p1 = find(a);
        int p2 = find(b);

        if (p1==p2) return false;

        if (size[p1]<size[p2]){
            swap(p1,p2);
        }
        
        parent[p2] = p1;
        size[p1] += size[p2];
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i=0;i<=n;i++){
            parent[i] = i;
        }

        for (auto &e: edges){
            if (!unite(e[0],e[1])) return e;
        }

        return {};
    }
};
