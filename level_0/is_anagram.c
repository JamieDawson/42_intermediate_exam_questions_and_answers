#include <stdio.h>


int	is_anagram(char *a, char *b) 
{
    int tab[127] = {0};
    
    for (int i = 0; a[i] != '\0'; i++)
        tab[(int)a[i]] += 1;
    
    for (int i = 0; b[i] != '\0'; i++)
        tab[(int)b[i]] -= 1;
        
    int i = 0;
    while (i < 126)
    {
        if (tab[i] != 0)
            break;
        i++;
    }
    
    if (i >= 126)
        return 1;
    return 0;
   
}


//Remove comment to test with a main()
/*
int main()
{
    char a[] = "abc";
    char b[] = "cba";
    int i = is_anagram(a, b);
    
    if (i == 1)
        printf("ana");
    else
        printf("no");
    return (0);
}
*/

//EXPLAINED:
/*
 
Create a tab with 127 spaces.

while characters in *a exist
	convert the char into an int and have that space in tab has a +1 value. (example: ascii value of e is 101. The 101th space in tab[] now equals 1.
	
Note: the string 'eee' in *a would make the 101th place in tab equal 3.

while characters in *b exist.
	Convert the char into an int, find that space in tab[], and subtract it by 1.

note: the string 'eee' in *b would make the 101th place in tab now equal 0.

check every space in tab[]. If any of them are not 0, then break out. This works for both positive and negative.

Final if statement checks if we scanned through all spots in the tab.


*/
