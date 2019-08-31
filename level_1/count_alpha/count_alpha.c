/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:54:00 by jadawson          #+#    #+#             */
/*   Updated: 2019/08/31 16:54:27 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     check_empty(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return 1;
        i++;
    }
    return (0);
}

char    find_letter(char *str)
{
    int i = 0;
    char c = ' ';
    while (str[i])
    {
        if (str[i] != ' ')
        {
            c = str[i]; //set to letter I gotta find.
            return c;
        }
        i++;
    }
    return c;
}

int        letter_amount(char *str, char c)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            count++;
            str[i] = ' ';
        }
        i++;
    }
    return (count);
}

int        main(int argc, char **argv)
{
    int i = -1;
    char c = ' ';
    int count = 0;
    int first = 1;

    if (argc == 2)
    {
        char *str = argv[1];

        while (str[++i]) //lowercase and remove non letters.
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            if (!(str[i] >= 'A' && str[i] <= 'Z'))
            {
                if (!(str[i] >= 'a' && str[i] <= 'z'))
                    str[i] = ' ';
            }
        }

        while (check_empty(str) == 1) //if 1 then it's not empty
        {
            c = find_letter(str);
            count = letter_amount(str, c);
            if (first == 1)
            {
                printf("%i%c", count, c);
                first = 0;
            }
            else
            {
                printf(", %i%c", count, c);
            }
        }
    }
    printf("\n");
    return (0);
}


/*
Steps:
1: Scan through string and remove all non-letter characters and lowecase uppercaseletters.
2: Check if the string is empty.
3: If string isn't empty, find the letter. (find_letter())
4: Once you found the letter, scan through the list to count how many times the letter appears (letter_amount())
5: Is first set to 1? Print it out as '%i%c', else, print as ', %i%c' to handle format.
6: Finally, print new line!
*/
