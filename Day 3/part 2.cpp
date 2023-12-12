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
    int adj[8][2] = { // excluding the number itself
        {-1, 1}, {0, 1}, {1, 1},
        {-1, 0}, {1, 0},
        {-1, -1}, {0, -1}, {1, -1}
    };
    vector<string> lines;
    ifstream file("input.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {            
            lines.push_back(line);
        }
        file.close();
    }

    map<int, vector<int>> locs;
    for (int j = 0; j < lines.size(); j++)
    {
        bool wasLastDigit = false;
        for (int i = 0; i < lines[0].length(); i++)
        {
            int num = 0;
            if (isdigit(lines[j][i]))
            {
                // enter this only for the first digit after '.'
                if (!wasLastDigit)
                {
                    num = atoi(&lines[j][i]);
                    int digitLength = int(log10(num) + 1);
                    for (int l = 0; l < digitLength; l++)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            int x = i + l + adj[k][0];
                            int y = j + adj[k][1];
                            if (x >= 0 && x < lines[0].length() && y >= 0 && y < lines.size()) // boundary condition
                            {
                                char c = lines[y][x];
                                if (c == '*')
                                {
                                    locs[y * lines[0].length() + x].push_back(num);
                                    l = digitLength;
                                    k = 8;
                                }
                            }
                        }
                    }
                }
                wasLastDigit = true;
            }
            else
            {
                wasLastDigit = false;
            }
        }
    }

    int sum = 0;
    for (auto i : locs)
    {
        if (i.second.size() == 2)
        {
            sum += i.second[0] * i.second[1];
        }
    }

    cout << sum << endl;

    return 0;
} 