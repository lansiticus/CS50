#include <stdio.h>
#include <stdlib.h>
 
typedef struct person
{
    struct person *parents[2]; //this is the node
    char alleles[2]; //this is the data
}
person;

int main(void)
{

person->parents = malloc(sizeof(person));


}