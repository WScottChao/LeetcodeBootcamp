class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        
        //leftproduct
        int leftproduct = 1;
        for(int l = 0; l < n; ++l){
            res[l] = leftproduct;
            leftproduct *= nums[l];
        }

        //rightproduct
        int rightproduct = 1;
        for(int r = n - 1; r >= 0; --r){
            res[r] *= rightproduct;
            rightproduct *= nums[r];
        }
        return res;
    }
};