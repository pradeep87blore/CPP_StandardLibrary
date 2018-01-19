#include "UnorderedMaps.h"
#include "Utilities.h"
#include "DemoClass.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <functional>

using namespace std;



#define PRINT_UMAP(a) {          \
    for (const auto &i : a)     \
    {                           \
        cout <<"Key : " << i.first <<", Value : " << i.second << endl;\
    }                           \
  };


void UnorderedMaps::UMapInitDemo()
{
    unordered_map<DemoClass, string> map1;
    map1.insert({ { DemoClass(5), "ABCDE" },{ DemoClass(1), "A" },{ DemoClass(3), "ABC" } });
    PRINT_UMAP(map1);
}

void UnorderedMaps::UMapOperationsDemo()
{

}

void UnorderedMaps::Demonstrate()
{
    PRINT("Demonstrating Unordered Maps");
    UMapInitDemo();
    UMapOperationsDemo();

    PRINT("End of demonstrating Unordered Maps");

}
