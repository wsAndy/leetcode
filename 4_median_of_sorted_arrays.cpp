// 这个要求计算量在log(M+N)中，这个问题下面这个不好

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> so ;
        for(auto i : nums1)
        {
            so.push_back(i);
        }
        for(auto i : nums2)
        {
            so.push_back(i);
        }

        sort(so.begin(),so.end());

        int len = so.size();
        if(len%2 == 0)
        {
            return (so[len/2-1] + so[len/2])/2.0;
        }else{
            return so[len/2];
        }


    }
};
