#include <stdio.h>
#include <string.h>

char infix[] = "a+b-c*d/e";
char str_postFix_exp[100]; // Stack for storing the operators , operands...
char postFix[100];         // Output postfix expression

int top = -1; // Stack pointer

// Function to check precedence of operators
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
    {

        if (ch == '*')
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }

    return 0;
}

void convert_infix_to_postFix(char *input, int length)
{
    int postfixIndex = 0; // To track index in postFix array
    for (int i = 0; i < length; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            // Pop operators from stack with higher or equal precedence and add them to postfix
            while (top != -1 && precedence(str_postFix_exp[top]) >= precedence(input[i]))
            {
                postFix[postfixIndex++] = str_postFix_exp[top]; // pop
                top--;
            }
            // Push the current operator to the stack
            top++;
            str_postFix_exp[top] = input[i];
        }
        else if (input[i] == '(')
        {
            top++;
            str_postFix_exp[top] = input[i];
        }
        else if (input[i] == ')')
        {
            while (str_postFix_exp[top] != '(') // it will pop the str_postFix_exp array  untill it found opening
            {
                postFix[postfixIndex++] = str_postFix_exp[top--];
            }
            top--; // Remove the '(' from the stack
        }
        else
        {
            // Add operand directly to postfix expression
            postFix[postfixIndex++] = input[i];
        }
    }

    // Pop  remaining operators from the stack
    while (top != -1)
    {
        postFix[postfixIndex++] = str_postFix_exp[top--];
    }
}

int main()
{
    int length = strlen(infix);
    // Convert infix to postfix
    convert_infix_to_postFix(infix, length);

    // Print the postfix expression
    printf("Postfix Expression: %s\n", postFix); // Add missing semicolon
    return 0;
}
