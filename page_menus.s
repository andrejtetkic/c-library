	.file	"page_menus.c"
	.text
	.comm	_activeUser, 524, 5
	.section .rdata,"dr"
LC0:
	.ascii "%lx\0"
	.text
	.globl	_hash_password
	.def	_hash_password;	.scl	2;	.type	32;	.endef
_hash_password:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$104, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-85(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$5381, -12(%ebp)
	leal	-85(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	sall	$5, %eax
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
L2:
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -16(%ebp)
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	L3
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.section .rdata,"dr"
LC1:
	.ascii "Log In\0"
LC2:
	.ascii "Sign Up\0"
	.text
	.globl	_landingPage
	.def	_landingPage;	.scl	2;	.type	32;	.endef
_landingPage:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	call	_clearScreen
	movl	$30, -12(%ebp)
	movl	$LC1, -24(%ebp)
	movl	$LC2, -20(%ebp)
	call	_windowHeight
	subl	$3, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %ebx
	call	_windowWidth
	movl	-12(%ebp), %edx
	addl	%edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	$_wrapperEmpty, 32(%esp)
	movl	$_wrapperEmpty, 28(%esp)
	movl	%ebx, 24(%esp)
	movl	$1, 20(%esp)
	movl	$3, 16(%esp)
	movl	%eax, 12(%esp)
	movl	$2, 8(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_inlineOneButtonSelect
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	je	L5
	cmpl	$1, -16(%ebp)
	je	L6
	jmp	L8
L5:
	call	_logIn
	jmp	L8
L6:
	call	_SignUp
	nop
L8:
	nop
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
LC3:
	.ascii "\11\11\11| \33[90mFirst name%s\33[0m|%s\0"
LC4:
	.ascii "\11\11\11| %s%s|\12\0"
LC5:
	.ascii "\11\11\11| \33[90mLast name%s\33[0m|%s\0"
LC6:
	.ascii "\11\11\11| \33[90mEmail%s\33[0m|%s\0"
LC7:
	.ascii "English\0"
LC8:
	.ascii "Srpski\0"
LC9:
	.ascii "\11\11\11| \33[90mUsername%s\33[0m|%s\0"
LC10:
	.ascii "\11\11\11| \33[90mPassword%s\33[0m|%s\0"
	.align 4
LC11:
	.ascii "\11\11\11| \33[90mPassword again%s\33[0m|%s\0"
LC12:
	.ascii "Username already taken\0"
	.text
	.globl	_SignUp
	.def	_SignUp;	.scl	2;	.type	32;	.endef
_SignUp:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	subl	$1840, %esp
	.cfi_offset 7, -12
	.cfi_offset 3, -16
	movl	$0, -52(%ebp)
	movl	$0, -252(%ebp)
	leal	-248(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -452(%ebp)
	leal	-448(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -652(%ebp)
	leal	-648(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -852(%ebp)
	leal	-848(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -1052(%ebp)
	leal	-1048(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -1252(%ebp)
	leal	-1248(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
L12:
	call	_clearScreen
	call	_SignUpArt
	movl	$34, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	subl	$11, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	call	_clearScreen
	call	_SignUpArt
	movl	$34, -16(%ebp)
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	subl	$10, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	call	_clearScreen
	call	_SignUpArt
	movl	$34, -20(%ebp)
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %ebx
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-20(%ebp), %eax
	subl	$7, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	leal	-1052(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	movl	$10, -24(%ebp)
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %ebx
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-20(%ebp), %ebx
	leal	-1052(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1052(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$LC7, -1784(%ebp)
	movl	$LC8, -1780(%ebp)
	call	_windowHeight
	subl	$3, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %ebx
	call	_windowWidth
	movl	-24(%ebp), %edx
	addl	%edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	$_wrapperEmpty, 32(%esp)
	movl	$_wrapperEmpty, 28(%esp)
	movl	%ebx, 24(%esp)
	movl	$1, 20(%esp)
	movl	$3, 16(%esp)
	movl	%eax, 12(%esp)
	movl	$2, 8(%esp)
	leal	-1784(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_inlineOneButtonSelect
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -32(%ebp)
	call	_clearScreen
	call	_SignUpArt
	movl	$34, -36(%ebp)
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %ebx
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-20(%ebp), %ebx
	leal	-1052(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1052(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-12(%ebp), %ebx
	movl	-32(%ebp), %eax
	movl	-1784(%ebp,%eax,4), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	-32(%ebp), %edx
	movl	-1784(%ebp,%edx,4), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-36(%ebp), %eax
	subl	$9, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	leal	-1252(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	call	_clearScreen
	call	_SignUpArt
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %ebx
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-20(%ebp), %ebx
	leal	-1052(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1052(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-12(%ebp), %ebx
	movl	-32(%ebp), %eax
	movl	-1784(%ebp,%eax,4), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	-32(%ebp), %edx
	movl	-1784(%ebp,%edx,4), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %ebx
	leal	-1252(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1252(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-36(%ebp), %eax
	subl	$9, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	leal	-252(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
L10:
	call	_clearScreen
	call	_SignUpArt
	movl	-12(%ebp), %ebx
	leal	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-16(%ebp), %ebx
	leal	-852(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-20(%ebp), %ebx
	leal	-1052(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1052(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-12(%ebp), %ebx
	movl	-32(%ebp), %eax
	movl	-1784(%ebp,%eax,4), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	-32(%ebp), %edx
	movl	-1784(%ebp,%edx,4), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %ebx
	leal	-1252(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-1252(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %ebx
	leal	-252(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-252(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-36(%ebp), %eax
	subl	$15, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
	leal	-452(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	leal	-452(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-252(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L10
	leal	-452(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	leal	-452(%ebp), %eax
	movl	%eax, (%esp)
	call	_memset
	leal	-252(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-252(%ebp), %eax
	movl	%eax, (%esp)
	call	_hash_password
	movl	$_compareByUsername, -1792(%ebp)
	leal	-1252(%ebp), %eax
	movl	%eax, -1788(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$8, 8(%esp)
	leal	-1792(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	_DB_select
	movl	%eax, -40(%ebp)
	cmpl	$0, -40(%ebp)
	je	L11
	movl	$LC12, (%esp)
	call	_puts
	movl	-40(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_free
	nop
L11:
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	jg	L12
	leal	-1052(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1776(%ebp), %eax
	addl	$216, %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-652(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1776(%ebp), %eax
	addl	$10, %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-852(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1776(%ebp), %eax
	addl	$110, %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-1252(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1776(%ebp), %eax
	addl	$316, %eax
	movl	%eax, (%esp)
	call	_strcpy
	leal	-252(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1776(%ebp), %eax
	addl	$416, %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	-32(%ebp), %eax
	movl	%eax, -1564(%ebp)
	movl	$0, -1260(%ebp)
	leal	-1776(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	_DB_insert
	nop
	addl	$1840, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.section .rdata,"dr"
LC13:
	.ascii "No matching records found.\0"
	.text
	.globl	_logIn
	.def	_logIn;	.scl	2;	.type	32;	.endef
_logIn:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$460, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	_clearScreen
	call	_logInArt
	movl	$34, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	subl	$9, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
	movl	$0, -236(%ebp)
	leal	-232(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	leal	-236(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	call	_clearScreen
	call	_logInArt
	movl	-28(%ebp), %ebx
	leal	-236(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	subl	%eax, %ebx
	movl	%ebx, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%eax, 8(%esp)
	leal	-236(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	_fillTimesN
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	subl	$9, %eax
	movl	%eax, 4(%esp)
	movl	$32, (%esp)
	call	_fillTimesN
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	$0, -436(%ebp)
	leal	-432(%ebp), %edx
	movl	$0, %eax
	movl	$49, %ecx
	movl	%edx, %edi
	rep stosl
	leal	-436(%ebp), %eax
	movl	%eax, (%esp)
	call	_fillInForm
	leal	-436(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-436(%ebp), %eax
	movl	%eax, (%esp)
	call	_hash_password
	movl	$_compareByUsername, -452(%ebp)
	leal	-236(%ebp), %eax
	movl	%eax, -448(%ebp)
	movl	$_compareByPassword, -444(%ebp)
	leal	-436(%ebp), %eax
	movl	%eax, -440(%ebp)
	leal	-456(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$16, 8(%esp)
	leal	-452(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	_DB_select
	movl	%eax, -32(%ebp)
	cmpl	$0, -32(%ebp)
	je	L14
	movl	-32(%ebp), %eax
	movl	$_activeUser, %edx
	movl	%eax, %ebx
	movl	$131, %eax
	movl	%edx, %edi
	movl	%ebx, %esi
	movl	%eax, %ecx
	rep movsl
	movl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_free
	jmp	L15
L14:
	movl	$LC13, (%esp)
	call	_puts
	call	_pressEnter
L15:
	call	_browse
	nop
	addl	$460, %esp
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
LFE30:
	.section .rdata,"dr"
LC14:
	.ascii "\0"
LC15:
	.ascii "no_results\0"
	.text
	.globl	_browse
	.def	_browse;	.scl	2;	.type	32;	.endef
_browse:
LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	$_compareSelectEverything, -24(%ebp)
	movl	$LC14, -20(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$8, 8(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	_DB_select
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L17
	movl	-28(%ebp), %eax
	movl	$_wrapperEmpty, 36(%esp)
	movl	$_wrapperEmpty, 32(%esp)
	movl	$7, 28(%esp)
	movl	$35, 24(%esp)
	movl	$_tempEnterFunc, 20(%esp)
	movl	%eax, 16(%esp)
	movl	$2432, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$_printBookItemSelected, 4(%esp)
	movl	$_printBookItem, (%esp)
	call	_browseInitiate
	jmp	L18
L17:
	movl	_activeUser+212, %eax
	movl	%eax, 4(%esp)
	movl	$LC15, (%esp)
	call	_getTranslation
	movl	%eax, (%esp)
	call	_puts
L18:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_free
	nop
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE31:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
	.def	_clearScreen;	.scl	2;	.type	32;	.endef
	.def	_windowHeight;	.scl	2;	.type	32;	.endef
	.def	_windowWidth;	.scl	2;	.type	32;	.endef
	.def	_wrapperEmpty;	.scl	2;	.type	32;	.endef
	.def	_inlineOneButtonSelect;	.scl	2;	.type	32;	.endef
	.def	_SignUpArt;	.scl	2;	.type	32;	.endef
	.def	_fillTimesN;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fillInForm;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	_compareByUsername;	.scl	2;	.type	32;	.endef
	.def	_DB_select;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	___mingw_free;	.scl	2;	.type	32;	.endef
	.def	_DB_insert;	.scl	2;	.type	32;	.endef
	.def	_logInArt;	.scl	2;	.type	32;	.endef
	.def	_compareByPassword;	.scl	2;	.type	32;	.endef
	.def	_pressEnter;	.scl	2;	.type	32;	.endef
	.def	_compareSelectEverything;	.scl	2;	.type	32;	.endef
	.def	_tempEnterFunc;	.scl	2;	.type	32;	.endef
	.def	_printBookItemSelected;	.scl	2;	.type	32;	.endef
	.def	_printBookItem;	.scl	2;	.type	32;	.endef
	.def	_browseInitiate;	.scl	2;	.type	32;	.endef
	.def	_getTranslation;	.scl	2;	.type	32;	.endef
