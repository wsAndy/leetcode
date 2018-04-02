class Solution {
public:
    int romanToInt(string s) {
        map<char, int> imap;
        imap['I'] = 1;
        imap['V'] = 5;
        imap['X'] = 10;
        imap['L'] = 50;
        imap['C'] = 100;
        imap['D'] = 500;
        imap['M'] = 1000;
        int sum = 0;
        int i;
        for(i = 0; i < s.length()-1; ++i)
        {
            if(imap[s[i]] < imap[s[i+1]])
            {
                sum += -1*imap[s[i]];
            }else{
                sum += imap[s[i]];
            }
        }
        sum += imap[s[i]];
        return sum;


    }
};
