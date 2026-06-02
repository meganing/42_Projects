This note is created to store my thinking/reasoning process over the project, as the Chinese saying goes "The palest ink is better than the best memory" (plus, I think it feels great that I can see my thinking process being organized clearly when I look back. It saves the time and hustle to extract the memory my brain, and can help me consolidate my memory as a firm evidence/piece.)

## Reasons for choosing Turk Algo ##

When I was doing the project, I looked into different algorithms that can be used :Butterfly, Bubble, Greedy, Radix. Among them, the most suggested by my peers was Radix. As I studied further, I found that Radix has superior O effciency among all, but at the end, I choose to use Turk. 

The reason is that: Turk works better in this project, provided that we will only sort till 500 numbers. With a smaller number of items to work with, Turk will always choose the way that costs the least, meanwhile, Radix will take same consistent steps to check bits by bits, so, it practically makes Turks takes lesser steps to reach the optimal solution compared to Radix. (In other words, the constant factor involved in this problem still have big influence on the overall efficiency since the sample size is small. If  )

If the problem allows very large numbers for trying, I will go with Radix for sure, as that will be a more efficient choice in ther long term.  (In other words, the constant factor involved in this problem still have big influence on the overall efficiency since the sample size is small. As the sample size grows bigger and bigger, the influence of the constant factor will be smaller or negligible, at this time, it would better to use algorithm with better big O notation. )

What I learned here: When we choose al algorithm to work with a problem, we should consider not only the efficiency, but also the pratical costs within the scope of the problem, and go for the optimal/practical one.

## Consideration for my struct structure

When I am implementing the code, I was on a cross road of whether to use a singly linked list or doubly linked list. Below are my considerations. 

Memory-wise, using singly linked list is obvious better. Since each nodes only occupies two integer and one pointer worth of memory. Meanwhile, doubly linked list occupies two integers and two pointers worth of memory for every nodes.
Efficiency-wise, using doubly linked list would be more efficient, since we don't need to loop to trace the previous nodes. In contrast, singly linked list requires looping to trace the previous node.
Practically, I chose singly linked list. Because in all the operations required for the project, only two operations would be involved in such tracing scenerio. If we use singly linked list, 1) we save memory, 2)we don't need to code that much for each operation for all pointer allocations, which goes well with 42's 25-line per function limitation, 3)easier to debug with less code complications. But if we use doubly linked list, it will go the other way around. And in my reasoning, it is nor worth it to go through such hustle for two operations's relative convinience. 

Hence, I used singly linked list throughout the project.

What I learned here : minimum necessary complexity -> we only add to a data structure what the problem actually demands. With maximum 500 nodes involved, singly linked list is enough, providing that backtracing is rare.