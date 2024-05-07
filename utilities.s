	.file	"utilities.c"
	.text
	.globl	_getKeyPressed
	.def	_getKeyPressed;	.scl	2;	.type	32;	.endef
_getKeyPressed:
LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	__getch
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L2
	cmpl	$224, -12(%ebp)
	jne	L3
L2:
	call	__getch
	movl	%eax, -12(%ebp)
L3:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE34:
	.section .rdata,"dr"
LC0:
	.ascii "cls\0"
	.text
	.globl	_clearScreen
	.def	_clearScreen;	.scl	2;	.type	32;	.endef
_clearScreen:
LFB35:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC0, (%esp)
	call	_system
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE35:
	.section .rdata,"dr"
LC1:
	.ascii "\12\12\12Press Enter to continue\0"
LC2:
	.ascii "%[^\12]\0"
	.text
	.globl	_pressEnter
	.def	_pressEnter;	.scl	2;	.type	32;	.endef
_pressEnter:
LFB36:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$136, %esp
	movl	$LC1, (%esp)
	call	_printf
	movl	__imp___iob, %eax
	movl	%eax, (%esp)
	call	_fflush
	leal	-108(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE36:
	.section .rdata,"dr"
LC3:
	.ascii "Memory allocation failed.\0"
	.text
	.globl	_fillTimesN
	.def	_fillTimesN;	.scl	2;	.type	32;	.endef
_fillTimesN:
LFB37:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movb	%al, -28(%ebp)
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L8
	movl	$LC3, (%esp)
	call	_puts
	movl	$1, (%esp)
	call	_exit
L8:
	movl	$0, -12(%ebp)
	jmp	L9
L10:
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movzbl	-28(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -12(%ebp)
L9:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L10
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE37:
	.globl	_windowHeight
	.def	_windowHeight;	.scl	2;	.type	32;	.endef
_windowHeight:
LFB38:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$-11, (%esp)
	call	_GetStdHandle@4
	subl	$4, %esp
	leal	-34(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_GetConsoleScreenBufferInfo@8
	subl	$8, %esp
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L13
	movl	$0, %eax
	jmp	L15
L13:
	movzwl	-32(%ebp), %eax
	cwtl
L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE38:
	.globl	_windowWidth
	.def	_windowWidth;	.scl	2;	.type	32;	.endef
_windowWidth:
LFB39:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$-11, (%esp)
	call	_GetStdHandle@4
	subl	$4, %esp
	leal	-34(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_GetConsoleScreenBufferInfo@8
	subl	$8, %esp
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L17
	movl	$0, %eax
	jmp	L19
L17:
	movzwl	-34(%ebp), %eax
	cwtl
L19:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE39:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	__getch;	.scl	2;	.type	32;	.endef
	.def	_system;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fflush;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_GetStdHandle@4;	.scl	2;	.type	32;	.endef
	.def	_GetConsoleScreenBufferInfo@8;	.scl	2;	.type	32;	.endef
