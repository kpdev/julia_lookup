
main.o:     file format elf64-x86-64

Contents of section .text:
 0000 ff050000 0000c366 0f1f8400 00000000  .......f........
 0010 ff050000 0000c366 0f1f8400 00000000  .......f........
 0020 ff050000 0000c366 0f1f8400 00000000  .......f........
 0030 ff050000 0000c366 0f1f8400 00000000  .......f........
 0040 8b0783f8 01741885 c0753a8b 0685c074  .....t...u:....t
 0050 2283f801 752f488d 05000000 00eb248b  "...u/H.......$.
 0060 0685c074 1783f801 751b488d 05000000  ...t....u.H.....
 0070 00eb1048 8d050000 0000eb07 488d0500  ...H........H...
 0080 000000ff 00c3                        ......          
Contents of section .comment:
 0000 00636c61 6e672076 65727369 6f6e2031  .clang version 1
 0010 352e302e 34202868 74747073 3a2f2f67  5.0.4 (https://g
 0020 69746875 622e636f 6d2f6b70 6465762f  ithub.com/kpdev/
 0030 6c6c766d 2d70726f 6a656374 2e676974  llvm-project.git
 0040 20386137 65616632 39646137 33343132   8a7eaf29da73412
 0050 33376365 64393262 62643031 39616138  37ced92bbd019aa8
 0060 37656137 30313337 642900             7ea70137d).     
Contents of section .eh_frame:
 0000 14000000 00000000 017a5200 01781001  .........zR..x..
 0010 1b0c0708 90010000 10000000 1c000000  ................
 0020 00000000 07000000 00000000 10000000  ................
 0030 30000000 00000000 07000000 00000000  0...............
 0040 10000000 44000000 00000000 07000000  ....D...........
 0050 00000000 10000000 58000000 00000000  ........X.......
 0060 07000000 00000000 14000000 6c000000  ............l...
 0070 00000000 46000000 00000000 00000000  ....F...........
Contents of section .llvm_addrsig:
 0000 0406080a                             ....            

Disassembly of section .text:

