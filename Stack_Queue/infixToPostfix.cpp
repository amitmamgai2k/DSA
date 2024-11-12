#include <iostream>
#include <math.h>
using namespace std;
char stack[100];
int top = -1;
// Push function
void push(char data)
{
    if (top < 99)
    {
        top++;
        stack[top] = data;
    }
    else
    {
        cout << "Stack Overflow" << endl;
    }
}
// Pop function
char pop()
{
    if (top >= 0)
    {
        char popped = stack[top];
        top--;
        return popped;
    }
    else
    {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
}
// Peek function
char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        return '\0';
    }
}
// Function to check the precedence
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
// Function to convert infix to postfix notation
string infixToPostFix(string s)
{
    string result;
    int Counter = 0; // To check balanced parentheses
    for (int i = 0; i < s.length(); i++)
    {
        // Check if it's a valid operand or operator
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' ||
              s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' || s[i] == ')'))
        {
            cout << "Invalid operator or operand: " << s[i] << endl;
            return "";
        }

        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
        }
        // Left parenthesis
        else if (s[i] == '(')
        {
            push(s[i]);
            Counter++;
        }
        else if (s[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                result += pop();
            }
            if (top != -1)
            {
                pop(); //
            }
            Counter--;
            if (Counter < 0)
            {
                cout << "() Mismatch" << endl;
                return " ";
            }
        }
        // Operator
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(s[i]))
            {
                result += pop();
            }
            push(s[i]);
        }
    }
    // Pop all remaining operators from the stack
    while (top != -1)
    {
        result += pop();
    }
    // Check for any remaining unbalanced parentheses
    if (Counter != 0)
    {
        cout << "() Mismatched" << endl;
        return " ";
    }
    return result;
}
// Function to evaluate the postfix expression using the same stack
int evaluatePostfixExpression(string s)
{
    top = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            push(s[i] - '0'); // Convert char digit to int and push
        }
        // If it's an operator, pop two operands and evaluate
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            int op2 = pop(); // Second operand
            int op1 = pop(); // First operand
            int result;
            switch (s[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            default:
                cout << "Invalid operator." << endl;
                return -1;
            }
            push(result);
        }
        else
        {
            cout << "Cannot evaluate expressions with variables." << endl;
            return -1;
        }
    }
    return pop();
}
int main()
{
    string infixExpression;
    // Infix expression input
    cout << "Enter an infix expression: ";
    cin >> infixExpression;
    // Conversion to postfix
    string postfixExpression = infixToPostFix(infixExpression);
    if (!postfixExpression.empty())
    {
        cout << "Postfix expression: " << postfixExpression << endl;
        bool containsVariable = false;
        for (char c : postfixExpression)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            {
                containsVariable = true;
                break;
            }
        }
        if (containsVariable)
        {
            cout << "Evaluation not possible with variables." << endl;
        }
        else
        {
            // Evaluate the postfix expression
            int result = evaluatePostfixExpression(postfixExpression);
            if (result != -1)
            {
                cout << "Evaluation result: " << result << endl;
            }
        }
    }
    return 0;
}
