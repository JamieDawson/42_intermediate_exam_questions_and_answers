/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:21:17 by jadawson          #+#    #+#             */
/*   Updated: 2019/10/07 17:21:23 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
  int value;
  struct s_node **nodes;
} Node;

int height_tree(Node *root) {
  int i, ret = 0;

  if (!root)
    return -1;

  if (!root->nodes || !*root->nodes)
    return 0;

  for (i = 0; root->nodes[i]; ++i) {
    int tmp = 1 + height_tree(root->nodes[i]);
    if (tmp > ret)
      ret = tmp;
  }
  return ret;
}

#ifdef DEBUG
Node *nn(int v, int l) {
  Node *n = calloc(sizeof(*n), 1);

  n->nodes = calloc(sizeof(*n->nodes), l + 1);
  n->value = v;

  return n;
}
int main() {
  Node *tr1 = nn(94, 2);

  tr1->nodes[0] = nn(34, 2);
  tr1->nodes[0]->nodes[0] = nn(1, 0);
  tr1->nodes[0]->nodes[1] = nn(99, 0);
  tr1->nodes[1] = nn(52, 1);
  tr1->nodes[1]->nodes[0] = nn(11, 1);
  tr1->nodes[1]->nodes[0]->nodes[0] = nn(13, 1);
  int ret = height_tree(tr1);
  printf("ret(%d)\n", ret);
  assert(ret == 3);
}
#endif
