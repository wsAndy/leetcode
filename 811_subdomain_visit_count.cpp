class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        vector<string> result;
        unordered_map<string, int> imap;
        for(int i = 0; i < cpdomains.size(); ++i)
        {
            string nums_add = cpdomains[i];
            size_t blo = nums_add.find(" ");
            int num = atoi( (nums_add.substr(0,blo)).c_str());
            string add = nums_add.substr(blo+1,nums_add.length()-blo-1);
            if( imap.find(add) != imap.end() )
            {
                imap[add] += num;
            }else{
                imap[add] = num;
            }


                for(int j = add.length()-1; j >= 0; --j)
                {
                    if(add[j] == '.')
                    {
                        string sub = add.substr(j+1,add.length()-j-1);
                        if( imap.find(sub) != imap.end() )
                        {
                            imap[sub] += num;
                        }else{
                            imap[sub] = num;
                        }
                    }
                }



        }
        for(auto i : imap)
        {
            string st = to_string(i.second)+" "+i.first;
            result.push_back( st );
        }
        return result;

    }
};
