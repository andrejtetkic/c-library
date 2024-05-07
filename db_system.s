	.file	"db_system.c"
	.text
	.comm	_activeUser, 524, 5
	.section .rdata,"dr"
LC0:
	.ascii "Invalid table type\0"
LC1:
	.ascii "Error opening file!\0"
	.text
	.globl	_Open_File
	.def	_Open_File;	.scl	2;	.type	32;	.endef
_Open_File:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	cmpl	$4, 8(%ebp)
	ja	L2
	movl	8(%ebp), %eax
	sall	$2, %eax
	addl	$L4, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L4:
	.long	L8
	.long	L7
	.long	L6
	.long	L5
	.long	L3
	.text
L8:
	leal	-42(%ebp), %eax
	movl	$1635017060, (%eax)
	movl	$1702060386, 4(%eax)
	movl	$1869570607, 8(%eax)
	movl	$1651781227, 12(%eax)
	movb	$0, 16(%eax)
	jmp	L9
L7:
	leal	-42(%ebp), %eax
	movl	$1635017060, (%eax)
	movl	$1702060386, 4(%eax)
	movl	$1869570607, 8(%eax)
	movl	$1936875371, 12(%eax)
	movl	$6452270, 16(%eax)
	jmp	L9
L6:
	leal	-42(%ebp), %eax
	movl	$1635017060, (%eax)
	movl	$1702060386, 4(%eax)
	movl	$1986359855, 8(%eax)
	movl	$779576681, 12(%eax)
	movw	$25204, 16(%eax)
	movb	$0, 18(%eax)
	jmp	L9
L5:
	leal	-42(%ebp), %eax
	movl	$1635017060, (%eax)
	movl	$1702060386, 4(%eax)
	movl	$1852142127, 8(%eax)
	movl	$778854772, 12(%eax)
	movw	$25204, 16(%eax)
	movb	$0, 18(%eax)
	jmp	L9
L3:
	leal	-42(%ebp), %eax
	movl	$1635017060, (%eax)
	movl	$1702060386, 4(%eax)
	movl	$1702065455, 8(%eax)
	movl	$1651781234, 12(%eax)
	movb	$0, 16(%eax)
	jmp	L9
L2:
	movl	$LC0, (%esp)
	call	_puts
	movl	$0, %eax
	jmp	L12
L9:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-42(%ebp), %eax
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L11
	movl	$LC1, (%esp)
	call	_puts
	movl	$0, %eax
	jmp	L12
L11:
	movl	-12(%ebp), %eax
L12:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.section .rdata,"dr"
LC2:
	.ascii "rb\0"
LC3:
	.ascii "Failed to allocate memory\0"
	.text
	.globl	_DB_select
	.def	_DB_select;	.scl	2;	.type	32;	.endef
_DB_select:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$2540, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$LC2, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Open_File
	movl	%eax, -56(%ebp)
	movl	16(%ebp), %eax
	shrl	$3, %eax
	movl	%eax, -60(%ebp)
	movl	$0, -28(%ebp)
	movl	$0, -32(%ebp)
	cmpl	$4, 8(%ebp)
	ja	L14
	movl	8(%ebp), %eax
	sall	$2, %eax
	addl	$L16, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L16:
	.long	L21
	.long	L30
	.long	L37
	.long	L44
	.long	L51
	.text
L28:
	movl	$0, -36(%ebp)
	jmp	L22
