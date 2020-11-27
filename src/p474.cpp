#include <vector>
#include <string>
#include <cstring>
using namespace std;
int max(int a,int b){return a>b?a:b;};
int min(int a,int b){return a<b?a:b;};
int main()
{
    vector<string> strs({"10","0","1"});
    int m=1;int n=1;
    // vector<vector<vector<int>>> dp(m + 1,vector<vector<int>>(n + 1,vector<int>(strs.size() + 1,0)));
    // vector<vector<vector<int>>> dp(m + 1,vector<vector<int>>(n + 1,vector<int>(strs.size() + 1,0)));
    // vector<vector<int>> count(strs.size(),vector<int>(2,0);
    int dp[m+1][n+1][strs.size()+1];
    bzero(dp,(m+1)*(n+1)*(strs.size()+1)*sizeof(int));
    int count[strs.size()][2];
    bzero(count,2*strs.size()*sizeof(int));

    for (int i = 0; i < strs.size(); i++)
    {
        for (auto c : strs[i])
            count[i][c - '0']++;
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 1; k < strs.size()+1; k++)
            {
                int &res = dp[i][j][k];
                if (i < count[k-1][0] || j < count[k-1][1])
                {
                    //deprecate element k
                    res = dp[i][j][k - 1];
                }
                else
                {
                    //choose element k
                    res = max(dp[i][j][k - 1], dp[i - count[k-1][0]][j - count[k-1][1]][k - 1] + 1);
                }
            }
        }
    }
    return dp[m][n][strs.size()];
}