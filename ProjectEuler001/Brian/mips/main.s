# If we list all the natural numbers below 10 that are multiples of 3 or 5,
# we get 3, 5, 6, and 9.  The sum of these multiples is 23.
#
# Find the sum of all the multiples below 1000.

.text
_start: # program entry point
	ori     $s0, $zero, 0x00        # initialize the total register
	ori     $s1, $zero, 0x03E8      # initialize the iterator register
_loop1: # loop to iterate through all the numbers in the target range
	addiu   $s1, $s1, -1            # subtract 1 from the iterator
	beqz    $s1, _end               # get answer is iterator is zero
	rem     $t0, $s1, 3             # store $iterator % 3 in $t2
	beqz    $t0, _loop2		# if divisible, add value to total
	rem     $t0, $s1, 5             # store $iterator % 5 in $t2
	beqz    $t0, _loop2             # if divisible, add value to total
	j       _loop1                  # go back to the beginning of loop
_loop2: # code to handle when the value is divisible by 3
	addu    $s0, $s0, $s1           # add the iterator to the sum
	j       _loop1                  # go back into the loop
_end: # code to output the answer to the problem
	addu    $a0, $zero, $s0         # move the total to the print buffer
	ori     $v0, $zero, 0x01        # set to print integer
	syscall                         # print the answer
	ori     $v0, $zero, 0x0A        # set to exit runtime
	syscall                         # terminate the current program