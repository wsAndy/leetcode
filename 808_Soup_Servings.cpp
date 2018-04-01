// 这种用状态来表示，的确有很好的效果，这才有算法的感觉啊


class Solution {
    private:
    // map 表示当前ab分别为xy存余量时候的a先消耗完的概率
    unordered_map<int, unordered_map<int, double> > map;
public:
    double soupServings(int N) {
        if(N==0)
        {
            return 0.5;
        }
        if(N>5000)
        {
            return 1;
        }

        return process(N,N);


    }


    double process(int x, int y)
    {
        if(x <= 0 && y >0)
        {
            return 1;
        }
        if(x <= 0 && y <= 0)
        {
            return 0.5;
        }

        if(x > 0 && y <= 0)
        {
            return 0;
        }

        if(map[x][y] != 0)
        {
            return map[x][y];
        }

        double pro = 0;
        pro += 0.25 * (process(x-100,y));
        pro += 0.25 * (process(x-75,y-25));
        pro += 0.25 * (process(x-50,y-50));
        pro += 0.25 * (process(x-25,y-75));

        map[x][y] = pro;
        return pro;

    }
};
