/*
https://leetcode.com/problems/maximum-sum-circular-subarray/
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)*
/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        if(a.size() == 1)
            return a[0];
        
		// calculating (a) max subarray sum and (b) max sum from right -- in O(n)
        int sum = a[a.size()-1];
        int ans = sum;
        if(sum < 0)
            sum = 0;
        
        vector<int> rsum = a;
        int temp_next = a[a.size()-1];
        for(int i=a.size()-2 ; i>=0 ; i--){
            
            sum += a[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
            
            rsum[i] = temp_next + a[i];
            temp_next = rsum[i];
            rsum[i] = max(rsum[i], rsum[i+1]);
        }
        
		// calculating sum from left and updating ans -- in O(n)
        int lsum = 0;
        for(int i=0 ; i<a.size()-2 ; i++){
            lsum += a[i];
            ans = max(ans, rsum[i+2]+lsum);
        }
        
        return ans;
    }
};
