	.file	"a.cpp"
	.text
	.globl	__Z1gi
	.def	__Z1gi;	.scl	2;	.type	32;	.endef
__Z1gi:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$3, %eax
	popl	%ebp
	ret
	.globl	__Z1fi
	.def	__Z1fi;	.scl	2;	.type	32;	.endef
__Z1fi:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z1gi
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$8, (%esp)
	call	__Z1fi
	addl	$1, %eax
	leave
	ret
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
