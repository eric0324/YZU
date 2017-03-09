.data
	msg1: .asciiz "a = "
	msg2: .asciiz "b = "
	msg3: .asciiz "Choose operator : (1)+ (2)- (3)* (4)/ ?: "
	msg4: .asciiz "Again?(1)yes (2)no "
	newline: .asciiz   "\n"
.text
main:	#print a = 
	la $a0,msg1        
       	li $v0,4
       	syscall
       	
	# a	
	li $v0,5                
       	syscall       
        add $s0,$v0,$zero
        
        #printb =
        la $a0,msg2        
        li $v0,4
        syscall
        
        # b    
        li $v0,5	                
        syscall       
        add $s1,$v0,$zero
      	
      	#msg:Choose operator ~~
	la $a0,msg3        
       	li $v0,4
       	syscall
       	
	#Choose operator ~~	
	li $v0,5               
       	syscall       
        add $s4,$v0,$zero
        
        beq $s4,1,add
        beq $s4,2,sub
        beq $s4,3,mul
        beq $s4,4,div
        
	
add:	add $s3, $s0, $s1
	j EXIT

sub:	sub $s3, $s0, $s1
	j EXIT
	
mul:	mul $s3, $s0, $s1
	j EXIT
	
div:	div $s3, $s0, $s1
	j EXIT
	
	
EXIT:  
       li $v0,1
       move $a0,$s3
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