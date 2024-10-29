#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct Person
{
	string Name;
	string Father_s_Name_Second_Name;
	string Surname;

	string Name2;
	string Father_s_Name_Second_Name2;
	string Surname2;
};

struct FlatNumber 
{
	string FlatNumer1;
	string FlatNumer2;
};

class People
{
private:
	vector<Person> p;
	int num;
public:
	People()
	{
		p.resize(1);
		for(int i = 0; i < p.size();i++)
		{
			cout << "First:\n";
			cout << "Input the name, father`s name(Second name) and surname:"; 
			cin >> p[i].Name >> p[i].Father_s_Name_Second_Name >> p[i].Surname;
			cout << endl;
			cout << p[i].Name << endl << p[i].Father_s_Name_Second_Name << endl << p[i].Surname;
		}
	}

	People(const vector<Person>& person, int num)
	{
		this->p = person;
		cout << "If you want to add one more person press '1':"; cin >> num;
		
		if (num == 1)
		{
			p.resize(1);
			for (int i = 0; i < p.size(); i++)
			{
				cout << "Second:";
				cout << "Input the name, father`s name(Second name) and surname:";
				cin >> p[i].Name2 >> p[i].Father_s_Name_Second_Name2 >> p[i].Surname2;
				cout << endl;
				cout << p[i].Name2 << endl << p[i].Father_s_Name_Second_Name2 << endl << p[i].Surname2;
			}
		};
	}
	 void saveToFile(const string& filename) {
		ofstream file(filename);
		if (!file.is_open())
		{
			cerr << "Error opening file for writing" << endl;
			return;
		}
		for (const auto& person : p)
		{
			file << person.Name << " " << person.Father_s_Name_Second_Name << " " << person.Surname << endl; file << person.Name2 << " " << person.Father_s_Name_Second_Name2 << " " << person.Surname2 << endl;
		}
		file.close();
	}
	~People() {};
};

class Flat : public People {
private:
	vector<FlatNumber> flat;

public:
	Flat() 
	{
		string a;
		cout << "\nIf you want to copy your class People you need to press '1' if no press '2': ";
		cin >> a;
		if (a == "1") {
			string filename = "FILE.txt";
			saveToFile(filename);
			cout << "Data saved to " << filename << endl;
		}
		if(a == "2")
		{
			cout << "Goodbye,have a nice day!";
		}
	}

	Flat(const FlatNumber& Flat) {}

	~Flat() {}
	
	void SaveToFile() 
	{
		ofstream file("SecondFile.txt");
			
		string number;
		cout << "Press the flat number:"; cin >> number;
		file << number;
		file.close();
	}
};



class Home : public Flat
{
private:
public:
	void File()
	{
		string n;
		cout << "\nPress 1 if you want to see all your data:"; cin >> n;
		if(n == "1")
		{
			string homeN;
			string lineone;
			string linetwo;

			cout << "\nInput the home number:"; cin >> homeN;

			ifstream fileOne("FILE.txt"); 
			ifstream fileTwo("SecondFile.txt");
			
			while(getline(fileOne,lineone) || getline(fileTwo, linetwo))
			{
					cout << "\nAboout person:" << lineone;
					cout << "\nHome number:" << homeN;
					cout << "\nFlat number:" << linetwo;
			}

			fileOne.close();
			fileTwo.close();
		}
	};
};

int main()
{
	Home h;
	h.SaveToFile();
	h.File();
	
}