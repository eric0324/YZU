.data
	msg1: .asciiz "a = "
	msg2: .asciiz "b = "
	msg3: .asciiz "Choose operator : (1)+ (2)- (3)* (4)/ ?: "
	msg4: .asciiz "Again?(1)yes (2)no "
	newline: .asciiz   "\n"
	addsym: .asciiz " + "
	subsym: .asciiz " - "
	mulsym: .asciiz " * "
	divsym: .asciiz " / "
	eqlsym: .asciiz " = "
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
    
    	
    	
    	
    	li $v0,1
       	move $a0,$s0
       	syscall
        la $a0,addsym      
        li $v0,4
        syscall
        li $v0,1
       	move $a0,$s1
       	syscall
       	la $a0,eqlsym      
        li $v0,4
        syscall
        jal add
        li $v0,1
       	move $a0,$s3
       	syscall
       	la $a0,newline
       	li $v0,4
       	syscall 
        
        
        
        
        li $v0,1
       	move $a0,$s0
       	syscall
        la $a0,subsym      
        li $v0,4
        syscall
        li $v0,1
       	move $a0,$s1
       	syscall
       	la $a0,eqlsym      
        li $v0,4
        syscall
        jal sub
        li $v0,1
	move $a0,$s3
       	syscall
       	la $a0,newline
       	li $v0,4
       	syscall 
        
        
        
        
        li $v0,1
       	move $a0,$s0
       	syscall
        la $a0,mulsym      
        li $v0,4
        syscall
        li $v0,1
      	move $a0,$s1
       	syscall
       	la $a0,eqlsym      
        li $v0,4
        syscall
        jal mul
        li $v0,1
       	move $a0,$s3
       	syscall
       	la $a0,newline
       	li $v0,4
       	syscall 
        
        
        li $v0,1
      	move $a0,$s0
	syscall
        la $a0,divsym      
        li $v0,4
        syscall
        li $v0,1
       	move $a0,$s1
       	syscall
       	la $a0,eqlsym      
        li $v0,4
        syscall
        jal div
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

	
add:	add $s3, $s0, $s1
	jr   $ra

sub:	sub $s3, $s0, $s1
	jr   $ra
	
mul:	mul $s3, $s0, $s1
	jr   $ra
	
div:	div $s3, $s0, $s1
	jr   $ra
