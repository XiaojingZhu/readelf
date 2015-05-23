#include<stdio.h>
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

Elf32_Ehdr elf_head;

void read(char *file,Elf32_Ehdr *elf_header)
{
	file = fopen(file,rb);
	if(file == NULL)
	{
		printf("cann't open the file %s",file);
		exit(1);
	}
	fread(elf_header,sizeof(Elf32_Ehdr),1,file);
}

void print(Elf32_Ehdr *elf_header)
{
	printf("ELF Header:\n");
	printf("Magic: %x %x ",elf_header->e_ident[0],elf_header->e_ident[1]);
}

int main(int argc, char *argv[])
{
	read(argv[1], elf_header);
	print(elf_head);
	return 0;
}
