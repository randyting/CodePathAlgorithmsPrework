int findMax(const vector<int> &D) {
    int max = 0;
    for (int i = 0; i < D.size(); i++ ) {
        if (D[i] > max) {
            max = D[i];
        }
    }
    
    return max;
}

int findMinGreaterThan(int value, int max, const vector<int> &B) {
    int min = max;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] < min && B[i] > value) {
            min = B[i];
        }
    }
    
    return min;
}

int numOccurrences(int value, const vector<int> &C) {
    int count = 0;
    for (int i = 0; i < C.size(); i++) {
        if (C[i] == value) {
            count++;
        }
    }
    return count;
}

int Solution::kthsmallest(const vector<int> &A, int k) {
    
    int occurrences = 0;
    int currentMin = 0;
    
    int max = findMax(A);

    while (occurrences < k) {
        currentMin = findMinGreaterThan(currentMin, max, A);
        occurrences += numOccurrences(currentMin, A);
    }
    
    return currentMin;
    
}