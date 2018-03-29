// 滑窗，判断是或否回文
// 下面的代码会超出内存，可能leetcode的测试机器限定了内存
// 代码功能应该是没有问题的

class Solution {
public:
string longestPalindrome(string s) {

    if(s.length() == 1)
    {
        return s;
    }
    if(s.empty())
    {
        return "";
    }
    int max_len = 1, st = 0;
    
    for(int i = 0; i < s.length(); )
    {
        int left = i, right = i;


        // find two consecutive element
        while(right < s.length() - 1 && s[right+1] == s[right])
        {
            right++;
        }
        i = right+1;
        // if has 2 consecutive element, the next while is used to find their neighbor
        // if not has 2, than right and left used to visit their neighbor too.
        while(i<s.length() && left > 0 && right < s.length()-1 && s[left-1] == s[right+1])
        {
            left--;
            right++;
        }

        int len = right - left + 1;
        if(max_len < len)
        {
            max_len = len;
            st = left;
        }

    }

    return s.substr(st, max_len);


    }
};
