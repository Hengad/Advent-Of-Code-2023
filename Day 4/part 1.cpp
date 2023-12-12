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

    int sum = 0;
    for (int i = 0; i < winNums.size(); i++)
    {
        int points = 0;
        for (auto val : winNums[i])
        {
            if (find(yourNums[i].begin(), yourNums[i].end(), val) != yourNums[i].end())
            {
                if (points == 0)
                    points++;
                else
                    points *= 2;
            }
        }
        sum += points;
    }

    cout << sum << endl;
    return 0;
}