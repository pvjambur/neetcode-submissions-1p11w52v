class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({n, 0});
        visited.insert(n);

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            for (int sq : squares) {
                int next = curr - sq;

                if (next == 0) return steps + 1;

                if (next > 0 && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};