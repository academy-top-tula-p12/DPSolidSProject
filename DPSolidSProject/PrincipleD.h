#pragma once
#include <iostream>

class IPrinter
{
public:
	virtual void Print(std::string text) = 0;
};

class PrinterConsole : public IPrinter
{
public:
	void Print(std::string text) override
	{
		std::cout << text << "\n";
	}
};

class PrinterHtml : public IPrinter
{
public:
	void Print(std::string text) override
	{
		std::cout << "<html>" << text << "</html>\n";
	}
};

class Book
{
	std::string text;
	IPrinter* printer;
public:
	std::string& Text() { return text; }
	IPrinter*& Printer() { return printer; }

	void Print()
	{
		printer->Print(this->text);
	}
};

