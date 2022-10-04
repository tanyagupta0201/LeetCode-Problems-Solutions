// Name: Shubham Yadav 
// Date: 4/10/22

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        set<int> s;
        for (auto &c : sentence)
            s.insert(c);
        return s.size() == 26;
    }
};