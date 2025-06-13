
main.o:     file format elf64-x86-64

Contents of section .text:
 0000 ff050000 0000c366 0f1f8400 00000000  .......f........
 0010 ff050000 0000c366 0f1f8400 00000000  .......f........
 0020 ff050000 0000c366 0f1f8400 00000000  .......f........
 0030 ff050000 0000c366 0f1f8400 00000000  .......f........
 0040 ff050000 0000c366 0f1f8400 00000000  .......f........
 0050 ff050000 0000c366 0f1f8400 00000000  .......f........
 0060 ff050000 0000c366 0f1f8400 00000000  .......f........
 0070 ff050000 0000c366 0f1f8400 00000000  .......f........
 0080 ff050000 0000c366 0f1f8400 00000000  .......f........
 0090 ff050000 0000c366 0f1f8400 00000000  .......f........
 00a0 ff050000 0000c366 0f1f8400 00000000  .......f........
 00b0 ff050000 0000c366 0f1f8400 00000000  .......f........
 00c0 ff050000 0000c366 0f1f8400 00000000  .......f........
 00d0 ff050000 0000c366 0f1f8400 00000000  .......f........
 00e0 ff050000 0000c366 0f1f8400 00000000  .......f........
 00f0 ff050000 0000c366 0f1f8400 00000000  .......f........
 0100 8b074883 f803775f 488d0d00 00000048  ..H...w_H......H
 0110 63048148 01c8ffe0 48630648 83f80473  c..H....Hc.H...s
 0120 46488d0d 00000000 eb344863 064883f8  FH.......4Hc.H..
 0130 04733448 8d0d0000 0000eb22 48630648  .s4H......."Hc.H
 0140 83f80473 22488d0d 00000000 eb104863  ...s"H........Hc
 0150 064883f8 04731048 8d0d0000 0000488d  .H...s.H......H.
 0160 04c1488b 00ff00c3                    ..H.....        
Contents of section .rodata:
 0000 00000000 00000000 00000000 00000000  ................
Contents of section .data.rel.ro:
 0000 00000000 00000000 00000000 00000000  ................
 0010 00000000 00000000 00000000 00000000  ................
 0020 00000000 00000000 00000000 00000000  ................
 0030 00000000 00000000 00000000 00000000  ................
 0040 00000000 00000000 00000000 00000000  ................
 0050 00000000 00000000 00000000 00000000  ................
 0060 00000000 00000000 00000000 00000000  ................
 0070 00000000 00000000 00000000 00000000  ................
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
 0060 07000000 00000000 10000000 6c000000  ............l...
 0070 00000000 07000000 00000000 10000000  ................
 0080 80000000 00000000 07000000 00000000  ................
 0090 10000000 94000000 00000000 07000000  ................
 00a0 00000000 10000000 a8000000 00000000  ................
 00b0 07000000 00000000 10000000 bc000000  ................
 00c0 00000000 07000000 00000000 10000000  ................
 00d0 d0000000 00000000 07000000 00000000  ................
 00e0 10000000 e4000000 00000000 07000000  ................
 00f0 00000000 10000000 f8000000 00000000  ................
 0100 07000000 00000000 10000000 0c010000  ................
 0110 00000000 07000000 00000000 10000000  ................
 0120 20010000 00000000 07000000 00000000   ...............
 0130 10000000 34010000 00000000 07000000  ....4...........
 0140 00000000 10000000 48010000 00000000  ........H.......
 0150 07000000 00000000 14000000 5c010000  ............\...
 0160 00000000 68000000 00000000 00000000  ....h...........
