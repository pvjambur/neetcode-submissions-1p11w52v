class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool dead[10000] = {};
        bool vis[10000] = {};

        for (string s : deadends) {
            dead[stoi(s)] = true;
        }

        int targetNum = stoi(target);

        if (dead[0])
            return -1;

        queue<int> q;
        q.push(0);
        vis[0] = true;

        int moves = 0;
        int place[4] = {1000, 100, 10, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int cur = q.front();
                q.pop();

                if (cur == targetNum)
                    return moves;

                for (int i = 0; i < 4; i++) {
                    int p = place[i];
                    int digit = (cur / p) % 10;

                    // Turn wheel forward
                    int next1;
                    if (digit == 9)
                        next1 = cur - 9 * p;
                    else
                        next1 = cur + p;

                    // Turn wheel backward
                    int next2;
                    if (digit == 0)
                        next2 = cur + 9 * p;
                    else
                        next2 = cur - p;

                    if (!dead[next1] && !vis[next1]) {
                        vis[next1] = true;
                        q.push(next1);
                    }

                    if (!dead[next2] && !vis[next2]) {
                        vis[next2] = true;
                        q.push(next2);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};