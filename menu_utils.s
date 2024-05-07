	.file	"menu_utils.c"
	.text
	.comm	_activeUser, 524, 5
	.globl	_contorlSelectedIndex
	.def	_contorlSelectedIndex;	.scl	2;	.type	32;	.endef
_contorlSelectedIndex:
LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$80, 8(%ebp)
	je	L2
	cmpl	$80, 8(%ebp)
	jg	L8
	cmpl	$77, 8(%ebp)
	je	L4
	cmpl	$77, 8(%ebp)
	jg	L8
	cmpl	$75, 8(%ebp)
	je	L5
	cmpl	$75, 8(%ebp)
	jg	L8
	cmpl	$9, 8(%ebp)
	je	L6
	cmpl	$72, 8(%ebp)
	jne	L8
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	subl	16(%ebp), %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L7
L2:
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L7
L5:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L7
L4:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L7
L6:
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L7
L8:
	nop
L7:
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE34:
	.section .rdata,"dr"
LC0:
	.ascii "%s\0"
LC1:
	.ascii "%s\33[42m%s\33[0m%s\0"
LC2:
	.ascii "%s\33[100m%s\33[0m%s\0"
LC3:
	.ascii "%s\33[42m%s%s%s\33[0m%s\0"
LC4:
	.ascii "%s\33[100m%s%s%s\33[0m%s\0"
	.text
	.globl	_inlineOneButtonSelect
	.def	_inlineOneButtonSelect;	.scl	2;	.type	32;	.endef
_inlineOneButtonSelect:
LFB35:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$0, -28(%ebp)
	movl	$0, -56(%ebp)
	jmp	L10
L25:
	movl	32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	_fillTimesN
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	36(%ebp), %eax
	call	*%eax
	movl	$10, (%esp)
	call	_putchar
	cmpl	$1, 28(%ebp)
	jne	L11
	movl	$0, -32(%ebp)
	jmp	L12
