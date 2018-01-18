#include <iostream>
#include "Utilities.h"

#include "Vector.h"
#include "List.h"
#include "Deque.h"
#include "Maps.h"


enum class EContainers
{
    VECTOR = 1, 
    DEQUE = 2, 
    LIST = 3, 
    MAP = 4,
    SET = 5,
    INVALID // Should be the last value. Add other containers before this
};

const int MAX_OPTIONS = static_cast<int>(EContainers::INVALID); // Increase this to match the number of containers for who demo is available

int main()
{
    PRINT("Welcome");
    
    while (1)
    {
        PRINT(R"(Choose on of the following options:
             1 - vector
             2 - deque
             3 - list
             4 - map
             5 - set
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
        case static_cast<int>(EContainers::VECTOR):
        {
            
            Vector::Demonstrate();
        }
        break;
        case static_cast<int>(EContainers::LIST):
        {
            List::Demonstrate();
        }
        break;
        case static_cast<int>(EContainers::DEQUE):
        {
            Deque::Demonstrate();
        }
        break;
        case static_cast<int>(EContainers::MAP):
        {
            Maps::Demonstrate();
        }
        break;
        case static_cast<int>(EContainers::SET):
        {

        }
        break;
        default:
            PRINT("Invalid container specified");
            break;

        }

        PRINT("\n\n---------------------------------------------\n\n"); // End of this demo cycle
    }
}