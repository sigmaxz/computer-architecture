# Simple Program that reads in an integer, and casts it to a
# floating point value. For example the floating point number
# 1.5 has a hex value of 0x3FC00000. This hex number has an
# integer value of 1,069,547,520.
#
# Sample Input : 1069547520
# Sample Output: 1.50000000

.text

main:
   la    $a0, STR3   # load a message to be output
   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0
 
   li    $v0, 5      # syscall 5 (read_int)
   syscall           # reads an int into $v0
 
   add $t0 , $v0, $zero #stores response
   beqz $t0, FixF #branch option1
   beq $t0, 1, FloatF # branch option2
 
 
   la    $a0, STR4   # load a message to be output
   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0
   b main

FixF:
   la    $a0, STR1   # load a message to be output
   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0

   li    $v0, 5      # syscall 5 (read_int)
   syscall           # reads an int into $v0
 
   add   $t0, $v0, $zero #stores decimal position in $t0
 
   la    $a0, STR2   # load a message to be output
   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0

   li    $v0, 5      # syscall 5 (read_int)
   syscall           # reads an int into $v0
 
   add   $t1, $v0, $zero #stores integer val of fixed point in $t1
 
   lw $t3, SignCheck # loading bit to check sign
 
   and   $t2, $t1, $t3 # sign stored in t2
   add $t7, $zero, $zero
 
   beqz $t2 , SignP #check if interger is positive to skip negative logic
 
   add $t7, $t3, $zero #if negative t7 would have the negative assigned
   not $t1, $t1 #make value postitive
   addi $t1,$t1,1 #add the one for correct value
 
SignP:
add $t2, $zero, $zero # zero out t2
#loop to find exponent
add $t4, $t1, $zero # positive decimal

Eloop:

beq $t4, 1, Ecal
srl $t4, $t4, 1
addi $t2, $t2, 1 # t2 contains number of shifts til you hit only value of 1

b Eloop
 
Ecal:
   add $t5, $t2, $zero #getting decimal pos
   add $t4, $t1, $zero #saving fixed point value
 
 
   not $t0,$t0
   add $t0, $t0, 1

   add $t0, $t0, $t2
 
   addi $t0, $t0, 127
   sll $t0, $t0, 23
 
   add $t7, $t7, $t0 #storing exponent value
 

 
  #Possible error or negative numbers
  #calculate fraction
 
  addi $t6, $zero, 32
  sub $t6, $t6, $t5
  sllv $t4, $t4, $t6
  srl $t4, $t4, 9
 
  add $t7, $t7, $t4
 
  add $v0, $t7, $zero
 

 

   mtc1  $v0, $f12   # moves integer to floating point register
   li    $v0, 2      # syscall 2 (print_float)
   syscall           # outputs the float at $f12
   b main
FloatF:
   la    $a0, STR5   # load a message to be output

   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0

   li    $v0, 6      # syscall 6 (read_float)
   syscall           # reads a float into $v0
     
   s.s $f0, FloatLabel
   
   ld $t0, FloatLabel
  
   la    $a0, STR6   # load a message to be output

   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0

   li    $v0, 5      # syscall 6 (read_float)
   syscall           # reads a float into $v0

   add $t3, $v0, $zero
   
 
  
   #Getting Exponent
   ld $t1,ExpCheck
   and $t1,$t1,$t0
   srl $t1,$t1,23
   subi $t1,$t1,127
   
   add $t2, $t1, $zero 
   
   add $a0, $t2, $zero
   li $v0, 1
   syscall 
   
   la $a0, STR6
   li $v0, 4
   syscall 
  
  
   #getting mantissa
   ld $t1,MantGet
   #add $t4,$t1,$zero
   and $t4, $t1, $t0
   ld $t1,MantAdd
   add $t4,$t1,$t4
   sll $t4,$t4,8
  
   add $t1,$t2,$t3
   
   
   add $t5,$zero,33
   sub $t1,$t5,$t1
   srlv $t4, $t4, $t1
  
   #Getting sign
   ld $t1, SignCheck
   and $t1, $t1, $t0
   beqz $t1,PosF
   not $t4,$t4
   addi $t4,$t4,1
  
   PosF:
  
   add $a0, $t4, $zero
   li $v0 , 1
   syscall 
  
   b main


DONE:

.data
FloatLabel:
   .float 0
   
SignCheck:
   .word 0x80000000

ExpCheck:
   .word 0x7f800000

MantGet:
   .word 0x007fffff
  
MantAdd:
   .word 0x00800000


STR1:
   .asciiz "Enter an Integer for decimal position:\n"
 
STR2:
   .asciiz "Enter an Integer for fixed point value:\n"

STR3:
   .asciiz "\nEnter 0 for Fixed to Float, 1 for Float to fixed:\n"

STR4:
   .asciiz "Error: incorrect input:\n"

STR5:
   .asciiz "\nEnter Float to convert:\n"

STR6:
   .asciiz "\nEnter desired decimal position:\n"
   
STR7:
   .asciiz "\n"