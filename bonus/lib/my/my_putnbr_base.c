/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** Convert and displays a decimal number into a number
*/

void my_putchar(char c);

static int divide_base(int nb, int base)
{
    int rest = 0;

    if (nb <= 0)
        return (1);
    rest = nb % base;
    divide_base(nb/base, base);
    if (rest < 10)
        my_putchar('0' + rest);
    else if (base > 10)
        my_putchar('A' + (rest - 10));
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_c = 0;

    for (int i = 0; base[i] != '\0'; i++)
        base_c++;
    if (nbr < 0) {
        nbr *= -1;
        my_putchar('-');
    }
    divide_base(nbr, base_c);
    return (0);
}
