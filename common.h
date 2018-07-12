#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdint.h>
#include <ctype.h>

union _bits256 { uint8_t bytes[32]; uint16_t ushorts[16]; uint32_t uints[8]; uint64_t ulongs[4]; uint64_t txid; unsigned char cbytes[32] };
typedef union _bits256 bits256;


#endif // COMMON_H_INCLUDED
