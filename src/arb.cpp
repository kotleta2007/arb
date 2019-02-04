#include <iostream>
#include <cmath>
#include <string>

// Add ltString

// Add Fibonacci

// Add factorials

// Add Euclid's Algorithm

// Add fractional arithmetic

// Add COMMENTS! 

// Add testing 

// Add .h file

// Add string equalizer (convert two numbers to same length using zeros)

// Add subtraction (Common Core) and regular subtraction

// Add MSB comparison in multString and powerString

std::string addString (std::string a, std::string b) {
    
    int sizeDiff = abs(a.size() - b.size());
    int strLength = std::max(a.size(), b.size());
    
    if (a.size() > b.size()) {
        for (int i = 0; i < sizeDiff; i++) {
            b = "0" + b;
        }
    } else {
        for (int i = 0; i < sizeDiff; i++) {
            a = "0" + a;
        }
    }
    
    int carry = 0;
    std::string resString;
    int sumDigit, aDigit, bDigit;
    
    for (unsigned int j = strLength; j > 0; --j) {
        
        // Extract into int: aDigit, bDigit
        aDigit = (a.at(j-1)) - '0';
        bDigit = (b.at(j-1)) - '0';
        
        
        sumDigit = aDigit + bDigit + carry;
        
        if (sumDigit >= 10) {
            sumDigit -= 10;
            carry = 1;
        } else
            carry = 0;
        
        resString = std::to_string(sumDigit) + resString;
        
    }
    
    if (carry != 0)
        resString = "1" + resString;
    
    
    return resString;
}

bool ltString(std::string a, std::string b)
{
    return false;
}

std::string ccsubString(std::string a, std::string b) {
    std::string resString = "0";
    
    while(ltString(a, addString(b, resString)))
        addString(resString, "1");
    
    return resString;
}

std::string multString(std::string a, std::string b) {
    std::string resString;
    
    int aInt = std::stoi(a);
    int bInt = std::stoi(b);
    
    if (aInt > bInt)
    {
        for (int i = 0; i < bInt; ++i)
        {
            resString = addString(resString, a);
        }
    }
    else {
        for (int i = 0; i < aInt; ++i)
        {
            resString = addString(resString, b);
        }
    }
    
    // compare strings
    // choose lesser to be the number of iterations
    // iterate, adding the other string to itself
    
    return resString;
}

std::string powerString(std::string a, std::string b)
{
    std::string resString = a;
    
    std::cout << std::stoi(b) << std::endl;
    
    for (int i = 2; i <= std::stoi(b); i++)
        resString = multString(resString, a);
    
    return resString;
}

int main(int argc, char * argv[]) {
    
    std::cout << addString("0","0") << std::endl;
    
    return 0;
}
