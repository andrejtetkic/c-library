	.file	"main.c"
	.text
	.comm	_activeUser, 524, 5
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	_initializeTranslationTable
	call	_landingPage
	call	_pressEnter
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_initializeTranslationTable;	.scl	2;	.type	32;	.endef
	.def	_landingPage;	.scl	2;	.type	32;	.endef
	.def	_pressEnter;	.scl	2;	.type	32;	.endef
