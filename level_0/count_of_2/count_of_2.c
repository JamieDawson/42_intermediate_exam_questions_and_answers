/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:17:29 by jadawson          #+#    #+#             */
/*   Updated: 2019/08/05 21:23:28 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     checker_2(int n) 
{
    int sum = 0;
    
    while (n != 0) 
    {
        if (n % 10 == 2)
            sum++;
        n /= 10;
    }
    return (sum);
}

int    count_of_2(int n)
{
    int i = 2;
    int sum = 0;
    
    if (n == 1 || n == 0)
        return 0;
    
    while (i <= n)
    {
        sum += checker_2(i);
        i++;
    }
    return (sum);
}

int    main(void)
{
	printf("%d\n", count_of_2(22));
}

/*
Logic:  

First, check if the number is 1 or 0 and just return 0.

i is used to start at 2 and build its way up to whatever number we give it (12, 25, 222, etc).

If we pass in 22, it runs the number through (n % 10 == 2), counts one 2, then it divides it by 10,
changing it from 22 to 2. The 2 then hits the (n % 10 == 2), which counts the last 2.

*/


