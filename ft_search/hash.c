#include "ft_search.h"

unsigned int	hash(const t_string key, size_t nel)
{
	unsigned int	hash;
	t_string		k;

	hash = 0;
	k = key;
	while (*k)
		hash = (hash << 5) + *k++;
	return (hash % nel);
}
