
// 这个的思路好，但是为什么就超过内存限制了，，，，

//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end()); // 排序

        vector< vector<int>> res;
        int length = nums.size();
        int i = 0;
        while(i<length)
        {
            int target = -1*nums[i];
            int l = i+1;
            int r = length-1;
            while( l < r )
            {
                int sum = nums[l] + nums[r];
                if( sum < target )
                {
                    while(l<r && nums[++l] == nums[l-1]);// 太小了，小值向右移动
                }
                else if( sum > target)
                {
                    while( l< r && nums[--r] == nums[r+1]);// 太大了，大值向左移动
                }else{

                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});

                    while(l<r && nums[++l] == nums[l-1]);
                    while(l<r && nums[--r] == nums[r+1]);

                }
            }

            while(nums[++i] == nums[i-1]); // 移动跨越与当前target一致的位置

        }

        return res;


    }

};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end()); // 排序

        vector< vector<int>> res;
        int length = nums.size();
        int i = 0;
        while(i<length)
        {
            int target = -1*nums[i];
            int l = i+1;
            int r = length-1;
            while( l < r )
            {
                int sum = nums[l]+nums[r];
                if( sum < target )
                {
                    while(l<r && nums[++l] == nums[l-1] ); // 太小了，小值向右移动
                }
                else if( sum > target)
                {
                    while( l< r && nums[--r] == nums[r+1]); // 太大了，大值向左移动
                }else{
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[l];
                    tmp[2] = nums[r];

                    res.push_back(tmp);
                    // res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l<r && nums[++i] == nums[i-1]); // 移动跨越与当前target一致的位置
                    continue;
                }
            }

            ++i;

        }

        return res;


    }

};
