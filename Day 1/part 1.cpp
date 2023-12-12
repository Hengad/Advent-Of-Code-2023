#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;

int main()
{
	string numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	int sum = 0;
	string line;
	ifstream file("input.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			string digits = "";
			string substring = "";
			for (int i = 0; i < line.length(); i++)
			{
				if (isdigit(line[i]))
				{
					substring = "";
					digits += line[i];
				}
				else
				{
					substring += line[i];
					for (int i = 0; i < substring.length(); i++)
					{
						for (int j = 0; j < sizeof(numbers) / sizeof(string); j++)
						{
							if (substring.substr(i, substring.length() - i).find(numbers[j]) != string::npos)
								digits += (char)(j + 1) + '0';
						}
					}
				}
			}
			string num{ digits[0], digits[digits.length() - 1] };
			sum += atoi(&num[0]);
		}
		file.close();
		cout << sum << endl;
	}
	return 0;
}