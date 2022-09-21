/*

((n & (n-1)) == 0)

What does if mean if ((a & b) == 0)? 
• It means that `a` and `b` does not have a 1 bit in the same place. 
• So, `n` and `n-1` never share a 1.  

What does `n-1` look like (as compered with `n`)?
• In decimal, if `n`=10 then `n-1`=9.
• In binary, if `n`=1111 than `n-1`=1110.
  But, if the least significant bit of `n` is equals to 0, 
  you should set to 1 all bit from 0 (position) until you find a 1, 
  and you flip that 1 to 0; 

So what does ((n & (n-1)) == 0) indicate?
• `n` and `n-1` must have no 1s in common
• If `n`=abcde1000 than `n-1`=abcde0111, abcde must be all 0s (000001000).
• The value `n` is therefore a power of two (or equal to 0).

*/