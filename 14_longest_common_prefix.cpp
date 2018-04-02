class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        string prefix = "";
        int min_length = strs[0].length();
        for(int i = 0; i < strs.size(); ++i)
        {
            if(strs[i].empty())
            {
                return "";
            }
            if(min_length > strs[i].length())
            {
                min_length = strs[i].length();
            }

        }
        for(int i = 0; i < min_length; ++i)
        {
            char tmp = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(tmp != strs[j][i])
                {
                    return prefix;
                }
            }
            prefix += tmp;
        }
        return prefix;

    }
};
