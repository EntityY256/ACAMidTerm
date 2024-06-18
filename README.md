Q-1: Expected Time complexity : O(N)
Amingst the array of N numbers, let there be K unique numbers and bi be frequency of each number such that b1+b2...+bk=N
Sort them in descending order.
For convenience let b1 be freq if 1st largest no. (m1), b2 frequency of 2nd largest number (m2) and so on
First you will have to decrease  1st b1 elements by m1, then m1-1, then m1-2....until it reaches m2 with m2+1decrease (for all b1 numbers)
Cost of this operation = b1* (f(m1)-f(m2)) where f(n)=n*(n+1)/2. Your balance decreases by this cost and new balance is K-b1* (f(m1)-f(m2))
Theb you will have b1+b2 numbers at m2 which must be lowered to m3. You will have to spend (b1+b2)*(f(m2)-f(m3)) for this next operation
After 2nd operation (if its successful), your new balance is K-b1*(f(m1)-f(m2))-(b1+b2)*(f(m2)-f(m3))
And like that you will proceed
If at a certain point, cost is greater than available amount Venkatesh can pay at a step, create a for loop that will loop from f(mk) to f(mk+1) and see where balance decreases to 0. 
When that happens you reach the minimum max height possible

Q-2: Expected Time complexity : O(N)
Create a deque (D), and set minimum length (MIN) to N+1 (A not so possible length). The deque maintains a set of numbers whose sum remains >=K (by storing indice values wrt prefix arrays). 
When it shrinks to minimum possible size, then you get your minimum sized array with correct MIN value. Else if its impossible, you get -1 as solution

Q-3: Expected Time complexity : O(NlogN+K)
This q can be solved simply by concept of heaps. Store elements of array A into a vector, as well as an empty array of same number of elements. Store sum of all events in the 1st place
Create a heap with vectors (make_heap),  and at each iteration, see that the vectors are sorted (via push_heap)
Remove the maximum and minimum elements from array. Lower the grand Sum by these 2 numbers, add the difference element to the heap and to the sum variable and Store sum at each steps in respective positions from initial empty array.
For each query, print the elements from 2nd array associated with it

Q-4: Expected Time complexity : O(2^N)
This q can be solved through a recursive approach. 
At each step, program must check what's the maximum possible oreo by considering/not considering a packet and looking at the packets present at beginning

Q-5: Expected Time complexity : O(N+K) (K is constant)
We create a frequency matrix (starting with 0s in all places) where we subsequently increase corresponding terms by 1 depending upon the properties of the numer ( rows for length of number and columns for sum of digits)
After storing respective values, we consider summation of all possible cross-term products

Q-6: Expected Time complexity : O(1)
This question relied on a simple formula and can be solved in O(1)

Q-7: Expected Time complexity : O(LOG(N) * K^3)
There is a mathematical trick of calculating A^B mod N very quickly (called modular exponentiation)
Similarly, if we have F(N)=A1*F(N-1)+A2*F(N-2)....+AK*F(N-K), we can use a concept called matrix exponentiation (Here, A1,A2...AK=1 (All))
