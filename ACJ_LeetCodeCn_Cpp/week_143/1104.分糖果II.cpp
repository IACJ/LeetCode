#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
     vector<int> distributeCandies(int candies, int num_people)
     {
          vector<int> ans(num_people,0);

          int i = 0;
          int j = 1;

          int candies_left = candies;

          do{
               ans[i % num_people] += std::min(candies_left, j);
               candies_left -= j;
               i++;
               j++;
          } while (candies_left >= 0);

          return ans;
     }
};

int main()
{
    cout << endl
         << "hello!" << endl;
    
    Solution solution;


    cout
        << endl
        << "Done." << endl
        << endl;
    return 0;
}