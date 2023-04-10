#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addrr - prints address
 * @pt: magic.
 * Return: no return.
 */
void print_addrr(char *pt)
{
	int n;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = pt[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (n = begin; n >= 22; n--)
		{
			if (pt[n] > 0)
				printf("%x", pt[n]);
			else if (pt[n] < 0)
				printf("%x", 256 + pt[n]);
		}
		if (pt[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (n = begin; n > 23; n--)
		{
			if (pt[n] >= 0)
				printf("%02x", pt[n]);

			else if (pt[n] < 0)
				printf("%02x", 256 + pt[n]);

		}
	}
	printf("\n");
}

/**
 * print_type - prints type
 * @pt: magic.
 * Return: no return.
 */
void print_type(char *pt)
{
	char type = pt[16];

	if (pt[5] == 1)
		type = pt[16];
	else
		type = pt[17];

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
 * print_osabi - prints osabi
 * @pt: magic.
 * Return: no return.
 */
void print_osabi(char *pt)
{
	char osabi = pt[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                   %d\n", pt[8]);
}


/**
 * print_version - prints version
 * @pt: magic.
 * Return: no return.
 */
void print_version(char *pt)
{
	int version = pt[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - prints data
 * @pt: magic.
 * Return: no return.
 */
void print_data(char *pt)
{
	char data = pt[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @pt: magic.
 * Return: no return.
 */
void print_magic(char *pt)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", pt[bytes]);

	printf("\n");

}

/**
 * check_sys - check the version system.
 * @pt: magic.
 * Return: no return.
 */
void check_sys(char *pt)
{
	char sys = pt[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(pt);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(pt);
	print_version(pt);
	print_osabi(pt);
	print_type(pt);
	print_addrr(pt);
}

/**
 * check_elf - check if it is an elf file.
 * @pt: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *pt)
{
	int addrr = (int)pt[0];
	char E = pt[1];
	char L = pt[2];
	char F = pt[3];

	if (addrr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the cod.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, ret_read;
	char pt[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	i = open(argv[1], O_RDONLY);

	if (i < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(i, 0, SEEK_SET);
	ret_read = read(i, pt, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(pt))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(pt);
	close(i);

	return (0);
}
