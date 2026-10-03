#include <stdio.h>
#include <stdlib.h>

#define N   18 //Number of subjects
#define MAX 20

typedef struct
{
    char name;
    u_int64_t marks[N/9];
    float average;
}student;


int main()
{
    int bits = 5;
    return EXIT_SUCCESS;
}

void getmarks(student *test)
{
    int sum;
    for(int i = 0; i < N/9; i++){
        for(int j = 0; j < 9; j++){
            float mark = 0;
            scanf("%f", &mark);
            sum += mark;
            mark *= 4;
            int marks = (int) mark;
            test->marks[i] | (marks << (j * 7)); //After packing the mark on 7 bits, we save it on 7 bits free of the test->marks[i]
        }
    }
    test->average = (sum / N);
}

void setmark(student *stdnt, float new_marks, int position)
{
    int row = position - 9;

    unsigned sign = ( (unsigned) -1 >> 1 ) + 1; // (unsigned) 111...111 >> 1 = 0111...1111, 0111...111 + 1 = 10000...000
    int index = row & sign; // Extract the Sign bit of row.
    sign = !(!sign);

    int column = (!(!index) * 9) + row; // Find the index of the value after finding where it is in the table with 'row'
    new_marks *= 4;
    int mark = (int) new_marks;

    unsigned mask = ( (unsigned) -1 << (sizeof(int) - 7 - 1) ) >> (sizeof(int) - 7 - 1);
    stdnt->marks[!index] & ~(mask << (position * 7)); // set the mark on 7 bits to 0;
    stdnt->marks[!index] | (mark << (position * 7)); //set the new mark.
}

//Extracting the bit on the 'position' index of 'num'
int extract(u_int64_t num, u_int8_t position)
{
    unsigned mask = -1 << 7; //1111...0000000
    mask = ~mask; // 000...1111111
    mask << (position * 7); // 000...1111111...000

    num &= mask;
    num >>= (position * 7);

    return num;
}
