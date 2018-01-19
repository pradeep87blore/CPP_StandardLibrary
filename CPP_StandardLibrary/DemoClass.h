#pragma once

#include <iostream>

// This class is just used to print out messages when the constructors and destructors are invoked
class DemoClass
{
    int iValue;
public:
    DemoClass(int iVal = 100); // Default Constructor
    ~DemoClass();

    void SetValue(int iVal);

    int GetValue() const;

    void PrintValue();

    // Overloaded operators:

    // Equal to operator:
    bool operator == (const DemoClass &);

    // No Equal to operator:
    //bool operator != (DemoClass &);

    // Lesser than operator:
    //bool operator < (const DemoClass &);

    // Greater than operator:
    //bool operator > (DemoClass &);

    // Lesser than or equal to operator:
    //bool operator <= (DemoClass &);

    // Greater than or equal to operator:
    //bool operator >= (DemoClass &);

    bool Equal(DemoClass &rhs);

    auto GetHash();

    friend std::ostream& operator<<(std::ostream& os, const DemoClass& dc);

};
// Equal to operator:
bool operator== (const DemoClass &lhs, const DemoClass &rhs);

// Not Equal to operator:
bool operator != (DemoClass &lhs, DemoClass &rhs);

// Lesser than operator:
bool operator < (DemoClass &lhs, DemoClass &rhs);

// Greater than operator:
bool operator > (DemoClass &lhs, DemoClass &rhs);

// Lesser than or equal to operator:
bool operator <= (DemoClass &lhs, DemoClass &rhs);

// Greater than or equal to operator:
bool operator >= (DemoClass &lhs, DemoClass &rhs);

// Compares two classes and returns true if they match
bool Equal(DemoClass &lhs, DemoClass &rhs);


//Hash functor for DemoClass
class DemoClassHasher
{
public:
    size_t operator()(const DemoClass& dc) const
    {
        //std::cout << "DemoClassHasher hash function called for " << dc.GetValue() << std::endl;
        return std::hash<int>()(dc.GetValue());
    }
};

// A bad Hash functor for DemoClass
// This ensures that there are many collisions
class DemoClassBadHasher
{
public:
    size_t operator()(const DemoClass& dc) const
    {
        return (dc.GetValue() % 3);
    }
};

class DemoClassCustomEquals
{
public:
    bool operator()(const DemoClass& dc1, const DemoClass &dc2) const
    {
        std::cout << "DemoClassCustomEquals : " << dc1.GetValue() << ", " << dc2.GetValue() << std::endl;
        return ((dc1.GetValue() % 3) == (dc2.GetValue() % 3));
    }
};


// Extending the std namespace to include the hash function for DemoClass
namespace std {

    template <>
    struct hash<DemoClass>
    {
        std::size_t operator()(const DemoClass& dc) const
        {
            //std::cout << "DemoClassHasher template specialization called for " << dc.GetValue() << std::endl;
            return (hash<int>()(dc.GetValue()));
        }
    };

}