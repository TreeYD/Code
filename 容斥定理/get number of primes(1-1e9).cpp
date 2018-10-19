#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define BIT ( sizeof( unsigned char ) * 8 )

int
main( void )
{
    unsigned char *BitArray;
    long maxsize;
    long i, j,t;

    scanf( "%ld", &maxsize );
    t=clock();
    maxsize = maxsize / BIT;
    BitArray = ( unsigned char * )malloc( maxsize * sizeof( unsigned char ) );
    assert( NULL != BitArray );

    for( i = 0; maxsize > i; ++i )
        BitArray[ i ] |= 0xFF;

    for( i = 2; maxsize * BIT > i; ++i )
        if( BitArray[ i / BIT ] & ( 1 << i % BIT ) )
            for( j = i; maxsize * BIT > j * i; ++j )
                    BitArray[ j * i / BIT ] &= ~(1 << ( j * i % BIT ));

    for( i = 2,j = 0; maxsize * BIT > i; ++i )
        if( BitArray[ i / BIT ] & ( 1 << i % BIT ) )++j;;
            //printf("%10ld%c",i, (j + 1) % 8 ? ' ' : '\n'), ++j;
    printf("time:%d   sum:%d\n",clock()-t,j);

    return 0;

}
