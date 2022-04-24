#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <any>
#include "voidset.cpp"


std::cout << "What is the 18 letter of the Alphabet?" << std::endl; //Second Question
while (std::cin >> answer2) //Question loop
{
    
    
    if (answer2 == 'r' && 'R') //True answer (FIX THE ERROR HERE)
    {
        ++tries;
        std::cout << "That is correct" << std::endl;
        std::cout << std::endl;
        std::cout << "Number of tries: " << tries << std::endl;
        break; //Breaks the while loop
    }
    else
    {
        ++tries; //Increments
        currentamount += penalty; 
        std::cout << "That is incorrect, try again" << std::endl
                    << "Number of tries: " << tries << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
    }
    
}

if (p >= 2)
{
        std::cout << "It took you: " << p << " tries to get the answer: " << a << "?!" << std::endl
                    << "Let us keep moving" << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
}

else
{
    std::cout << "It really took you only: " << p << " try to get the answer: " << a << "?! You're awesome!" << std::endl; //Using Reference Variables to check numbers
    std::cout << std::endl;
    
    if (p <= -5) //Condition based on number of tries
    {
        *reset = *reset - 5;
        std::cout << "Number of tries: " << *reset << std::endl; //Checks to be sure
    }
    else if (p >= -4 && p <= 0)
    {
        *reset = *reset - 2;
        std::cout << "Number of tries: " << *reset << std::endl; //Checks to be sure
    }
    

}