// Name: Aditya Byju
// Date: 26/10/2022

/*
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Eg:
        Input: tokens = ["2","1","+","3","*"]
        Output: 9
        Explanation: ((2 + 1) * 3) = 9

    Time complexity: O(n)
    Space complexity: O(n)
    (n is the length of token)
*/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        long long a, b, c;
        stack<int> s;

        // loop for evaluating each token
        for (int i = 0; i < tokens.size(); ++i)
        {
            // check if the current token is a number, and then push it into the stack
            if (isdigit(tokens[i][0]) || isdigit(tokens[i][1]))
                s.push(stoi(tokens[i]));

            // if the current token is an operator then pop the latest 2 operands from the stack and perform the operation on them, adn push the result back into the stack
            else
            {
                // operand 1
                a = s.top();
                s.pop();

                // operand 2
                b = s.top();
                s.pop();

                // switch statement to determine which operation to perform, c is the variable to store the result of the operation
                switch (tokens[i][0])
                {
                case '+':
                    c = b + a;
                    break;
                case '-':
                    c = b - a;
                    break;
                case '*':
                    c = b * a;
                    break;
                default:
                    c = b / a;
                }

                // push the result back into the stack
                s.push(c);
            }
        }

        // return final computed result
        return s.top();
    }
};