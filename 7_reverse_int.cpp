// 下面的这个 check操作，用于检测是否超过int32的max，因为超过时会随机分配数字
// INT_MIN与INT_MAX分别表示当前的int最小值与最大值
// 累成在tmp中体现，不用每次计算10的幂
class Solution {
public:
    int reverse(int x) {
        if(x <= INT_MIN || x >= INT_MAX)
        {
            return 0;
        }

        int tmp = 0, check = 0;
        while(1)
        {
            if(x == 0)
            {
                break;
            }

            check = tmp * 10 + x % 10;
            if(check / 10 != tmp)
            {
                return 0;
            }
            x = x/10;
            tmp = check;

        }

        return tmp;


    }

};
