/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 下面这个是大数版本
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int l1_len = 1, l2_len = 1;

        vector<int> l1_num, l2_num, res;
        l1_num = convertVec(l1);
        l2_num = convertVec(l2);

        res = addVec(l1_num, l2_num);
        ListNode *l3;
        l3 = convertNode(res);
        return l3;

    }

    vector<int> addVec(vector<int>& l1, vector<int>& l2)
    {
        vector<int> res;
        int l1_len = l1.size();
        int l2_len = l2.size();
        int l_len,sm_len;
        vector<int> long_vec, small_vec;
        if(l1_len >= l2_len)
        {
            l_len = l1_len;
            sm_len = l2_len;
            long_vec = l1;
            small_vec = l2;
        }else{
            l_len = l2_len;
            sm_len = l1_len;
            long_vec = l2;
            small_vec = l1;
        }

        for(int i = 0; i < sm_len; ++i)
        {
            res.push_back( long_vec[i]+small_vec[i] );
        }
        for(int i = sm_len; i < l_len; ++i)
        {
            res.push_back(long_vec[i]);
        }

        for(int i = 0; i < res.size()-1; ++i)
        {
            if(res[i] > 9)
            {
                res[i] = res[i]%10;
                res[i+1] += 1;
            }
        }
        if(res[res.size()-1]>9)
        {
            res[res.size()-1] = res[res.size()-1]%10;
            res.push_back(1);
        }
        return res;


    }

    ListNode* convertNode( vector<int> num)
    {
        ListNode* l1 = new ListNode(0);
        ListNode* l_save = l1;
        for(int i = 0; i < num.size(); ++i)
        {
            ListNode* l3 = new ListNode(num[i]);

            l3->next=l1->next;
            l1->next = l3;
            l1 = l3;
        }
        ListNode* tmp = l_save;
        l_save = l_save->next;
        delete(tmp);
        return l_save;

    }



    vector<int> convertVec(ListNode* l)
    {

        vector<int> vec;
        while(l != NULL)
        {
            vec.push_back(l->val);
            l = l->next;
        }

        return vec;
    }

};
