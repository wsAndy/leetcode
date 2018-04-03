// 相当于计算每一个两两相加，然后找到是否存在对应的负数
// 要避免重复输出
// 下面这个方法是超时了
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
        {
            return vector<vector<int>>();
        }

        int length = nums.size();
        vector< vector<int>> res, res_re;
        vector< vector<int>> sum(length, vector<int>(length,0));

        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                if(i == j)
                    continue;

                sum[i][j] = nums[i] + nums[j];
            }
        }

        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                if(i == j)
                    continue;
                auto itp = find(nums.begin(), nums.end(),-1*(sum[i][j]));
                int pl = itp-nums.begin();
                if(itp != nums.end() && pl != i && pl != j)
                {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[pl];
                    res.push_back(tmp);
                }
            }
        }




//         for(int i = 0; i < res.size(); ++i)
//         {
//             for(int j = 0; j < res[i].size(); ++j)
//             {
//                 cout << res[i][j] << " ";
//             }
//             cout << endl;
//         }


        for(int i = 0; i < res.size(); ++i)
        {
            if(notfind(res[i],res_re))
            {
                res_re.push_back(res[i]);
            }
        }
        
        return res_re;


    }

    bool notfind(vector< int>& res1, vector< vector< int>>& res2)
    {
        for(int i = 0; i < res2.size(); ++i)
        {
            set<int> set1;
            set1.insert(res1[0]);
            set1.insert(res1[1]);
            set1.insert(res1[2]);
            int ss = set1.size();

            set1.insert(res2[i][0]);
            set1.insert(res2[i][1]);
            set1.insert(res2[i][2]);

            if(set1.size() == ss)
            {
                return false;
            }
        }
        return true;
    }
};
