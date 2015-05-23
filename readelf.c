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

	printf("  Class:\t\t\t\t\t");
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
	
	printf("  Data:\t\t\t\t\t\t");
	switch(elf_header->e_ident[5])
	{
		case 0: printf("Invalid data encoding\n");break;
		case 1: printf("2's complement, lttle endian(LSB)\n");break;
		case 2: printf("2's complement, big endian(MSB)\n");break;
	}
	printf("  Version:\t\t\t\t\t");
	switch(elf_header->e_ident[6])
	{
		case 0:printf("%d (invalid)\n",elf_header->e_version);break;
		case 1:printf("%d (current)\n",elf_header->e_version);break;
	}
	
	printf("  OS/ABI:\t\t\t\t\t");
	switch(elf_header->e_ident[7])
	{
	case ELFOSABI_NONE:
	    printf("UNIX System V\n");
	    break;
	case ELFOSABI_HPUX:
	    printf("HP-UX operating system\n");
	    break;
	case ELFOSABI_NETBSD:
	    printf("NetBSD \n");
	    break;
	case ELFOSABI_LINUX:
	    printf("GNU/Alias for ELFOSABI_GNU \n");
	    break;
	case ELFOSABI_SOLARIS:
	    printf("Solaris\n");
	    break;
	case ELFOSABI_AIX:
	    printf("AIX \n");
	    break;
	case ELFOSABI_IRIX:
	    printf("IRIX\n");
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
	
	printf("  ABI Version:\t\t\t\t\t");
	switch(elf_header->e_ident[6])
	{
	case 0 :
	    printf("0\n");
	    break;
	case 1 :
	    printf("1\n");
	    break;
	}
	
	printf("  Type:\t\t\t\t\t\t");
    switch(elf_header->e_type)
	{
	case ET_NONE:
	    printf("No file type\n ");
	    break;
	case ET_REL:
	    printf("Relocatable file\n ");
	    break;
	case ET_EXEC:
	    printf("Executable file \n");
	    break;
	case ET_DYN:
	    printf("Shared Object File \n");
	    break;
	case ET_CORE:
	    printf("Core file\n ");
	    break;
	case ET_LOOS:
	    printf("Operating System Specific\n ");
	    break;
	case ET_HIOS:
	    printf("Operating system Specific\n ");
	    break;
	case ET_LOPROC:
	    printf("Processor specific \n");
	    break;
	case ET_HIPROC:
	    printf("Processor specific\n");
	    break;
	}
	
	printf("  Machine:\t\t\t\t\t");
	switch(elf_header->e_machine)
	{
		case EM_NONE:
			printf("No machine\n");
			break;
		case EM_32:
			printf("AT%T WE 32100\n");
			break;
		case EM_SPARC:
			printf("SPARC\n");
			break;
		case EM_386:
			printf("Intel 80386\n");
			break;
		case EM_68k:
			printf("Motorola 68000\n");
			break;
		case EM_88k:
			printf("Motorola 88000");
			break;
		case EM_860:
			printf("Intel 80860\n");
			break;
		case EM_MIPS:
			printf("MIPS RS3000\n");
			break;
		default:
			printf("other machine\n");
	}
	printf("  Version:\t\t\t\t\t");
	switch(elf_header->e_version)
	{
		case 0:
			printf("0\n");
			break;
		case 1:
			printf("1\n");
			break;
	}
	printf("  Entry point address:\t\t\t\t0x%x\n"
		,elf_header->e_entry);
	printf("  Start of program headers:\t\t\t%d "
		"bytes into file\n",elf_header->e_phoff);
	printf("  Start of section headers:\t\t\t%d"
		"bytes into file\n",elf_header->e_shoff);
	printf("  Flags:\t\t\t\t\t0x%x\n"
		,elf_header->e_flags);
	printf("  Size of this header:\t\t\t\t%d (bytes)\n"
		,elf_header->e_ehsize);
	printf("  Size of program header:\t\t\t%d (bytes)\n"
		,elf_header->e_phentsize);
	printf("  Number of program header:\t\t\t%d\n"
		,elf_header->e_phnum);
	printf("  Size of section headers:\t\t\t%d (bytes)\n"
		,elf_header->e_shentsize);
	printf("  Number of section headers:\t\t\t%d\n"
		,elf_header->e_shnum);
	printf("  Section header string table index:\t\t%d\n"
		,elf_header->e_shstrndx);
}

int main(int argc, char *argv[])
{
	read(argv[1], &elf_header);
	print(&elf_header);
	return 0;
}
