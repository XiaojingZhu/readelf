/* Values for e_type, which identifies the object file type.  */

#define ET_NONE		0	/* No file type */
#define ET_REL		1	/* Relocatable file */
#define ET_EXEC		2	/* Executable file */
#define ET_DYN		3	/* Shared object file */
#define ET_CORE		4	/* Core file */
#define ET_LOOS		0xFE00	/* Operating system-specific */
#define ET_HIOS		0xFEFF	/* Operating system-specific */
#define ET_LOPROC	0xFF00	/* Processor-specific */
#define ET_HIPROC	0xFFFF	/* Processor-specific */


/* EI_OSABI	7	 Operating System/ABI indication */
#define ELFOSABI_NONE	      0	/* UNIX System V ABI */
#define ELFOSABI_HPUX	      1	/* HP-UX operating system */
#define ELFOSABI_NETBSD	      2	/* NetBSD */
#define ELFOSABI_GNU	      3	/* GNU */
#define ELFOSABI_LINUX	      3	/* Alias for ELFOSABI_GNU */
#define ELFOSABI_SOLARIS      6	/* Solaris */
#define ELFOSABI_AIX	      7	/* AIX */
#define ELFOSABI_IRIX	      8	/* IRIX */
#define ELFOSABI_FREEBSD      9	/* FreeBSD */
#define ELFOSABI_TRU64	     10	/* TRU64 UNIX */
#define ELFOSABI_MODESTO     11	/* Novell Modesto */
#define ELFOSABI_OPENBSD     12	/* OpenBSD */
#define ELFOSABI_OPENVMS     13	/* OpenVMS */
#define ELFOSABI_NSK	     14	/* Hewlett-Packard Non-Stop Kernel */
#define ELFOSABI_AROS	     15	/* AROS */
#define ELFOSABI_FENIXOS     16 /* FenixOS */
#define ELFOSABI_C6000_ELFABI 64 /* Bare-metal TMS320C6000 */
#define ELFOSABI_C6000_LINUX 65 /* Linux TMS320C6000 */
#define ELFOSABI_ARM	     97	/* ARM */
#define ELFOSABI_STANDALONE 255	/* Standalone (embedded) application */

/*   e_machine         Machine*/
#define EM_NONE  0   /*No machine*/
#define EM_32    1   /*AT%T WE 32100*/
#define EM_SPARC 2   /*SPARC*/
#define EM_386   3   /*Intel 80386*/
#define EM_68k   4   /*Motorola 68000*/
#define EM_88k   5   /*Motorola 88000*/
#define EM_860   7   /*Intel 80860*/
#define EM_MIPS  8   /*MIPS RS3000*/