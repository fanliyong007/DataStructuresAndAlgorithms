/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp;
        for(auto i:nums)
        {
            need_index=find(nums.begin(),nums.end(),targe-i);
            if(need_index!= -1)
            {
                tmp.push_back(i);
                tmp.push_back(nums[need_index]);
            }
        }
        return tmp;
    }
};

