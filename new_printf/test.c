#include <stdio.h>
#include <wchar.h>
#include <stddef.h>
#include <inttypes.h>

int	main(void)
{
	int k;
	printf("%zu   %zu   |%05.3d|, %s", sizeof(ptrdiff_t), sizeof(signed int), -10, "%04.3d");
	return (1);
}
