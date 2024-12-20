
#include "include/ft_printf.h"

int main(void)
{
	//ft_printf("|%+d|\n", 2147483647);
	//printf("|%+d|\n", 2147483647);
	//ft_printf("|%-4.5d%d%4d%-10d-d5%-.3d|\n", 300000, 400000, 500000, 600000, 700000);
	//ft_printf("|%1x|\n", 0);
	//printf("|%1x|\n", 0);
	//ft_printf("|%.11d|\n", (int)-2147483648);
	//printf("|%.11d|\n", (int)-2147483648);
	ft_printf("|%-.d|\n", 0);
	printf("|%-.d|\n", 0);
	printf("|% i|\n", -3);
	printf("|% i|\n", 0);
	printf("|%+i|\n", 0);
	ft_printf("|%030d|\n", (int)-2147483648);
}	
