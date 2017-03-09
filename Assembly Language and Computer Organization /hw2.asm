.data
	msg1: .asciiz "a = "
	msg2: .asciiz "b = "
	msg3: .asciiz "Choose operator : (1)+ (2)- (3)* (4)/ ?: "
	msg4: .asciiz "Again?(1)yes (2)no "
	newline: .asciiz   "\n"
	value:  .word 0, 0, 0 ,0 ,0
.text
#s0  =   a
#s1  =  b
#s4  = op
main:	la $t0, value           # load address "value" into $t0 	
	#print a = 
	la $a0,msg1        
       	li $v0,4
       	syscall
       	
	# a	
	li $v0,5                
       	syscall       
        sw  $v0, 0($t0)  
        
        #printb =
        la $a0,msg2        
        li $v0,4
        syscall
        
        # b    
        li $v0,5	                
        syscall       
        sw  $v0, 4($t0)
      	
      	#msg:Choose operator ~~
	la $a0,msg3        
       	li $v0,4
       	syscall
       	
	#Choose operator ~~	
	li $v0,5               
       	syscall       
        sw  $v0, 8($t0)
        
        lw $t1, 0($t0)          # load the first num  
    	lw $t2, 4($t0)          # load the second num  
    	lw $t6, 8($t0)          # load the operation  
        
        beq $t6,1,add
        beq $t6,2,sub
        beq $t6,3,mul
        beq $t6,4,div
        
	
add:	add $s3, $t1, $t2
	sw $s3, 12($t0)
	j EXIT

sub:	sub $s3, $t1, $t2
	sw $s3, 12($t0)
	j EXIT
	
mul:	mul $s3, $t1, $t2
	sw $s3, 12($t0)
	j EXIT
	
div:	div $s3, $t1, $t2
	sw $s3, 12($t0)
	j EXIT


EXIT:  

	lw $a0,12($t0)  
      	li $v0,1
     	syscall
       
       la $a0,newline
       li $v0,4
       syscall
       
       la $a0,msg4
       li $v0,4
       syscall
       
	li $v0,5	                
        syscall       
        add $s5,$v0,$zero
        
        beq $s5,1,main