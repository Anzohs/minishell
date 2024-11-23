#ifndef FT_SEARCH_H
# define FT_SEARCH_H

# include "../libs.h"
#include <stdint.h>

//typedef enum s_action	t_action;
typedef char			*t_string;
typedef struct s_entry	t_entry;
typedef struct s_node	t_node;
typedef struct s_hash	t_hash;

struct s_entry
{
	t_string	key;
	void		*value;
};

typedef enum  s_action
{
	ENTER,
	FIND,
}	t_action;

struct s_node
{
	t_entry			entry;
	struct s_node	*next;
};

struct  s_hash
{
	t_node	**node;
	size_t	len;
};

//functions of the hashmap!
t_hash		*hcreate(size_t nel);
void		hdestroy(t_hash *ht);
t_entry		*hsearch(t_hash *ht, t_entry item, t_action action);
unsigned int	hash(const t_string key, size_t nel);
#endif