Contents of section .llvm_addrsig:
 0000 06080a0c 0e101214 16181a1c 1e202224  ............. "$

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
  40:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x46
  46:	c3                   	ret
  47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4e:	00 00 
  50:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x56
  56:	c3                   	ret
  57:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  5e:	00 00 
  60:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x66
  66:	c3                   	ret
  67:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  6e:	00 00 
  70:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x76
  76:	c3                   	ret
  77:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  7e:	00 00 
  80:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x86
  86:	c3                   	ret
  87:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  8e:	00 00 
  90:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0x96
  96:	c3                   	ret
  97:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  9e:	00 00 
  a0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xa6
  a6:	c3                   	ret
  a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  ae:	00 00 
  b0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xb6
  b6:	c3                   	ret
  b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  be:	00 00 
  c0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xc6
  c6:	c3                   	ret
  c7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  ce:	00 00 
  d0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xd6
  d6:	c3                   	ret
  d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  de:	00 00 
  e0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xe6
  e6:	c3                   	ret
  e7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  ee:	00 00 
  f0:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 0xf6
  f6:	c3                   	ret
  f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  fe:	00 00 
 100:	8b 07                	mov    (%rdi),%eax
 102:	48 83 f8 03          	cmp    $0x3,%rax
 106:	77 5f                	ja     0x167
 108:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 0x10f
 10f:	48 63 04 81          	movslq (%rcx,%rax,4),%rax
 113:	48 01 c8             	add    %rcx,%rax
 116:	ff e0                	jmp    *%rax
 118:	48 63 06             	movslq (%rsi),%rax
 11b:	48 83 f8 04          	cmp    $0x4,%rax
 11f:	73 46                	jae    0x167
 121:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 0x128
 128:	eb 34                	jmp    0x15e
 12a:	48 63 06             	movslq (%rsi),%rax
 12d:	48 83 f8 04          	cmp    $0x4,%rax
 131:	73 34                	jae    0x167
 133:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 0x13a
 13a:	eb 22                	jmp    0x15e
 13c:	48 63 06             	movslq (%rsi),%rax
 13f:	48 83 f8 04          	cmp    $0x4,%rax
 143:	73 22                	jae    0x167
 145:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 0x14c
 14c:	eb 10                	jmp    0x15e
 14e:	48 63 06             	movslq (%rsi),%rax
 151:	48 83 f8 04          	cmp    $0x4,%rax
 155:	73 10                	jae    0x167
 157:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 0x15e
 15e:	48 8d 04 c1          	lea    (%rcx,%rax,8),%rax
 162:	48 8b 00             	mov    (%rax),%rax
 165:	ff 00                	incl   (%rax)
 167:	c3                   	ret

Disassembly of section .rodata:

0000000000000000 <.rodata>:
	...

Disassembly of section .data.rel.ro:

