#pragma once
#include <iostream>

using namespace std;

class Room {
	string name;
	int areax;
	int areay;
	int areaz;
	bool roof;
public:
	Room(string name, int areax, int areay, int areaz, bool roof) : name{ name }, areax{ areax }, areay{ areay }, areaz{areaz}, roof{ roof }{}
	Room() :name{ "undefined" }, areax{ 0 }, areay{0}, roof{ false }{}

	string get_name()
	{
		return Room::name;
	}
	int get_areax()
	{
		return Room::areax;
	}
	int get_areay()
	{
		return Room::areay;
	}
	int get_areaz()
	{
		return Room::areaz;
	}
	bool get_roof()
	{
		return Room::roof;
	}
	int get_wall_sum()
	{
		if (Room::roof == false)
		{
			return (Room::areax * Room::areaz * 2) + (Room::areay * Room::areaz * 2);
		}
		else
		{
			return (Room::areax * Room::areaz * 2) + (Room::areay * Room::areaz * 2)+(Room::areax*Room::areay);
		}
		
	}
};







class Wallpaper {
	string name;
	int size;
	int price;
public:
	Wallpaper(string name, int size, int price) : name{ name }, size{ size }, price{ price }{}
	Wallpaper() {
		name = "";
		size = 0;
		price = 0;
	}
	string get_name()
	{
		return Wallpaper::name;
	}
	int get_size()
	{
		return Wallpaper::size;
	}
	int get_price()
	{
		return Wallpaper::price;
	}
};






class Apartament {
	int size;
	int size2;
	
public:
	
	Apartament(int size1,int sizq) {
		
		size = size1;
		size2 = sizq;
	}
	Room* Array{ new Room[size]{} };
	Wallpaper* Array_w{ new Wallpaper[size2]{} };

	
	int Get_size() 
	{
		return Apartament::size;
	}
	int Sum_of_rooms()
	{
		int sum = 0;
		for (int i = 0; i < Apartament::size; i++)
		{
			sum += Apartament::Array[i].get_wall_sum();
		}
		return sum;
	}
	void Raschet()
	{
		for (int i = 0; i < Apartament::size2; i++)
		{
			cout <<Array_w[i].get_name()<<":" << Sum_of_rooms() / Array_w[i].get_size() * Array_w[i].get_price() <<"руб" << endl;
			
		}
	}
	
};
void Assign(Apartament Array, int size)
{
	string name1;
	int areax1;
	int areay1;
	int areaz1;
	int roof1;

	for (int i = 0; i < size; i++)
	{
		cin >> name1;
		cin >> areax1;
		cin >> areay1;
		cin >> areaz1;
		cin >> roof1;
		bool roof2;
		if (roof1 == 1)
		{
			roof2 = true;
		}
		else
		{
			roof2 = false;
		}
		Room buf(name1, areax1, areay1, areaz1, roof2);
		Array.Array[i] = buf;
	}

}
void Assign_w(Apartament Array, int size)
{
	string name1;
	int price;
	int size1;

	for (int i = 0; i < size; i++)
	{
		cin >> name1;
		cin >> price;
		cin >> size1;
		
		Wallpaper buf(name1,size1,price);
		Array.Array_w[i] = buf;
	}

}