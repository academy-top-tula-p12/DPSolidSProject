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
		std::cout << "чистить картошку\n";
		std::cout << "варим картошку\n";
		std::cout << "толчем картошку\n";
		std::cout << "добавляем молоко и масло\n";
		std::cout << "пюре готово\n";
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
		std::cout << "чистить картошку\n";
		std::cout << "варим картошку\n";
		std::cout << "толчем картошку\n";
		std::cout << "добавляем молоко и масло\n";
		std::cout << "пюре готово\n";
	}
};

class SaladMeal : public IMeal
{
public:
	void Make() override
	{
		std::cout << "режем огурцы\n";
		std::cout << "режем помидоры\n";
		std::cout << "поливаем маслом\n";
		std::cout << "салат готов\n";
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
		std::cout << "чистить картошку\n";
	}

	void Cook() override
	{
		std::cout << "варим картошку\n";
		std::cout << "толчем картошку\n";
		std::cout << "добавляем молоко и масло\n";
	}

	void Final() override
	{
		std::cout << "пюре готово\n";
	}
};

class SaladMealSecond : public MealBase
{
public:
	void Prepare() override
	{
		std::cout << "режем огурцы\n";
		std::cout << "режем помидоры\n";
	}

	void Cook() override
	{
		std::cout << "смешиваем овощи\n";
		std::cout << "поливаем маслом\n";
	}

	void Final() override
	{
		std::cout << "салат готов\n";
	}
};

