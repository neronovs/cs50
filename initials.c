#include <stdio.h>
#include <cs50.h>

char ini(char name)
{
    char init = name;
    if (init>=97 && init<=122)
    {
        init -= 32;
    }
    return  init;
}

void print(char in) 
{
    printf("%c", in);
}

int main(void)
{
    string in = GetString();
    char *fullnamee = in;
    int index = 0;
    print(ini(fullnamee[index]));
    
    for (int i = 0; i <= 50; i++) {
        if (fullnamee[i] == ' ') {
            index = i+1;
            print(ini(fullnamee[index]));
        }
    }
    
    printf("\n");
}
