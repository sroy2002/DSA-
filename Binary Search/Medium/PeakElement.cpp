// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.

//BRUTE FORCE CODE, TC: O(N) SC: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            if((i==0 || (nums[i]>nums[i-1])) && (i==n-1 || (nums[i]>nums[i+1])))
            {
                return i;
            }
        }
        return -1;
    }
};

// OPTIMAL CODE TC: O(logN) SC: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1, high = n-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            if((nums[mid]>nums[mid+1]) && (nums[mid]>nums[mid-1])){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low = mid+1;
            }
            else high = mid-1;
        }
        return -1;
    }
};

 