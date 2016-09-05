#include <stdio.h>
#include <cs50.h>
#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

void cryptoFunc(string text, int k) {
    
    int i = 0;
    char *arrText = text;
        
    while (arrText[i] > 0 && arrText[i] < 127) {
    
        //if a letter then shift it + "k"
        if (arrText[i] >= 65 && arrText[i] <= 90 ) {
            if (arrText[i] + k - 90 <= 0) printf("%c", arrText[i] + k);
            //cycling of the abc
            else printf("%c", 65 + (arrText[i] + k - 91));
        } else if (arrText[i] >= 97 && arrText[i] <= 122 ) {
            if (arrText[i] + k - 122 <= 0) printf("%c", arrText[i] + k);
            //cycling of the abc
            else printf("%c", 97 + (arrText[i] + k - 123));
        } else 
            //if spec.symbols then print that we have    
            { printf("%c", arrText[i]); }

        i++;
    }
    
    printf("\n");
}

int main(int argc, string argv[]) {

    string text = "";
    int k = 0;
    
    //check the input args
    if (argc > 2 || argc < 2) 
    {
        printf("You need to enter 1 argument!");
        return 1;
    }
    else  
    {
        k = atoi(argv[1]);
    } 
    
    //change k to row 0-26
    if (k > 26) {
        int dif = k % 26;
        if (dif > 0) {
            k = dif;
        } 
    }
    
    //take a text to a char array
    text = GetString();

    cryptoFunc(text, k);
    
    return 0;
}
