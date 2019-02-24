question:

621. Task Scheduler

answer:

emmmm. Finally, I still haven't finshed this question. I am trying to arrange the array to the best combination that has least interval. But this solution makes too many restrictions, and the code will be more complicated.

The right way to solve this question as follow :

1.get the most frequently appearing element.
2.assume it's A. arrange it like this A .... A .... A .... A
3.the dots between A and A is n elements of others.
4.if there are multiply element like A. The Final array is : A B ... A B ... A B ... A B
5.so the answer is size of A .... A .... A .... plus number of element like A.
