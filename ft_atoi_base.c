int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		if(str[i] == '+' || str[i] == '-' 
			|| str[0] == '\0' || str[1] == '\0' 
				|| (str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
				return(1);
		while(str[j])
		{
			if(str[j] == str[i])
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_check_str(char *str, int *i)
{
	int	j;

	j = 0;
	while((str[*i] >= 9 && str[*i] <= 13) || (str[*i] == 32))
		*i += 1;
	while(str[*i] == '+' || str[*i] == '-')
	{
		if(str[*i] == '-')
			j++;
		*i += 1;
	}
	if(j % 2 == 1)
		return(1);
	return(0);
}

int	ft_strstr(char *str, char to_find, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == to_find)
			return(1);
		*j += 1;
		i++;
	}
	return(0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	R;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = ft_strlen(base);
	if(ft_check_base(base) == 1)
		return(0);
	ft_check_str(str, &i);
	while(str[i] && ft_strstr(base,str[i], &k) == 1)
	{
		R = (R * j) + (k);
		i++;
		k = 0;
	}
	i = 0;
	if (ft_check_str(str, &i) % 2 == 1)
		R *= -1;
	return(R);
}

#include <stdio.h>

int main()
{
	printf("%d \n", ft_atoi_base("FFFFFF", "0123456789ABCDEF"));
	return 0;
}
