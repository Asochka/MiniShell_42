#include "../includes/minishell.h"

void	ft_free_struct_bp(t_block_process *bp)
{
	int			i;

	i = 0;
	while (bp->argv[i])
	{
		free(bp->argv[i]);
		i++;
	}
	free(bp->argv);
	i = 0;
	while (i < bp->files_count)
	{
		free(bp->files[i].file_name);
		i++;
	}
	free(bp->files);
	free(bp);
}

void	ft_free_block_process(t_list **head)
{
	t_list	*prev;

	if (!*head)
		return ;
	while (*head)
	{
		prev = (*head);
		(*head) = (*head)->next;
		if (prev->content)
			ft_free_struct_bp((t_block_process *)prev->content);
		free(prev);
	}
}
