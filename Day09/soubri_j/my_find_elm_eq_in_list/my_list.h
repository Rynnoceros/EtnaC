#ifndef __MYLISTH__ 
# define __MYLISTH__ 
typedef struct list_s { 
    void *data; 
    struct list_s *next; 
} list_t; 
#endif // !__MYLISTH__ 