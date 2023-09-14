#include <iostream>
#include "PrincipleO.h"
#include "PrincipleL.h"
#include "PrincipleD.h"

void TestRectangle(Rectangle* rect)
{
    rect->SetHeight(10);
    rect->SetWidth(5);
    if (rect->Area() != 50)
        std::cout << "calculate error\n";
    else
        std::cout << "calculate good\n";
}

void InitAccount(Account* acc)
{
    acc->SetCapital(200);
    std::cout << acc->Capital() << "\n";
}

void CalcInterest(Account* acc)
{
    float sum = acc->GetInterest(1000, 1, 10);
    if (sum < 1200)
        throw 2;
}

int main()
{
    /*
    setlocale(LC_ALL, "Russian");

    Cook* jim = new Cook("Jim");
    jim->MakeDinner();

    CookGood* bob = new CookGood("Bob");
    bob->MakeDinner(new PotateMeal());
    bob->MakeDinner(new SaladMeal());

    CookGoodSecond* tom = new CookGoodSecond("Tom");
    std::vector<MealBase*> menu;
    menu.push_back(new PatatoMealSecond());
    menu.push_back(new SaladMealSecond());
    tom->MakeDinner(menu);
    */

    /*
    Rectangle* rect = new Rectangle();
    TestRectangle(rect);
    std::cout << "\n";
    delete rect;

    rect = new Square();
    TestRectangle(rect);
    std::cout << "\n";
    */

    //Account* acc = new MicroAccaunt();
    //InitAccount(acc);
    //CalcInterest(acc);


    Book* book = new Book();
    book->Text() = "Hello world";

    book->Printer() = new PrinterConsole();
    book->Print();
    book->Printer() = new PrinterHtml();
    book->Print();
}
