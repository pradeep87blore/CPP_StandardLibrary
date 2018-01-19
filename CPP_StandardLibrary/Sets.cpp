#include "Sets.h"
#include "Utilities.h"
#include "RevComparer.h"
#include <set>
#include <string>
#include <iostream>
#include <functional>

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

    PRINT("Another set with reverse sorted insertions");
    set<string, RevComparer<string>> set2{ "A", "B", "C", "B", "A", "C" };
    PRINT_SET(set2);

    // By doing the following, no two strings that are of same length can be added to the set
    // Thus, only the first string with a specific string length gets added to the set
    PRINT("Demonstrating using a comparer that compares the string lengths, to sort the strings in ascending string lengths");
    PRINT("Note that each string in this set will have a unique string length, no two strings with same string length get added");
    auto comparer = [](const string& str1, const string& str2) {return str1.length() < str2.length(); };
    set<string, function<bool(const string&, const string&)>> set3(comparer);
    set3.insert("A");
    set3.insert("ABCD");
    set3.insert("CDE");
    set3.insert("ABCDE");
    set3.insert("ABC");
    set3.insert("B");
    PRINT_SET(set3);
}

void Sets::SetOperationsDemo()
{
    set<string> set1{ "A", "B", "C" };
    set1.insert({ "D", "Z", "M", "F" });

    PRINT("Now using new set: ");

    set<int> set2;
    if (set2.empty())
        PRINT("Set is initially empty");
    else
        PRINT("Set is not empty");

    set2.insert({ 1,2,3,99, 32, 24, 1, 5, 6, 10 });
    PRINT("After inserting 1,2,3,99, 32, 24, 1, 5, 6, 10 (10 elements with 1 repeated element");
    PRINT_SET(set2);

    PRINT("Current set size:");
    PRINT(to_string(set2.size()));

    PRINT("Find the position of 24 and printing till the end of the set");
    auto i24 = set2.find(24);
    for (i24; i24 != end(set2); ++i24)
    {
        cout << *i24 << " ";
    }

    PRINT("Finding the element that comes before 5 in the set:");
    auto iBefore5 = set2.lower_bound(5);
    --iBefore5; // To go to the prev element
    PRINT(to_string(*iBefore5));

    PRINT("Finding the element that comes next to 5 in the set:");
    auto iNextTo5 = set2.upper_bound(5);
    PRINT(to_string(*iNextTo5));

    // Note, we can use equal_range to get the lower_bound and upper_bound in a single call as well.

    // Demonstrating erase:
    auto it3 = set2.find(3);
    set2.erase(it3);
    PRINT("After erasing 3 from the set:");
    PRINT_SET(set2);

    // Erasing using value:
    set2.erase(99);
    PRINT("After erasing 99 from the set:");
    PRINT_SET(set2);

    // To erase everything greater than 5:
    auto it5 = set2.upper_bound(5);
    set2.erase(it5, end(set2));

    PRINT("After erasing everything greater than 5");
    PRINT_SET(set2);

    set2.clear();
    PRINT("Size after clearing the set: ");
    PRINT(to_string(set2.size()));
}


void Sets::MultiSetInitializationDemo()
{

    multiset<string> set1{ "A", "B", "C", "B", "E" };
    PRINT_SET(set1);

    PRINT("Another set with reverse sorted insertions");
    multiset<string, RevComparer<string>> set2{ "A", "B", "C", "E", "D", "C" };
    PRINT_SET(set2);

    // By doing the following, no two strings that are of same length can be added to the set
    // Thus, only the first string with a specific string length gets added to the set
    PRINT("Demonstrating using a comparer that compares the string lengths, to sort the strings in ascending string lengths");
    PRINT("Since this is a multi set, equal length strings are also added to it and appear in the order of insertion");
    auto comparer = [](const string& str1, const string& str2) {return str1.length() < str2.length(); };
    multiset<string, function<bool(const string&, const string&)>> set3(comparer);
    set3.insert("A");
    set3.insert("ABCD");
    set3.insert("CDE");
    set3.insert("ABCDE");
    set3.insert("ABC");
    set3.insert("B");
    PRINT_SET(set3);
}

void Sets::MultiSetOperationsDemo()
{
    multiset<int> set1;
    if (set1.empty())
        PRINT("Set is initially empty");
    else
        PRINT("Set is not empty");

    set1.insert({ 1,2,3,99, 32, 24, 1, 5, 6, 10 });
    PRINT("After inserting 1,2,3,99, 32, 24, 1, 5, 6, 10 (10 elements with 1 repeated element");
    PRINT_SET(set1);

    PRINT("Current set size:");
    PRINT(to_string(set1.size()));

    PRINT("Find the position of 24 and printing till the end of the set");
    auto i24 = set1.find(24);
    for (i24; i24 != end(set1); ++i24)
    {
        cout << *i24 << " ";
    }

    PRINT("Finding the element that comes before 5 in the set:");
    auto iBefore5 = set1.lower_bound(5);
    --iBefore5; // To go to the prev element
    PRINT(to_string(*iBefore5));

    PRINT("Finding the element that comes next to 5 in the set:");
    auto iNextTo5 = set1.upper_bound(5);
    PRINT(to_string(*iNextTo5));

    //Inserting duplicate elements to the set
    set1.insert({ 1,2,3,4,5,5,4,3,2,1 });
    PRINT("Inserted some duplicate elements to the set. The set is now:");
    PRINT_SET(set1);

    PRINT("Counting the number of 1s in the set:");
    auto count1 = set1.count(1);
    PRINT(to_string(count1));

    PRINT("Printing all the 2s present:");
    auto itFirst2 = set1.find(2);
    auto itLast2 = set1.upper_bound(2);

    for (auto it = itFirst2; it != itLast2; ++it)
    {
        PRINT(to_string(*it));
    }

    PRINT("Using equal_range to get all the 4s present in the set:");
    auto itAll4s = set1.equal_range(4);

    for (auto it = itAll4s.first; it != itAll4s.second; ++it)
    {
        PRINT(to_string(*it));
    }
    
    // Demonstrating erase:
    auto it3 = set1.find(3);
    set1.erase(it3);
    PRINT("After erasing 3 from the set:");
    PRINT_SET(set1);

    // Erasing using value:
    set1.erase(99);
    PRINT("After erasing 99 from the set:");
    PRINT_SET(set1);

    // To erase everything greater than 5:
    auto it5 = set1.upper_bound(5);
    set1.erase(it5, end(set1));

    PRINT("After erasing everything greater than 5");
    PRINT_SET(set1);

    set1.clear();
    PRINT("Size after clearing the set: ");
    PRINT(to_string(set1.size()));
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
