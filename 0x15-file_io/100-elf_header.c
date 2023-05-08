#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - To prints address
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *ptr)
{
	int m;
	int bgn;
	char s;

	printf("  Entry point address:               0x");

	s = ptr[4] + '0';
	if (s == '1')
	{
		bgn = 26;
		printf("80");
		for (m = bgn; m >= 22; m--)
		{
			if (ptr[m] > 0)
				printf("%x", ptr[m]);
			else if (ptr[m] < 0)
				printf("%x", 256 + ptr[m]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (s == '2')
	{
		bgn = 26;
		for (m = bgn; m > 23; m--)
		{
			if (ptr[m] >= 0)
				printf("%02x", ptr[m]);

			else if (ptr[m] < 0)
				printf("%02x", 256 + ptr[m]);

		}
	}
	printf("\n");
}

/**
 * print_type - To prints type
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - To print osabi
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - To prints version
 * @ptr: magic.
 * Return: no return.
 */
void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - To print data
 * @ptr: magic.
 * Return: no return.
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - To print magic info.
 * @ptr: magic.
 * Return: no return.
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys - To check the version system.
 * @ptr: magic.
 * Return: no return.
 */
void check_sys(char *ptr)
{
	char s = ptr[4] + '0';

	if (s == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (s == '1')
		printf("  Class:                             ELF32\n");

	if (s == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - To check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file and 0 if not.
 */
int check_elf(char *ptr)
{
	int addrr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addrr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - To check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int f, ret_r;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	f = open(argv[1], O_RDONLY);

	if (f < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(f, 0, SEEK_SET);
	ret_r = read(f, ptr, 27);

	if (ret_r == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(ptr);
	close(f);

	return (0);
}
