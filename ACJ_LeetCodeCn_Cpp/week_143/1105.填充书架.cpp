#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
     int minHeightShelves(vector<vector<int>> &books, int shelf_width)
     {
          vector<int> dp(books.size() + 1, __INT_MAX__);
          dp[0] = 0;

          for (int i = 1; i <= books.size(); i++)
          {
               int j = i - 1;
               int space_left = shelf_width;
               int level_height = 0;

               while (j>=0)
               {
                    space_left -= books[j][0];
                    if (space_left < 0)
                    {
                         break;
                    }
                    level_height = std::max(level_height, books[j][1]);
                    dp[i] = std::min(dp[i], dp[j] + level_height);
                    j--;
               }
          }
          return dp[books.size()];
     }
};

int main()
{
    cout << endl
         << "hello!" << endl;
    
    Solution solution;


    cout << endl
         << "Done." << endl
         << endl;
    return 0;
}