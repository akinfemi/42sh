#include "minishell.h"

int		ft_history_add(t_data *data, t_dlist *input_chain)
{
	t_dlist	*new;
	char	*str;

	str = ft_dlsttostr(input_chain);
	if (data->history)
		while (data->history->next)
			data->history = data->history->next;
	str = ft_strcut(str, "\\\n");
	if (!data->history->prev || ft_strcmp(str, (char *)data->history->prev->content))
	{
		new = ft_dlst_new(str, sizeof(char) * (ft_strlen(str) + 1));
		ft_dlst_add_before(&data->history, new);
		data->history = data->history->next;
		ft_strdel((char **)&data->history->content);
	}
	return (0);
}
