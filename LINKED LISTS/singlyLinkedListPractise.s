	.file	"singlyLinkedListPractise.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.section	.text$_ZN4nodeC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4nodeC1Ei
	.def	__ZN4nodeC1Ei;	.scl	2;	.type	32;	.endef
__ZN4nodeC1Ei:
LFB1447:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1447:
	.text
	.globl	__Z12insertAtHeadRP4nodei
	.def	__Z12insertAtHeadRP4nodei;	.scl	2;	.type	32;	.endef
__Z12insertAtHeadRP4nodei:
LFB1448:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZN4nodeC1Ei
	subl	$4, %esp
	movl	%ebx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1448:
	.globl	__Z12insertAtTailRP4nodei
	.def	__Z12insertAtTailRP4nodei;	.scl	2;	.type	32;	.endef
__Z12insertAtTailRP4nodei:
LFB1449:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZN4nodeC1Ei
	subl	$4, %esp
	movl	%ebx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1449:
	.globl	__Z19insertAtAnyPositionRP4nodeS1_ii
	.def	__Z19insertAtAnyPositionRP4nodeS1_ii;	.scl	2;	.type	32;	.endef
__Z19insertAtAnyPositionRP4nodeS1_ii:
LFB1450:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	cmpl	$1, 16(%ebp)
	jne	L5
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	jmp	L4
L5:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
L8:
	movl	16(%ebp), %eax
	subl	$2, %eax
	cmpl	-16(%ebp), %eax
	jle	L7
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
	jmp	L8
L7:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L9
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtTailRP4nodei
	jmp	L4
L9:
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZN4nodeC1Ei
	subl	$4, %esp
	movl	%ebx, -20(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-20(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 4(%eax)
L4:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1450:
	.section .rdata,"dr"
LC0:
	.ascii "List is empty \0"
LC1:
	.ascii "-->\0"
	.text
	.globl	__Z5printRP4node
	.def	__Z5printRP4node;	.scl	2;	.type	32;	.endef
__Z5printRP4node:
LFB1451:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	L11
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	jmp	L10
L11:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
L13:
	cmpl	$0, -12(%ebp)
	je	L10
	movl	-12(%ebp), %eax
	movl	(%eax), %ebx
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	jmp	L13
L10:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1451:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1452:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$32, %esp
	call	___main
	movl	$8, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	$23, (%esp)
	movl	%ebx, %ecx
	call	__ZN4nodeC1Ei
	subl	$4, %esp
	movl	%ebx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$5, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$6, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$7, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$8, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$9, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$58, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtHeadRP4nodei
	movl	$7, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtTailRP4nodei
	movl	$22, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z12insertAtTailRP4nodei
	movl	$55, 12(%esp)
	movl	$3, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z19insertAtAnyPositionRP4nodeS1_ii
	movl	$45, 12(%esp)
	movl	$4, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z19insertAtAnyPositionRP4nodeS1_ii
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z5printRP4node
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1452:
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1885:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1885:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1884:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L19
	cmpl	$65535, 12(%ebp)
	jne	L19
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L19:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1884:
	.def	__GLOBAL__sub_I__Z12insertAtHeadRP4nodei;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z12insertAtHeadRP4nodei:
LFB1886:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1886:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z12insertAtHeadRP4nodei
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
