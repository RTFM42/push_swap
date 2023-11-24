#include "push_swap.h"

t_node	*ps_stack_op_rotate(t_node *node)
{
	t_node	*isolate;

	if (node == NULL || node->next == NULL)
		return (node);
	isolate = node;
	node = node->next;
	node->prev = NULL;
	node = ps_node_last(node);
	node->next = isolate;
	isolate->next = NULL;
	isolate->prev = node;
	return (ps_node_first(node));
}