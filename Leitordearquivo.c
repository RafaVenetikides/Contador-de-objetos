// C program to illustrate fgetc() function
#include <stdio.h>
 
int main ()
{
    // open the file
    FILE *fp = fopen("PjBL2 - Imagens\\01.ppm", "r");
 
    int i = 0;
    // Return if could not open file
    if (fp == NULL)
      return 0;
 
    do
    {
        // Taking input single character at a time
        char c = fgetc(fp);
 
        // Checking for end of file
        if (feof(fp))
            break ;

        i++;
        printf("%c", c);
    }  while(1);
    
    printf("\n%d", i); 
    fclose(fp);
    return(0);
}