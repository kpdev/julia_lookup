
main_empty.o:     file format elf64-x86-64

Contents of section .text:
 0000 f30f1efa 488b1648 89f84889 f74889c6  ....H..H..H..H..
 0010 488b5218 ffe2662e 0f1f8400 00000000  H.R...f.........
 0020 f30f1efa 8b050000 000083c0 01890500  ................
 0030 000000c3 66662e0f 1f840000 00000090  ....ff..........
 0040 f30f1efa 8b050000 000083c0 01890500  ................
 0050 000000c3 66662e0f 1f840000 00000090  ....ff..........
 0060 f30f1efa 488b1648 89f84889 f74889c6  ....H..H..H..H..
 0070 488b5220 ffe2662e 0f1f8400 00000000  H.R ..f.........
 0080 f30f1efa 8b050000 000083c0 01890500  ................
 0090 000000c3 66662e0f 1f840000 00000090  ....ff..........
 00a0 f30f1efa 8b050000 000083c0 01890500  ................
 00b0 000000c3                             ....            
Contents of section .text._ZN8ElementBD2Ev:
 0000 f30f1efa c3                          .....           
Contents of section .text._ZN8ElementAD2Ev:
 0000 f30f1efa c3                          .....           
Contents of section .text._ZN8ElementBD0Ev:
 0000 f30f1efa be080000 00e90000 0000      ..............  
Contents of section .text._ZN8ElementAD0Ev:
 0000 f30f1efa be080000 00e90000 0000      ..............  
