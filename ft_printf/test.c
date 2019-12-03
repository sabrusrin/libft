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

/* 	d = ft_printf("!%32.16ls!", L"(╯°□°)╯︵ ┻━┻ ");
	printf("\n%d\n", d);
	d = printf("!%32.16ls!", L"(╯°□°)╯︵ ┻━┻ ");
	printf("\n%d\n\n", d);

	d = ft_printf("%56.44ls", L"こんにちは、私はprintf単体テストです");
	printf("\n%d\n", d);
	d = printf("%56.44ls", L"こんにちは、私はprintf単体テストです");
	printf("\n%d\n\n", d);

	d = ft_printf("\\!/%2.2ls\\!/", L"┬─┬﻿ ノ( ゜-゜ノ)");
	printf("\n%d\n", d);
	d = printf("\\!/%2.2ls\\!/", L"┬─┬﻿ ノ( ゜-゜ノ)");
	printf("\n%d\n\n", d);

	d = ft_printf("!%52.3ls!", L"");
	printf("\n%d\n", d);
	d = printf("!%52.3ls!", L"");
	printf("\n%d\n\n", d); */

	d = ft_printf("|% -61.54zd|", 0);
	printf("\n%d\n", d);
	d = printf("|% -61.54zd|", 0);
	printf("\n%d\n\n", d);
/*
	d = ft_printf("%#.o, %#.0o", 0, 0);
	printf("\n%d\n", d);
	d = printf("%#.o, %#.0o", 0, 0);
	printf("\n%d\n\n", d);

	d = ft_printf("%#o, %#o", 0, 0);
	printf("\n%d\n", d);
	d = printf("%#o, %#o", 0, 0);
	printf("\n%d\n\n", d);

	d = ft_printf("%#.o", 42);
	printf("\n%d\n", d);
	d = printf("%#.o", 42);
	printf("\n%d\n\n", d);

	d = ft_printf("%.o, %.0o", 0, 0);
	printf("\n%d\n", d);
	d = printf("%.o, %.0o", 0, 0);
	printf("\n%d\n\n", d); */


/* 	d = ft_printf("|%0#15x|", -355555);
	printf("\n%d\n", d);
	d = printf("|%0#15x|", -355555);
	printf("\n%d\n\n", d);

	d = ft_printf("\\!/%8.16hhD\\!/", 3480415246880446420);
	printf("\n%d\n", d);
	d = printf("\\!/%8.16hhD\\!/", 3480415246880446420);
	printf("\n%d\n\n", d);

	d = ft_printf("42%032.2zx42", 416065976);
	printf("\n%d\n", d);
	d = printf("42%032.2zx42", 416065976);
	printf("\n%d\n\n", d);

	d = ft_printf("^.^/%#29.2zx^.^/", -1228020156);
	printf("\n%d\n", d);
	d = printf("^.^/%#29.2zx^.^/", -1228020156);
	printf("\n%d\n\n", d);

	d = ft_printf("^.^/%#27.22zo^.^/", 1238082569);
	printf("\n%d\n", d);
	d = printf("^.^/%#27.22zo^.^/", 1238082569);
	printf("\n%d\n\n", d);

	d = ft_printf("\\!/%#58.12zo\\!/", -215076898);
	printf("\n%d\n", d);
	d = printf("\\!/%#58.12zo\\!/", -215076898);
	printf("\n%d\n\n", d);
 */

/* 	d = ft_printf("!% 42.31hhd!", (char)1349783);
	printf("\n%d\n", d);
	d = printf("!% 42.31hhd!", (char)1349783);
	printf("\n%d\n\n", d);

	d = ft_printf("42%+48.32zd42", 0);
	printf("\n%d\n", d);
	d = printf("42%+48.32zd42", 0);
	printf("\n%d\n\n", d);

	d = ft_printf("!%20.18zd!", 0);
	printf("\n%d\n", d);
	d = printf("!%20.18zd!", 0);
	printf("\n%d\n\n", d);

	d = ft_printf(">------------<%48.24zd>------------<", 0);
	printf("\n%d\n", d);
	d = printf(">------------<%48.24zd>------------<", 0);
	printf("\n%d\n\n", d);

	d = ft_printf("\\!/%+56.33hhd\\!/", -1040849184);
	printf("\n%d\n", d);
	d = printf("\\!/%+56.33hhd\\!/", -1040849184);
	printf("\n%d\n\n", d);

	d = ft_printf("^.^/%043.2zd^.^/", 29934278);
	printf("\n%d\n", d);
	d = printf("^.^/%043.2zd^.^/", 29934278);
	printf("\n%d\n", d);

	d = ft_printf("%016zd", 0);
	printf("\n%d\n", d);
	d = printf("%016zd", 0);
	printf("\n%d\n\n", d);
 */
/* 	d = ft_printf("!%20.18zd!", 0);
	printf("\n%d\n", d);
	d = printf("!%20.18zd!", 0);
	printf("\n%d\n\n", d); */


	//printf("\n\n%zd %zd - %zu", -40, 40, sizeof(size_t));
	//printf("%zu   %zu   |%-05d|, %s", sizeof(ptrdiff_t), sizeof(signed int), -10, "%-05d");
	return (1);
}
/*alias rt='make re; ./run_test -e d'*/
/*alias tt='gcc -o test test.c -I ../includes -L ../ -lftprintf; ./test'*/
