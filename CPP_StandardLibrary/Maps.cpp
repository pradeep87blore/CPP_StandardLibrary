#include "Maps.h"
#include "Utilities.h"
#include "RevComparer.h"
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// A macro to print the map container
// Using a macro since the map types might be different and might have comparators, etc.
#define PRINT_MAP(a) {          \
    for (const auto &i : a)     \
    {                           \
        cout << "Key : "<< i.first << ", Value : " << i.second << endl;\
    }                           \
  };


void Maps::InitializationDemo()
{
    map<int, string> map1{ {1, "Hello"}, {2, "World"}, {3, "!"} };
    PRINT_MAP(map1);

    // This demostrates using a custom comparator
    // The comparator compares the keys and not the values
    PRINT("Map sorted in reverse using a custom comparator : ");
    map<string, string, RevComparer<string>> map2;
    map2["A"] = "AAAA";
    map2["B"] = "BBBB";
    map2["C"] = "CCCC";
    PRINT_MAP(map2);

}


void Maps::MapOperationsDemo()
{
    map <int, string> map1;
    auto ret = map1.insert(make_pair<int, string>(10, "Hi"));
    if (ret.second == false)
    {
        PRINT("Inserting with key value 10 failed");
    }
    else
    {
        PRINT("Inserting with key value 10 succeeded");
    }

    PRINT_MAP(map1);
    ret = map1.insert(make_pair<int, string>(10, "Hello"));
    if (ret.second == false)
    {
        PRINT("Inserting with key value 10 failed");
    }
    else
    {
        PRINT("Inserting with key value 10 succeeded");
    }

    PRINT_MAP(map1);
    ret = map1.insert({ 11, "World" });
    if (ret.second == false)
    {
        PRINT("Inserting with key value 11 failed");
    }
    else
    {
        PRINT("Inserting with key value 11 succeeded");
    }
    PRINT_MAP(map1);

    PRINT("Using the [] operator:");

    map1[11] = "Welcome";
    PRINT_MAP(map1);
    map1[11] = "Now";
    map1[12] = "!";

    PRINT_MAP(map1);

    PRINT("Using the emplace operation to add key value pair 1234-1234:");
    map1.emplace(1234, "1234");
    PRINT_MAP(map1);

    PRINT("Printing from Key value 11");
    auto key10 = map1.find(11);
    for (auto &i = key10; i != end(map1); i++)
    {
        cout << "Key : " << i->first << ", Value : " << i->second << endl; \
    }

    //Counting the number of keys (useful to find if the key is present or not)
    auto keyCount = map1.count(10);
    auto keyCount2 = map1.count(100);

    PRINT("10 is present " + to_string(keyCount) + " number of times");
    PRINT("100 is present " + to_string(keyCount) + " number of times");

    PRINT("Demonstrating deletion. map1 is now: ");
    for (int iIndex = 1000; iIndex < 1010; iIndex++)
    {
        map1[iIndex] = to_string(iIndex * 2);
    }
    PRINT_MAP(map1);

    map1.erase(1001);
    PRINT("After erarsing key 1001, map1 is now: ");
    PRINT_MAP(map1);

    auto iter1005 = map1.find(1005);
    map1.erase(iter1005, end(map1));
    PRINT("After erasing from 1005 to the end of the map, map1 is now: ");
    PRINT_MAP(map1);

    if (map1.empty())
        PRINT("Map is empty");
    else
        PRINT("Map is not empty now");

    PRINT("Current map size: ");
    PRINT(to_string(map1.size()));

    map1.clear();
    PRINT("Map is cleared");

    if (map1.empty())
        PRINT("Map is empty");
    else
        PRINT("Map is not empty now");

    PRINT("Current map size: ");
    PRINT(to_string(map1.size()));

}

void Maps::MultiMapsInitializationDemo()
{
    multimap<int, string> map1{ { 1, "Hello" },{ 2, "World" },{ 3, "!" } };
    PRINT_MAP(map1);

    PRINT("After Adding new elements with keys 1, 2 and 3:");
    for (int iIndex = 0; iIndex < 4; iIndex++)
    {
        map1.insert(make_pair(iIndex, to_string(iIndex * 3)));
    }
    PRINT_MAP(map1);

    // This demostrates using a custom comparator
    // The comparator compares the keys and not the values
    PRINT("Map sorted in reverse using a custom comparator : ");
    multimap<string, string, RevComparer<string>> map2;
    map2.insert({ "A", "AAAA" });
    map2.emplace("B","BBBB");
    map2.insert(make_pair("C","CCCC"));
    map2.insert({ "A", "ABCD" });
    map2.insert({ "A", "AABBCCDD" });
    PRINT_MAP(map2);
}

void Maps::MultiMapsOperationsDemo()
{
    PRINT("Demonstrating adding new values, retrieving all the values for a key and other such operations:");
    multimap<int, string> map1{ {1,"1"}, {2, "2"}, {3, "3"}, {1, "A"}, {2, "B"} };
    PRINT_MAP(map1);

    PRINT("Adding some values :");
    for (int iIndex = 0; iIndex < 10; iIndex++)
    {
        map1.insert({ iIndex / 2, to_string(iIndex) });
    }
    PRINT_MAP(map1);

    auto lower = map1.lower_bound(1);
    if(lower != end(map1))
        PRINT("Value of the lowest key position of 1 is :" + lower->second);

    // Upper bound returns the element after the last key position. Hence, decrement it to get last value for this key
    auto higher = map1.upper_bound(1);    
    if (higher != end(map1))
    {
        --higher;
        PRINT("Value of the highest key position of 1 is :" + higher->second);
    }

    auto rangeOf1 = map1.equal_range(1);
    PRINT("All values with key 1 :");
    for (auto i = rangeOf1.first; i != rangeOf1.second; ++i)
    {
        PRINT(i->second);
    }

    PRINT("Erasing all elements with key 2:");
    map1.erase(2);
    PRINT_MAP(map1);

    PRINT("Erasing the value 8 for key 4:");
    auto rangeOf4 = map1.equal_range(4);

    for (auto i = rangeOf4.first; i != rangeOf4.second; ++i)
    {
        if (i->second.compare(to_string(8)) == 0)
        {
            map1.erase(i);
            break;
        }
    }
    PRINT_MAP(map1);

    PRINT("Count of all elements with key 3 : " + to_string(map1.count(3)));

    PRINT("Current map size: ");
    PRINT(to_string(map1.size()));

    map1.clear();
    PRINT("Aftering clearing the map, size is: ");
    PRINT(to_string(map1.size()));

}

void Maps::Demonstrate()
{
    PRINT("Maps Demo:\n");
    InitializationDemo();
    MapOperationsDemo();
    PRINT("\nEnd of Maps Demo:\n");

    PRINT("\nMultiMaps Demo:\n");
    MultiMapsInitializationDemo();
    MultiMapsOperationsDemo();
    PRINT("\nEnd of MultiMaps Demo:\n");
}

