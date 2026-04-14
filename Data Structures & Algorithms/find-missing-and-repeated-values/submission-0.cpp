class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0, actualSqSum = 0;

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        long long diff = actualSum - expectedSum;          
        long long diffSq = actualSqSum - expectedSqSum;      

        long long sum = diffSq / diff;                     

        int repeated = (diff + sum) / 2;
        int missing = repeated - diff;

        return {repeated, missing};
    }
};