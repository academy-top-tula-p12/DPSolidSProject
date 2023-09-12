#pragma once
#include <iostream>

class Rectangle
{
protected:
	int width;
	int height;
public:
	virtual int GetWidth() { return width; }
	virtual int GetHeight() { return height; }
	virtual void SetWidth(int width) 
	{
		this->width = width;
	}
	virtual void SetHeight(int height)
	{
		this->height = height;
	}

	int Area()
	{
		return GetWidth() * GetHeight();
	}
};

class Square : public Rectangle
{
public:
	virtual void SetWidth(int width)
	{
		this->width = width;
		this->height = width;
	}
	virtual void SetHeight(int height)
	{
		this->height = height;
		this->width = height;
	}
};

//////
class Account
{
	int capital;
public:
	int& Capital() { return capital; }
	virtual void SetCapital(int money)
	{
		if (money < 0)
			throw 1;
		this->Capital() = money;
	}

	virtual float GetInterest(float sum, int month, int rate)
	{
		if (sum < 0 || month > 12 || month < 1 || rate < 0)
			throw 1;

		float result = sum;
		for (int i = 0; i < month; i++)
			result += result * rate / 100;

		if (sum >= 1000)
			result += 100;

		return result;
	}
};

class MicroAccaunt : public Account
{
	void SetCapital(int money) override
	{
		if (money < 0)
			throw 1;
		if (money > 100)
			throw 2;
		this->Capital() = money;
	}

	float GetInterest(float sum, int month, int rate) override
	{
		if (sum < 0 || month > 12 || month < 1 || rate < 0)
			throw 1;

		float result = sum;
		for (int i = 0; i < month; i++)
			result += result * rate / 100;

		return result;
	}
};
