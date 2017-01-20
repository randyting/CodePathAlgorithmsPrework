vector<vector<int> > Solution::prettyPrint(int A) {
    
    int numRows = 2*A -1;
    
    vector<int> topRow(numRows, A);
    
    vector<vector<int>> ret(numRows, topRow);
    
    for (int i = 1; i < numRows/2 + 1; i++ ) {
        for (int j = i; j < numRows - i; j++ ) {
            ret[i][j] = A - i;
            ret[j][i] = A - i;
            ret[numRows - i - 1][j] = A - i;
            ret[j][numRows - i - 1] = A - i;
        }
    }
    
    return ret;
}
