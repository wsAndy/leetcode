// 这个傻乎乎题目，条件设置这么多

class Solution {
public:
    int myAtoi(string str) {
        vector<int> new_vec;
        int i = 0;
        int minus = 1;
        int used = 0;
        int seq = 0;
        int change = false;
        while(i<str.size())
        {
            if(str[i] == '+')
            {
                used++;
                if( (i+1)<str.size() && (int(str[i+1]) >int('9') || int(str[i+1]) < int('0') ) )
                {
                    return 0;
                }
            }
            if(str[i] == '-')
            {
                minus = -1;
                used++;

                if( (i+1)<str.size() && (int(str[i+1]) >int('9') || int(str[i+1]) < int('0') ) )
                {
                    return 0;
                }
            }
            if( int(str[i]) <= int('9') && int(str[i]) >= int('0') )
            {
                seq = 1;
                change = true;
                new_vec.push_back( minus*(int(str[i])-int('0'))  );
            }else{
                seq = 0;
            }

            if(change == true && seq == 0)
            {
                break;
            }

            if(str[i] != ' ' && str[i] != '+' && str[i] != '-' && (int(str[i])<int('0') || int(str[i]) > int('9')) )
            {
                return 0;
            }

            i++;
        }
        if(used > 1)
        {
            return 0;
        }

        int ans = 0, tmp = 0;
        i = 0;
        while(i<new_vec.size())
        {
            tmp = ans * 10 + new_vec[i]%10;
            if(tmp/10 != ans)
            {
                if(minus == -1)
                {
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
            ans = tmp;
            i++;
        }

        return ans;

    }
};
