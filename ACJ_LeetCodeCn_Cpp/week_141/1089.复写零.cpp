#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> temp;
        int length = arr.size();
        int i = 0;
        while (length > 0)
        {
            if (arr[i] != 0){
                temp.push_back(arr[i]);
                length--;
            }else{
                temp.push_back(0);
                length--;
                if (length > 0) {
                    temp.push_back(0);
                    length--;
                }
            }
            i++;
        }
        arr.swap(temp);
    }
};

// int main() {
//     cout << "come on!" << endl;

//     vector<int> a = { 1, 0, 2, 3, 0, 4, 5, 0 };
//     Solution solution;
//     solution.duplicateZeros(a);
//     for (const auto& item : a) {
//         cout << item << ' ';
//     }

//     cout << endl;
//     return 0;
// }