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
                    if (atoi(&words[i - 1][0]) > 14)
                        possible = false;
                }
                else if (words[i].find("red") != string::npos)
                {
                    if (atoi(&words[i - 1][0]) > 12)
                        possible = false;
                }
                else if (words[i].find("green") != string::npos)
                {
                    if (atoi(&words[i - 1][0]) > 13)
                        possible = false;
                }
            }
            if (possible)
                sum += atoi(&words[1][0]);
        }
        file.close();
        cout << sum << endl;
    }
    return 0;
}