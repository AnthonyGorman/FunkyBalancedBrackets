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
    int size = 0;
    while (*s != 0){ // Final pass through catches edge case '()}' or similar
        size ++;
        s ++;
    }
    if(d % 2 == 1 && !(d + 1 < size)) // If distance parity odd and distance is accurate -> Balanced
        return "YES";
    else 
        return "NO";
}

/* This recursive method determines whether a string of brackets is balanced 
or not. The returned integer is the distance to its matching bracket. A bracket
will always have an odd distance to its matching bracket. So if it is an even 
distance away then its inner brackets are not balanced, hence its string of 
brackets is not balanced.
*/
int funkyBalanced(char *s){
    int d = 1;
    if (*s == 0)
        return d; // No brackets is balanced brackets
    else if (strchr(")]}", *s) != NULL)
        d = -1; // No effect or catch edge case '}' or similar
    else
        if(strchr(")]}", *(s+1)) != NULL){ // Base case d = 1
            if(!bracketMap(*s, *(s+1))) // if the bracket next to it does not match
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
        d = d + 1 + funkyBalanced(s+d+1); // Finally, test the next set of brackets 
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