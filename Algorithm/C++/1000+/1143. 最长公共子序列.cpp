class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> lens(len1 + 1, vector<int>(len2 + 1));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    lens[i][j] = lens[i - 1][j - 1] + 1;
                } else {
                    lens[i][j] = max(lens[i - 1][j], lens[i][j - 1]);
                }
            }
        }

        return lens[len1][len2];
    }
};