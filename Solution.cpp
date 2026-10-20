#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDescents(int left, int right, vector<int>& descents){
        return descents[right] - descents[left];
    }
    bool canBeRotated(int left, int right, 
                     vector<int>& nums, vector<int>& descents){
        int isEndsDescent= 0;
        if(nums[right] > nums[left]) isEndsDescent = 1;
        return countDescents(left, right, descents) + isEndsDescent <= 1;
    }
    bool isValid(int k, int n, vector<int>& nums,
                 vector<int>& descents, vector<bool>& validCut){
        for(int left = 0; left < n; left += k){
            int right = left + k - 1;
            if(!validCut[left]) return false;
            if(!canBeRotated(left, right, nums, descents)) return false;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> descents(n, 0);
        for(int i = 1; i < n; i++){
            descents[i] = descents[i - 1];
            if(nums[i - 1] > nums[i]) descents[i]++;
        }
        vector<int> preMax(n);
        preMax[0] = nums[0];
        for(int i = 1; i < n; i++){
            preMax[i] = max(preMax[i - 1], nums[i]);
        }
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        vector<bool> validCut(n, true);
        for(int i = 1; i < n; i++){
            validCut[i] = preMax[i - 1] <= suffMin[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                if(isValid(i, n, nums, descents, validCut))
                   res += i;
            }
        }
        return res;
    }
};

