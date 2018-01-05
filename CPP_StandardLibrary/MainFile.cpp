#include <iostream>
#include "Utilities.h"

#include "Vector.h"
#include "List.h"
#include "Deque.h"




const int MAX_OPTIONS = 3; // Increase this to match the number of containers for who demo is available

enum EContainers
{
    VECTOR = 1, 
    DEQUE = 2, 
    LIST = 3, 
    INVALID // Should be the last value. Add other containers before this
};

int main()
{
    PRINT("Welcome");

    while (1)
    {
        PRINT(R"(Choose on of the following options:
             1 - vector
             2 - deque
             3 - list
             Q - Quit)");

        char cOption = 0;

        std::cin >> cOption;

        int iOption = atoi(&cOption);

        if ((iOption < 1) || (iOption > MAX_OPTIONS))
        {
            if (cOption == 'Q')
            {
                PRINT("Thanks, Bye!");
                break;
            }
            PRINT("Wrong Message. Please try again");
            continue;
        }

        switch (iOption)
        {
        case VECTOR:
        {
            
            Vector::Demonstrate();
        }
        break;
        case LIST:
        {
            List::Demonstrate();
        }
        break;
        case DEQUE:
        {
            Deque::Demonstrate();
        }
        break;
        default:
            PRINT("Invalid container specified");
            break;

        }

        PRINT("\n\n---------------------------------------------\n\n"); // End of this demo cycle
    }
}