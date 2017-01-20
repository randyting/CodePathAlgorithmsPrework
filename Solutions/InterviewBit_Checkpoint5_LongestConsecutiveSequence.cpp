void quickSort(vector<int> &B, int left, int right) {
    int i = left;
    int j = right;
    int tmp;
    int pivot = B[(left + right)/2];
    
    while (i <= j) {
        while (B[i] < pivot) {
            i++;
        }
        while (B[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = B[i];
            B[i] = B[j];
            B[j] = tmp;
            i++;
            j--;
        }
    }
    
    if (left < j) {
        quickSort(B, left, j);
    }
    if (i < right) {
        quickSort(B, i, right);
    }
}

int Solution::longestConsecutive(const vector<int> &A) {
    vector<int> X = A;
    
    quickSort(X, 0, X.size()-1);

    
    int count = 1;
    int maxCount = 1;
    
    for (int i = 0; i < X.size() - 1; i++) {
        if (X[i+1] == X[i]+1 ) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else if (X[i+1] == X[i]) {
          continue;
        } else {
            count = 1;
        }
    }
    
    return maxCount;
}