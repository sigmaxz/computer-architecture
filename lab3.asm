# Simple Program that reads in an integer, and casts it to a
# floating point value. For example the floating point number
# 1.5 has a hex value of 0x3FC00000. This hex number has an
# integer value of 1,069,547,520.
#
# Sample Input : 1069547520
# Sample Output: 1.50000000

.text

main:
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

DONE:

.data
SignCheck:
   .word 0x80000000
  
STR1:
   .asciiz "Enter an Integer for decimal position:\n"
  
STR2:
   .asciiz "Enter an Integer for fixed point value:\n"