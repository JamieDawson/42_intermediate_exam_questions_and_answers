/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:33:05 by jadawson          #+#    #+#             */
/*   Updated: 2019/09/09 16:01:01 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //for printf. Delete
#include <stdlib.h> //keep.

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

int isEmpty(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return 1;
	return 0;
}

void *peek(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (NULL);
	return(stack->top->content);
}

void push(struct s_stack *stack, void *content)
{
	if (stack == NULL)
		return ;

	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}


void *pop(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return NULL;
	
	struct s_node *node = stack->top;
	void *content = node->content;
	stack->top = node->next;
	free(node);
	return (content);

}

int		main()
{
	char a[] = "aaa";
	(void)a;
	char b[] = "bbb";
	(void)b;
	
	struct s_stack *stack;
	stack = init();
	printf("%i isEmpty\n", isEmpty(stack));
	
	push(stack, a);
	printf("%s peek\n", peek(stack));
	push(stack, b);	
	printf("%s peek\n", peek(stack));

	printf("%s pop\n", pop(stack));
	printf("%s peek\n", peek(stack));
	printf("%s pop\n", pop(stack));
	printf("%s peek\n", peek(stack));

	return (0);
}
