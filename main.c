#include "Includes/libft.h"
#include "Includes/fdf.h"

char    **ft_parsing(int fd, int count_line)
{
    char    **save;
    int     i;

    i = 0;
    save = malloc(sizeof(char*) * (count_line + 1));
    if (!save)
        return (NULL);
    while(i < count_line)
    {
        save[i] = get_next_line(fd);
        i++;
    }
    save[i] = 0;
    return (save);
}

int ft_count_line(int fd)
{
    int     i;
    char    *dest;

    i = 0;
    dest = get_next_line(fd);
    while(dest != NULL)
    {
        free(dest);
        dest = get_next_line(fd);
        i++;
    }
    free(dest);
    return (i);
}

int ft_count_int(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != ' ' && s[i])
		{
			i++;
			if (s[i] == ' ' || !s[i])
				j++;
		}
		if (s[i])
			i++;
	}
	return (j);
}

// static void	*ft_check_null(int **str)
// {
// 	int	j;

// 	j = 0;
// 	while (str[j])
// 	{
// 		free(str[j]);
// 		j++;
// 	}
// 	free(str);
// 	return (NULL);
// }

int **ft_convert(char **save, int count_line)
{
    int     **tab;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    tab = malloc(sizeof(int *) * (count_line));
    if (!tab)
        return(NULL);
    while (save[i])
    {
        tab[i] = malloc(sizeof(int) * ft_count_int(save[i]));
        if (!tab[i])
            return (0);
        while (save[i][j])
        {
            if (save[i][j] != ' ')
            {
                tab[i][k] = ft_atoi(save[i], &j);
                k++;
            }
            else
                j++;
        }
        i++;
        j = 0;
        k = 0;
    }
    return (tab);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    int     fd;
    int     i;
    char    **save;
    int     **parse;

    fd = open(argv[1], O_RDONLY);
    i = ft_count_line(fd);
    fd = open(argv[1], O_RDONLY);
    save = ft_parsing(fd, i);
    parse = ft_convert(save, i);
    i = 0;
    while (save[i] != 0)
    {
        printf("%s",save[i]);
        free(save[i]);
        i++;
    }
    printf("%d", parse[9][3]);
    free(save);
    close(fd);

	return (0);
}
