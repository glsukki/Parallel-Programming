#include<stdio.h>
#include<math.h>
#include<omp.h>


void main(){
    int i, num;
    int fact1 = 1, fact2 = 1;

    printf("Enter the number whose factorial is to be found : ");
    scanf("%d", &num);

    // When firstPrivate is not used - to find the factorial of the number - fact1
    #pragma omp parallel for firstprivate(num)
    for(i = 2; i <= num; i++)
        fact1 = fact1 * i;

    printf("When the First Private Clause is not used, factorial of %d is : %d\n", num, fact1);

    // When firstPrivate is used - to find the factorial of the number - fact2 - here the variable - fact2 - remains constant
    #pragma omp parallel for firstprivate(num, fact2)
     for(i = 2; i <= num; i++)
        fact2 = fact2 * i;
    
    printf("When the First Private Clause is used, factorial of %d is : %d\n", num, fact2);

}


// // Information regarding Private Clauses in Open MP
// https://nanxiao.gitbooks.io/openmp-little-book/content/posts/private-firstprivate-and-lastprivate-clauses.html


// Private Clause - are used to make sure that the value of a  variable does not change during parallel execution by threads.
// The value of a particular variable mentioned to be private remains the same when you check it after the execution 
// - but during execution - the value may be different and changed

// First Private Clauses - are used to make sure that the value of the variable remains the same/constant
// even during the execution of the statement in parallel computation and remains the same even after execution. 
// From the first thread itself it remains constant
