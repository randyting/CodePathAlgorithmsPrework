int Solution::numRange(vector<int> &A, int B, int C) {
    
    int numOccurrences = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int currentSum = A[i];
        int subStringEndIndex = i;
        while (currentSum <= C && subStringEndIndex <= A.size() - 1) {
            if (currentSum >= B) {
                numOccurrences++;   
            }
            subStringEndIndex++;
            currentSum += A[subStringEndIndex];
        }
    }
    
    return numOccurrences;
}