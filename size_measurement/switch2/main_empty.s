
main_empty.o:     file format elf64-x86-64

Contents of section .text:
 0000 ff050000 0000ff05 00000000 ff050000  ................
 0010 0000ff05 00000000 c3                 .........       
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
 0010 1b0c0708 90010000 14000000 1c000000  ................
 0020 00000000 19000000 00000000 00000000  ................
Contents of section .llvm_addrsig:
 0000 04050607                             ....            

Disassembly of section .text:

0000000000000000 <.text>:
   0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x6
   6:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xc
   c:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x12
  12:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x18
  18:	c3                   	ret

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
  13:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	19 00                	sbb    %eax,(%rax)
	...

Disassembly of section .llvm_addrsig:

0000000000000000 <.llvm_addrsig>:
   0:	04 05                	add    $0x5,%al
   2:	06                   	(bad)
   3:	07                   	(bad)
