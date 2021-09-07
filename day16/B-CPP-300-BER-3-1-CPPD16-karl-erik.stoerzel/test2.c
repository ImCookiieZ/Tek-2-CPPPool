#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *allocatedMemory = malloc(60 * 1024 + 1);
	memset(allocatedMemory, 0, 60 * 1024 + 1);
	unsigned int pointerToMemory = 0;
	allocatedMemory[pointerToMemory]--;
	while (allocatedMemory[pointerToMemory])
	{
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		pointerToMemory++;
		allocatedMemory[pointerToMemory]++;
		pointerToMemory--;
	}
	pointerToMemory++;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	write(1, &allocatedMemory[pointerToMemory], 1);
	while (allocatedMemory[pointerToMemory])
	{
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		pointerToMemory++;
		allocatedMemory[pointerToMemory]++;
		pointerToMemory--;
	}
	pointerToMemory++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	write(1, &allocatedMemory[pointerToMemory], 1);
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	allocatedMemory[pointerToMemory]--;
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]--;
	while (allocatedMemory[pointerToMemory])
	{
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		pointerToMemory++;
		allocatedMemory[pointerToMemory]++;
		pointerToMemory--;
	}
	pointerToMemory++;
	allocatedMemory[pointerToMemory]--;
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	while (allocatedMemory[pointerToMemory])
	{
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		allocatedMemory[pointerToMemory]--;
		pointerToMemory++;
		allocatedMemory[pointerToMemory]++;
		allocatedMemory[pointerToMemory]++;
		pointerToMemory--;
	}
	pointerToMemory++;
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]++;
	while (allocatedMemory[pointerToMemory])
	{
		allocatedMemory[pointerToMemory]--;
		pointerToMemory++;
		allocatedMemory[pointerToMemory]++;
		allocatedMemory[pointerToMemory]++;
		allocatedMemory[pointerToMemory]++;
		pointerToMemory--;
	}
	pointerToMemory++;
	allocatedMemory[pointerToMemory]++;
	write(1, &allocatedMemory[pointerToMemory], 1);
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	allocatedMemory[pointerToMemory]++;
	write(1, &allocatedMemory[pointerToMemory], 1);
	return 0;
}