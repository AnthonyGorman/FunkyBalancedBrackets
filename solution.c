#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
bool bracketMap(char l, char r);

int funkyBalanced(char* s);

char* isBalanced(char* s) {
    int d = funkyBalanced(s);
    int size = strlen(s);
    if(d % 2 == 1 && d + 1 >= size) // If the distance parity is odd and distance is accurate -> Balanced
        return "YES";
    else 
        return "NO";
}

/* This recursive method determines whether a string of brackets is balanced 
or not. The returned integer is the distance to its matching bracket. A bracket
will always have an odd distance to its matching bracket. If it has an even 
distance to its matching bracket, its inner brackets are not balanced, hence the string of 
brackets is not balanced.
*/
int funkyBalanced(char *s){
    int d = 1;
    if (*s == 0)
        return d; // No brackets is balanced brackets
    else if (strchr(")]}", *s) != NULL)
        d = -1; // No effect or catch edge case '}'
    else
        if(strchr(")]}", *(s+1)) != NULL){ // Base case d = 1
            if(!bracketMap(*s, *(s+1))) // Check if brackets match
                d = 0;
        }
        else if (strchr("([{", *(s+1)) != NULL){ // push the next bracket onto the stack
            d = 2 + funkyBalanced(s+1); // adding two effectively pops
            if(!bracketMap(*s, *(s+d))){ // Now we know the distance. Test it
                d = 0;
            }
        } 
        else
            d = 0; // handles '('
    if (d % 2 == 1) 
        d = d + 1 + funkyBalanced(s+d+1); // If odd distance, test the next set of brackets 
    return d;
}

// The bracket map.
bool bracketMap(char l, char r){
    switch(l){
        case '(':
            return r == ')';
        case '[':
            return r == ']';
        case '{':
            return r == '}';
        default:
            return false;
    }
}