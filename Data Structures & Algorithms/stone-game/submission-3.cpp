class Solution {
private:
    int choose(int left, int right, int player, vector<int>& piles, vector<vector<int>>& dp, vector<int>& players){
        if (left>right) return 0;
        
        int new_player = 0;
        if (player==0) new_player = 1;

        if (dp[left][player]==-1){
            dp[left][player] = piles[left] + choose(left+1,right,new_player,piles,dp,players);
        }

        if (dp[right][player]==-1){
            dp[right][player] = piles[right] + choose(left,right-1,new_player,piles,dp,players);
        }

        return players[player] += max(dp[left][player],dp[right][player]);

    }

public:
    bool stoneGame(vector<int>& piles) {
        return true;
        
    }
};