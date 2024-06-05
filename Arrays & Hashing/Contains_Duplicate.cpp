// https://leetcode.com/problems/contains-duplicate/description/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    public:
        bool containsDuplicate(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
            for (std::vector<int>::size_type i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                    return (true);
            }
            return (false);
        }
};

int main() {
    // Test case 1: contains duplicate
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 1};
    Solution solution1;
    bool result1 = solution1.containsDuplicate(nums1);
    std::cout << "Test case 1: " << (result1 ? "Contains duplicate" : "No duplicate") << std::endl;

    // Test case 2: no duplicate
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    Solution solution2;
    bool result2 = solution2.containsDuplicate(nums2);
    std::cout << "Test case 2: " << (result2 ? "Contains duplicate" : "No duplicate") << std::endl;

    return 0;
}