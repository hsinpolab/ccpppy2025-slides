	.build_version macos,  13, 0
	.text
	.zerofill __DATA,__bss,__ZStL8__ioinit,1,0
	.text
	.globl _main
_main:
LFB4114:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$16, %rsp
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	sall	-4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	sall	-4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	sall	-4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	sall	-4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	sall	-4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
	leave
LCFI2:
	ret
LFE4114:
	.section	__TEXT,__StaticInit,regular,pure_instructions
__Z41__static_initialization_and_destruction_0v:
LFB5259:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	leaq	__ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSt8ios_base4InitC1Ev
	leaq	___dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	__ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	__ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	___cxa_atexit
	nop
	popq	%rbp
LCFI5:
	ret
LFE5259:
	.const
__ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
__ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
__ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
__ZSt39__is_implicitly_default_constructible_vItE:
	.byte	1
__ZSt39__is_implicitly_default_constructible_vIPKcE:
	.byte	1
__ZNSt8__detail14__destructibleIN9__gnu_cxx17__normal_iteratorIPcSt4spanIcLm18446744073709551615EEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implIN9__gnu_cxx17__normal_iteratorIPcSt4spanIcLm18446744073709551615EEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleISt16reverse_iteratorIN9__gnu_cxx17__normal_iteratorIPcSt4spanIcLm18446744073709551615EEEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implISt16reverse_iteratorIN9__gnu_cxx17__normal_iteratorIPcSt4spanIcLm18446744073709551615EEEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt8__format10_Sink_iterIcEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt8__format10_Sink_iterIcEEEE:
	.byte	1
__ZNSt8__detail14__destructibleIN9__gnu_cxx17__normal_iteratorIPwSt4spanIwLm18446744073709551615EEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implIN9__gnu_cxx17__normal_iteratorIPwSt4spanIwLm18446744073709551615EEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleISt16reverse_iteratorIN9__gnu_cxx17__normal_iteratorIPwSt4spanIwLm18446744073709551615EEEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implISt16reverse_iteratorIN9__gnu_cxx17__normal_iteratorIPwSt4spanIwLm18446744073709551615EEEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt8__format10_Sink_iterIwEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt8__format10_Sink_iterIwEEEE:
	.byte	1
__ZNSt8__detail14__destructibleIPcEE:
	.byte	1
__ZNSt8__detail19__destructible_implIPcEE:
	.byte	1
__ZNSt8__detail14__destructibleIPwEE:
	.byte	1
__ZNSt8__detail19__destructible_implIPwEE:
	.byte	1
__ZNSt8__detail14__destructibleIN9__gnu_cxx17__normal_iteratorIPcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implIN9__gnu_cxx17__normal_iteratorIPcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEEEE:
	.byte	1
__ZSt22__is_specialization_ofINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES1_E:
	.byte	1
__ZSt22__is_specialization_ofINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEES1_E:
	.byte	1
__ZNSt8__detail14__destructibleIPKwEE:
	.byte	1
__ZNSt8__detail19__destructible_implIPKwEE:
	.byte	1
__ZNSt8__detail14__destructibleImEE:
	.byte	1
__ZNSt8__detail19__destructible_implImEE:
	.byte	1
__ZSt39__is_implicitly_default_constructible_vIPKwE:
	.byte	1
__ZNSt8__detail14__destructibleIPKcEE:
	.byte	1
__ZNSt8__detail19__destructible_implIPKcEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIbEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIiEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIjEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIxEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIyEE:
	.byte	1
__ZNSt8__format24__is_formattable_integerIfEE:
	.space 1
__ZNSt8__format24__is_formattable_integerIdEE:
	.space 1
__ZNSt8__format24__is_formattable_integerIeEE:
	.space 1
__ZNSt8__format24__is_formattable_integerIPKwEE:
	.space 1
__ZNSt8__format24__is_formattable_integerISt17basic_string_viewIwSt11char_traitsIwEEEE:
	.space 1
__ZNSt8__format24__is_formattable_integerIPKvEE:
	.space 1
__ZNSt8__format24__is_formattable_integerIPKcEE:
	.space 1
__ZNSt8__format24__is_formattable_integerISt17basic_string_viewIcSt11char_traitsIcEEEE:
	.space 1
__ZSt22__is_specialization_ofINSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEESt6vectorE:
	.space 1
__ZNSt8__detail14__destructibleIN9__gnu_cxx17__normal_iteratorIPwNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implIN9__gnu_cxx17__normal_iteratorIPwNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEEEEEE:
	.byte	1
__ZSt22__is_specialization_ofINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESt6vectorE:
	.space 1
__ZNSt8__detail14__destructibleIiEE:
	.byte	1
__ZNSt8__detail19__destructible_implIiEE:
	.byte	1
__ZNSt8__detail14__destructibleIjEE:
	.byte	1
__ZNSt8__detail19__destructible_implIjEE:
	.byte	1
__ZNSt8__detail14__destructibleIlEE:
	.byte	1
__ZNSt8__detail19__destructible_implIlEE:
	.byte	1
__ZNSt8__detail14__destructibleIPKDiEE:
	.byte	1
__ZNSt8__detail19__destructible_implIPKDiEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt9__unicode13_Utf_iteratorIDiwPKDiS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt9__unicode13_Utf_iteratorIDiwPKDiS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt9__unicode13_Utf_iteratorIDicPKDiS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt9__unicode13_Utf_iteratorIDicPKDiS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleISt17basic_string_viewIwSt11char_traitsIwEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implISt17basic_string_viewIwSt11char_traitsIwEEEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt9__unicode13_Utf_iteratorIwDiPKwS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt9__unicode13_Utf_iteratorIwDiPKwS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail14__destructibleISt17basic_string_viewIcSt11char_traitsIcEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implISt17basic_string_viewIcSt11char_traitsIcEEEE:
	.byte	1
__ZNSt8__detail14__destructibleINSt9__unicode13_Utf_iteratorIcDiPKcS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail19__destructible_implINSt9__unicode13_Utf_iteratorIcDiPKcS4_NS1_5_ReplEEEEE:
	.byte	1
__ZNSt8__detail30__integer_to_chars_is_unsignedIoEE:
	.byte	1
	.section	__TEXT,__StaticInit,regular,pure_instructions
__GLOBAL__sub_I_integer_double.cpp:
LFB6127:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	call	__Z41__static_initialization_and_destruction_0v
	popq	%rbp
LCFI8:
	ret
LFE6127:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x10
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB4114-.
	.set L$set$2,LFE4114-LFB4114
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB4114
	.long L$set$3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB5259-.
	.set L$set$7,LFE5259-LFB5259
	.quad L$set$7
	.uleb128 0
	.byte	0x4
	.set L$set$8,LCFI3-LFB5259
	.long L$set$8
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$11,LEFDE5-LASFDE5
	.long L$set$11
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB6127-.
	.set L$set$12,LFE6127-LFB6127
	.quad L$set$12
	.uleb128 0
	.byte	0x4
	.set L$set$13,LCFI6-LFB6127
	.long L$set$13
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.set L$set$14,LCFI7-LCFI6
	.long L$set$14
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.align 3
LEFDE5:
	.ident	"GCC: (Homebrew GCC 14.3.0) 14.3.0"
	.mod_init_func
_Mod.init:
	.align 3
	.quad	__GLOBAL__sub_I_integer_double.cpp
	.subsections_via_symbols
