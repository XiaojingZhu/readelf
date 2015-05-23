#include<stdio.h>
#include<stdlib.h>
#include"elfinfo.h"  //储存相关信息的表
#define EI_NIDENT  16

typedef struct{
	unsigned char	e_ident[EI_NIDENT];
	unsigned short	e_type;
	unsigned short	e_machine;
	unsigned int	e_version;
	unsigned int	e_entry;
	unsigned int	e_phoff;
	unsigned int	e_shoff;
	unsigned int	e_flags;	
	unsigned short	e_ehsize;
	unsigned short	e_phentsize;
	unsigned short	e_phnum;
	unsigned short	e_shentsize;
	unsigned short	e_shnum;
	unsigned short	e_shstrndx;
} Elf32_Ehdr;

Elf32_Ehdr elf_header;

void read(char *filename,Elf32_Ehdr *elf_header)
{
	FILE *file ;
	file = (FILE*)fopen(filename,"rb");
	if(file == NULL)
	{
		printf("cann't open the file %s",file);
		exit(1);
	}
	fread(elf_header,sizeof(Elf32_Ehdr),1,file);
}

void print(Elf32_Ehdr *elf_header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for( i = 0; i < 16; i++)
	{
		if(elf_header->e_ident[i] > 0xe)
			printf("%x ",elf_header->e_ident[i]);
		else
			printf("0%x ",elf_header->e_ident[i]);
	}	
	printf("\n");

	printf("Class:\t\t\t");
	for( i = 0; i< 3; i++)
	{
		printf("%c",elf_header->e_ident[i+1]);
	}
	switch(elf_header->e_ident[4])
	{
		case 0: printf("Invalid class\n");
				break;
		case 1: printf("32\n");
				break;
		case 2: printf("64\n");
	}
	
	printf("Data:\t\t\t");
	switch(elf_header->e_ident[5])
	{
		case 0: printf("Invalid data encoding\n");break;
		case 1: printf("2's complement, lttle endian(LSB)\n");break;
		case 2: printf("2's complement, large endian(MSB)\n");break;
	}
	printf("Version:\t\t\t");
	switch(elf_header->e_ident[6])
	{
		case 0:printf("%d (invalid)\n",elf_header->e_version);break;
		case 1:printf("%d (current)\n",elf_header->e_version);break;
	}
	
	printf("OS/ABI:\t\t");
	switch(elf_header->e_ident[7])
	{
	case ELFOSABI_NONE:
	    printf("UNIX System V\n ");
	    break;
	case ELFOSABI_HPUX:
	    printf("HP-UX operating system\n ");
	    break;
	case ELFOSABI_NETBSD:
	    printf("NetBSD \n");
	    break;
	case ELFOSABI_LINUX:
	    printf("GNU/Alias for ELFOSABI_GNU \n");
	    break;
	case ELFOSABI_SOLARIS:
	    printf("Solaris\n ");
	    break;
	case ELFOSABI_AIX:
	    printf("AIX \n");
	    break;
	case ELFOSABI_IRIX:
	    printf("IRIX\n ");
	    break;
	default:
	    printf("Other\n");
	    break;
	    /* remaining */
	    //#define ELFOSABI_FREEBSD      9	/* FreeBSD */
	    //#define ELFOSABI_TRU64	     10	/* TRU64 UNIX */
	    //#define ELFOSABI_MODESTO     11	/* Novell Modesto */
	    //#define ELFOSABI_OPENBSD     12	/* OpenBSD */
	    //#define ELFOSABI_OPENVMS     13	/* OpenVMS */
	    //#define ELFOSABI_NSK	     14	/* Hewlett-Packard Non-Stop Kernel */
	    //#define ELFOSABI_AROS	     15	/* AROS */
	    //#define ELFOSABI_FENIXOS     16 /* FenixOS */
	    //#define ELFOSABI_C6000_ELFABI 64 /* Bare-metal TMS320C6000 */
	    //#define ELFOSABI_C6000_LINUX 65 /* Linux TMS320C6000 */
	    //#define ELFOSABI_ARM	     97	/* ARM */
	    //#define ELFOSABI_STANDALONE 255	/* Standalone (embedded) application *
	}
}

int main(int argc, char *argv[])
{
	read(argv[1], &elf_header);
	print(&elf_header);
	return 0;
}
