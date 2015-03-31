	.file	"private_static.cpp"
	.globl	__ZN1A2xpE
	.data
	.align 4
__ZN1A2xpE:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.globl	__ZN1B2arE
	.bss
	.align 4
__ZN1B2arE:
	.space 12
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L1
	cmpl	$65535, 12(%ebp)
	jne	L1
	movl	$1, (%esp)
	call	__Znwj
	movl	%eax, __ZN1B2arE
	movl	$1, (%esp)
	call	__Znwj
	movl	%eax, __ZN1B2arE+4
	movl	$1, (%esp)
	call	__Znwj
	movl	%eax, __ZN1B2arE+8
L1:
	leave
	ret
	.def	__GLOBAL__sub_I__ZN1A2xpE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN1A2xpE:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN1A2xpE
	.ident	"GCC: (i686-win32-sjlj-rev2, Built by MinGW-W64 project) 4.9.2"
	.def	__Znwj;	.scl	2;	.type	32;	.endef
