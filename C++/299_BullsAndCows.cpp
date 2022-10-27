// Name: Aditya Byju
// Date: 26/10/2022

/*
    You are playing the Bulls and Cows game with your friend.

    You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
        - The number of "bulls", which are digits in the guess that are in the correct position.
        - The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position.Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

    Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

    The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

    Eg:
        Input: secret = "1807", guess = "7810"
        Output: "1A3B"

    Time complexity: O(n)
    (n is the length of secret)
    Space complexity: O(1)
*/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();

        // vector to store and process the number of occurences of each digit in secret and guess
        vector<int> v(10);
        int bulls = 0, cows = 0;

        // loop to compare secret and guess
        for (int i = 0; i < n; ++i)
        {
            // if both elements of secret and guess are same then increment bulls
            if (secret[i] == guess[i])
                bulls++;

            // if not update vector v, and then increment cows if it satisfies the conditions
            else
            {
                // increment count of specific digit, and increment cows if its count is less than 0
                // count less than 0 indicates that the specific digit was found earlier in guess
                if (v[secret[i] - '0']++ < 0)
                    cows++;

                // decrement count of specific digit, and increment cows if its count is greater than 0
                // count greater than 0 indicates that the specific digit was found earlier in secret
                if (v[guess[i] - '0']-- > 0)
                    cows++;
            }
        }

        // return formatted result string
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};