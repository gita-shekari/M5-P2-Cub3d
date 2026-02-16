#include "cub3d.h"

//while (line[i] == ' ' || line[i] =='\t')
int	pass_spaces(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

static int	process_line(char *line, t_env *env, int i, int fd)
{
	char *cpy_line;

	cpy_line = NULL;
	if (line[i] == '1' || line[i] =='0')
	{
		cpy_line = ft_strdup(line);
		if (!cpy_line)
			return (ft_malloc("process line"));
		return (parse_map(fd, env, cpy_line));
	}
	else if (!line[i] || line[i] == '\n')
		return (2);
	else
	{
		if (!parse_textures(line, i, env))
			return (0);
		else
			return (2);
	}
}

int	init_env(int fd, t_env *env)
{
	char	*line;
	int		i;
	int		res;

	line = get_next_line(fd);
	if(!line)
		return (0);
	while (line)
	{
		i = pass_spaces(line);
		res = process_line(line, env, i, fd);
		if (res == 0)
		{
			free_charptr(&line);
			return (line = get_next_line(-1), 0);
		}
		else if (res == 1)
		{
			free_charptr(&line);
			break ;
		}
		free_charptr(&line);
		line = get_next_line(fd);
	}
	return (1);
}
