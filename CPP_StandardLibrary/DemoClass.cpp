#include "DemoClass.h"
#include "Utilities.h"


#define NO_DEBUG_HERE // Enable this flag to prevent debug prints


DemoClass::~DemoClass()
{
#ifndef NO_DEBUG_HERE
    PRINT("DemoClass destructor called for class with value : " + std::to_string(iValue));
#endif
}


DemoClass::DemoClass(int iVal): iValue(iVal)
{
#ifndef NO_DEBUG_HERE
    PRINT("DemoClass constructor called for class with value : " + std::to_string(iValue));
#endif
}

void DemoClass::SetValue(int iVal = 100)
{
    this->iValue = iVal;
}

int DemoClass::GetValue()
{
    return iValue;
}

void DemoClass::PrintValue()
{
    PRINT(std::to_string(iValue));
}