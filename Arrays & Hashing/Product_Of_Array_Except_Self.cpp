// https://leetcode.com/problems/product-of-array-except-self/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:

        vector<int> productExceptSelf(vector<int>& nums)
        {
            int size = nums.size();
            vector<int> left(size, 1);
            vector<int> right(size, 1);
            vector<int> result(size);

            for (int i = 1; i < size; i++)
                left[i] = left[i - 1] * nums[i - 1];

            for (int i = size - 2; i >= 0; i--)
                right[i] = right[i + 1] * nums[i + 1];

            for (int i = 0; i < size; i++)
                result[i] = left[i] * right[i];

            return (result);
        }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    std::cout << "Result: [";
    for (vector<int>::size_type i = 0; i < result.size(); i++)
        std::cout << result[i] << ",";
    std::cout << "]\n";

    return 0;
}