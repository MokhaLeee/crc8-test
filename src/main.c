#include <stdio.h>
#include <stdlib.h>

#include "crc8.h"

uint8_t crc_ref_table[CRC8_TABLE_SIZE];

int main(int argc, char **argv)
{
    int i, j;

    uint32_t test_buf = 0xB2A610;

    crc8_populate_msb(crc_ref_table, CRC8_DEFAULT_POLYNOMIAL);

    fprintf(stdout, "default crc_ref_table:\n\t");
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            fprintf(stdout, "%#4x ", crc_ref_table[j * 16 + i]);
        }
        fprintf(stdout, "\n\t");
    }

    fprintf(stdout, "\n");
    fprintf(stdout, "test crc8 is: %#x\n", crc8_ext(crc_ref_table, (const uint8_t *)&test_buf, sizeof(test_buf), 0));
    fprintf(stdout, "test crc8 is: %#x\n", crc8((const uint8_t *)&test_buf, sizeof(test_buf)));

    exit(EXIT_SUCCESS);
}
