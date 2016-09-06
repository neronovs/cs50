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

void cryptoFunc(string text, string k) {
    
    //char *arrText = text;
    int j = 0;
    int shift = 0;
        
    for (int i = 0; i < strlen(text); i++) {
    
        shift = tolower(k[j]) - 97;
        
        //if a letter 
        if (isalpha(text[i])) {

            int change = (tolower(text[i]) + shift);
            
            if (change - 97 > 26) {
                //printf("!!!!!!!!!change - 97 > 26");
                change = ((change - 97) % 26) + 97;
            }
            
            if (isupper(text[i])) change -= 32;
            
            printf("%c", change);

        } else //if spec.symbols then print that we have
            { 
                printf("%c", text[i]);
                j--;
            }
            
        if (j == strlen(k)-1) j = 0;
        else j++;
        
    }
    
    printf("\n");
}

int checkAlpha(string k) {
    for (int ii = 0; ii < strlen(k); ii++) {
        if (!isalpha(k[ii])) 
        {
            printf("Input a word only!\n");
            return 1;
        } 
    }
    return 0;
}

int main(int argc, string argv[]) {

    /// text – a text, k — a key word, kj — j letter of the key word, 
    /// pi — a letter with the index "i" in the original text, ci — a letter with the index "i" in the crypting. 
    
    string text = "";
    string k = "";
    
    //check the input args
    if (argc > 2 || argc < 2) 
    {
        printf("Input one argument!");
        return 1;
    }
    else  
    {
        k = argv[1];
        
        int res = checkAlpha(k);
        if (res == 1) return 1;
    } 

    //take a text to a char array
    text = GetString();

    cryptoFunc(text, k);
    
    return 0;
}
