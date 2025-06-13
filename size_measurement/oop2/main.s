
main.o:     file format elf64-x86-64

Contents of section .text:
 0000 f30f1efa 8b050000 000083c0 01890500  ................
 0010 0000008b 05000000 0083c001 89050000  ................
 0020 00008b05 00000000 83c00189 05000000  ................
 0030 008b0500 00000083 c0018905 00000000  ................
 0040 c3                                   .               
Contents of section .comment:
 0000 00474343 3a202855 62756e74 75203133  .GCC: (Ubuntu 13
 0010 2e332e30 2d367562 756e7475 327e3234  .3.0-6ubuntu2~24
 0020 2e303429 2031332e 332e3000           .04) 13.3.0.    
Contents of section .note.gnu.property:
 0000 04000000 10000000 05000000 474e5500  ............GNU.
 0010 020000c0 04000000 03000000 00000000  ................
Contents of section .eh_frame:
 0000 14000000 00000000 017a5200 01781001  .........zR..x..
 0010 1b0c0708 90010000 14000000 1c000000  ................
 0020 00000000 41000000 00000000 00000000  ....A...........

Disassembly of section .text:

0000000000000000 <.text>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0xa
   a:	83 c0 01             	add    $0x1,%eax
   d:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x13
  13:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x19
  19:	83 c0 01             	add    $0x1,%eax
  1c:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x22
  22:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x28
  28:	83 c0 01             	add    $0x1,%eax
  2b:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x31
  31:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x37
  37:	83 c0 01             	add    $0x1,%eax
  3a:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x40
  40:	c3                   	ret

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 62             	sub    %dl,0x62(%rbp)
   9:	75 6e                	jne    0x79
   b:	74 75                	je     0x82
   d:	20 31                	and    %dh,(%rcx)
   f:	33 2e                	xor    (%rsi),%ebp
  11:	33 2e                	xor    (%rsi),%ebp
  13:	30 2d 36 75 62 75    	xor    %ch,0x75627536(%rip)        # 0x7562754f
  19:	6e                   	outsb  %ds:(%rsi),(%dx)
  1a:	74 75                	je     0x91
  1c:	32 7e 32             	xor    0x32(%rsi),%bh
  1f:	34 2e                	xor    $0x2e,%al
  21:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  24:	20 31                	and    %dh,(%rcx)
  26:	33 2e                	xor    (%rsi),%ebp
  28:	33 2e                	xor    (%rsi),%ebp
  2a:	30 00                	xor    %al,(%rax)

Disassembly of section .note.gnu.property:

0000000000000000 <.note.gnu.property>:
   0:	04 00                	add    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	10 00                	adc    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	05 00 00 00 47       	add    $0x47000000,%eax
   d:	4e 55                	rex.WRX push %rbp
   f:	00 02                	add    %al,(%rdx)
  11:	00 00                	add    %al,(%rax)
  13:	c0 04 00 00          	rolb   $0x0,(%rax,%rax,1)
  17:	00 03                	add    %al,(%rbx)
  19:	00 00                	add    %al,(%rax)
  1b:	00 00                	add    %al,(%rax)
  1d:	00 00                	add    %al,(%rax)
	...

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
  24:	41 00 00             	add    %al,(%r8)
	...
