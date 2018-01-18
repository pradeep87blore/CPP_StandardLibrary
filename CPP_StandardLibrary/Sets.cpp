#include "Sets.h"
#include "Utilities.h"
#include <set>
#include <string>
#include <iostream>

using namespace std;

#define PRINT_SET(a) {  \
for(auto &i: a)         \
{                       \
    cout << i << endl;  \
}                       \
};

void Sets::SetInitializationDemo()
{
    set<string> set1{ "A", "B", "C" };
    PRINT_SET(set1);
}

void Sets::SetOperationsDemo()
{

}


void Sets::MultiSetInitializationDemo()
{

}

void Sets::MultiSetOperationsDemo()
{

}


void Sets::Demonstrate()
{
    PRINT("\nDemonstrating sets:\n");
    SetInitializationDemo();
    SetOperationsDemo();
    PRINT("\nEnd of set demonstration:\n");

    PRINT("\nDemonstrating multi sets:\n");
    MultiSetInitializationDemo();
    MultiSetOperationsDemo();
    PRINT("\nEnd of multi set demonstration:\n");
}
