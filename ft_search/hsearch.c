#include "ft_search.h"

static	t_entry	*hash_search(t_node *n, t_entry item)
{
	while(n)
	{
		if (strcmp(n->entry.key, item.key) == 0)
			return (&n->entry);
		n = n->next;
	}
	return (NULL);
}

static	t_entry	*hash_add(t_hash *ht, t_entry item, unsigned int i)
{
	t_node	*new;

	new = ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (NULL);
	new->entry.key = strdup(item.key);
	new->entry.value = strdup((t_string)item.value);
	ht->node[i] = new;
	return (&new->entry);
}

t_entry		*hsearch(t_hash *ht, t_entry item, t_action action)
{
	if (!item.key || (action != FIND && action != ENTER) || !ht)
		return (NULL);
	if (action == ENTER)
		return (hash_add(ht, item, hash(item.key, ht->len)));
	if (action == FIND)
		return (hash_search(ht->node[hash(item.key, ht->len)], item));
	return (NULL);
}
