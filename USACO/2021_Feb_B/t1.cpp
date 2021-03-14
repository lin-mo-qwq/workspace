#include <iostream>
#include <map>
#include <string>
using namespace std;

string animals[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

map<string, int> when_born;

string get_animal(int year)
{
	int a = 0, y = 2021;
	while (y < year)
	{
		y++;
		a++;
		if (a == 12)
			a = 0;
	}
	while (y > year)
	{
		y--;
		a--;
		if (a == -1)
			a = 11;
	}
	return animals[a];
}

int main(void)
{
	int N;
	when_born["Bessie"] = 2021;
	cin >> N;
	string cowa, born, in, relation, animal, year, from, cowb;
	for (int i = 0; i < N; i++)
	{
		cin >> cowa >> born >> in >> relation >> animal >> year >> from >> cowb;
		when_born[cowa] = when_born[cowb];
		do
		{
			if (relation == "previous")
				when_born[cowa]--;
			else
				when_born[cowa]++;
		} while (get_animal(when_born[cowa]) != animal);
	}
	int diff = when_born["Bessie"] - when_born["Elsie"];
	if (diff < 0)
		diff = -diff;
	cout << diff << "\n";
}