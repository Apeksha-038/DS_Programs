#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    return 0;
}

int isValid(char str[]) {
    int i = 0;
    char ch;

    while (str[i] != '\0') {

        if (str[i] == '(' ||
            str[i] == '[' ||
            str[i] == '{') {

            push(str[i]);
        }


        else if (str[i] == ')' ||
                 str[i] == ']' ||
                 str[i] == '}') {

            if (top == -1)
                return 0;

            ch = pop();

            if (!isMatching(ch, str[i]))
                return 0;
        }

        i++;
    }


    if (top == -1)
        return 1;

    return 0;
}

int main() {
    char str[MAX];

    printf("Enter brackets: ");
    scanf("%s", str);

    if (isValid(str))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}
