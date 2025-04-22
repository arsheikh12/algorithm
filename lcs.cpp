#include <bits/stdc++.h>
using namespace std;
string LCS(const string &string1, const string &string2) {
    int n = string1.size();
    int m = string2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
           else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    string Lsc = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (string1[i - 1] == string2[j - 1])
        {
            Lsc += string1[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
         else
        {
            --j;
        }
    }
    reverse(Lsc.begin(), Lsc.end());
    return Lsc;
}
int main() {
    string string1 = "lullabybabies";
    string string2 = "skullandbones";
    string Lsc = LCS(string1, string2);
    cout << "LCS: " << Lsc << endl;
    return 0;
}
