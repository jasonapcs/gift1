/*
ID: jason.z2
PROG: gift1
LANG: C++14
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct person {
	int givemoney;
	int takemoney = 0;
	string name;

	

	person(string n) : name(n) {}

	person() = default;
};

int main() {
	ifstream input;
	int amountPeople;
	vector<person> pNames;


	input.open("gift1.in");
	input >> amountPeople;
	
	pNames.resize(amountPeople);
	
	for (int i = 0; i < amountPeople; i++) {
		input >> pNames[i].name;
	}
	
	for (int i = 0; i < amountPeople; i++) {
		string temp;
		input >> temp;

		int a = 0;
		for (a = 0; a < amountPeople; a++)
			if (pNames[a].name == temp) break;


		int givePeopleAmount;
		pNames[a].takemoney = 0;
		pNames[a].givemoney = 0;
		input >> pNames[a].givemoney >> givePeopleAmount;
		if (givePeopleAmount) {
			int tempmodamount = pNames[a].givemoney % givePeopleAmount;
			pNames[a].takemoney += tempmodamount;
			pNames[a].takemoney -= pNames[a].givemoney;
			int amountgiven = (pNames[a].givemoney - tempmodamount) / givePeopleAmount;
			for (int j = 0; j < givePeopleAmount; j++) {
				string givePersonName;
				input >> givePersonName;
				int k;
				for (k = 0; k < amountPeople; k++) 
					if (pNames[k].name == givePersonName) break;

				pNames[k].takemoney += amountgiven;
			}
		}
	}
	
	input.close();

	ofstream output;
	output.open("gift.out");

	for (int i = 0; i < amountPeople; i++) {
		output << pNames[i].name << " " << pNames[i].takemoney << std::endl;
	}

	output.close();
	return 0;

}
