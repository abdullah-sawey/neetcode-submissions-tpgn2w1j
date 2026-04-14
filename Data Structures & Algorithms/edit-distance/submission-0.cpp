class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        return dfs(0, 0, word1, word2, m, n);
    }

    int dfs(int i, int j, string& word1, string& word2, int m, int n) {
        if (i == m) return n - j;
        if (j == n) return m - i;
        if (word1[i] == word2[j]){
            return dfs(i + 1, j + 1, word1, word2, m, n);
        }

        int res = min(1+dfs(i + 1, j, word1, word2, m, n),
                      1+dfs(i, j + 1, word1, word2, m, n));
        res = min(res, 1+dfs(i + 1, j + 1, word1, word2, m, n));
        return res ;
    }
};