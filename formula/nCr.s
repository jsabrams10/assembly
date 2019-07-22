.globl nCr
	.type	nCr, @function
nCr:
        .cfi_startproc			# Begin.
        pushq   %rbp			# Use Frame Pointer.
        .cfi_def_cfa_offset 16	
        .cfi_offset 6, -16
        movq    %rsp, %rbp	
        .cfi_def_cfa_register 6
        pushq   %rbx			# Save registers.
        subq    $40, %rsp		# Allocate Stack space.
        .cfi_offset 3, -24
        movl    %edi, -36(%rbp)	
        movl    %esi, -40(%rbp)
        movl    -36(%rbp), %eax
        movl    %eax, %edi
        movl    $0, %eax
        call    Factorial		# Call Factorial.
        movl    %eax, -20(%rbp)
        movl    -40(%rbp), %eax
        movl    %eax, %edi
        movl    $0, %eax
        call    Factorial		# Call Factorial.
        movl    %eax, %ebx
        movl    -36(%rbp), %eax
        subl    -40(%rbp), %eax		# Subtract.
        movl    %eax, %edi
        movl    $0, %eax
        call    Factorial		# Call Factorial.
        imull   %ebx, %eax		# Multiply.
        movl    %eax, -24(%rbp)
        movl    -20(%rbp), %eax
        cltd
        idivl   -24(%rbp)		# Divide.
        movl    %eax, -28(%rbp)
        movl    -28(%rbp), %eax
        addq    $40, %rsp
        popq    %rbx			# Reset Stack Pointer.
        popq    %rbp			# Restore Frame Pointer.
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc			# End.
.LFE0:
        .size   nCr, .-nCr        

.globl Factorial
	.type	Factorial, @function
Factorial:
        .cfi_startproc			# Begin.
        pushq   %rbp			# Use Frame Pointer.
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    %edi, -20(%rbp)
        movl    -20(%rbp), %eax
        movl    %eax, -4(%rbp)
        movl    $1, -8(%rbp)
        jmp     .L4
.L5:
        movl    -20(%rbp), %eax
        subl    -8(%rbp), %eax		# Subtract.
        movl    -4(%rbp), %edx
        imull   %edx, %eax		# Multiply.
        movl    %eax, -4(%rbp)
        addl    $1, -8(%rbp)		# Add.
.L4:
        movl    -8(%rbp), %eax
        cmpl    -20(%rbp), %eax		# Compare.
        jl      .L5
        movl    -4(%rbp), %eax
        popq    %rbp			# Reset Frame Pointer.
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc			# End.
.LFE1:
        .size   Factorial, .-Factorial
