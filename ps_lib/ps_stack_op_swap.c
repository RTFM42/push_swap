#include "push_swap.h"

t_node	*ps_stack_op_swap(t_node *node)
{
	t_node	*node_1;
	t_node	*node_2;
	t_node	*node_3;

	if (node == NULL || node->next == NULL)
		return (node);
	node_1 = node;
	node_2 = node->next;
	node_3 = node->next->next;
	node_2->prev = NULL;
	node_2->next = node_1;
	node_1->prev = node_2;
	node_1->next = node_3;
	if (node_3 != NULL)
		node_3 -> prev = node_1;
	return (node_2);
}