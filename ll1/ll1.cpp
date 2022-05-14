#include <iostream>
#include <vector>
#include<string>
#include <fstream>

using namespace std;

void Grammar();
static vector<string> rules;
int value(char ch);
vector<char> right_table(vector<string> left_value);
vector<char> left_table(vector<string> right_value);
void table(vector<string> left_rules, vector<string> right_rules);

void Grammar() 
{
	
	vector<string> left_rules;
	vector<string> right_rules;
	string leftSide;
	string rightSide;

	
	vector<string> rules{ "S->aS", "S->B", "B->bBc", "B->C", "C->dCe", "C->D", "D->fDg","D->h"};

	cout << "\nThe rules: \n" << endl;
	for (int i = 0; i < rules.size(); i++)
		                                    
		cout << rules[i] << endl;

	for (size_t i = 0; i < rules.size(); i++) 
	{
		char pos = rules[i].find("->");
		leftSide = rules[i].substr(0, pos);
		left_rules.push_back(leftSide);
		rightSide = rules[i].substr(pos + 2, 4);
		right_rules.push_back(rightSide);
	}

	table(left_rules, right_rules); 	
}


void table(vector<string> left_rules, vector<string> right_rules) 
{
	vector<string> right_index;
	vector<int> left_index;
	vector<char> right_variables, left_variables, variables;

	// Szabályok
	left_variables = left_table(left_rules);
	right_variables = right_table(right_rules);
	variables = left_table(left_rules);

	for (int n = 0; n < right_variables.size(); n++) 
	{
		variables.push_back(right_variables[n]);
	}

	cout << "\nThe table:\n\n\t";

	for(vector<char>::iterator j = right_variables.begin(); j < right_variables.end(); ++j) 
	{
		cout << *j << "\t";
	}

	cout << "\n\n";

	for(vector<char>::iterator k = variables.begin(); k < variables.end(); ++k)	
	
		cout << *k << "\t";

		for(int j = 0; j < right_variables.size(); j++)
		{
			if(value(*k) >= 65 && value(*k) <= 90)
			{
				for(int i = 0; i < left_rules.size(); i++)
				{
					if(*k == left_rules[i][0])
					{
						left_index.push_back(i);
					}
				}
				for(int i = 0; i < left_index.size(); i++)
				{
					right_index.push_back(right_rules[left_index[i]]);
				}
				if(right_variables[j] == right_index[0][0])
				{
					cout << "(" << right_variables[0] << "," << left_index[0] + 1 << ")" << "\t";
				}
				else if (right_variables[j] == right_index[0][0])
				{
					cout << "(" << right_index[1] << "," << left_index[1] + 1 << ")" << "\t";
				}
				else 
				{
					cout << "error" << "\t";
				}
				left_index.clear();
				right_index.clear();
			}
			else if(*k == '#' && right_variables[j] == '#')
			{
				cout << "ACCEPT" << "\t";
			}
			else if(*k == right_variables[j])
			{
				cout << "POP" << "\t";
			}
			else
			{
				cout << "error" << "\t";
			}
		}
		cout << endl << endl;
	}
}

vector<char> right_table(vector<string> left_value)
{
	vector<char> data;
	for(int i = 0; i < left_value.size(); i++)
	{
		for(int j = 0; j < left_value[i].size(); j++)
		{
			if(value(left_value[i][j]) >= 97 && value(left_value[i][j]) <= 122)
			{
				if(data.size() > 0)
				{
					for(int m = 0; m < data.size(); m++)
					{
						if(data[m] == left_value[i][j])
						{
							break;
						}
						else if(m + 1 == data.size())
						{
							data.push_back(left_value[i][j]);
						}
					}
				}
				else
				{
					data.push_back(left_value[i][j]);
				}
			}
		}
	}
	data.push_back('#');
	return data;
}

vector<char> left_table(vector<string> right_value) 
{
	vector<char> data;
	for(int i = 0; i < right_value.size(); i++)
	{
		for(int j = 0; j < right_value[i].size(); j++)
		{
			if(value(right_value[i][j]) >= 65 && value(right_value[i][j]) <= 90)
			{
				if(data.size() > 0)
				{
					for(int m = 0; m < data.size(); m++)
					{
						if(data[m] == right_value[i][j])
						{
							break;
						}
						else if(m + 1 == data.size())
						{
							data.push_back(right_value[i][j]);
						}
					}
				}
				else
				{
					data.push_back(right_value[i][j]);
				}
			}
		}
	}
	return data;
}


int value(char ch)	
{
	int value = ch;
	return value;
}

int main()
{

	Grammar();
}