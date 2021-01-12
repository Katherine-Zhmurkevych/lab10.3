//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createDataFile(string filename) 
{
	ofstream fout(filename); 
	char ch; 
	string s; 
	do
	{
		cout << "enter line: "; getline(cin, s); 
		cout << s << endl;
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void readDataFile(string fname) 
{
	ifstream fin(fname); 
	string s;           
	while (getline(fin, s))           
	{                                  
		cout << s << endl;
	}
}

void addLineToFile(string line, string filename) 
{
	fstream fout(filename, std::ios::app);
	fout << line << endl;
}

void getProductsByShop(string shopName, string filename)
{
	ifstream fin(filename);
	string line;
	while (getline(fin, line))          
	{
		if (line.find(shopName) != string::npos) {
			cout << line << endl;
		}
	}
}

int main()
{
	string line1 = "maslo; ashan; 54";
	string line2 = "moloko; silpo; 22";
	string line3 = "cheese; vam; 78";
	string line4 = "yogurt; arsen; 25";
	string line5 = "bread; ashan; 18";
	string newFile = "data.txt";
	createDataFile(newFile);
	readDataFile(newFile);
	addLineToFile(line1, newFile);
	addLineToFile(line2, newFile);
	addLineToFile(line3, newFile);
	addLineToFile(line4, newFile);
	addLineToFile(line5, newFile);
	readDataFile(newFile);
	string shop;
	cout << "Enter shop's name: " << endl; cin >> shop;
	getProductsByShop(shop, "data.txt");

	return 0;
}