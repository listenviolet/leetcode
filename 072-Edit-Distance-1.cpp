#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 1010

int main()
{
    string word1, word2;
    while(cin >> word1 >> word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0)); // Initialize with 0
        /*
        for(int i = 0; i < n + 1; ++i)
            for(int j = 0; j < m + 1; ++j)
                cout << dp[i][j] << " ";
        cout << endl;
        */
        for(int i = 1; i <=n; ++i)
        {
            dp[i][0] = i;
        }
        for(int j = 1; j <= m; ++j)
        {
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j], dp[i][j - 1]) + 1);
                }
            }
        }

        cout << dp[n][m] << endl;
    }
    return 0;
}