L27:
	movl	-36(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-36(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%esp)
	leal	-2532(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	testl	%eax, %eax
	jne	L23
	movl	-212(%ebp), %eax
	cmpl	$1, %eax
	je	L23
	movl	-32(%ebp), %eax
	addl	$1, %eax
	imull	$2432, %eax, %eax
	movl	-28(%ebp), %edx
	movl	%edx, -64(%ebp)
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_realloc
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	jne	L25
	movl	$LC3, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L26
L25:
	movl	-32(%ebp), %eax
	imull	$2432, %eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leal	-2532(%ebp), %eax
	movl	$2432, %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	-4(%eax,%ecx), %ebx
	movl	%ebx, -4(%edx,%ecx)
	leal	4(%edx), %ebx
	andl	$-4, %ebx
	subl	%ebx, %edx
	subl	%edx, %eax
	addl	%edx, %ecx
	andl	$-4, %ecx
	shrl	$2, %ecx
	movl	%ecx, %edx
	movl	%ebx, %edi
	movl	%eax, %esi
	movl	%edx, %ecx
	rep movsl
	addl	$1, -32(%ebp)
L23:
	addl	$1, -36(%ebp)
L22:
	movl	-36(%ebp), %eax
	cmpl	-60(%ebp), %eax
	jl	L27
L21:
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2432, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L28
	jmp	L29
L36:
	movl	$0, -40(%ebp)
	jmp	L31
L35:
	movl	-40(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-40(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%esp)
	leal	-2532(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	testl	%eax, %eax
	jne	L32
	movl	-2420(%ebp), %eax
	cmpl	$1, %eax
	je	L32
	movl	-32(%ebp), %eax
	addl	$1, %eax
	imull	$116, %eax, %eax
	movl	-28(%ebp), %edx
	movl	%edx, -72(%ebp)
	movl	%eax, -76(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_realloc
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	jne	L34
	movl	$LC3, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L26
L34:
	movl	-32(%ebp), %eax
	imull	$116, %eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leal	-2532(%ebp), %eax
	movl	$116, %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	-4(%eax,%ecx), %ebx
	movl	%ebx, -4(%edx,%ecx)
	leal	4(%edx), %ebx
	andl	$-4, %ebx
	subl	%ebx, %edx
	subl	%edx, %eax
	addl	%edx, %ecx
	andl	$-4, %ecx
	shrl	$2, %ecx
	movl	%ecx, %edx
	movl	%ebx, %edi
	movl	%eax, %esi
	movl	%edx, %ecx
	rep movsl
	addl	$1, -32(%ebp)
L32:
	addl	$1, -40(%ebp)
L31:
	movl	-40(%ebp), %eax
	cmpl	-60(%ebp), %eax
	jl	L35
L30:
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$116, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L36
	jmp	L29
L43:
	movl	$0, -44(%ebp)
	jmp	L38
L42:
	movl	-44(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-44(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%esp)
	leal	-2532(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	testl	%eax, %eax
	jne	L39
	movl	-1996(%ebp), %eax
	cmpl	$1, %eax
	je	L39
	movl	-32(%ebp), %eax
	addl	$1, %eax
	imull	$540, %eax, %eax
	movl	-28(%ebp), %edx
	movl	%edx, -80(%ebp)
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_realloc
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	jne	L41
	movl	$LC3, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L26
L41:
	movl	-32(%ebp), %eax
	imull	$540, %eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leal	-2532(%ebp), %eax
	movl	$540, %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	-4(%eax,%ecx), %ebx
	movl	%ebx, -4(%edx,%ecx)
	leal	4(%edx), %ebx
	andl	$-4, %ebx
	subl	%ebx, %edx
	subl	%edx, %eax
	addl	%edx, %ecx
	andl	$-4, %ecx
	shrl	$2, %ecx
	movl	%ecx, %edx
	movl	%ebx, %edi
	movl	%eax, %esi
	movl	%edx, %ecx
	rep movsl
	addl	$1, -32(%ebp)
L39:
	addl	$1, -44(%ebp)
L38:
	movl	-44(%ebp), %eax
	cmpl	-60(%ebp), %eax
	jl	L42
L37:
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$540, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L43
	jmp	L29
L50:
	movl	$0, -48(%ebp)
	jmp	L45
L49:
	movl	-48(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-48(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%esp)
	leal	-2532(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	testl	%eax, %eax
	jne	L46
	movl	-2476(%ebp), %eax
	cmpl	$1, %eax
	je	L46
	movl	-32(%ebp), %eax
	addl	$1, %eax
	imull	$60, %eax, %eax
	movl	-28(%ebp), %edx
	movl	%edx, -88(%ebp)
	movl	%eax, -92(%ebp)
	movl	-92(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_realloc
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	jne	L48
	movl	$LC3, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L26
L48:
	movl	-32(%ebp), %eax
	imull	$60, %eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	-2532(%ebp), %edx
	movl	%edx, (%eax)
	movl	-2528(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-2524(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	-2520(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-2516(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	-2512(%ebp), %edx
	movl	%edx, 20(%eax)
	movl	-2508(%ebp), %edx
	movl	%edx, 24(%eax)
	movl	-2504(%ebp), %edx
	movl	%edx, 28(%eax)
	movl	-2500(%ebp), %edx
	movl	%edx, 32(%eax)
	movl	-2496(%ebp), %edx
	movl	%edx, 36(%eax)
	movl	-2492(%ebp), %edx
	movl	%edx, 40(%eax)
	movl	-2488(%ebp), %edx
	movl	%edx, 44(%eax)
	movl	-2484(%ebp), %edx
	movl	%edx, 48(%eax)
	movl	-2480(%ebp), %edx
	movl	%edx, 52(%eax)
	movl	-2476(%ebp), %edx
	movl	%edx, 56(%eax)
	addl	$1, -32(%ebp)
L46:
	addl	$1, -48(%ebp)
L45:
	movl	-48(%ebp), %eax
	cmpl	-60(%ebp), %eax
	jl	L49
L44:
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$60, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L50
	jmp	L29
L57:
	movl	$0, -52(%ebp)
	jmp	L52
L56:
	movl	-52(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	-52(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	12(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%edx), %edx
	movl	%edx, 4(%esp)
	leal	-2532(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	testl	%eax, %eax
	jne	L53
	movl	-2012(%ebp), %eax
	cmpl	$1, %eax
	je	L53
	movl	-32(%ebp), %eax
	addl	$1, %eax
	imull	$524, %eax, %eax
	movl	-28(%ebp), %edx
	movl	%edx, -96(%ebp)
	movl	%eax, -100(%ebp)
	movl	-100(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_realloc
	movl	%eax, -28(%ebp)
	cmpl	$0, -28(%ebp)
	jne	L55
	movl	$LC3, (%esp)
	call	_printf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L26
L55:
	movl	-32(%ebp), %eax
	imull	$524, %eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leal	-2532(%ebp), %eax
	movl	$524, %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	-4(%eax,%ecx), %ebx
	movl	%ebx, -4(%edx,%ecx)
	leal	4(%edx), %ebx
	andl	$-4, %ebx
	subl	%ebx, %edx
	subl	%edx, %eax
	addl	%edx, %ecx
	andl	$-4, %ecx
	shrl	$2, %ecx
	movl	%ecx, %edx
	movl	%ebx, %edi
	movl	%eax, %esi
	movl	%edx, %ecx
	rep movsl
	addl	$1, -32(%ebp)
L53:
	addl	$1, -52(%ebp)
L52:
	movl	-52(%ebp), %eax
	cmpl	-60(%ebp), %eax
	jl	L56
L51:
	movl	-56(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$524, 4(%esp)
	leal	-2532(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L57
	jmp	L29
L14:
	movl	$LC0, (%esp)
	call	_puts
	nop
L29:
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	20(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-28(%ebp), %eax
L26:
	addl	$2540, %esp
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
LFE27:
	.section .rdata,"dr"
LC4:
	.ascii "ab\0"
	.text
	.globl	_DB_insert
	.def	_DB_insert;	.scl	2;	.type	32;	.endef
_DB_insert:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$LC4, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Open_File
	movl	%eax, -12(%ebp)
	cmpl	$4, 8(%ebp)
	ja	L59
	movl	8(%ebp), %eax
	sall	$2, %eax
	addl	$L61, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L61:
	.long	L65
	.long	L64
	.long	L63
	.long	L62
	.long	L60
	.text
L65:
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2432, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L66
L64:
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$116, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L66
L63:
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$540, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L66
L62:
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$60, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L66
L60:
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$524, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L66
L59:
	movl	$LC0, (%esp)
	call	_puts
	jmp	L58
L66:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L58:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.section .rdata,"dr"
LC5:
	.ascii "rb+\0"
LC6:
	.ascii "Keys don't match!\0"
	.text
	.globl	_DB_update
	.def	_DB_update;	.scl	2;	.type	32;	.endef
_DB_update:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$2472, %esp
	movl	$LC5, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_Open_File
	movl	%eax, -12(%ebp)
	cmpl	$4, 12(%ebp)
	ja	L69
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	$L71, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L71:
	.long	L75
	.long	L74
	.long	L73
	.long	L72
	.long	L70
	.text
L75:
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L78
	movl	$LC6, (%esp)
	call	_puts
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L68
L80:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L78
	movl	$1, 8(%esp)
	movl	$-2432, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2432, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	nop
	jmp	L81
L78:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$2432, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	testl	%eax, %eax
	jne	L80
	jmp	L81
L74:
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L83
	movl	$LC6, (%esp)
	call	_puts
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L68
L85:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L83
	movl	$1, 8(%esp)
	movl	$-116, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$116, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	nop
	jmp	L81
L83:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$116, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	testl	%eax, %eax
	jne	L85
	jmp	L81
L73:
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L87
	movl	$LC6, (%esp)
	call	_puts
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L68
L89:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L87
	movl	$1, 8(%esp)
	movl	$-540, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$540, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	nop
	jmp	L81
L87:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$540, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	testl	%eax, %eax
	jne	L89
	jmp	L81
L72:
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L91
	movl	$LC6, (%esp)
	call	_puts
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L68
L93:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L91
	movl	$1, 8(%esp)
	movl	$-60, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$60, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	nop
	jmp	L81
L91:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$60, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	testl	%eax, %eax
	jne	L93
	jmp	L81
L70:
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L95
	movl	$LC6, (%esp)
	call	_puts
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L68
L97:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L95
	movl	$1, 8(%esp)
	movl	$-524, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$524, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	nop
	jmp	L81
L95:
	movl	-12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$524, 4(%esp)
	leal	-2448(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	testl	%eax, %eax
	jne	L97
	jmp	L81
L69:
	movl	$LC0, (%esp)
	call	_puts
	jmp	L68
L81:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L68:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.globl	_DB_delete
	.def	_DB_delete;	.scl	2;	.type	32;	.endef
_DB_delete:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$3704, %esp
	movl	$LC5, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_Open_File
	movl	%eax, -12(%ebp)
	cmpl	$4, 12(%ebp)
	ja	L100
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	$L102, %eax
	movl	(%eax), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L102:
	.long	L106
	.long	L105
	.long	L104
	.long	L103
	.long	L101
	.text
L106:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2444(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$1, -124(%ebp)
	leal	-2444(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_DB_update
	jmp	L99
L105:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-2560(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$1, -2448(%ebp)
	leal	-2560(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_DB_update
	jmp	L99
L104:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-3100(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$1, -2564(%ebp)
	leal	-3100(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_DB_update
	jmp	L99
L103:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-3160(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$1, -3104(%ebp)
	leal	-3160(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_DB_update
	jmp	L99
L101:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-3684(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	$1, -3164(%ebp)
	leal	-3684(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_DB_update
	jmp	L99
L100:
	movl	$LC0, (%esp)
	call	_puts
L99:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE30:
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	___mingw_realloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_strcmp;	.scl	2;	.type	32;	.endef
	.def	_fseek;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
