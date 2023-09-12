#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

class Report
{
    std::string text;
public:
    std::string& Text() { return text; }

    void ToFirstPage()
    {
        std::cout << "Go to first page\n";
    }

    void ToLastPage()
    {
        std::cout << "Go to last page\n";
    }

    void ToPage(int pageNumber)
    {
        std::cout << "Go to " << pageNumber << " page\n";
    }


};

class Printer
{
public:
    void Print(Report* report)
    {
        std::cout << "Report:\n";
        std::cout << report->Text() << "\n";
    }
};


class Computer
{
    std::string processor;
    int memory;
public:
    std::string& Processor() { return processor; }
    int& Memory() { return memory; }

    Computer(std::string processor, int memory)
        : processor{ processor }, memory{ memory } {}
};

class Store
{
    std::vector<Computer*> computers;

public:
    void Process()
    {
        // input data
        std::string processor;
        int memory;

        std::cout << "Input processor name: ";
        std::cin >> processor;
        std::cout << "Input memry size(Gb): ";
        std::cin >> memory;

        // validation
        bool result = memory > 0 && memory <= 64;
        if (result)
            throw new std::exception("incorrect memry size");
        else
        {
            computers.push_back(new Computer(processor, memory));

            // save to file
            std::fstream file;
            file.open("data.txt", std::ios::app);
            file << processor << " " << memory << "\n";
        }
    }
};

class ICompReader
{
public:
    virtual std::vector<std::string> GetData() = 0;
};

class ICompBinder
{
public:
    virtual Computer* CreateComputer(std::vector<std::string>) = 0;
};

class ICompValidator
{
public:
    virtual bool IsValid(Computer* computer) = 0;
};

class ICompSaver
{
public:
    virtual void Save(Computer* computer, std::string fileName) = 0;
};

class StoreGood
{
    std::vector<Computer*> computers;

    ICompReader* reader;
    ICompBinder* binder;
    ICompValidator* validator;
    ICompSaver* saver;

public:
    StoreGood(ICompReader* reader,
        ICompBinder* binder,
        ICompValidator* validator,
        ICompSaver* saver)
        : reader{ reader },
        binder{ binder },
        validator{ validator },
        saver{ saver } {}

    void Process()
    {
        std::vector<std::string> data = reader->GetData();

        Computer* computer = binder->CreateComputer(data);

        if (validator->IsValid(computer))
        {
            computers.push_back(computer);
            saver->Save(computer, "data.txt");
        }
    }
};

class ConsoleCompReader : public ICompReader
{
public:
    std::vector<std::string> GetData() override
    {
        std::vector<std::string> data(2);

        std::cout << "Input processor name: ";
        std::cin >> data[0];
        std::cout << "Input memry size(Gb): ";
        std::cin >> data[1];
        return data;
    }
};



