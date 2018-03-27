// 这个创冲循环自然可解决
// 使用unordered_map这个内部实现红黑树的数据结构，能很灵活的处理问题

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size() -1; ++i)
        {
            for(int j = i+1; j < nums.size(); ++j )
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }

        return res;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        // 构造树
        unordered_map<int, int > int_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = int_map.find(target - nums[i]);
            if (it != int_map.end())
            {
                res[0] = i;
                res[1] = it->second;
                break;
            }
            int_map[nums[i]] = i;
        }

        return res;
    }
};
