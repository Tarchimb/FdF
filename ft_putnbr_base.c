#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb, int size, char *base)
{
	int	i;

	i = 0;
	if(nb > 9)
	{
		ft_putnbr((nb / size), size, base);
		ft_putchar(base[nb % size]);
	}
	if(nb < 9)
	{
		ft_putchar(base[nb]);
	}
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		if(str[i] == '+' || str[i] == '-' 
			|| str[0] == '\0' || str[1] == '\0')
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

void	ft_putnbr_base(int	nbr, char *base)
{
	int	i;
	int	R;

	i = 0;
	R = 0;
	if(ft_check_base(base) == 1)
		return;
	ft_putnbr(nbr,ft_strlen(base), base);
	
}

#include <stdio.h>

int main ()
{
	char base[17] = "theo";
	int nbr = 14711;

	ft_putnbr_base(nbr, base);
	return(0);
}
