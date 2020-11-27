#include "util.cpp"
int main()
{
    vector<int> nums{1, 3, 2, 4, 5, 1, 4, 5};
    int target = 5;
    int s = nums.size();
    //全部变为正数，加减操作改为加或不加，转变为0-1背包问题
    // int base=0;
    // for(auto &n:nums) base=max(base,n);
    // for(auto &n:nums) n+=base;
    // int target=S+base*s;
    //dp
    vector<vector<int>> dp(target + 1, vector<int>(s + 1, 0));
    // dp[0][0]=1;
    for (int i = 0; i < target + 1; i++)
    {
        for (int j = 1; j < s + 1; j++)
        {
            dp[0][j] = 1;
            int &res = dp[i][j];
            if (nums[j - 1] > i)
            {
                //drop current element;
                res = dp[i][j - 1];
            }
            else
            {
                //choose current element
                res = dp[i - nums[j - 1]][j - 1] + dp[i][j - 1];
            }
            writeCSV(dp);
        }
    }
    return dp[target][s - 1];
}
