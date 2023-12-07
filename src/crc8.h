#pragma once

#include "stdint.h"
#include "stdlib.h"

#define CRC8_TABLE_SIZE 256
#define CRC8_DEFAULT_POLYNOMIAL 0x31

void crc8_populate_msb(uint8_t table[CRC8_TABLE_SIZE], uint8_t polynomial);
uint8_t crc8_ext(const uint8_t table[CRC8_TABLE_SIZE], const uint8_t *pdata, size_t nbytes, uint8_t crc);
uint8_t crc8(const uint8_t *pdata, size_t nbytes);
