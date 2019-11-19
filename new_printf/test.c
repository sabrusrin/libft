#include <stdio.h>
#include <wchar.h>
#include <stddef.h>

int	main(void)
{
	int k;
	printf("%zu   %zu", sizeof(ptrdiff_t), sizeof(wint_t));
	return (1);
}
