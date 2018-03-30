// 构建二维vector
// 根据字符串的字符的编号，确定在哪一行vector，输入

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
        {
            return s;
        }

        vector< vector<char> > A;
        for(int i = 0; i < numRows; ++i)
        {
            vector<char> tmp;
            tmp.push_back('a');
            A.push_back(tmp);
        }

        int rows = 0, block = 0;
        for(int i = 0; i < s.length(); )
        {

            if( (i - block) / (numRows) == 0 )
            {
                rows = (i - block) % (numRows);
                A[ rows ].push_back(s[i]);
				i++;
            }else{
                // for next numRows-2
                // than block+(2*numRows-2)
                int j = 0;
                while(j < numRows - 2 && i < s.length())
                {

                    A[rows - j - 1].push_back(s[i]);
                    i++;
                    j++;
                }
                block = block + 2*numRows-2;
            }

        }


        string sout;
        for(int i = 0; i < numRows; ++i)
        {
            for(int j = 1; j < A[i].size(); ++j)
            {
                sout+=A[i].at(j);
            }
        }
        return sout;
    }
};
