#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {

        vector<vector<int>> max_subsequence(str1.size() + 1, vector<int>(str2.size() + 1, -1));
        vector<vector<pair<int, int>>> max_subsequence_prev_point(str1.size() + 1, vector<pair<int, int>>(str2.size() + 1, pair<int, int>(0, 0)));

        max_subsequence[0][0] = 0;

        for (int i = 0; i <= str1.size(); i++)
        {
            max_subsequence[i][0] = 0;
            max_subsequence_prev_point[i][0] = pair<int, int>(i - 1, 0);
        }

        for (int i = 0; i <= str2.size(); i++)
        {
            max_subsequence[0][i] = 0;
            max_subsequence_prev_point[0][i] = pair<int, int>(0, i - 1);
        }

        for (int i = 1; i <= str1.size(); i++)
        {
            for (int j = 1; j <= str2.size(); j++)
            {
                if (str1[i-1] == str2[j-1]){
                    if (max_subsequence[i][j] < max_subsequence[i - 1][j - 1] + 1){
                        max_subsequence[i][j] = max_subsequence[i - 1][j - 1] + 1;
                        max_subsequence_prev_point[i][j] = pair<int, int>(i - 1, j - 1);
                    }
                }
                if (max_subsequence[i][j] <= max_subsequence[i - 1][j]) {
                    max_subsequence[i][j] =  max_subsequence[i - 1][j];
                    max_subsequence_prev_point[i][j] = pair<int, int>(i - 1, j);
                }
                if (max_subsequence[i][j] <= max_subsequence[i][j - 1])
                {
                    max_subsequence[i][j] = max_subsequence[i][j - 1];
                    max_subsequence_prev_point[i][j] = pair<int, int>(i, j - 1);
                }
            }
        }

        // cout << "\t\t";
        // for (int j = 0; j < str2.size(); j++)
        // {
        //     cout << str2[j] << '\t';
        // }
        // cout << endl;
        // for (int i = 0; i <= str1.size(); i++)
        // {
        //     if (i > 0){
        //         cout << str1[i - 1] << '\t';
        //     }else {
        //         cout << '\t';
        //     }
        //     for (int j = 0; j <= str2.size(); j++)
        //     {
        //         cout << max_subsequence[i][j] << '\t';
        //     }
        //     cout << endl;
        // }

        string ans = "";
        pair<int, int> point = make_pair<int, int>(str1.size(), str2.size());
        while (true)
        {
            // cout << point.first << ' ' << point.second ;
            if (point.first == 0 && point.second == 0){
                break;
            }
            pair<int, int> prev_point = max_subsequence_prev_point[point.first][point.second];
            if (point.first - prev_point.first == 1 && point.second - prev_point.second == 0){
                ans = str1[prev_point.first] + ans;
            }
            else
            {
                ans = str2[prev_point.second] + ans;
            }

            point = max_subsequence_prev_point[point.first][point.second];
            // cout << '\t' << point.first << ' ' << point.second << endl;
        }

        return ans;
    }
};

int main() {
    cout << "hello" << endl;
    Solution solution;
    // cout << solution.shortestCommonSupersequence("abac", "cab") << endl;
    cout << solution.shortestCommonSupersequence("bbabacaa", "cccababab") << endl;
}
