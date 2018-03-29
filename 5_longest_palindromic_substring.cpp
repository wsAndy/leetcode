// 滑窗，判断是或否回文

// 但是这个的测试通不过，很奇怪啊


class Solution {
public:
string longestPalindrome(string s) {

        vector<char> seq;
        vector<char> inv_seq;
        for(int i = 0; i < s.length(); ++i)
        {
            seq.push_back( s.at(i) );
            inv_seq.push_back( s.at(s.length()-1-i) );
        }


        // vector<int> res;
        int max_st,max_en;
        max_st = 0;
        max_en = 0;



            vector<int> tmp_seq_zero;
            vector<int> tmp_st_vec;
            vector<int> tmp_en_vec;

        // 移动错位相减，比较最长0
        for(int i = 0; i < 2*s.length()-1; ++i)
        {

            // 记录差值
            int j_len = 0, j_st = 0, k_st = 0;
            if(i<s.length())
            {
                j_len = i+1;
                j_st = 0;
                k_st = s.length() - j_len;
            }else{
                j_len = s.length();
                j_st = i-s.length()+1;
                k_st = 0;
            }


            int tmp_st = j_st, tmp_en = j_st;

            for(int j = j_st, k = k_st; j < j_len; ++j, ++k)
            {


                if( int(seq[j]) - int(inv_seq[k]) == 0)
                {

                    tmp_en = j;
                    if(j == j_len-1)
                    {
                        tmp_seq_zero.push_back(tmp_en-tmp_st);
                        tmp_st_vec.push_back(tmp_st);
	                    tmp_en_vec.push_back(tmp_en);
                    }

                }else{

                    tmp_seq_zero.push_back(tmp_en-tmp_st); // 把之前的存起来
                    tmp_st_vec.push_back(tmp_st);
                    tmp_en_vec.push_back(tmp_en);

                    tmp_en = j+1;
                    tmp_st = j+1;
                    if( j == j_len-1 )
                    {
                        tmp_en = j;
                        tmp_st = j;
                    }

                }
            }


        }
                    // 知道tmp_seq_zero中最大的那个

    string res;
    int count_num = 0;
				while(1)
				{
                    // 知道tmp_seq_zero中最大的那个
            int tmp_m = 0, tmp_m_ind = 0;
            for(int j = 0; j < tmp_seq_zero.size(); ++j)
            {
                if( tmp_seq_zero[j] > tmp_m )
                {
                    tmp_m = tmp_seq_zero[j];
                    tmp_m_ind = j;
                }
            }

        res.clear();
        for(int i = tmp_st_vec[tmp_m_ind]; i <= tmp_en_vec[tmp_m_ind]; ++i)
        {
            res+=s.at(i);
        }

        bool jud = true;
				for(int i = 0; i < (tmp_en_vec[tmp_m_ind]-tmp_st_vec[tmp_m_ind]+1)/2;++i)
				{
					if(s.at(i+tmp_st_vec[tmp_m_ind]) != s.at(tmp_en_vec[tmp_m_ind]-i) )
					{
						jud = false;
						break;
					}
				}
				if(jud)
				{
                    break;

				}else{
					tmp_seq_zero[tmp_m_ind] = 0;

				}
                    count_num ++;

                    if(count_num >= 1000)
                    {
                        break;
                    }

			}
    return res;


    }
};
