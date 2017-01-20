vector<int> Solution::nextGreater(vector<int> &A) {
   
   vector<int> R(A.size(), -1);
   
   for (int i = 0; i < A.size() - 1; i++ ) {
       int j = i+1;
       while ( j < A.size() - 1 && A[j] <= A[i] ) {
            j++;
        }
        if (A[j] > A[i]) {
            R[i] = A[j];
        }
   }
   
   return R;
   
}