#include <Windows.h>
#include "mem.h"
#include <iostream>

namespace setts
{
    const auto moneyset = 0x1EFA5D39250;
}

const auto mem = Memory("amtrucks.exe");



int main()
{
hack:
    system("cls");
    DWORD oldMoney = mem.Read<uint32_t>(setts::moneyset);
    int var;
    std::cout << "1. Set Money\n2. Add Money\n3. Subtract Money\n4. Clear Money\n\n";
    std::cin >> var;
    switch (var)
    {
    case 1:
        system("cls");
        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        std::cout << "What would you like to set it to?: ";
        DWORD amt;
        std::cin >> amt;

        mem.Write<uint32_t>(setts::moneyset, amt);

        std::cout << "\nMoney Set! Might have to finish a job for money to appear. (9 to go back to menu)";

        while (true)
        {
            if (GetAsyncKeyState('9'))
                break;
        }

        amt = NULL;

        if (amt != NULL)
            MessageBoxA(nullptr, "Bad cake found!", "NULL", MB_ICONERROR | MB_OK);

        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        if (oldMoney != mem.Read<uint32_t>(setts::moneyset))
            MessageBoxA(nullptr, "Bad chip found!", "NULL", MB_ICONERROR | MB_OK);

        goto hack;
        break;

    case 2:
        system("cls");
        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        std::cout << "How much would you like to add?: ";
        DWORD amt1;
        std::cin >> amt1;

        mem.Write<uint32_t>(setts::moneyset, amt1 += oldMoney);

        std::cout << "\nMoney Added! Might have to finish a job for money to appear. (9 to go back to menu)";

        while (true)
        {
            if (GetAsyncKeyState('9'))
                break;
        }

        amt1 = NULL;

        if (amt1 != NULL)
            MessageBoxA(nullptr, "Bad cake found!", "NULL", MB_ICONERROR | MB_OK);

        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        if (oldMoney != mem.Read<uint32_t>(setts::moneyset))
            MessageBoxA(nullptr, "Bad chip found!", "NULL", MB_ICONERROR | MB_OK);


        goto hack;
        break;

    case 3:
        system("cls");

        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        std::cout << "How much would you like to remove?: ";
        DWORD amt2;
        std::cin >> amt2;

        mem.Write<uint32_t>(setts::moneyset, oldMoney - amt2);
        
        if (oldMoney < 0)
        {
            mem.Write<uint32_t>(setts::moneyset, 0);
            MessageBoxA(nullptr, "Dont go below negative u silly goose", "silly billy", MB_OK);
        }

        std::cout << "\nMoney Removed! Might have to finish a job for money to appear. (9 to go back to menu)";

        while (true)
        {
            if (GetAsyncKeyState('9'))
                break;
        }

        amt = NULL;

        if (amt != NULL)
            MessageBoxA(nullptr, "Bad cake found!", "NULL", MB_ICONERROR | MB_OK);

        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        if (oldMoney != mem.Read<uint32_t>(setts::moneyset))
            MessageBoxA(nullptr, "Bad chip found!", "NULL", MB_ICONERROR | MB_OK);

        goto hack;
        break;

    case 4:
        system("cls");
        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        mem.Write<uint32_t>(setts::moneyset, 0);
        std::cout << "Removed all money! Might have to finish a job for money to dissapear! (9 to go back to menu)";

        while (true)
        {
            if (GetAsyncKeyState('9'))
                break;
        }

        oldMoney = mem.Read<uint32_t>(setts::moneyset);
        if (oldMoney != mem.Read<uint32_t>(setts::moneyset))
            MessageBoxA(nullptr, "Bad chip found!", "NULL", MB_ICONERROR | MB_OK);

        goto hack;
        break;

    default:
        goto hack;
    }
}


