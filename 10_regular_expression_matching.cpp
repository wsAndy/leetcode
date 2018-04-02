class Solution {
public:
    bool isMatch(string s, string p) {

        if(p.empty())
        {
            return s.empty();
        }
        int s_len = s.length();
        int p_len = p.length();

        vector< vector<bool>> P( s_len+1, vector<bool>(p_len+1, false) );

        P[0][0] = true;
        for(int i = 0; i < s_len+1; ++i)
        {
            for(int j = 1; j < p_len+1; ++j)
            {

                if(p[j-1] == '*')
                {
                    P[i][j] = P[i][j-2] || ( i>0 && P[i-1][j] && ( s[i-1] == p[j-2] ||p[j-2] == '.' ) ); // 这个不好理解

                }else {
                    P[i][j] = ( i>0 &&P[i-1][j-1] && ( s[i-1] == p[j-1] || p[j-1] == '.') );
                }


            }
        }
        return P[s_len][p_len];

    }
};
