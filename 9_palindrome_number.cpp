
// 如果是进行每一位数字的分析，可能跑得更快

class Solution {
public:
    bool isPalindrome1(int x) {
        if(x < 10 && x >= 0)
        {
            return true;
        }else if(x<0)
        {
            return false;
        }

        int ans = 0;
        int xx = x;
        while(1)
        {
            ans = ans * 10 + xx % 10;
            xx = xx / 10;
            if(xx == 0)
            {
                break;
            }
        }

        if(ans-x == 0){
            return true;
        }else{
            return false;
        }


    }

    // 下面这种解法比上面的更慢
    bool isPalindrome(int x)
    {
        if(x< 10 && x >=0)
        {
            return true;
        }else if(x < 0)
        {
            return false;
        }
        int xx = x;
        int len = 1, mul = 1;
        while(1)
        {
            xx = xx / 10;
            if(xx == 0)
            {
                break;
            }else{
                mul = mul * 10;
                len++;
            }
        }
        xx = x;
        int xx_l = x, xx_r = x;
        int j = 0;
        while(j<len/2)
        {
            if( xx_r % 10 != xx_l / mul)
            {
                return false;
            }
            j++;
            xx_r = (xx_r - xx_r%10)/10;
            xx_l = (xx_l % mul);
            mul = mul / 10;
        }
        return true;
    }
};
