#include <unistd.h>

void ft_putstr(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		write(1, &str[i], 1);
	}
}

void ft_putnbr(int nb) {
	char c;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int ft_strlen(char *str) {
	int x = 0;
	while (str[x] != '\0') {
		x++;
	}
	return x;
}

int count_letters(char *str) {
	int letter = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z')) {
			letter++;
		}
	}
	return letter;
}

int count_digits(char *str) {
	int numbers = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			numbers++;
		}
	}
	return numbers;
}

int main() {
	char *text = "Salut les Copains de 42";

	ft_putstr("Lettres : ");
	ft_putnbr(count_letters(text));
	write(1, "\n", 1);

	ft_putstr("Chiffres : ");
	ft_putnbr(count_digits(text));
	write(1, "\n", 1);

	return 0;
}
