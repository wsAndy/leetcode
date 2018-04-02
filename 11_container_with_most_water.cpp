class Solution {
public:
    int maxArea(vector<int>& height) {

//         int l,r;
//         l = 0;
//         r = height.size()-1;
//         int S = 0;


//         for(int i = 0; i < height.size()-1; ++i)
//         {
//             for(int j = i+1; j<height.size();++j)
//             {
//                 int tmpS = (j-i)*min(height[j],height[i]);
//                 if(S < tmpS)
//                 {
//                     S = tmpS;
//                     l = i;
//                     r = j;
//                 }
//             }
//         }

        int l,r;
        l = 0;
        r = height.size()-1;
        int S = 0;
        while(l<r)
        {
            int h = min(height[l], height[r]);
            S = max(S, (r-l)*h);
            while(l<r && height[l] <=h ) l++;
            while(l<r && height[r] <=h ) r--;
        }
        return S;

    }
};
