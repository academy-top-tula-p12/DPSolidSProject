#pragma once
#include <iostream>
#include <string>
#include <vector>

class Cook
{
	std::string name;
public:
	std::string Name() { return name; }
	Cook(std::string name) : name{ name } {}

	void MakeDinner()
	{
		std::cout << "������� ��������\n";
		std::cout << "����� ��������\n";
		std::cout << "������ ��������\n";
		std::cout << "��������� ������ � �����\n";
		std::cout << "���� ������\n";
	}
};

class IMeal
{
public:
	virtual void Make() = 0;
};

class CookGood
{
	std::string name;
public:
	std::string Name() { return name; }
	CookGood(std::string name) : name{ name } {}

	void MakeDinner(IMeal* meal)
	{
		meal->Make();
	}
};

class PotateMeal : public IMeal
{
public:
	void Make() override
	{
		std::cout << "������� ��������\n";
		std::cout << "����� ��������\n";
		std::cout << "������ ��������\n";
		std::cout << "��������� ������ � �����\n";
		std::cout << "���� ������\n";
	}
};

class SaladMeal : public IMeal
{
public:
	void Make() override
	{
		std::cout << "����� ������\n";
		std::cout << "����� ��������\n";
		std::cout << "�������� ������\n";
		std::cout << "����� �����\n";
	}
};


class MealBase
{
public:
	virtual void Prepare() = 0;
	virtual void Cook() = 0;
	virtual void Final() = 0;

	void Make()
	{
		Prepare();
		Cook();
		Final();
	}
};


class CookGoodSecond
{
	std::string name;
public:
	std::string Name() { return name; }
	CookGoodSecond(std::string name) : name{ name } {}

	void MakeDinner(std::vector<MealBase*> menu)
	{
		for (auto meal : menu)
			meal->Make();
	}
};

class PatatoMealSecond : public MealBase
{
public:
	void Prepare() override
	{
		std::cout << "������� ��������\n";
	}

	void Cook() override
	{
		std::cout << "����� ��������\n";
		std::cout << "������ ��������\n";
		std::cout << "��������� ������ � �����\n";
	}

	void Final() override
	{
		std::cout << "���� ������\n";
	}
};

class SaladMealSecond : public MealBase
{
public:
	void Prepare() override
	{
		std::cout << "����� ������\n";
		std::cout << "����� ��������\n";
	}

	void Cook() override
	{
		std::cout << "��������� �����\n";
		std::cout << "�������� ������\n";
	}

	void Final() override
	{
		std::cout << "����� �����\n";
	}
};

