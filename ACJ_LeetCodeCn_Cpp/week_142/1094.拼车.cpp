#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

bool sort_function(vector<int> &i, vector<int> &j) { return (i[0] < j[0]); } // 从大到小

class Solution
{
public:
     bool carPooling(vector<vector<int>> &trips, int capacity)
     {
          // std::sort(trips.begin(), trips.end(), sort_function);
          // for (int i = 0; i < trips.size(); i++)
          // {
          //      cout << trips[i][0] << ' ' << trips[i][1] << ' ' << trips[i][2] << ' '  << endl;
          // }

          map<int, int> map_station_up;
          map<int, int> map_station_down;
          int max_station = 0;

          for (int i = 0; i < trips.size(); i++)
          {
               map_station_up[trips[i][1]] += trips[i][0];
               map_station_down[trips[i][2]] += trips[i][0];
               max_station = std::max(max_station, trips[i][2]);
               max_station = std::max(max_station, trips[i][1]);
          }
          int now_in_car_num = 0;
          for (int i = 0; i <= max_station; i++)
          {
               now_in_car_num = now_in_car_num + map_station_up[i] - map_station_down[i];
               if (now_in_car_num > capacity){
                    return false;
               }
          }

          return true;
     }
};

int main()
{
    cout << endl
         << "hello!" << endl;
    
    Solution solution;

    vector<vector<int>> trips = { {9, 3, 4}, {9, 1, 7}, {4, 2, 4}, {7, 4, 5}};

    cout << solution.carPooling(trips,23);
    cout
        << endl
        << "Done." << endl
        << endl;
    return 0;
}