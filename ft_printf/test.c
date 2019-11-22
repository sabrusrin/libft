#include <stdio.h>
#include <wchar.h>
#include <stddef.h>
#include <inttypes.h>
#include <locale.h>
#include "libft.h"
#include "ft_printf.h"
//#include <stdio.h>

int	main(void)
{
	int	d;

	setlocale(LC_ALL, "");

	d = ft_printf("!%32.16ls!", L"(╯°□°)╯︵ ┻━┻ ");
	printf("\n%d\n", d);
	d = printf("!%32.16ls!", L"(╯°□°)╯︵ ┻━┻ ");
	printf("\n%d\n\n", d);

	d = ft_printf("42%56.44ls42", L"こんにちは、私はprintf単体テストです");
	printf("\n%d\n", d);
	d = printf("42%56.44ls42", L"こんにちは、私はprintf単体テストです");
	printf("\n%d\n\n", d);

	d = ft_printf("42%20.16zd42", -294712504);
	printf("\n%d\n", d);
	d = printf("42%20.16zd42", -294712504);
	printf("\n%d\n", d);

	d = ft_printf("|%2lc|", (char)9876);
	printf("\n%d\n", d);
	d = printf("|%2lc|", (char)9876);
	printf("\n%d\n", d);

	//printf("\n\n%zd %zd - %zu", -40, 40, sizeof(size_t));
	//printf("%zu   %zu   |%-05d|, %s", sizeof(ptrdiff_t), sizeof(signed int), -10, "%-05d");
	return (1);
}
