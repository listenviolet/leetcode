class Solution {
public:
    bool helper(string &s, string &p, int i, int j)
    {
        if(i == s.size() && j == p.size()) return true;
        if(i == s.size())
        {
            for(int k = j; k < p.size(); ++k)
            {
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(p[j] >= 'a' && p[j] <= 'z')
        {
            if(s[i] == p[j]) return helper(s, p, i + 1, j + 1);
            else return false;
        }
        
        if(p[j] == '?')
        {
            return helper(s, p, i + 1, j + 1);
        }
        
        if(p[j] == '*')
        {
            if(j == p.size() - 1) return true;
            bool flag = false;
            for(int k = i; k < s.size(); ++k)
            {
                if(s[k] == p[j + 1] || p[j + 1] == '?')
                {
                    flag = helper(s, p, k + 1, j + 2);
                    if(flag) return flag;
                }
            }
            return flag;
        }
        return false;
    }
    
    
    bool isMatch(string s, string p) {
        if(p.size() == 0 && s.size() == 0) return true;
        if(p.size() == 0) return false;
        for(int i = 0; i < p.size() - 1; ++i)
        {
            int cnt = 0;
            int k = i;
            while(k < p.size() && p[k] == '*') {cnt++; k++;}
            if(cnt > 1)
            {
                for(int j = i; j <= p.size() - cnt; ++j)
                    p[j] = p[j + cnt - 1];
                p.erase(p.size() - cnt + 1, cnt - 1);
            }
        }
        return helper(s, p, 0, 0);
    }
    
    
};
// Time Limit Exceeded
// "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
// "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"