// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
    public:
        bool isAnagram(std::string s, std::string t)
        {
            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());
            if (s == t)
                return (true);
            return (false);
        }
};

int main()
{
    Solution solution;
    std::string s = "anagram";
    std::string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    std::cout << "Is Anagram: " << (result ? "true" : "false") << std::endl;
    return 0;
}