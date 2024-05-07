	.file	"translation_table.c"
	.text
	.comm	_hashTable, 400, 5
	.globl	_hash
	.def	_hash;	.scl	2;	.type	32;	.endef
_hash:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, -20(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%eax,%edx), %ecx
	movl	8(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	addl	%ecx, %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L2:
	movl	-16(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jb	L3
	movl	-12(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.globl	_insert
	.def	_insert;	.scl	2;	.type	32;	.endef
_insert:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_hash
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	_hashTable(,%eax,4), %eax
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	L9
	movl	$12, (%esp)
	call	_malloc
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, %edx
	movl	-20(%ebp), %eax
	movl	%edx, (%eax)
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcpy
	leal	12(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	$0, -12(%ebp)
	jmp	L7
L8:
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movl	%edx, -28(%ebp)
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, %ecx
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%ecx, 4(%eax,%edx,4)
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	4(%eax,%edx,4), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcpy
	addl	$1, -12(%ebp)
L7:
	cmpl	$1, -12(%ebp)
	jle	L8
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, _hashTable(,%eax,4)
L9:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.globl	_getTranslation
	.def	_getTranslation;	.scl	2;	.type	32;	.endef
_getTranslation:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_hash
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	_hashTable(,%eax,4), %eax
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L11
	movl	$0, %eax
	jmp	L12
L11:
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L13
	movl	-16(%ebp), %eax
	movl	12(%ebp), %edx
	movl	4(%eax,%edx,4), %eax
	jmp	L12
L13:
	movl	$0, %eax
L12:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
LC0:
	.ascii "Ime\0"
LC1:
	.ascii "First Name\0"
LC2:
	.ascii "name\0"
LC3:
	.ascii "Prezime\0"
LC4:
	.ascii "Last Name\0"
LC5:
	.ascii "lastname\0"
LC6:
	.ascii "Korisnicko Ime\0"
LC7:
	.ascii "Username\0"
LC8:
	.ascii "username\0"
LC9:
	.ascii "Nista nije pronadjeno :(\0"
LC10:
	.ascii "No Results Found\0"
LC11:
	.ascii "no_results\0"
	.text
	.globl	_initializeTranslationTable
	.def	_initializeTranslationTable;	.scl	2;	.type	32;	.endef
_initializeTranslationTable:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC0, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$LC2, (%esp)
	call	_insert
	movl	$LC3, 8(%esp)
	movl	$LC4, 4(%esp)
	movl	$LC5, (%esp)
	call	_insert
	movl	$LC6, 8(%esp)
	movl	$LC7, 4(%esp)
	movl	$LC8, (%esp)
	call	_insert
	movl	$LC9, 8(%esp)
	movl	$LC10, 4(%esp)
	movl	$LC11, (%esp)
	call	_insert
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
