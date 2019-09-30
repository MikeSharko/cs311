//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Mike Sharko
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate a post-fix expression using stack
//Algorithm: Reading an expression, if it is an operand we push to the stack if it is 
//an operator we apply the operator to the two operands  and push 
//the evaluated expression to the top of the stack. Then we show the result to the user.
//If anything goes wrong we throw an error feedback :)
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result; // evaluated result using operator with box1 and box2
  
  while (expression[i] != '\0')
  {
	  try
	  {
		  item = expression[i];  // current char

		  if (isdigit(item)) {
			  postfixstack.push(item - 48);
			  postfixstack.displayAll();
		  }

		  else if ((item=='+') || (item=='-') || (item=='*') || (item=='/') )
		  {
			  postfixstack.pop(box1);
			  postfixstack.pop(box2);
			  
			  switch (item)
			  {
			  case '+': result = (box1 + box2); break;
			  case '-': result = (box2 - box1); break;
			  case '*': result = (box2 * box1); break;
			  case '/': result = (box2 / box1); break;
			  default:  return 0; break;

			  }
			  postfixstack.push(result);
			  postfixstack.displayAll();
		  }
		  else {
			  throw "invalid item";
		  }
		  

		  // ** do all the steps in the algorithm given in Notes-1


	  } // this closes try
	 // Catch exceptions and report problems and quit the program now (exit(1)). 
	 // Error messages describe what is wrong with the expression.
	  catch (stack::Overflow)
	  {
		  cerr << "Error: Stack overflow, the expression was too long" << endl;
		  return -1;
	  }
	  catch (stack::Underflow)
	  {
		  cerr << "Error: Stack underflow, to few operands(numbers)" << endl;
		  return -1;
	  }
	  catch (char const* errormsg) // for invalid item case
	  {
		  cerr << "Error: Expression contains invalid item!" << endl;
		  return -1;
	  }

	  // go back to the loop after incrementing i
	  i++; // incrementing i to evaluate next expression
  }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
 
  postfixstack.pop(result);
  cout << "The evaluated result is: " << result << endl;

 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if (!postfixstack.isEmpty()) {
	  cerr << "[Error] Incomplete expression! " << endl
		  << endl;

	  cerr << "Current stack" << endl;
	  cerr << "--------------" << endl;
	  postfixstack.displayAll();
  }

}// end of the program
