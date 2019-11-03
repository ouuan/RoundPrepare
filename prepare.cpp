#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string problem_path, template_path;

string quote(string s)
{
	return "\"" + s + "\"";
}

void copy_template(string file_name)
{
	system(("copy " + quote(template_path) + " " + quote(problem_path + "\\" + file_name)).c_str());
	system(quote(problem_path + "\\" + file_name).c_str());
}

int main()
{
	ifstream fin("config.ini");
	getline(fin, template_path);
	
	int tot;
	
	cout << "Site\\Round name: ";
	getline(cin, problem_path);
	system(("mkdir " + quote(problem_path)).c_str());
	
	cout << "Number of problems (-number for custom name): ";
	cin >> tot;
	
	if (tot >= 0)
	{
		for (int i = 0; i < tot; ++i)
		{
			copy_template(string(1, 'A' + i) + ".cpp");
		}
	}
	else
	{
		for (int i = 0; i > tot; --i)
		{
			string problem;
			cout << "Problem " << - i + 1 << ": ";
			cin >> problem;
			copy_template(problem + ".cpp");
		}
	}
	
	return 0;
}
