void swap(vector<int> &B, int idx1, int idx2) {
    int tmp = B[idx1];
    B[idx1] = B[idx2];
    B[idx2] = tmp;
}

int partition(vector<int> &D, int startIdx, int endIdx) {
    int pivotIdx = endIdx;
    int pointerIdx = startIdx;
    int i = startIdx;
    while (i < pivotIdx) {
        if (D[i] <= D[pivotIdx]) {
            swap(D, i, pointerIdx);
            pointerIdx++;
        } 
        i++;
    }
    swap(D, pivotIdx, pointerIdx);
    return pointerIdx;
}

void quickSort(vector<int> &C, int startIdx, int endIdx) {
    if (startIdx >= endIdx) {
        return;
    }
    
    int pivotIdx = partition(C, startIdx, endIdx);
    
    quickSort(C, startIdx, pivotIdx-1);
    quickSort(C, startIdx+1, endIdx);
}


int Solution::kthsmallest(const vector<int> &A, int k) {
    
    vector<int> copyVector = A;
    quickSort(copyVector, 0, A.size()-1);
    
    return copyVector[k-1];
    
}