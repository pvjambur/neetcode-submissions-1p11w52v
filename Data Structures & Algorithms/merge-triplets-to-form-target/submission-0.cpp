class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        bool X=false, Y=false, Z=false;
        for (auto &v: triplets){
            if (v[0]==x && v[1]<=y && v[2]<=z) X = true;
            if (v[0]<=x && v[1]==y && v[2]<=z) Y = true;
            if (v[0]<=x && v[1]<=y && v[2]==z) Z = true;
        }

        if (X && Y && Z) return true;
        return false;
    }
};
