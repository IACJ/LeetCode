#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
     vector<double> sampleStats(vector<int> &count)
     {
          double min_num = 999;
          double max_num = -1;
          double average_num = 0;
          double median_num = 0;
          double node_num = 0;

          double temp_sum_num = 0;
          long long temp_sum_times = 0;

          long long temp_node_num_times = 0;

          for (int i = 0; i < count.size(); i++)
          {
               if (count[i] != 0){
                    max_num = std::max(max_num, double(i));
                    min_num = std::min(min_num, double(i));
                    temp_sum_num += i * count[i];
                    temp_sum_times += count[i];
                    if (temp_node_num_times < count[i]){
                         node_num = i;
                         temp_node_num_times = count[i];
                    }
               }
          }
          average_num = temp_sum_num / temp_sum_times;

          long long temp_hafl_times = 0;

          // 找中位数
          for (int i = 0; i < count.size(); i++)
          {
               temp_hafl_times += count[i];
               if (temp_sum_times == 2 * temp_hafl_times)
               {
                    if (temp_sum_times % 2 == 1){
                         median_num = i+1;
                    }else{
                         median_num = i + 0.5;
                    }
                    break;
               }
               if (temp_sum_times < 2 * temp_hafl_times){
                
                    median_num = i;
                    break;
               }
          }
          vector<double> ans;
          ans.push_back(min_num);
          ans.push_back(max_num);
          ans.push_back(average_num);
          ans.push_back(median_num);
          ans.push_back(node_num);
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