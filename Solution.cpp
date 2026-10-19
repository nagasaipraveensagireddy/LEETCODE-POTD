class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0, cnt = 0;
        for(int& it : nums){
            if(it < target) lessCount++;
            else if(it == target) cnt++;
        }
        vector<int> res;
        int idx = lessCount;
        for(int i = 0; i < cnt; i++){
            res.push_back(idx++);
        }
        return res;
    }
};