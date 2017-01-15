void swapElements(vector<int> &C, int index1, int index2) {
    int temp = C[index1];
    C[index1] = C[index2];
    C[index2] = temp;
}

void permuteVector(map<vector<int>, bool> &existsMap, 
                    vector<vector<int>> &permutations, 
                    vector<int> &C, 
                    int left, 
                    int right) {
    if (left == right) {
        if (!existsMap[C]) {
            permutations.push_back(C);
            existsMap[C] = true;
        }
    } else {
        for (int i = left; i <= right; i++) {
            vector<int> D = C;
            swapElements(D, left, i);
            permuteVector(existsMap, permutations, D, left+1, right);
            swapElements(D, left, i);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    map<vector<int>, bool> existsMap;
    vector<vector<int>> ret;
    permuteVector(existsMap, ret, A, 0, A.size()-1);
    
    return ret;
}