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

    vector<int> num;
    sort(num.begin(), num.end());

    int place = 0;
    for(int i = 0; i < num.size()-1; ++i)
    {
        if(target > num[i] && target < num[i+1])
        {
            place = i;
            break;
        }
    }

    int st = 0;
    for(int i = 0; i < place; ++i)
    {
        if(num[i] + num[place] == target)
        {
            st = i;
            break;
        }
    }



    return 0;
}
