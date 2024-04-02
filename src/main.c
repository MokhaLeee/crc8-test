#include <stdio.h>
#include <stdlib.h>

#include "crc8.h"

uint8_t crc_ref_table[CRC8_TABLE_SIZE];

void debug_test(void)
{
    int i, j;
    crc8_populate_msb(crc_ref_table, CRC8_DEFAULT_POLYNOMIAL);

    fprintf(stdout, "default crc_ref_table:\n\t");
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            fprintf(stdout, "%#4x ", crc_ref_table[j * 16 + i]);
        }
        fprintf(stdout, "\n\t");
    }
}

int main(int argc, char **argv)
{
    uint8_t crc;
    uint8_t data[] = {0xAA, 0, 0, 5, 0x6F, 9, 10, 11, 1, 1};

#if 0
    debug_test();
#endif

    crc = crc8(data, sizeof(data));
    fprintf(stdout, "test crc8 is: %#x\n", crc);

    exit(EXIT_SUCCESS);
}
