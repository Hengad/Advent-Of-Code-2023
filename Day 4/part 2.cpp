#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<vector<int>> winNums;
    vector<vector<int>> yourNums;
    ifstream file("input.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            bool startReading = false;
            string buffer = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ':')
                {
                    startReading = true;
                    i += 2;
                }
                if (line[i] == '|')
                {
                    string intBuff = "";
                    vector<int> nums;
                    for (int k = 0; k < buffer.length(); k++)
                    {
                        intBuff += buffer[k];
                        if(buffer[k] == ' ' && intBuff != " ")
                        {
                            nums.push_back(atoi(&intBuff[0]));
                            intBuff = "";
                        }
                    }
                    winNums.push_back(nums);
                    buffer = "";
                    i += 2;
                }
                if (startReading)
                {
                    buffer += line[i];
                }
            }
            string intBuff = "";
            vector<int> nums;
            for (int k = 0; k < buffer.length(); k++)
            {
                intBuff += buffer[k];
                if (buffer[k] == ' ' && intBuff != " ")
                {
                    nums.push_back(atoi(&intBuff[0]));
                    intBuff = "";
                }
            }
            nums.push_back(atoi(&intBuff[0]));
            yourNums.push_back(nums);
        }
        file.close();
    }

    // <cardNumber, numberOfCopies>
    map<int, int> copiesForCard;
    for (int i = 0; i < winNums.size(); i++)
    {
        copiesForCard[i + 1] = 1;
    }
    for (int i = 0; i < winNums.size(); i++)
    {
        int matchingNumbers = 0;
        for (auto val : winNums[i])
        {
            if (find(yourNums[i].begin(), yourNums[i].end(), val) != yourNums[i].end())
            {
                matchingNumbers++;
                copiesForCard[i+1 + matchingNumbers] += copiesForCard[i+1];
            }
        }
    }

    int totalCards = 0;
    for (auto e : copiesForCard)
    {
        totalCards += e.second;
    }
    cout << "total: " << totalCards << endl;

    return 0;
}