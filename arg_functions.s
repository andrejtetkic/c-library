	.file	"arg_functions.c"
	.text
	.comm	_activeUser, 524, 5
	.section .rdata,"dr"
LC0:
	.ascii "\33[100m %s%s\33[0m%s\0"
	.text
	.globl	_printBookItem
	.def	_printBookItem;	.scl	2;	.type	32;	.endef
_printBookItem:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$3, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	16(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_getBookInformation
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_getBookInformation
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	nop
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
LC1:
	.ascii "\33[41m %s%s\33[0m%s\0"
	.text
	.globl	_printBookItemSelected
	.def	_printBookItemSelected;	.scl	2;	.type	32;	.endef
_printBookItemSelected:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$3, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	16(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_getBookInformation
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_getBookInformation
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	nop
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
LC2:
	.ascii "selected item ISBN = %s\0"
	.text
	.globl	_tempEnterFunc
	.def	_tempEnterFunc;	.scl	2;	.type	32;	.endef
_tempEnterFunc:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	call	_pressEnter
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.globl	_wrapperEmpty
	.def	_wrapperEmpty;	.scl	2;	.type	32;	.endef
_wrapperEmpty:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_fillTimesN;	.scl	2;	.type	32;	.endef
	.def	_getBookInformation;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_pressEnter;	.scl	2;	.type	32;	.endef
