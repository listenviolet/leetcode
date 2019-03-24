class Solution {
public:
    inline int min(int a,int b)
    {
        return a<b?a:b;
    }
    int minDistance(string word1, string word2) {
        string *wp1,*wp2;
        if(word2.size()<=word1.size())
        {
            wp1=&word1;
            wp2=&word2;
        }
        else
        {
            wp1=&word2;
            wp2=&word1;
        }
        
        int *f=new int[wp2->size()+1];
        for(int i=0;i<=wp2->size();i++)
            f[i]=i;
        int last,tmp;
        for(int i=1;i<=wp1->size();i++)
        {
            
            last=f[0];
            f[0]++;
            for(int j=1;j<=wp2->size();j++)
            {
                
                tmp=f[j];
                if((*wp1)[i-1]== (*wp2)[j-1])
                    f[j]=last;
                else
                {
                    f[j]=min(min(last,f[j]),f[j-1])+1;
                }
                last=tmp;
                
            }
        }
        
        return f[wp2->size()];
    }
};

// Copied from the fastest accepted solution.
// runtime: 8ms
// Alg:
// use 1-dim lsit instead of 2-dims array
// which avoid searching by cols so that the speed is faster.
