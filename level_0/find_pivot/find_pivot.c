/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:42:27 by jadawson          #+#    #+#             */
/*   Updated: 2019/08/31 16:49:31 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_pivot(int* arr, int n) {
    
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];


    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (tmp == sum - tmp - arr[i])
            return i;
        tmp += arr[i];
    }
    return -1;
}


/************
  Test Main
************/

/*
#include <stdio.h>
int main() {

    int a[] = {1, 2, 3, 4, 0, 6};
    printf("%d\n", find_pivot(a, 6));

    int b[] = {-5, 10, 2, 5};
    printf("%d\n", find_pivot(b, 4));

    int c[] = {1, 100, 0, 0, 1};
    printf("%d\n", find_pivot(c, 5));

    int d[] = {7, 9, 8};
    printf("%d\n", find_pivot(d, 3));

    int e[] = {1, 2};
    printf("%d\n", find_pivot(e, 2));

    return 0;
}
*/



/*
Explained with int a[] = {1, 2, 3,4, 0, 6}
Each number represents an iteration through the loop.


 temp  sum  tmp  arg[i]
1) 0 == 16 - 0 - 1
	0 == 15  (false)  

2) 1 == 16 - 2 - 2
	1 == 13 (false)

3) 3 == 16 - 3 - 3
	3 == 10  (false)

4) 6 == 16 - 6 - 4
	6 == 6  (true)

Returns i, which is at arg[3] position (the number 4 in the array).


*/























