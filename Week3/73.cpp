class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();         // size of rows
        int n = matrix[0].size();      // sizes of cols

        vector<int> rows(m, 0);        // initalize rows as m
        vector<int> cols(n, 0);        // initalize cols as n

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;       // mark i rows needs to be set as 0
                    cols[j] = 1;       // mark j cols needs to be set as 0
                }
            }
        }

        // sett 0 rows
        for (int i = 0; i < m; i++) {
            if (rows[i] == 1) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // sett 0 cols
        for (int j = 0; j < n; j++) {
            if (cols[j] == 1) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};