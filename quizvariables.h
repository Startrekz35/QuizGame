#ifdef main_cpp
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
#endif