0000000000000000 <.data.rel.ro>:
	...

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
  67:	00 10                	add    %dl,(%rax)
  69:	00 00                	add    %al,(%rax)
  6b:	00 6c 00 00          	add    %ch,0x0(%rax,%rax,1)
  6f:	00 00                	add    %al,(%rax)
  71:	00 00                	add    %al,(%rax)
  73:	00 07                	add    %al,(%rdi)
  75:	00 00                	add    %al,(%rax)
  77:	00 00                	add    %al,(%rax)
  79:	00 00                	add    %al,(%rax)
  7b:	00 10                	add    %dl,(%rax)
  7d:	00 00                	add    %al,(%rax)
  7f:	00 80 00 00 00 00    	add    %al,0x0(%rax)
  85:	00 00                	add    %al,(%rax)
  87:	00 07                	add    %al,(%rdi)
  89:	00 00                	add    %al,(%rax)
  8b:	00 00                	add    %al,(%rax)
  8d:	00 00                	add    %al,(%rax)
  8f:	00 10                	add    %dl,(%rax)
  91:	00 00                	add    %al,(%rax)
  93:	00 94 00 00 00 00 00 	add    %dl,0x0(%rax,%rax,1)
  9a:	00 00                	add    %al,(%rax)
  9c:	07                   	(bad)
  9d:	00 00                	add    %al,(%rax)
  9f:	00 00                	add    %al,(%rax)
  a1:	00 00                	add    %al,(%rax)
  a3:	00 10                	add    %dl,(%rax)
  a5:	00 00                	add    %al,(%rax)
  a7:	00 a8 00 00 00 00    	add    %ch,0x0(%rax)
  ad:	00 00                	add    %al,(%rax)
  af:	00 07                	add    %al,(%rdi)
  b1:	00 00                	add    %al,(%rax)
  b3:	00 00                	add    %al,(%rax)
  b5:	00 00                	add    %al,(%rax)
  b7:	00 10                	add    %dl,(%rax)
  b9:	00 00                	add    %al,(%rax)
  bb:	00 bc 00 00 00 00 00 	add    %bh,0x0(%rax,%rax,1)
  c2:	00 00                	add    %al,(%rax)
  c4:	07                   	(bad)
  c5:	00 00                	add    %al,(%rax)
  c7:	00 00                	add    %al,(%rax)
  c9:	00 00                	add    %al,(%rax)
  cb:	00 10                	add    %dl,(%rax)
  cd:	00 00                	add    %al,(%rax)
  cf:	00 d0                	add    %dl,%al
  d1:	00 00                	add    %al,(%rax)
  d3:	00 00                	add    %al,(%rax)
  d5:	00 00                	add    %al,(%rax)
  d7:	00 07                	add    %al,(%rdi)
  d9:	00 00                	add    %al,(%rax)
  db:	00 00                	add    %al,(%rax)
  dd:	00 00                	add    %al,(%rax)
  df:	00 10                	add    %dl,(%rax)
  e1:	00 00                	add    %al,(%rax)
  e3:	00 e4                	add    %ah,%ah
  e5:	00 00                	add    %al,(%rax)
  e7:	00 00                	add    %al,(%rax)
  e9:	00 00                	add    %al,(%rax)
  eb:	00 07                	add    %al,(%rdi)
  ed:	00 00                	add    %al,(%rax)
  ef:	00 00                	add    %al,(%rax)
  f1:	00 00                	add    %al,(%rax)
  f3:	00 10                	add    %dl,(%rax)
  f5:	00 00                	add    %al,(%rax)
  f7:	00 f8                	add    %bh,%al
  f9:	00 00                	add    %al,(%rax)
  fb:	00 00                	add    %al,(%rax)
  fd:	00 00                	add    %al,(%rax)
  ff:	00 07                	add    %al,(%rdi)
 101:	00 00                	add    %al,(%rax)
 103:	00 00                	add    %al,(%rax)
 105:	00 00                	add    %al,(%rax)
 107:	00 10                	add    %dl,(%rax)
 109:	00 00                	add    %al,(%rax)
 10b:	00 0c 01             	add    %cl,(%rcx,%rax,1)
 10e:	00 00                	add    %al,(%rax)
 110:	00 00                	add    %al,(%rax)
 112:	00 00                	add    %al,(%rax)
 114:	07                   	(bad)
 115:	00 00                	add    %al,(%rax)
 117:	00 00                	add    %al,(%rax)
 119:	00 00                	add    %al,(%rax)
 11b:	00 10                	add    %dl,(%rax)
 11d:	00 00                	add    %al,(%rax)
 11f:	00 20                	add    %ah,(%rax)
 121:	01 00                	add    %eax,(%rax)
 123:	00 00                	add    %al,(%rax)
 125:	00 00                	add    %al,(%rax)
 127:	00 07                	add    %al,(%rdi)
 129:	00 00                	add    %al,(%rax)
 12b:	00 00                	add    %al,(%rax)
 12d:	00 00                	add    %al,(%rax)
 12f:	00 10                	add    %dl,(%rax)
 131:	00 00                	add    %al,(%rax)
 133:	00 34 01             	add    %dh,(%rcx,%rax,1)
 136:	00 00                	add    %al,(%rax)
 138:	00 00                	add    %al,(%rax)
 13a:	00 00                	add    %al,(%rax)
 13c:	07                   	(bad)
 13d:	00 00                	add    %al,(%rax)
 13f:	00 00                	add    %al,(%rax)
 141:	00 00                	add    %al,(%rax)
 143:	00 10                	add    %dl,(%rax)
 145:	00 00                	add    %al,(%rax)
 147:	00 48 01             	add    %cl,0x1(%rax)
 14a:	00 00                	add    %al,(%rax)
 14c:	00 00                	add    %al,(%rax)
 14e:	00 00                	add    %al,(%rax)
 150:	07                   	(bad)
 151:	00 00                	add    %al,(%rax)
 153:	00 00                	add    %al,(%rax)
 155:	00 00                	add    %al,(%rax)
 157:	00 14 00             	add    %dl,(%rax,%rax,1)
 15a:	00 00                	add    %al,(%rax)
 15c:	5c                   	pop    %rsp
 15d:	01 00                	add    %eax,(%rax)
 15f:	00 00                	add    %al,(%rax)
 161:	00 00                	add    %al,(%rax)
 163:	00 68 00             	add    %ch,0x0(%rax)
	...

Disassembly of section .llvm_addrsig:

0000000000000000 <.llvm_addrsig>:
   0:	06                   	(bad)
   1:	08 0a                	or     %cl,(%rdx)
   3:	0c 0e                	or     $0xe,%al
   5:	10 12                	adc    %dl,(%rdx)
   7:	14 16                	adc    $0x16,%al
   9:	18 1a                	sbb    %bl,(%rdx)
   b:	1c 1e                	sbb    $0x1e,%al
   d:	20 22                	and    %ah,(%rdx)
   f:	24                   	.byte 0x24
