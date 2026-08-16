class Solution {
private:
    Node* solve(vector<vector<int>>& grid,
                int r, int c, int len) {

        // Check whether this entire square is same
        bool same = true;

        for (int i = r; i < r + len; i++) {
            for (int j = c; j < c + len; j++) {
                if (grid[i][j] != grid[r][c]) {
                    same = false;
                    break;
                }
            }

            if (!same) break;
        }

        // Entire region is uniform
        if (same) {
            return new Node(grid[r][c], true);
        }

        int half = len / 2;

        Node* topLeft =
            solve(grid, r, c, half);

        Node* topRight =
            solve(grid, r, c + half, half);

        Node* bottomLeft =
            solve(grid, r + half, c, half);

        Node* bottomRight =
            solve(grid, r + half, c + half, half);

        Node* root = new Node(0, false);

        root->topLeft = topLeft;
        root->topRight = topRight;
        root->bottomLeft = bottomLeft;
        root->bottomRight = bottomRight;

        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid, 0, 0, n);
    }
};