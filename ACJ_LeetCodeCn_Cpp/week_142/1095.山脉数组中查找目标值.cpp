#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class MountainArray
{
     public : 
     int get(int index){
          return _vec[index];
     }
     int length(){
          return _vec.size();
     }

private:
     const vector<int> _vec = {3,5,3,2,0};
};

class Solution
{
public:
     int findInMountainArray(int target, MountainArray &mountainArr)
     {
          int left_val = mountainArr.get(0);
          if (left_val == target)
          {
               return 0;
          }
          int right_val = mountainArr.get(mountainArr.length() - 1);

          int half_index = 0;
          int half_value = 0;
          int half_value_right = 0;
          int half_value_left = 0;
          int mountain_mid_index = 0;
          int mountain_mid_value = 0;
          int left_index = 0;
          int right_index = mountainArr.length() - 1;

          while(true){
               half_index = (left_index + right_index) / 2;
               half_value = mountainArr.get(half_index);
               half_value_right = mountainArr.get(half_index + 1);
               half_value_left = mountainArr.get(half_index - 1);

               if (half_value_left < half_value && half_value > half_value_right)
               {
                    mountain_mid_index = half_index;
                    mountain_mid_value = half_value;
                    if (half_value == target)
                    {
                         return half_index;
                    }
                    break;
               }
               else if (half_value_left < half_value && half_value < half_value_right)
               {
                    left_index = half_index;
                    if (half_value == target)
                    {
                         return half_index;
                    }
               }
               else if (half_value_left > half_value && half_value > half_value_right)
               {
                    right_index = half_index;
               }
          }

          int find_left = -1;
          int find_right = -1;

          if (left_val < target && mountain_mid_value > target){
               find_left = binary_find(mountainArr, 0, mountain_mid_index, target,false);
               if (find_left != -1)
               {
                    return find_left;
               }
          }

          if (right_val < target && mountain_mid_value > target)
          {
               find_right = binary_find(mountainArr, mountain_mid_index, mountainArr.length() - 1, target,true);
               if (find_right != -1)
               {
                    return find_right;
               }
          }

          if (right_val == target)
          {
               return mountainArr.length() - 1;
          }
          else 
          {
               return -1;
          }
     }

     int binary_find(MountainArray &mountainArr, int left_boundary, int right_boundary,int target,bool revert_order = false)
     {
          int half_index = 0;
          int half_value = 0;
          int left_index = left_boundary;
          int right_index = right_boundary;

          while (right_index - left_index > 1)
          {
               half_index = (left_index + right_index) / 2;
               half_value = mountainArr.get(half_index);

               if (half_value == target){
                    return half_index;
               }
               else if (half_value > target)
               {
                    if (!revert_order)
                    {
                         right_index = half_index;
                    }
                    else 
                    {
                         left_index = half_index;
                    }

               }
               else if ( half_value < target)
               {
                    if (!revert_order)
                    {
                         left_index = half_index;
                    }
                    else
                    {
                         right_index = half_index;
                    }
               }
          }
          return -1;
     }
};

int main()
{
    cout << endl
         << "hello!" << endl;
    
    Solution solution;
    MountainArray mountain_array;
    cout << solution.findInMountainArray(2, mountain_array) << endl;

    cout
        << endl
        << "Done." << endl
        << endl;
    return 0;
}