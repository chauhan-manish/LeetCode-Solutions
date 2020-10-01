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
