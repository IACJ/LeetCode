#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
     bool parseBoolExpr(string expression)
     {
          if (expression.size() == 1)
          {
               if (expression[0] =='t')
               {
                    return true;
               }
               else
               {
                    return false;
               }
          }

          vector<char> stack_op;
          vector<bool> stack_val;

          int i = 0;

          while (i < expression.size())
          {
               char c = expression[i];
               switch (c)
               {
               case '!':
               {
                    stack_op.push_back('!');
                    i++;
                    break;
               }
               case '|':
               {
                    stack_op.push_back('|');
                    i++;
                    break;
               }
               case '&':
               {
                    stack_op.push_back('&');
                    i++;
                    break;
               }
               case 't':
               {
                    bool this_val = true;
                    if (stack_val.empty())
                    {
                         stack_val.push_back(this_val);
                    }
                    else
                    {
                         bool last_val = stack_val.back();
                         stack_val.pop_back();
                         if (stack_op.back() == '|')
                         {
                              this_val = last_val || this_val;
                         }
                         else if (stack_op.back() == '&')
                         {
                              this_val = last_val && this_val;
                         }
                         stack_val.push_back(this_val);
                    }
                    break;
               }
               case 'f':
               {
                    bool this_val = false;
                    if (stack_val.empty())
                    {
                         stack_val.push_back(this_val);
                    }
                    else
                    {
                         bool last_val = stack_val.back();
                         stack_val.pop_back();
                         if (stack_op.back() == '|')
                         {
                              this_val = last_val || this_val;
                         }
                         else if (stack_op.back() == '&')
                         {
                              this_val = last_val && this_val;
                         }
                         stack_val.push_back(this_val);
                    }
                    break;
               }
               case ')':
               {
                    if (stack_op.back() == '!')
                    {
                         bool this_val = stack_val.back();
                         stack_val.pop_back();
                         stack_val.push_back(!this_val);
                    }
                    stack_op.pop_back();
                    break;
               }
               case ',':
               {  
                    break;
               }

               default:
               {
                    break;
               }
               }
               i++;
          }

          return stack_val[0];
     }
};

int main()
{
    cout << endl
         << "hello!" << endl;
    
    Solution solution;

    solution.parseBoolExpr("!(&(&(f),&(!(t),&(f),|(f)),&(!(&(f)),&(t),|(f,f,t))))");

    cout
        << endl
        << "Done." << endl
        << endl;
    return 0;
}