0000000000000000 <.text>:
   0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x6
   6:	c3                   	ret
   7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
   e:	00 00 
  10:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x16
  16:	c3                   	ret
  17:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  1e:	00 00 
  20:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x26
  26:	c3                   	ret
  27:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  2e:	00 00 
  30:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x36
  36:	c3                   	ret
  37:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  3e:	00 00 
  40:	8b 07                	mov    (%rdi),%eax
  42:	83 f8 01             	cmp    $0x1,%eax
  45:	74 18                	je     0x5f
  47:	85 c0                	test   %eax,%eax
  49:	75 3a                	jne    0x85
  4b:	8b 06                	mov    (%rsi),%eax
  4d:	85 c0                	test   %eax,%eax
  4f:	74 22                	je     0x73
  51:	83 f8 01             	cmp    $0x1,%eax
  54:	75 2f                	jne    0x85
  56:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 0x5d
  5d:	eb 24                	jmp    0x83
  5f:	8b 06                	mov    (%rsi),%eax
  61:	85 c0                	test   %eax,%eax
  63:	74 17                	je     0x7c
  65:	83 f8 01             	cmp    $0x1,%eax
  68:	75 1b                	jne    0x85
  6a:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 0x71
  71:	eb 10                	jmp    0x83
  73:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 0x7a
  7a:	eb 07                	jmp    0x83
  7c:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 0x83
  83:	ff 00                	incl   (%rax)
  85:	c3                   	ret

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 63 6c             	add    %ah,0x6c(%rbx)
   3:	61                   	(bad)
   4:	6e                   	outsb  %ds:(%rsi),(%dx)
   5:	67 20 76 65          	and    %dh,0x65(%esi)
   9:	72 73                	jb     0x7e
   b:	69 6f 6e 20 31 35 2e 	imul   $0x2e353120,0x6e(%rdi),%ebp
  12:	30 2e                	xor    %ch,(%rsi)
  14:	34 20                	xor    $0x20,%al
  16:	28 68 74             	sub    %ch,0x74(%rax)
  19:	74 70                	je     0x8b
  1b:	73 3a                	jae    0x57
  1d:	2f                   	(bad)
  1e:	2f                   	(bad)
  1f:	67 69 74 68 75 62 2e 	imul   $0x6f632e62,0x75(%eax,%ebp,2),%esi
  26:	63 6f 
  28:	6d                   	insl   (%dx),%es:(%rdi)
  29:	2f                   	(bad)
  2a:	6b 70 64 65          	imul   $0x65,0x64(%rax),%esi
  2e:	76 2f                	jbe    0x5f
  30:	6c                   	insb   (%dx),%es:(%rdi)
  31:	6c                   	insb   (%dx),%es:(%rdi)
  32:	76 6d                	jbe    0xa1
  34:	2d 70 72 6f 6a       	sub    $0x6a6f7270,%eax
  39:	65 63 74 2e 67       	movsxd %gs:0x67(%rsi,%rbp,1),%esi
  3e:	69 74 20 38 61 37 65 	imul   $0x61653761,0x38(%rax,%riz,1),%esi
  45:	61 
  46:	66 32 39             	data16 xor (%rcx),%bh
  49:	64 61                	fs (bad)
  4b:	37                   	(bad)
  4c:	33 34 31             	xor    (%rcx,%rsi,1),%esi
  4f:	32 33                	xor    (%rbx),%dh
  51:	37                   	(bad)
  52:	63 65 64             	movsxd 0x64(%rbp),%esp
  55:	39 32                	cmp    %esi,(%rdx)
  57:	62 62 64 30 31       	(bad)
  5c:	39 61 61             	cmp    %esp,0x61(%rcx)
  5f:	38 37                	cmp    %dh,(%rdi)
  61:	65 61                	gs (bad)
  63:	37                   	(bad)
  64:	30 31                	xor    %dh,(%rcx)
  66:	33 37                	xor    (%rdi),%esi
  68:	64 29 00             	sub    %eax,%fs:(%rax)

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     0x1f
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 10    	or     %dl,0x10000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	07                   	(bad)
  25:	00 00                	add    %al,(%rax)
  27:	00 00                	add    %al,(%rax)
  29:	00 00                	add    %al,(%rax)
  2b:	00 10                	add    %dl,(%rax)
  2d:	00 00                	add    %al,(%rax)
  2f:	00 30                	add    %dh,(%rax)
  31:	00 00                	add    %al,(%rax)
  33:	00 00                	add    %al,(%rax)
  35:	00 00                	add    %al,(%rax)
  37:	00 07                	add    %al,(%rdi)
  39:	00 00                	add    %al,(%rax)
  3b:	00 00                	add    %al,(%rax)
  3d:	00 00                	add    %al,(%rax)
  3f:	00 10                	add    %dl,(%rax)
  41:	00 00                	add    %al,(%rax)
  43:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
  47:	00 00                	add    %al,(%rax)
  49:	00 00                	add    %al,(%rax)
  4b:	00 07                	add    %al,(%rdi)
  4d:	00 00                	add    %al,(%rax)
  4f:	00 00                	add    %al,(%rax)
  51:	00 00                	add    %al,(%rax)
  53:	00 10                	add    %dl,(%rax)
  55:	00 00                	add    %al,(%rax)
  57:	00 58 00             	add    %bl,0x0(%rax)
  5a:	00 00                	add    %al,(%rax)
  5c:	00 00                	add    %al,(%rax)
  5e:	00 00                	add    %al,(%rax)
  60:	07                   	(bad)
  61:	00 00                	add    %al,(%rax)
  63:	00 00                	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 14 00             	add    %dl,(%rax,%rax,1)
  6a:	00 00                	add    %al,(%rax)
  6c:	6c                   	insb   (%dx),%es:(%rdi)
  6d:	00 00                	add    %al,(%rax)
  6f:	00 00                	add    %al,(%rax)
  71:	00 00                	add    %al,(%rax)
  73:	00 46 00             	add    %al,0x0(%rsi)
	...

Disassembly of section .llvm_addrsig:

0000000000000000 <.llvm_addrsig>:
   0:	04 06                	add    $0x6,%al
   2:	08 0a                	or     %cl,(%rdx)
