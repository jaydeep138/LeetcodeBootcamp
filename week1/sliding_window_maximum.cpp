class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;
        for(int i = 0; i < k; i++) {
            window[nums[i]]++;
        }
        int last = 0;
        vector<int> ans;
        ans.push_back(window.rbegin()->first);
        for(int i = k; i < nums.size(); i++) {
            window[nums[last]]--;
            if(!window[nums[last]]) window.erase(nums[last]);
            window[nums[i]]++;
            ans.push_back(window.rbegin()->first);
            last++;
        }
        return ans;
    }
};