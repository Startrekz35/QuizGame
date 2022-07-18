#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <any>
#include "quizvariables.h"


signed int answer;
char answer2;
signed int &a {answer}; //Reference to link a to the number of answers
signed int tries {0}; //Current amount to be reset 
signed int totaltries {0}; //total amount of tries - to store amount of tries took && be calculated for end bonus
signed int &p {tries}; //Reference to link p to the number of tries
signed int currentamount; //Current Amount for the question
signed int totalamount {0}; //Total Amount
signed int penalty {-1000}; //Penalty for incorrect answer
signed int &ca {currentamount};
signed int *mon; //Linked to current amount
signed int &tm {totalamount};
signed int *reset; //Want to try something special as a bonus for right answers in the least amount of tries
signed int bonus; //To keep track of the *reset number of tries


void enter() //First attempt at a function in my project
{
    while (std::cin.get() != '\n');
}

void totalprize()
{
    totalamount += currentamount;
}

void gameover()
{
    std::cout << "You have: $" << tm << std::endl
                                << "Thank You For Playing!" 
                                << "GAME OVER" << std::endl;
}


int main()
{

currentamount = 10000;
mon = &currentamount;

//Directions
std::cout << "You'll start with: $" << tm << std::endl; //total amount
std::cout << std::endl
            << "Press Enter to Continue" << std::endl;
                enter(); //Enter to continue

std::cout << "This first question is worth: $" << currentamount << std::endl;
    enter();

std::cout << "Every time you get an answer wrong, you'll lose a certain amount." << std::endl;
    enter();

std::cout << "For this question, you lose $" << abs(penalty) << " with every incorrect attempt." << std::endl;
    enter();

std::cout << "We are also playing with golf rules, meaning: The lowest amount of tries wins you a bonus amount of money." << std::endl;
    enter();

//Probably my biggest mistake to keep track of...
std::cout << "To make things EVEN MORE interesting, the bonus money stacks, so if you meet the criteria for both bonuses, you receive those as well!" << std::endl;
    enter();
            
std::cout << "You'll also get stacks of bonus tries based on how many attempts it takes to get the right answer." << std::endl;
    enter();

//Money and Bonuses
//Attempts
int col_width {20};
std::cout << std::left; //Left Justified
std::cout << std::setw(col_width) << "Tries" << std::setw(col_width) << "Attempts" << std::endl; //Bonus tries based on amount of attempts
std::cout << std::endl;

std::cout << std::setw(col_width) << "-10" << std::setw(col_width) << "1 Attempt" << std::endl;
    enter();

std::cout << std::setw(col_width) << "-5" << std::setw(col_width) << "Up to 5 Attempts" << std::endl;
    enter();


//Tries
std::cout << std::left;
std::cout << std::setfill('-');
std::cout << std::setw(col_width) << "BONUS" << std::setw(col_width) << "Tries" << std::endl; //Bonus money based on amount of tries left
std::cout << std::endl;

std::cout << std::setw(col_width) << "$50,000" << std::setw(15) << "Less than -10 tries" << std::endl;
    enter();

std::cout << std::setw(col_width) << "$25,000" << std::setw(20) << "Less than -5 tries" << std::endl;
    enter();

std::cout << std::setw(col_width) << "$10,000" << std::setw(14) << "Took 0 tries" << std::endl;
    enter();

std::cout << std::setw(col_width) << "$5,000" << std::setw(12) << "1-5 tries" << std::endl;
    enter();


//Penalty
std::cout << std::left;
std::cout << std::setw(col_width) << "Questions" << std::setw(col_width) << "Penalty amount" << std::endl;
std::cout << std::endl;

std::cout << std::setw(col_width) << "Question 1" << std::setw(col_width) << "-$1000" << std::endl;
    enter();

std::cout << std::setw(col_width) << "Question 2" << std::setw(col_width) << "-$5000" << std::endl;
    enter();

std::cout << std::setw(col_width) << "Question 3" << std::setw(col_width) << "-$15000" << std::endl;
    enter();

/********************************************************************************************************/
//Begins the Game
std::cout << "Let's play!" << std::endl;
    enter(); //Enter to continue
std::cout << std::endl;


//First Question                
std::cout << "First Question" << std::endl;
std::cout << std::endl;

std::cout << "What's 2*6*4?" << std::endl;

while (std::cin >> answer) //Question loop
{
    if (answer != 2*6*4) //conditional
    {
        ++tries; //Increments
        currentamount += penalty;

        std::cout << std::endl;
        std::cout << "That is incorrect, try again" << std::endl
                    << "Number of tries: " << tries << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
            
            if (currentamount <= 0) //Ends Game
                {
                    gameover();
                    return 0;
                    
                    
                }
        
        
    }
    
    if (answer == 2*6*4) //True answer
    {
        ++tries;
        std::cout << std::endl;
        std::cout << "That is correct" << std::endl;
        std::cout << std::endl;
        std::cout << "Number of tries: " << tries << std::endl;
        
        totalprize(); //I forgot to add the current amount won to the total amount
        
        std::cout << "Total amount: $" << totalamount << std::endl;
        totaltries = tries; //stores tries attempted
        enter();
        totalamount = currentamount;
        break; //Breaks the while loop
    }

    
}

reset = &tries; //Links Pointer to the number of tries
if (p == 1) //Conditional based on number of tries
    {
        std::cout << "It really took you only: " << p << " try to get the answer: " << answer << "?! You're awesome!" << std::endl; //Using Reference Variables to check numbers
        std::cout << std::endl;
        enter();
        std::cout << "For your reward, your number of tries will be shortened by ten." << std::endl;
        *reset = *reset - 10; // -9
        
        std::cout << "Total Amount: $" << totalamount << std::endl;
        enter();
        std::cout << "Let us keep moving." << std::endl
                    << "Press Enter to Continue" << std::endl;
        enter();

    }
    else if (p < 1 && p <= 5) //Conditional based on tries up to 5 attempts
    {
        std::cout << "It took you: " << p << " tries to get the answer: " << answer << "?!" << std::endl;
        enter();
        std::cout <<  "Let's keep moving" << std::endl
                    << "Total Amount: $" << tm << std::endl;

        std::cout << "For your reward, your number of tries will be shortened by ten." << std::endl;
        *reset = *reset - 5;
        std::cout << "Number of tries: " << *reset << std::endl
                    << "Press Enter to Continue" << std::endl;
    }
    else
    {
        std::cout << "It took you: " << p << " tries to get the answer: " << answer << std::endl;
                    enter();
                    std::cout << "Let us keep moving" << std::endl;
                        enter();
                    std::cout << "Total Amount: $" << tm << std::endl;
    }

std::cout << std::endl;

/************************************************************************************************************/
bonus = *reset; // -9
std::cout << "Bonus Tries: " << bonus << std::endl;


tries = 0; //This also turns the *reset to 0
currentamount = 20000;
penalty = -5000;

std::cout << "This question is worth: $" << *mon << std::endl;
    enter();
std::cout << "For this question, you lose $" << abs(penalty) << " with every incorrect attempt." << std::endl;
    enter();

std::cout << "What is the 18 letter of the Alphabet?" << std::endl; //Second Question

//Interesting tidbit
//If the order of the if else conditions are reversed, the code won't work
// ex. if (answer2 != 82) vs if (answer2 == 82)
while (std::cin >> answer2) //Question loop
{
        if ((answer2 == 82) || (answer2 == 114))
	{
        ++tries;
        std::cout << "That is correct" << std::endl;
            enter();
        std::cout << "Number of tries: " << tries << std::endl;
            totalprize();
        std::cout << "Total amount: " << tm << std::endl;
            totaltries += tries;
                enter();
        break; //Breaks the while loop

	}

        else  
    {
        ++tries;
        currentamount += penalty; 
        std::cout << "That is incorrect, try again" << std::endl
                    << "Number of tries: " << tries << std::endl
                    << "Current Amount: $" << currentamount << std::endl;
    }

}

if (p == 1) //Conditional based on number of tries
    {
        totaltries += tries;
        std::cout << "It really took you only: " << p << " try to get the answer: " << answer2 << "?! You're awesome!" << std::endl; //Using Reference Variables to check numbers
        std::cout << std::endl;
        enter();

        std::cout << "For your reward, your number of tries will be shortened by ten." << std::endl;
        *reset = *reset - 10; // -9
    
        std::cout << "Total Amount: $" << totalamount << std::endl;
        enter();
        std::cout << "Let us keep moving." << std::endl
                    << "Press Enter to Continue" << std::endl;
        enter();

    }
    else if (p < 1 && p <= 5) //Conditional based on tries up to 5 attempts
    {
        totaltries += tries;
        std::cout << "It took you: " << p << " tries to get the answer: " << answer2 << "?!" << std::endl;
        enter();
        std::cout <<  "Let's keep moving" << std::endl
                    << "Total Amount: $" << tm << std::endl;

        std::cout << "For your reward, your number of tries will be shortened by five." << std::endl;
        *reset = *reset - 5;
    }
    else
    {
        totaltries += tries;
        std::cout << "It took you: " << p << " tries to get the answer: " << answer2 << "?!" << std::endl;
                    enter();
                    std::cout << "Let us keep moving" << std::endl;
                    enter();
                    std::cout << "Total Amount: $" << tm << std::endl;
    }
std::cout << std::endl;
/****************************************************************************************/
//Final Question
bonus += *reset;
std::cout << "Bonus Tries: " << bonus << std::endl;

tries = 0;
currentamount = 100000;
penalty = 15000;
std::cout << "Your third question is a Multiple Choice one" << std::endl;
            enter();
std::cout << "For this question, you lose $" << abs(penalty) << " with every incorrect attempt." << std::endl;
enter();
            std::cout << "When did the most current Preview Release of C++ 23 Release? Was it:" << std::endl
            << "1: December 15, 2020" << std::endl
            << "2: March 17, 2022" << std::endl
            << "3: October 14, 1985" << std::endl
            << "4: November 15, 2022" << std::endl;
            
            answer = 2;

            
    
while (std::cin >> answer) //Question loop
{
    
    
    if (answer == 2) 
    {
        ++tries;
        std::cout << "That is correct" << std::endl;
        std::cout << std::endl;
        std::cout << "Number of tries: " << tries << std::endl;
        totalprize();
        break; 
    }
    else
    {
        ++tries; 
        currentamount += penalty; 
        std::cout << "That is incorrect, try again" << std::endl
                    << "Number of tries: " << tries << std::endl
                    << "Current Amount: $" << currentamount << std::endl;

    }
    
}

if (p == 1) //Conditional based on number of tries
    {
        totaltries += tries;
        std::cout << "It really took you only: " << p << " try to get the answer: " << answer << "?! You're awesome!" << std::endl; //Using Reference Variables to check numbers
        std::cout << std::endl;
        enter();
        std::cout << "For your reward, your number of tries will be shortened by ten." << std::endl;
        *reset = *reset - 10; // -9
        
        std::cout << "Total Amount: $" << totalamount << std::endl;
        enter();

    }
    else if (p < 1 && p <= 5) //Conditional based on tries up to 5 attempts
    {
        totaltries += tries;
        std::cout << "It took you: " << p << " tries to get the answer: " << answer << "?!" << std::endl;
        enter();
        std::cout <<  "Let's keep moving" << std::endl
                    << "Total Amount: $" << tm << std::endl;

        std::cout << "For your reward, your number of tries will be shortened by five." << std::endl;
        *reset = *reset - 5;
    }

    else
    {
        totaltries += tries;
        std::cout << "It took you: " << p << " tries to get the answer: " << answer << "?!" << std::endl;
                    enter();
                    std::cout << "Total Amount: $" << tm << std::endl;
    }


std::cout << std::endl;
bonus += *reset;

std::cout << "Let's see your final score." << std::endl;

std::cout << "Total Amount: " << tm << std::endl;

std::cout << "Bonus amount of Tries: " << bonus << std::endl;
if (bonus <= 5)
{
    std::cout << "You get Bonus Money for your exemplary performance!!" << std::endl;
    if (bonus <= -10)
    {
        tm += 90000;
        std::cout << "For gathering less than -10 tries (Golf Rules - Less is better) - " 
                    << "You get the MAX BONUS of $50k, plus the added $40k from the other accrued bonus tries to give you a combined total amount of: $" 
                    << tm << std::endl;
    }
    else if (bonus <= 5)
    {
        tm += 40000;
        std::cout << "For gathering -5 tries or less than this, (Golf Rules - Less is better) - " 
                    << "You get the BONUS of $25k, plus the added $15k from the other accrued bonus tries to give you a combined total of: $" 
                    << tm << std::endl;
    }
    else if (bonus == 0)
    {
        tm += 10000;
        std::cout << "For gathering 0 tries (Golf Rules - Less is better) - " 
                    << "You get the BONUS of $10k, plus the added $5k from the other accrued bonus tries to give you a combined total of: $" 
                    << tm << std::endl;
    }
    else if (bonus > 0 && bonus <= 5)
    {
        tm += 5000;
        std::cout << "For getting around 5 tries or less (Golf Rules - Less is better) - " 
                    << "You get the BONUS of $5k, giving you a total of: $" 
                    << tm << std::endl;
    }
} 
else
{
    std::cout << "You did not get any added money due to the amount of tries taken" << std::endl;
}

    gameover();
    return 0;
}
