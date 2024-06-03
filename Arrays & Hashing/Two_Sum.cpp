// https://leetcode.com/problems/two-sum/description/

#include <vector>
#include <iostream>

class Solution 
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            for (std::vector<int>::size_type i = 0; i < nums.size(); i++)
            {
                for (std::vector<int>::size_type j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] + nums[j] == target)
                        return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
            return {};
        }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(nums, target);
    if (result.size() == 2) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
        std::cout << "Values: " << nums[result[0]] << ", " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No two elements sum up to the target." << std::endl;
    }
    return 0;
}