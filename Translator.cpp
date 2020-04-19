#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include <fstream>
using namespace std;
map<string, string> CreateTranslator(string Word, string Translation)
{
	map<string, string>myMap = {};
    myMap.insert(pair<string, string>(Word, Translation));
	return myMap;
}
void AddWord(map<string, string> map, string w, string m)
{
	auto it = map.begin();
	for (; it != map.end(); it++)
	{
		if (map.find(w) == map.end())
		{
			map.insert(pair<string, string>(w, m));
		}
	}
}
void DeleteWord(map<string, string> map, string w)
{
	auto it = map.begin();
	for (; it != map.end(); it++)
	{
		if ((*it).first==w)
		{
			map.erase(it);
		}
	}
}
string SearchByWord(map<string, string> map, string w)
{
	auto it = map.begin();
	for (; it != map.end(); it++)
	{
		if ((*it).first == w)
		{
			cout << (*it).first << ' ' << it->second << "\n";
		}
	}
}
string RedactByWord(map<string, string> map, string w, string m)
{
	auto it = map.begin();
	for (; it != map.end(); it++)
	{
		if ((*it).first == w)
		{
			it->second=m;
		}
	}
}
void readTranslator(string way)
{
	ifstream file;
	file.open(way);
	if (!file)
	{
		cout << "Файл не открыт\n\n";
	}
	else
	{
		cout << "Все ОК! Файл открыт!\n\n";
	}
	string s;
	for (file >> s; !file.eof(); file >> s)
	{ 
		cout << s << endl;
	}
	file.close();
}
void writeTranslator(map<string, string> t)
{
	ofstream file;
	string buff;
	file.open("translator.txt");
	auto it = t.begin();
	for (; it != t.end(); it++)
	{
			file << (*it).first << ' ' << it->second << "\n";
	}
	file.close();
}
int main()
{
	string s, m;
	s = "Picturesque";
	m = "- живописный";
	map<string, string>ResMap = CreateTranslator(s,m);
	AddWord(ResMap, "Hello", "Привет");
	auto it = ResMap.begin();
	for (; it != ResMap.end(); it++)
	{
		cout << (*it).first << ' ' << it->second << "\n";
	}
	cout << "Search: " << SearchByWord(ResMap, "Hello")<<endl;
	RedactByWord(ResMap, "Hello", "Здравствуйте");
	auto it = ResMap.begin();
	for (; it != ResMap.end(); it++)
	{
		cout << (*it).first << ' ' << it->second << "\n";
	}
	DeleteWord(ResMap, "Hello");
	auto it = ResMap.begin();
	for (; it != ResMap.end(); it++)
	{
		cout << (*it).first << ' ' << it->second << "\n";
	}
	
	system("pause");
	return 0;



}
