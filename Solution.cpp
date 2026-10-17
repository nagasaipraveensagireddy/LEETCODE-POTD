class Solution {
public:
    static bool compare(int num1, int num2){
        int a = num1, b = num2;
        int x = 0, y = 0;
        while(a){
            int d = a % 10;
            x += d;
            a /= 10;
        }
        while(b){
            int d = b % 10;
            y += d;
            b /= 10;
        }
        if(x == y) return num1 < num2;
        return x < y;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end(), compare);
        int cnt = 0;
        vector<int> visited(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(i == mpp[nums[i]] || visited[i]) continue;

            int cycleSize = 0;
            int j = i;
            while(!visited[j]){
                visited[j] = 1;
                j = mpp[nums[j]];
                cycleSize++;
            }
            cnt += cycleSize - 1; 
        }
        return cnt;
    }
};