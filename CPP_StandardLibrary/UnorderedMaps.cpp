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
    PRINT("unordered_map created with hash from extending the std namespace with template specialization");
    unordered_map<DemoClass, string> map1;
    map1.insert({ { DemoClass(5), "ABCDE" },{ DemoClass(1), "A" },{ DemoClass(3), "ABC" } });
    PRINT_UMAP(map1);

    PRINT("unordered_map created with hash function object for DemoClass");
    unordered_map<DemoClass, string, DemoClassHasher> map2;
    map2.insert({
    { DemoClass(1), "AAAA" },
    { DemoClass(2), "BBBB" },
    { DemoClass(3), "CCCC" } });

    map2[4] = "DDDD";
    map2[4] = "EEEE"; // This replaces the previous value with key 4 to EEEE
    PRINT_UMAP(map2);

    // Check on the below since the custom comparer is called only twice, for the first and last elements
    /*PRINT("unordered_map created with Demo Class hash function object and a custom comparator:");
    
    unordered_map < DemoClass, string, DemoClassHasher, DemoClassCustomEquals >map3;
    map3[DemoClass(1)] = "1";
    map3[DemoClass(2)] = "2";
    map3[DemoClass(3)] = "3";
    map3[DemoClass(4)] = "4";
    map3[DemoClass(5)] = "5";
    map3[DemoClass(6)] = "6";
    map3[DemoClass(7)] = "7";
    map3[DemoClass(8)] = "8";
    map3[DemoClass(9)] = "9";

    PRINT("Using a custom comparator that compares the value % 3, instead of direct ==");
    PRINT("Inserting DemoClass objects with values from 1 - 9");
    PRINT_UMAP(map3);*/
    

    // Using Lambdas    
    PRINT("unordered map with custom lambda and custom comparator:");
    unordered_map < DemoClass, string, function<size_t(const DemoClass& dc)>,
        function<bool(const DemoClass& dc1, const DemoClass& dc2)>> map3(10,
            [](const auto &dc) { return hash<int>()(dc.GetValue()); },
            [](const auto &dc1, const auto &dc2) 
        { 
        cout << dc1.GetValue() << "," << dc2.GetValue() << endl;
        return ((dc1.GetValue() % 2) == (dc2.GetValue() % 2)); });

    map3[DemoClass(1)] = "AAAA";
    map3[DemoClass(2)] = "BBBB";
    map3[DemoClass(3)] = "CCCC";
    map3[DemoClass(1)] = "DDDD";
    map3[DemoClass(4)] = "EEEE";
    map3[DemoClass(5)] = "FFFF";
    PRINT_UMAP(map3);

    //TODO: Note, not sure how the comparator is being used, need to check on this.



    
}

void UnorderedMaps::UMapOperationsDemo()
{
    unordered_map<int, string> map1{ {1, "AA"}, {2, "BB"}, {1, "CC"}, {3, "DD"} };
    PRINT(R"(Unordered map after adding the following elements {1, "AA"}, {2, "BB"}, {1, "CC"}, {3, "DD"}") is:)");
    PRINT_UMAP(map1);

    PRINT("Unordered map size is now " + to_string(map1.size()));

    PRINT("Unordered map bucket count is now " + to_string(map1.bucket_count()));

    unordered_map<DemoClass, string, DemoClassBadHasher> map2;
    map2[DemoClass(1)] = "AAAA";
    map2[DemoClass(2)] = "BBBB";
    map2[DemoClass(3)] = "CCCC";
    map2[DemoClass(4)] = "DDDD";
    map2[DemoClass(5)] = "EEEE";
    map2[DemoClass(6)] = "FFFF";
    map2[DemoClass(7)] = "GGGG";
    map2[DemoClass(8)] = "HHHH";

    PRINT("Now, this is a unordered map with an inefficient hash function, since it causes many collisions:");
    PRINT_UMAP(map2);

    PRINT("Unordered map size is now " + to_string(map1.size()));

    PRINT("Unordered map bucket count is now " + to_string(map1.bucket_count()));

    auto bucket = map2.bucket(DemoClass(2));
    PRINT("DemoClass(2) is the key, the bucket containing this key has " + to_string(map2.bucket_size(bucket)) + " elements");
    PRINT("Other elements in the same bucket are : ");
    auto itBucketBeg = map2.begin(bucket);
    auto itBucketEnd = map2.end(bucket);

    for (itBucketBeg; itBucketBeg != itBucketEnd; ++itBucketBeg)
    {
        PRINT("Key : " + to_string(itBucketBeg->first.GetValue()) + ", Value : " + itBucketBeg->second);
    }



}

void UnorderedMaps::Demonstrate()
{
    PRINT("Demonstrating Unordered Maps");
    UMapInitDemo();
    UMapOperationsDemo();

    PRINT("End of demonstrating Unordered Maps");

}
