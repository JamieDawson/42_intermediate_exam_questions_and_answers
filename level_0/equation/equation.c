/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:24:33 by jadawson          #+#    #+#             */
/*   Updated: 2019/08/31 16:27:55 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdio.h>


void    equation(int n)
{
    int a = -1, b, c;


    while (++a < 10)
    {
        b = -1;
        while (++b < 10)
        {
            c = -1;
            while (++c < 10)
                if (10 * a + b + 10 * c + a == n)
                    printf("A = %d, B = %d, C = %d\n", a, b, c);
        }
    }
}

/*
Explained with example:
n = 42

10 * 0 + 2 + 10 * 4 + 0 (PEMDAS: In this case, do multiplication first. 10 * 0 and 10 * 4)

    0 + 2 + 40 + 0  (PEMDAS:  Now add 40 + 2)

            42   (result)
*/
