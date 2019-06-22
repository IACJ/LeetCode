#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Obj
{
    int value;
    int lable;
    Obj(int value, int lable) : value(value), lable(lable){}
};

bool sort_function(Obj i, Obj j) { return (i.value > j.value); } // 从大到小

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        vector<Obj> vec;
        std::unordered_map<int, int> unordered_map_label_times;
        int ans = 0;

        for (int i = 0; i < values.size(); i++)
        {
            vec.emplace_back(values[i], labels[i]);
        }
        std::sort(vec.begin(), vec.end(), sort_function);

        for (int i = 0; i < values.size(); i++)
        {
            // cout << vec[i].value  << '\t' << vec[i].lable << endl;
           
            if (unordered_map_label_times[vec[i].lable] < use_limit)
            {
                ans += vec[i].value;
                unordered_map_label_times[vec[i].lable]++;
                num_wanted--;
                // cout << "used" << endl;
            }
            if (num_wanted == 0){
                break;
            }
        }

        return ans;
    }
};

int main(){
    cout << "come on!" << endl;
    vector<int> a = {5, 4, 3, 2, 1};
    vector<int> b = {1, 1, 2, 2, 3};

    Solution solution;
    cout << solution.largestValsFromLabels(a, b, 3, 1) << endl;

    a = {5, 4, 3, 2, 1};
    b = {1, 3, 3, 3, 2};
    cout << solution.largestValsFromLabels(a, b, 3, 2) << endl;

    a = {9, 8, 8, 7, 6};
    b = {0, 0, 0, 1, 1};
    cout << solution.largestValsFromLabels(a, b, 3, 1) << endl;

    a = {9, 8, 8, 7, 6};
    b = {0, 0, 0, 1, 1};
    cout << solution.largestValsFromLabels(a, b, 3, 2) << endl;



    return 0;
}