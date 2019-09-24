/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:57:54 by jadawson          #+#    #+#             */
/*   Updated: 2019/09/23 18:44:34 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

struct s_stack {
 	struct s_node *top;
 };

#include <stdlib.h>
#include <stdio.h>

int	is_looping(struct s_node *node)
{
	if (node == NULL || node->next == NULL)
		return (0);

	struct s_node *slow;
	struct s_node *fast;

	slow = node;
	fast = node->next;
	
	while (fast->next && fast->next->next)
	{
		if (slow == fast)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}

 struct s_stack *init(void)
 {
 	 struct s_stack *stack = malloc(sizeof(struct s_stack));
 	 stack->top = NULL;
 	return (stack);
 }

 int pop(struct s_stack *stack)
 {
 	if (stack == NULL || stack->top == NULL)
 		return (0);
 	struct s_node *node = stack->top;
	int value = node->value;
 	stack->top = node->next;
 	free(node);
 	return (value);
 }

void push(struct s_stack *stack, int value)
{
 	if (stack == NULL)
 		return ;

 	struct s_node *node = malloc(sizeof(struct s_node));
 	node->value = value;
 	node->next = stack->top;
 	stack->top = node;
}

 int peek(struct s_stack *stack)
 {
 	if (stack == NULL || stack->top == NULL)
 		return (0);
 	return (stack->top->value);
 }

 int isEmpty(struct s_stack *stack)
 {
 	if (stack == NULL || stack->top == NULL)
		return (1);
 	return (0);
 }

 int	main(void)
 {
 	struct s_stack *stack = init();
	
 	push(stack, 1);
 	push(stack, 2);
 	push(stack, 3);
 	push(stack, 4);
 	push(stack, 5);
 	push(stack, 6);
 	push(stack, 7);
 	push(stack, 8);
 	push(stack, 9);
 	push(stack, 10);

 	stack->top->next = stack->top;

 	printf("is looping? %d\n",
 		is_looping(stack->top)
 		);
}


