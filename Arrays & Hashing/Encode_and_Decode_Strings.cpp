// https://leetcode.com/problems/encode-and-decode-strings/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:

        string encode(vector<string>& strs)
        {
            string encode_str = "";

            for (vector<string>::size_type i = 0; i < strs.size(); i++)
                encode_str += to_string(strs[i].length()) + "#" + strs[i];

            return encode_str;
        }

        vector<string> decode(string s)
        {
            vector<string> decode_strs;

            size_t i = 0;
            while (i < s.length())
            {
                size_t pos = s.find("#", i);
                size_t len = stoi(s.substr(i, pos - i));
                decode_strs.push_back(s.substr(pos + 1, len));
                i = pos + len + 1;
            }

            return decode_strs;
        }
};

int main()
{
    Solution solution;
    vector<string> strs = {"Hello", "Wo#rld", "!"};
    string encode_str = solution.encode(strs);
    vector<string> decode_strs = solution.decode(encode_str);

    std::cout << "Encode: " << encode_str << "\n";
    std::cout << "Decode: [";
    for (vector<string>::size_type i = 0; i < decode_strs.size(); i++)
        std::cout << decode_strs[i] << ",";
    std::cout << "]\n";

    return 0;
}