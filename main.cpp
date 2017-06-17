#include <string.h>

#include "dynamic_ring_buffer.h"

int main()
{
    dynamic_ring_buffer *buffer = new dynamic_ring_buffer(16);

    buffer->write_data("123456789", strlen("123456789"));
    buffer->print_buffer();

    /* buffer extend from 16 bytes to 20 bytes */
    buffer->write_data("abcdefghigk", strlen("abcdefghigk"));
    buffer->print_buffer();

    /* loop search */
    buffer->kmp_init("89ab");
    printf("start position:%d\n", buffer->kmp_search_ring_buffer());

    /* drop the oldest 4 bytes from buffer */
    buffer->drop_data(4);
    buffer->print_buffer();

    /* doesn't extend buffer */
    buffer->write_data("oxyz", strlen("oxyz"));
    buffer->print_buffer();

    /* after drop search string */
    buffer->kmp_init("gkox");
    printf("start position:%d\n", buffer->kmp_search_ring_buffer());    

    delete buffer;
    
    return 0;
}
