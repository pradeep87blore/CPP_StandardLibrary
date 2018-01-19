#pragma once

#include <ostream>

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

//ostream& operator<<(ostream& os, const DemoClass& dc);


// Extending the std namespace to include the hash function for DemoClass
namespace std {

    template <>
    struct hash<DemoClass>
    {
        std::size_t operator()(const DemoClass& k) const
        {
            using std::size_t;
            using std::hash;
            using std::string;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:

            return (hash<int>()(k.GetValue()));
        }
    };

}