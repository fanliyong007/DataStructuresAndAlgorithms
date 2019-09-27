/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp;
        tmp.insert(nums[0]+nums[1]);
        return tmp;
    }
};

