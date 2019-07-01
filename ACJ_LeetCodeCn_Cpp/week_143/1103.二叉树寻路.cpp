#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
     vector<int> pathInZigZagTree(int label)
     {
          vector<int> ans;

          int now_num = label;
          ans.insert(ans.begin(), now_num);

          int base_num;
          int father_away;
          int father;

          while (now_num > 1)
          {
               base_num = 1;
               while (base_num <= now_num)
               {
                    base_num *= 2;
               }
               base_num /= 2;
               father_away = (now_num - base_num) / 2;
               father = base_num - father_away - 1;
               now_num = father;
               ans.insert(ans.begin(), now_num);
          }

          return ans;
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