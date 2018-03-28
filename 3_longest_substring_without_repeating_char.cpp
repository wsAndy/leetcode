// 滑窗
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 首先从第一个开始进入unorderedmap, 直到第一次出现相似，得到长度，先存下start以及end标记
        // 从找到的位置之后map中目前长度，这个范围内检索是否重复，没有重复就把这段全抓下来，继续向后抓
        // 直到终点，对于发现相同时、或者是到终点，则更新map
        unordered_map<char,int> imap;
        int sta = 0, en = 0;
        int max = 0;

        int len = 1;
        for(int i = 0; i < s.length(); i=i+1)
        {
            auto it = imap.find(s[i]);
            if(it != imap.end())
            {
                int find_ind = it->second; // find the same item's index


                if(find_ind + max + 1 >= s.length())
                {
                    return max; // 之后的长度已经小于目前最长的，则直接退出
                }
                // 更新imap，先把之前的删了
                for(int j = sta; j < find_ind + 1; ++j)
                {
                    imap.erase(s[j]);
                }
                // 把当前找到的加入
                imap[s[i]] = i;

                sta = find_ind + 1;



            }else{
                // not find
                imap[s[i]] = i;
                en = i;
                len = en - sta + 1;
                if(max < len)
                {
                    max = len;
                }
            }


        }

        return max;

    }
};
