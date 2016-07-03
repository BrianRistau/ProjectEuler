# Each new term in the Fibonacci sequence is generated by adding the previous
# two terms.  By starting with 1 and 2, the first 10 terms will be...
#   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
#
# By considering the terms in the Fibonacci sequence whose values do not
# exceed four million, find the sum of the even-valued terms

.text
_start: # program entry point
	ori     $s0, $zero, 0x00        # store the sum of the even terms
	ori     $s1, $zero, 0x3D0900    # store the maximum value
	ori     $a0, $zero, 0x01        # store the first fibonacci number
	ori     $a1, $zero, 0x01        # store the second fibonacci number
_loop: # code to loop through all the fibonacci digits
	jal     _fibonacci             # get the next fibonacci digit
	bgtu    $v0, $s1, _end         # exit loop if number is too large
	or      $a0, $zero, $a1        # move the first fibonacci digit
	or      $a1, $zero, $v0        # move the second fibonacci digit
	andi    $t0, $a1, 0x01         # check if the number is even
	bnez    $t0, _loop             # start loop again if odd
	addu    $s0, $s0, $a1          # add the even number to the total
	j       _loop                  # go back to the beginning of loop
_end: # code to output result and exit program
	or      $a0, $zero, $s0        # move total to argument register
	ori     $v0, $zero, 0x01       # set value register to print int
	syscall                        # output the result
	ori     $v0, $zero, 0x0A       # set value register to terminate
	syscall                        # terminate runtime
_fibonacci: # function to get the next number in the fibonacci sequence
# $a0 and $a1 are the previous two numbers in the sequence
# $v0 contains the next number in the sequence
	addu	$v0, $a0, $a1           # get the next number
	jr      $ra                     # return the number