L15:
	cmpl	$0, -32(%ebp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -44(%ebp)
	movl	-56(%ebp), %eax
	cmpl	%eax, -32(%ebp)
	jne	L13
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	jmp	L14
L13:
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
L14:
	addl	$1, -32(%ebp)
L12:
	movl	-32(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	L15
	movl	$10, (%esp)
	call	_putchar
L11:
	movl	$0, -36(%ebp)
	jmp	L16
L19:
	cmpl	$0, -36(%ebp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -52(%ebp)
	movl	-56(%ebp), %eax
	cmpl	%eax, -36(%ebp)
	jne	L17
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %edi
	movl	8(%ebp), %ebx
	movl	8(%ebp), %esi
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %esi
	movl	%esi, %eax
	shrl	%eax
	subl	%eax, %ebx
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -64(%ebp)
	movl	8(%ebp), %ebx
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	shrl	%eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	-64(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	jmp	L18
L17:
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %edi
	movl	8(%ebp), %ebx
	movl	8(%ebp), %esi
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %esi
	movl	%esi, %eax
	shrl	%eax
	subl	%eax, %ebx
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -64(%ebp)
	movl	8(%ebp), %ebx
	movl	-36(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	shrl	%eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	-64(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
L18:
	addl	$1, -36(%ebp)
L16:
	movl	-36(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	L19
	cmpl	$1, 28(%ebp)
	jne	L20
	movl	$10, (%esp)
	call	_putchar
	movl	$0, -40(%ebp)
	jmp	L21
L24:
	cmpl	$0, -40(%ebp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -48(%ebp)
	movl	-56(%ebp), %eax
	cmpl	%eax, -40(%ebp)
	jne	L22
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	jmp	L23
L22:
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	imull	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
L23:
	addl	$1, -40(%ebp)
L21:
	movl	-40(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	L24
L20:
	movl	$10, (%esp)
	call	_putchar
	movl	40(%ebp), %eax
	call	*%eax
	call	_getKeyPressed
	movl	%eax, -28(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_contorlSelectedIndex
	movl	16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -64(%ebp)
	fildl	-64(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, -64(%ebp)
	fildl	-64(%ebp)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_fmin
	fnstcw	-58(%ebp)
	movzwl	-58(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -60(%ebp)
	fldcw	-60(%ebp)
	fistpl	-64(%ebp)
	fldcw	-58(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, -64(%ebp)
	fildl	-64(%ebp)
	fstpl	8(%esp)
	fldz
	fstpl	(%esp)
	call	_fmax
	fnstcw	-58(%ebp)
	movzwl	-58(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -60(%ebp)
	fldcw	-60(%ebp)
	fistpl	-64(%ebp)
	fldcw	-58(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -56(%ebp)
	call	_clearScreen
L10:
	cmpl	$13, -28(%ebp)
	jne	L25
	movl	-56(%ebp), %eax
	addl	$92, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE35:
	.section .rdata,"dr"
	.align 4
LC7:
	.ascii "\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\10\0"
LC8:
	.ascii "                            \0"
	.text
	.globl	_clearline
	.def	_clearline;	.scl	2;	.type	32;	.endef
_clearline:
LFB36:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC7, (%esp)
	call	_printf
	movl	$LC8, (%esp)
	call	_printf
	movl	$LC7, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE36:
	.globl	_fillInForm
	.def	_fillInForm;	.scl	2;	.type	32;	.endef
_fillInForm:
LFB37:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L29
L32:
	cmpl	$8, -16(%ebp)
	jne	L30
	cmpl	$0, -12(%ebp)
	je	L30
	subl	$1, -12(%ebp)
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
L30:
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-16(%ebp), %edx
	movb	%dl, (%eax)
	call	_clearline
	movl	__imp___iob, %eax
	addl	$32, %eax
	movl	%eax, (%esp)
	call	_fflush
L29:
	call	_getchar
	movl	%eax, -16(%ebp)
	cmpl	$-1, -16(%ebp)
	je	L33
	cmpl	$10, -16(%ebp)
	jne	L32
L33:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE37:
	.section .rdata,"dr"
LC9:
	.ascii "\12\12\0"
	.align 4
LC10:
	.ascii "\11\11\11\33[94m  ___ ___ ___ _  _   _   _ ___ \0"
	.align 4
LC11:
	.ascii "\11\11\11 / __|_ _/ __| \\| | | | | | _ \\\0"
	.align 4
LC12:
	.ascii "\11\11\11 \\__ \\| | (_ | .` | | |_| |  _/\0"
	.align 4
LC13:
	.ascii "\11\11\11 |___/___\\___|_|\\_|  \\___/|_|  \12\12\33[0m\0"
	.text
	.globl	_SignUpArt
	.def	_SignUpArt;	.scl	2;	.type	32;	.endef
_SignUpArt:
LFB38:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	movl	$LC12, (%esp)
	call	_puts
	movl	$LC13, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE38:
	.section .rdata,"dr"
	.align 4
LC14:
	.ascii "\11\11\11\33[94m _      ___    ___        ___  _  _ \0"
	.align 4
LC15:
	.ascii "\11\11\11| |    / _ \\  / __|      |_ _|| \\| |\0"
	.align 4
LC16:
	.ascii "\11\11\11| |__ | (_) || (_ |       | | | .  |\0"
	.align 4
LC17:
	.ascii "\11\11\11|____| \\___/  \\___|      |___||_|\\_|\12\12\33[0m\0"
	.text
	.globl	_logInArt
	.def	_logInArt;	.scl	2;	.type	32;	.endef
_logInArt:
LFB39:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC14, (%esp)
	call	_puts
	movl	$LC15, (%esp)
	call	_puts
	movl	$LC16, (%esp)
	call	_puts
	movl	$LC17, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE39:
	.section .rdata,"dr"
LC18:
	.ascii "Naziv Knjige i biblioteka\0"
LC19:
	.ascii "R. R. Martin\0"
LC20:
	.ascii "Na Stanju\0"
LC21:
	.ascii "\0"
LC22:
	.ascii "4.32* (7)\0"
	.text
	.globl	_getBookInformation
	.def	_getBookInformation;	.scl	2;	.type	32;	.endef
_getBookInformation:
LFB40:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$432, %esp
	movl	$LC18, -140(%ebp)
	movl	$LC19, -280(%ebp)
	movl	$LC20, -420(%ebp)
	cmpl	$4, 12(%ebp)
	ja	L37
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	$L39, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L39:
	.long	L43
	.long	L42
	.long	L41
	.long	L40
	.long	L38
	.text
L43:
	movl	8(%ebp), %eax
	jmp	L36
L42:
	movl	$LC21, %eax
	jmp	L36
L41:
	movl	-280(%ebp), %eax
	jmp	L36
L40:
	movl	$LC22, %eax
	jmp	L36
L38:
	movl	-420(%ebp), %eax
	jmp	L36
L37:
L36:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE40:
	.section .rdata,"dr"
LC23:
	.ascii "\12\0"
	.text
	.globl	_BrowseDisplay
	.def	_BrowseDisplay;	.scl	2;	.type	32;	.endef
_BrowseDisplay:
LFB41:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$200, %esp
	call	_windowWidth
	movl	32(%ebp), %edx
	leal	4(%edx), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -28(%ebp)
	call	_windowHeight
	subl	40(%ebp), %eax
	cltd
	idivl	36(%ebp)
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	imull	%edx, %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	cltd
	idivl	-28(%ebp)
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	cltd
	idivl	-32(%ebp)
	imull	%ecx, %eax
	movl	%eax, -36(%ebp)
	movl	$-1, -12(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L47
L58:
	movl	$0, -20(%ebp)
	jmp	L48
L54:
	movl	$0, -24(%ebp)
	jmp	L49
L53:
	movl	-28(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	cmpl	%eax, 28(%ebp)
	jne	L50
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
L50:
	movl	-24(%ebp), %eax
	cmpl	-12(%ebp), %eax
	je	L51
	movl	-28(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	cmpl	%eax, 8(%ebp)
	jne	L52
	movl	-28(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	imull	24(%ebp), %eax
	movl	%eax, %edx
	movl	20(%ebp), %eax
	addl	%eax, %edx
	movl	32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	16(%ebp), %eax
	call	*%eax
	jmp	L51
L52:
	movl	-28(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	cmpl	%eax, 28(%ebp)
	jl	L51
	movl	-28(%ebp), %eax
	imull	-16(%ebp), %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	imull	24(%ebp), %eax
	movl	%eax, %edx
	movl	20(%ebp), %eax
	addl	%eax, %edx
	movl	32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %eax
	call	*%eax
L51:
	addl	$1, -24(%ebp)
L49:
	movl	-24(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jl	L53
	movl	$10, (%esp)
	call	_putchar
	addl	$1, -20(%ebp)
L48:
	cmpl	$4, -20(%ebp)
	jle	L54
	cmpl	$0, -12(%ebp)
	jns	L59
	movl	-32(%ebp), %eax
	cltd
	idivl	-28(%ebp)
	movl	%eax, %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	cmpl	%eax, -16(%ebp)
	je	L59
	movl	$LC23, (%esp)
	call	_puts
	addl	$1, -16(%ebp)
L47:
	movl	-32(%ebp), %eax
	cltd
	idivl	-28(%ebp)
	movl	%eax, %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	cmpl	%eax, -16(%ebp)
	jl	L58
	jmp	L46
L59:
	nop
L46:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE41:
	.globl	_browseInitiate
	.def	_browseInitiate;	.scl	2;	.type	32;	.endef
_browseInitiate:
LFB42:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	$0, -24(%ebp)
	movl	44(%ebp), %eax
	call	*%eax
	movl	%eax, %ebx
	movl	40(%ebp), %eax
	call	*%eax
	addl	%ebx, %eax
	movl	%eax, -16(%ebp)
	jmp	L61
L63:
	call	_clearScreen
	call	_windowWidth
	movl	32(%ebp), %edx
	leal	4(%edx), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -20(%ebp)
	movl	40(%ebp), %eax
	call	*%eax
	movl	$10, (%esp)
	call	_putchar
	movl	-24(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_BrowseDisplay
	movl	44(%ebp), %eax
	call	*%eax
	call	_getKeyPressed
	movb	%al, -9(%ebp)
	movsbl	-9(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_contorlSelectedIndex
	movl	24(%ebp), %eax
	subl	$1, %eax
	movl	-24(%ebp), %edx
	cmpl	%edx, %eax
	jle	L62
	movl	%edx, %eax
L62:
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	notl	%eax
	andl	%edx, %eax
	movl	%eax, -24(%ebp)
	cmpb	$13, -9(%ebp)
	jne	L61
	movl	-24(%ebp), %eax
	imull	20(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	movl	28(%ebp), %eax
	call	*%eax
L61:
	cmpb	$27, -9(%ebp)
	jne	L63
	nop
	nop
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE42:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_fillTimesN;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_getKeyPressed;	.scl	2;	.type	32;	.endef
	.def	_fmin;	.scl	2;	.type	32;	.endef
	.def	_fmax;	.scl	2;	.type	32;	.endef
	.def	_clearScreen;	.scl	2;	.type	32;	.endef
	.def	_fflush;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_windowWidth;	.scl	2;	.type	32;	.endef
	.def	_windowHeight;	.scl	2;	.type	32;	.endef
