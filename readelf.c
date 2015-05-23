#include<stdio.h>
#include<stdlib.h>
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
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for(int i = 0; i < 16; i++)
	{
		printf("%x ",elf_header->ident[i];
	}	
	printf("\n");

	printf("Class:\t\t\t");
	for(int i = 0; i< 3; i++)
	{
		printf("%c",elf_header->ident[i+1];
	}

}

int main(int argc, char *argv[])
{
	read(argv[1], &elf_header);
	print(&elf_header);
	return 0;
}
