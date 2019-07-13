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
        stack_char_.clear();

        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];

            switch (c)
            {
            case '!':
                stack_char_.push_back(c);
                break;
            case '&':
                stack_char_.push_back(c);
                break;
            case '|':
                stack_char_.push_back(c);
                break;
            case '(': 
                stack_char_.push_back(c);
                break;
            case ')':
                this->closeBrackets();
                break;
            case ',':
                stack_char_.push_back(c);
                break;
            case 't':
                this->pushValue(true);
                break;
            case 'f':
                this->pushValue(false);
                break;
            default:
                assert(false);
                break;
            }
            // for (auto i : stack_char_)
            // {
            //     cout << i;
            // }
            // cout << endl;
        }

        assert((stack_char_.size() == 1));

        if (stack_char_[0] == 't')
        {
            return true;
        }
        else
        {
            return false;
        }
     }

    void pushValue(bool this_value){

        if (stack_char_.empty() || stack_char_.back() != ',')
        {
            if (this_value)
            {
                stack_char_.push_back('t');
            }
            else
            {
                stack_char_.push_back('f');
            }
        }
        else
        {
            char last_value_char = stack_char_[stack_char_.size() - 2];
            bool last_value = false;
            if (last_value_char == 't')
            {
                last_value = true;
            }
            else
            {
                last_value = false;
            }
            char last_op_char = stack_char_[stack_char_.size() - 4];
            bool final_value = false;
            if (last_op_char == '|')
            {
                final_value = last_value || this_value;
            }
            else if (last_op_char == '&')
            {
                final_value = last_value && this_value;
            }
            stack_char_.pop_back(); // ,
            stack_char_.pop_back(); // t/f
            this->pushValue(final_value);
        }
    }

    void closeBrackets(){
        if (stack_char_.size() >= 3)
        {
            char last_value_char = stack_char_[stack_char_.size() - 1];
            bool last_value = false;
            if (last_value_char == 't')
            {
                last_value = true;
            }
            else
            {
                last_value = false;
            }
            char last_op_char = stack_char_[stack_char_.size() - 3];
            if (last_op_char == '!')
            {
                last_value = !last_value;
            }

            stack_char_.pop_back(); // t/f
            stack_char_.pop_back(); // (
            stack_char_.pop_back(); // !


            this->pushValue(last_value);
        }
    }

private:
    vector<char> stack_char_;
};

int main()
{
    cout << "hello!" << endl;

    Solution solution;

    cout << solution.parseBoolExpr("!(&(&(f),&(!(t),&(f),|(f)),&(!(&(f)),&(t),|(f,f,t))))") << endl;
    cout << solution.parseBoolExpr("!(f)") << endl;

    cout
        << "Done." << endl;
    return 0;
}