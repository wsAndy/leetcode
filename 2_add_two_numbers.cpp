/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 这个说白了就是一个大数加法啊，下面这个实现的小数基本是没有问题的了
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> l1_len_vec, l2_len_vec;
        int l1_len = 1, l2_len = 1;
        l1_len_vec.push_back(l1_len);
        l2_len_vec.push_back(l2_len);

        int l1_num, l2_num;
        l1_num = convertInt(l1, l1_len_vec);
        l2_num = convertInt(l2, l2_len_vec);
        l1_len = l1_len_vec[0];
        l2_len = l2_len_vec[0];
        int res = l1_num + l2_num;
        int base_len = 1;
        if(l1_len > l2_len)
        {
            base_len = l1_len;
        }else{
            base_len = l2_len;
        }
        if( res/base_len == 0)
        {
            ;
        }else{
            base_len += 1;
        }
        ListNode *l3;
        l3 = convertNode(res, base_len);
        return l3;

    }

    ListNode* convertNode(int num, int num_len)
    {
        ListNode* l1 = new ListNode(0);
        ListNode* l_save = l1;
        int mult = 1;
        int last = 0;
        for(int i = 1; i <= num_len; ++i)
        {

            int tmp = num%mul(i) - last;
            last += tmp;
            int now_val = tmp/mul(i-1);

            ListNode* l3 = new ListNode(now_val);

            l3->next=l1->next;
            l1->next = l3;
            l1 = l3;
        }
        ListNode* tmp = l_save;
        l_save = l_save->next;
        delete(tmp);
        return l_save;

    }

    int convertInt(ListNode* l, vector<int>& l_len_vec)
    {
        int l_len = l_len_vec[0];
        ListNode* l_base = l;
        int res = 0;
        vector<int> vec;
        while(l != NULL)
        {
            vec.push_back(l->val);
            l = l->next;
        }
        for(int i = vec.size()-1; i >= 0; i--)
        {
            res += vec[i]*( mul(i) );
        }
        l_len = vec.size();
        l_len_vec[0] = l_len;
        return res;
    }

    int mul(int i)
    {
        int res = 1;
        for(int j = 0;j<i;++j)
        {
            res = res * 10;
        }
        return res;
    }
};
