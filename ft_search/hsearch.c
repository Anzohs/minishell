#include "ft_search.h"
#include <stdlib.h>

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
	t_entry	*entry;

	entry = hsearch(ht, item, FIND);
	if (entry)
	{
		free(entry->value);
		entry->value = strdup((t_string)item.value);
		return (entry);
	}
	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->entry.key = strdup(item.key);
	new->entry.value = strdup((t_string)item.value);
	if (ht->node[i])
	{
		free(ht->node[i]->entry.key);
		free(ht->node[i]->entry.value);
		free(ht->node[i]);
	}
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
