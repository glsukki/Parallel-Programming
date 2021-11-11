#include<stdio.h>
#include<math.h>
#include<string.h>


//  Arrays to store the Prime and Sine values
int primes[1000];
double sines[1000];


// Function to check if a number is prime or not and then append it to the "primes" array if it is a Prime Number
void primeTable(int size){
    int i, j;
    // p - is used for indexing the "primes" array
    // isPrime - is used as a flag
    int p, isPrime;

    // first prime number starts with - 2 - hence i = 2
    i = 2;
    p = 0;

    while(p < size){
        isPrime = 1;
        for(j = 2; j < i; j++){
            if(( i % j ) == 0){
                isPrime = 0;
                break;
            }
        }

        if(isPrime){
            primes[p] = i;
            p++;
        }
        i++;
    }
}

// Function to calculate the sine values till the mentioned size.
// M_PI - is equivalent to = 3.1415... 

void sineTable(int size){
    int i;
    for(i = 0; i < size; i++)
        sines[i] = sin(i*M_PI/180);
}


int main(){
    int i, size;

    // Defining the size of the Prime and Sine Table for which the values are to be generated till
    printf("Enter the size of the Prime & Sine - Table : ");
    scanf("%d", &size);


    // Running both the Prime and Sine functions in Parallel
    #pragma omp parallel sections
    {
        // Calling the Prime Function to be executed in Parallel
        #pragma omp section
        {
            primeTable(size);
            // Printing the Prime Values which are stored in the Global Variable - primes[]
            printf("The Prime Values generated are as follows : \n");
            for(i = 0; i < size; i++)
                printf("%d\n", primes[i]);
        }

        // Calling the Sine Function to be executed in Parallel
        #pragma omp section
        {
            sineTable(size);
            // Printing the Sine Valyes which are stored in the Global Variable - sines[]
            printf("The Sine Values generated are as follows : \n");
            for(i = 0; i < size; i++)
                printf("%lf\n", sines[i]);
        }
    }
}