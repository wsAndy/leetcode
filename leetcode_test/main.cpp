#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int target = 9;
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);

    vector<int> num_sort;
    sort(num.begin(), num.end());

    int place = 0;
    for(int i = 0; i < num_sort.size()-1; ++i)
    {
        if(target > num_sort[i] && target < num_sort[i+1])
        {
            place = i;
        }
    }


    return 0;
}
