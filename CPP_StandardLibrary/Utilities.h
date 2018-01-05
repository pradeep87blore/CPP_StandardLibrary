#pragma once
#include <string>
#include <algorithm>

#define PRINT(a) Utilities::PrintMessage(a)
#define PRINT_CONTAINER(a) Utilities::PrintContainer(a)

class Utilities
{
    // Prevent class instantiation
    Utilities() {}
    ~Utilities() {}
public:
    static void PrintMessage(std::string str);

    template <typename T>
    static void PrintContainer(T &container, string sContainerName = "")
    {
        if (sContainerName == "")
        {
            PRINT("Container contains: ");
        }
        else
        {
            PRINT(sContainerName + " Container contains: ");
        }

        for (auto &i = begin(container); i != end(container); i++)
        {
            i->PrintValue();
        }
    }
};


