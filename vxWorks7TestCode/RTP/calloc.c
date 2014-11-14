#include <stdio.h>
#include "vxWorks.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


#define N 50000


static void
fixed_test (int size)
{
  char *ptrs[N];
  int i;

  for (i = 0; i < N; ++i)
    {
      int j;

      ptrs[i] = (char *) calloc (1, size);

      if (ptrs[i] == NULL)
	break;

      for (j = 0; j < size; ++j)
	{
	  if (ptrs[i][j] != '\0')
	    printf ("byte not cleared (size %d, element %d, byte %d)",
		   size, i, j);
	  ptrs[i][j] = '\xff';
	}
    }

  while (i-- > 0)
    free (ptrs[i]);
}



static void
null_test (void)
{

  calloc (0, 0);
  calloc (0, UINT_MAX);
  calloc (UINT_MAX, 0);
  calloc (0, ~((size_t) 0));
  calloc (~((size_t) 0), 0);
}


static int
do_test (void)
{
 
  fixed_test (96);
  fixed_test (5);
  fixed_test (17);
  fixed_test (6);
  fixed_test (31);
  fixed_test (96);


/*  null_test ();
*/
  return 0;
}


int main (
    int	   argc,	
    char * argv[]
    ) {
    printf("Start Test \n");
    do_test();
    printf("End Test \n");
    return 0;
}
