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
    int sum = 0;
    string line;
    string temp;
    ifstream file("input.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            int highestBlue = 1;
            int highestGreen = 1;
            int highestRed = 1;
            bool possible = true;
            stringstream ss(line);
            vector<string> words;
            while (getline(ss, temp, ' '))
            {
                words.push_back(temp);
            }
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i].find("blue") != string::npos)
                {
                    int num = atoi(&words[i - 1][0]);
                    if (num > highestBlue)
                        highestBlue = num;
                }
                else if (words[i].find("red") != string::npos)
                {
                    int num = atoi(&words[i - 1][0]);
                    if (num > highestRed)
                        highestRed = num;
                }
                else if (words[i].find("green") != string::npos)
                {
                    int num = atoi(&words[i - 1][0]);
                    if (num > highestGreen)
                        highestGreen = num;
                }
            }
            sum += highestBlue * highestGreen * highestRed;
            cout << line << endl;
            cout << highestBlue << " - " << highestGreen << " - " << highestRed << " - " << endl;
        }
        file.close();
        cout << sum << endl;
    }
    return 0;
}