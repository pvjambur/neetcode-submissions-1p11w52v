class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int n = dominoes.size();
        int prev = 0;

        for (int i = 1; i < n; i++) {
            if (dominoes[i] == '.') continue;

            int cnt = i - prev - 1;

            if (dominoes[prev] == dominoes[i]) {
                for (int j = prev + 1; j < i; j++)
                    dominoes[j] = dominoes[prev];
            }
            else if (dominoes[prev] == 'R' && dominoes[i] == 'L') {
                for (int j = 0; j < cnt / 2; j++) {
                    dominoes[prev + 1 + j] = 'R';
                    dominoes[i - 1 - j] = 'L';
                }
            }

            prev = i;
        }

        return dominoes.substr(1, n - 2);
    }
};