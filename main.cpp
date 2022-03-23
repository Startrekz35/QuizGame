#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <any>

signed int answer;
char answer2;
signed int &a {answer}; //Reference to link a to the number of answers
signed int tries {0}; //signed gives the user the chance to enter negative numbers
signed int &p {tries}; //Reference to link p to the number of tries
signed int currentamount; //Current Amount for the question
signed int totalamount {0}; //Total Amount
signed int penalty {-100}; //Penalty for incorrect answer
signed int &ca {currentamount};
signed int *mon; //Linked to current amount
signed int &tm {totalamount};
signed int *reset; //Want to try something special as a bonus for right answers in the least amount of tries


int main()
{
    
currentamount = 500;
mon = &currentamount;

std::cout << "You'll start with: $" << tm << std::endl
            << "This first question is worth: $" << currentamount << std::endl
            << "Every time you get an answer wrong, you'll lose a certain amount." << std::endl
            << "For this question, you lose $100 with every incorrect attempt." << std::endl
            << "We are also playing with golf rules, meaning: The lowest amount of tries wins you a bonus amount of money." << std::endl;



std::cout << "BONUS" << std::setw(10) << "Tries" << std::endl;
std::cout << std::endl;
std::cout << "$50,000" << std::setw(10) << "Less than -10" << std::endl;



std::cout << "Let's play!" << std::endl;
std::cout << std::endl;

std::cout << "What's 2*6*4" << std::endl; //Question 1

while (std::cin >> answer) //Question loop
{
    if (answer != 2*6*4) //conditional
    {
        ++tries; //Increments
        currentamount += penalty; 
        
        std::cout << "That is incorrect, try again" << std::endl
                    << "Number of tries: " << tries << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
            
            if (currentamount == 0)
                {
                    std::cout << "You have: $" << *mon << std::endl;
                }
        
        
    }
    
    if (answer == 2*6*4) //True answer
    {
        ++tries;
        std::cout << "That is correct" << std::endl;
        std::cout << std::endl;
        std::cout << "Number of tries: " << tries << std::endl;
        break; //Breaks the while loop
    }

    
}

reset = &tries; //Links Pointer to the number of tries
if (p == 1) //Conditional based on number of tries
    {
        std::cout << "It really took you only: " << p << " try to get the answer: " << a << "?! You're awesome!" << std::endl; //Using Reference Variables to check numbers
        std::cout << std::endl;
        std::cout << "For your reward, your number of tries will be shortened by ten." << std::endl;
        *reset = *reset - 10; // -9
        
        std::cout << "Current Amount: $" << currentamount << std::endl
                    << "Number of tries: " << *reset << std::endl //Checks to be sure
                    << "Let us keep moving." << std::endl;
    }
    else
    {
        std::cout << "It took you: " << p << " tries to get the answer: " << a << "?!" << std::endl
                    << "Let us keep moving" << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
    }


std::cout << std::endl;


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



    return 0;
}
