// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
    private:
        int count = 1;
        unordered_map<int, int> map;
        vector<int> result;
        vector<pair<int, int>> pairs;

    public:

        vector<int> topKFrequent(vector<int>& nums, int k)
        {

            sort(nums.begin(), nums.end());

            for (vector<int>::size_type i = 0; i <= nums.size() - 1; i++)
            {
                if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                    count++;
                else
                {
                    map[nums[i]] = count;
                    count = 1;
                }
            }

            pairs.assign(map.begin(), map.end());

            sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });

            for (int i = 0; i < k; i++)
                result.push_back(pairs[i].first);

            return result;
        }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, -1};
    int k = 1;
    vector<int> result = solution.topKFrequent(nums, k);

    std::cout << "[";
    for (const auto& num : result)
        std::cout << num << ",";
    std::cout << "]\n";

    return 0;
}