// https://leetcode.com/problems/group-anagrams/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
    private:
        unordered_map <string, vector<string>> map;
        string sortedStr;
        vector<vector<string>> result;

    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {

            for (vector<string>::size_type i = 0; i < strs.size(); i++)
            {
                sortedStr = strs[i];
                sort(sortedStr.begin(), sortedStr.end());
                map[sortedStr].push_back(strs[i]);
            }

            for (auto i = map.begin(); i != map.end(); i++)
                result.push_back(i->second);

            return result;
        }
};

int main()
{    
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    std::cout << "[";
    for (const auto& group : result)
    {
        std::cout << "[";
        for (const auto& str : group)
            std::cout << str << ",";
        std::cout << "],";
    }
    std::cout << "]\n";

    return 0;
}