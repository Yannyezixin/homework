#ifndef TWO_NUMS
#define TWO_NUMS
#define SIZE 10000

typedef struct pair{
    int x;
    int y;
} pair;

enum status {
    P_OK,
    P_FALSE
};

enum status two_nums(int [], int, int, pair *);

#endif