Contents of section .text.startup:
 0000 f30f1efa 53488d1d 00000000 488d3500  ....SH......H.5.
 0010 00000048 89da488d 3d000000 00e80000  ...H..H.=.......
 0020 00004889 da5b488d 35000000 00488d3d  ..H..[H.5....H.=
 0030 00000000 e9000000 00                 .........       
Contents of section .init_array:
 0000 00000000 00000000                    ........        
Contents of section .rodata._ZTS7Element:
 0000 37456c65 6d656e74 00                 7Element.       
Contents of section .data.rel.ro._ZTI7Element:
 0000 00000000 00000000 00000000 00000000  ................
Contents of section .rodata._ZTS8ElementA:
 0000 38456c65 6d656e74 4100               8ElementA.      
Contents of section .data.rel.ro._ZTI8ElementA:
 0000 00000000 00000000 00000000 00000000  ................
 0010 00000000 00000000                    ........        
Contents of section .rodata._ZTS8ElementB:
 0000 38456c65 6d656e74 4200               8ElementB.      
Contents of section .data.rel.ro._ZTI8ElementB:
 0000 00000000 00000000 00000000 00000000  ................
 0010 00000000 00000000                    ........        
Contents of section .data.rel.ro.local._ZTV8ElementA:
 0000 00000000 00000000 00000000 00000000  ................
 0010 00000000 00000000 00000000 00000000  ................
 0020 00000000 00000000 00000000 00000000  ................
 0030 00000000 00000000                    ........        
Contents of section .data.rel.ro.local._ZTV8ElementB:
 0000 00000000 00000000 00000000 00000000  ................
 0010 00000000 00000000 00000000 00000000  ................
 0020 00000000 00000000 00000000 00000000  ................
 0030 00000000 00000000                    ........        
Contents of section .data.rel.local:
 0000 00000000 00000000 00000000 00000000  ................
Contents of section .comment:
 0000 00474343 3a202855 62756e74 75203133  .GCC: (Ubuntu 13
 0010 2e332e30 2d367562 756e7475 327e3234  .3.0-6ubuntu2~24
 0020 2e303429 2031332e 332e3000           .04) 13.3.0.    
Contents of section .note.gnu.property:
 0000 04000000 10000000 05000000 474e5500  ............GNU.
 0010 020000c0 04000000 03000000 00000000  ................
Contents of section .eh_frame:
 0000 14000000 00000000 017a5200 01781001  .........zR..x..
 0010 1b0c0708 90010000 10000000 1c000000  ................
 0020 00000000 16000000 00000000 10000000  ................
 0030 30000000 00000000 14000000 00000000  0...............
 0040 10000000 44000000 00000000 14000000  ....D...........
 0050 00000000 10000000 58000000 00000000  ........X.......
 0060 16000000 00000000 10000000 6c000000  ............l...
 0070 00000000 14000000 00000000 10000000  ................
 0080 80000000 00000000 14000000 00000000  ................
 0090 10000000 94000000 00000000 05000000  ................
 00a0 00000000 10000000 a8000000 00000000  ................
 00b0 05000000 00000000 10000000 bc000000  ................
 00c0 00000000 0e000000 00000000 10000000  ................
 00d0 d0000000 00000000 0e000000 00000000  ................
 00e0 1c000000 e4000000 00000000 39000000  ............9...
 00f0 00450e10 8302610e 08000000 00000000  .E....a.........

Disassembly of section .text:

0000000000000000 <.text>:
   0:	f3 0f 1e fa          	endbr64
   4:	48 8b 16             	mov    (%rsi),%rdx
   7:	48 89 f8             	mov    %rdi,%rax
   a:	48 89 f7             	mov    %rsi,%rdi
   d:	48 89 c6             	mov    %rax,%rsi
  10:	48 8b 52 18          	mov    0x18(%rdx),%rdx
  14:	ff e2                	jmp    *%rdx
  16:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  1d:	00 00 00 
  20:	f3 0f 1e fa          	endbr64
  24:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x2a
  2a:	83 c0 01             	add    $0x1,%eax
  2d:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x33
  33:	c3                   	ret
  34:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  3b:	00 00 00 00 
  3f:	90                   	nop
  40:	f3 0f 1e fa          	endbr64
  44:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x4a
  4a:	83 c0 01             	add    $0x1,%eax
  4d:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x53
  53:	c3                   	ret
  54:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  5b:	00 00 00 00 
  5f:	90                   	nop
  60:	f3 0f 1e fa          	endbr64
  64:	48 8b 16             	mov    (%rsi),%rdx
  67:	48 89 f8             	mov    %rdi,%rax
  6a:	48 89 f7             	mov    %rsi,%rdi
  6d:	48 89 c6             	mov    %rax,%rsi
  70:	48 8b 52 20          	mov    0x20(%rdx),%rdx
  74:	ff e2                	jmp    *%rdx
  76:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  7d:	00 00 00 
  80:	f3 0f 1e fa          	endbr64
  84:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0x8a
  8a:	83 c0 01             	add    $0x1,%eax
  8d:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0x93
  93:	c3                   	ret
  94:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  9b:	00 00 00 00 
  9f:	90                   	nop
  a0:	f3 0f 1e fa          	endbr64
  a4:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 0xaa
  aa:	83 c0 01             	add    $0x1,%eax
  ad:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 0xb3
  b3:	c3                   	ret

Disassembly of section .text._ZN8ElementBD2Ev:

0000000000000000 <.text._ZN8ElementBD2Ev>:
   0:	f3 0f 1e fa          	endbr64
   4:	c3                   	ret

Disassembly of section .text._ZN8ElementAD2Ev:

0000000000000000 <.text._ZN8ElementAD2Ev>:
   0:	f3 0f 1e fa          	endbr64
   4:	c3                   	ret

Disassembly of section .text._ZN8ElementBD0Ev:

0000000000000000 <.text._ZN8ElementBD0Ev>:
   0:	f3 0f 1e fa          	endbr64
   4:	be 08 00 00 00       	mov    $0x8,%esi
   9:	e9 00 00 00 00       	jmp    0xe

Disassembly of section .text._ZN8ElementAD0Ev:

0000000000000000 <.text._ZN8ElementAD0Ev>:
   0:	f3 0f 1e fa          	endbr64
   4:	be 08 00 00 00       	mov    $0x8,%esi
   9:	e9 00 00 00 00       	jmp    0xe

Disassembly of section .text.startup:

0000000000000000 <.text.startup>:
   0:	f3 0f 1e fa          	endbr64
   4:	53                   	push   %rbx
   5:	48 8d 1d 00 00 00 00 	lea    0x0(%rip),%rbx        # 0xc
   c:	48 8d 35 00 00 00 00 	lea    0x0(%rip),%rsi        # 0x13
  13:	48 89 da             	mov    %rbx,%rdx
  16:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 0x1d
  1d:	e8 00 00 00 00       	call   0x22
  22:	48 89 da             	mov    %rbx,%rdx
  25:	5b                   	pop    %rbx
  26:	48 8d 35 00 00 00 00 	lea    0x0(%rip),%rsi        # 0x2d
  2d:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 0x34
  34:	e9 00 00 00 00       	jmp    0x39

Disassembly of section .init_array:

0000000000000000 <.init_array>:
	...

Disassembly of section .rodata._ZTS7Element:

0000000000000000 <.rodata._ZTS7Element>:
   0:	37                   	(bad)
   1:	45 6c                	rex.RB insb (%dx),%es:(%rdi)
   3:	65 6d                	gs insl (%dx),%es:(%rdi)
   5:	65 6e                	outsb  %gs:(%rsi),(%dx)
   7:	74 00                	je     0x9

Disassembly of section .data.rel.ro._ZTI7Element:

0000000000000000 <.data.rel.ro._ZTI7Element>:
	...

Disassembly of section .rodata._ZTS8ElementA:

0000000000000000 <.rodata._ZTS8ElementA>:
   0:	38 45 6c             	cmp    %al,0x6c(%rbp)
   3:	65 6d                	gs insl (%dx),%es:(%rdi)
   5:	65 6e                	outsb  %gs:(%rsi),(%dx)
   7:	74 41                	je     0x4a
	...

Disassembly of section .data.rel.ro._ZTI8ElementA:

0000000000000000 <.data.rel.ro._ZTI8ElementA>:
	...

Disassembly of section .rodata._ZTS8ElementB:

0000000000000000 <.rodata._ZTS8ElementB>:
   0:	38 45 6c             	cmp    %al,0x6c(%rbp)
   3:	65 6d                	gs insl (%dx),%es:(%rdi)
   5:	65 6e                	outsb  %gs:(%rsi),(%dx)
   7:	74 42                	je     0x4b
	...

Disassembly of section .data.rel.ro._ZTI8ElementB:

0000000000000000 <.data.rel.ro._ZTI8ElementB>:
	...

Disassembly of section .data.rel.ro.local._ZTV8ElementA:

0000000000000000 <.data.rel.ro.local._ZTV8ElementA>:
	...

Disassembly of section .data.rel.ro.local._ZTV8ElementB:

0000000000000000 <.data.rel.ro.local._ZTV8ElementB>:
	...

Disassembly of section .data.rel.local:

0000000000000000 <.data.rel.local>:
	...

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
  13:	08 90 01 00 00 10    	or     %dl,0x10000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	16                   	(bad)
  25:	00 00                	add    %al,(%rax)
  27:	00 00                	add    %al,(%rax)
  29:	00 00                	add    %al,(%rax)
  2b:	00 10                	add    %dl,(%rax)
  2d:	00 00                	add    %al,(%rax)
  2f:	00 30                	add    %dh,(%rax)
  31:	00 00                	add    %al,(%rax)
  33:	00 00                	add    %al,(%rax)
  35:	00 00                	add    %al,(%rax)
  37:	00 14 00             	add    %dl,(%rax,%rax,1)
  3a:	00 00                	add    %al,(%rax)
  3c:	00 00                	add    %al,(%rax)
  3e:	00 00                	add    %al,(%rax)
  40:	10 00                	adc    %al,(%rax)
  42:	00 00                	add    %al,(%rax)
  44:	44 00 00             	add    %r8b,(%rax)
  47:	00 00                	add    %al,(%rax)
  49:	00 00                	add    %al,(%rax)
  4b:	00 14 00             	add    %dl,(%rax,%rax,1)
  4e:	00 00                	add    %al,(%rax)
  50:	00 00                	add    %al,(%rax)
  52:	00 00                	add    %al,(%rax)
  54:	10 00                	adc    %al,(%rax)
  56:	00 00                	add    %al,(%rax)
  58:	58                   	pop    %rax
  59:	00 00                	add    %al,(%rax)
  5b:	00 00                	add    %al,(%rax)
  5d:	00 00                	add    %al,(%rax)
  5f:	00 16                	add    %dl,(%rsi)
  61:	00 00                	add    %al,(%rax)
  63:	00 00                	add    %al,(%rax)
  65:	00 00                	add    %al,(%rax)
  67:	00 10                	add    %dl,(%rax)
  69:	00 00                	add    %al,(%rax)
  6b:	00 6c 00 00          	add    %ch,0x0(%rax,%rax,1)
  6f:	00 00                	add    %al,(%rax)
  71:	00 00                	add    %al,(%rax)
  73:	00 14 00             	add    %dl,(%rax,%rax,1)
  76:	00 00                	add    %al,(%rax)
  78:	00 00                	add    %al,(%rax)
  7a:	00 00                	add    %al,(%rax)
  7c:	10 00                	adc    %al,(%rax)
  7e:	00 00                	add    %al,(%rax)
  80:	80 00 00             	addb   $0x0,(%rax)
  83:	00 00                	add    %al,(%rax)
  85:	00 00                	add    %al,(%rax)
  87:	00 14 00             	add    %dl,(%rax,%rax,1)
  8a:	00 00                	add    %al,(%rax)
  8c:	00 00                	add    %al,(%rax)
  8e:	00 00                	add    %al,(%rax)
  90:	10 00                	adc    %al,(%rax)
  92:	00 00                	add    %al,(%rax)
  94:	94                   	xchg   %eax,%esp
  95:	00 00                	add    %al,(%rax)
  97:	00 00                	add    %al,(%rax)
  99:	00 00                	add    %al,(%rax)
  9b:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 0xa1
  a1:	00 00                	add    %al,(%rax)
  a3:	00 10                	add    %dl,(%rax)
  a5:	00 00                	add    %al,(%rax)
  a7:	00 a8 00 00 00 00    	add    %ch,0x0(%rax)
  ad:	00 00                	add    %al,(%rax)
  af:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 0xb5
  b5:	00 00                	add    %al,(%rax)
  b7:	00 10                	add    %dl,(%rax)
  b9:	00 00                	add    %al,(%rax)
  bb:	00 bc 00 00 00 00 00 	add    %bh,0x0(%rax,%rax,1)
  c2:	00 00                	add    %al,(%rax)
  c4:	0e                   	(bad)
  c5:	00 00                	add    %al,(%rax)
  c7:	00 00                	add    %al,(%rax)
  c9:	00 00                	add    %al,(%rax)
  cb:	00 10                	add    %dl,(%rax)
  cd:	00 00                	add    %al,(%rax)
  cf:	00 d0                	add    %dl,%al
  d1:	00 00                	add    %al,(%rax)
  d3:	00 00                	add    %al,(%rax)
  d5:	00 00                	add    %al,(%rax)
  d7:	00 0e                	add    %cl,(%rsi)
  d9:	00 00                	add    %al,(%rax)
  db:	00 00                	add    %al,(%rax)
  dd:	00 00                	add    %al,(%rax)
  df:	00 1c 00             	add    %bl,(%rax,%rax,1)
  e2:	00 00                	add    %al,(%rax)
  e4:	e4 00                	in     $0x0,%al
  e6:	00 00                	add    %al,(%rax)
  e8:	00 00                	add    %al,(%rax)
  ea:	00 00                	add    %al,(%rax)
  ec:	39 00                	cmp    %eax,(%rax)
  ee:	00 00                	add    %al,(%rax)
  f0:	00 45 0e             	add    %al,0xe(%rbp)
  f3:	10 83 02 61 0e 08    	adc    %al,0x80e6102(%rbx)
  f9:	00 00                	add    %al,(%rax)
  fb:	00 00                	add    %al,(%rax)
  fd:	00 00                	add    %al,(%rax)
	...
