#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
#define LOG printf("%s|%d|  ",__FILE__,__LINE__); printf

const u8 myZikuIndex[]={
0x44,0x81,0x4b,0x81,0x56,0x81,0x70,0x81,0x8d,0x81,0x8f,0x81,0x90,0x81,0xb2,0x81,0xb3,0x81,0xbd,0x81,0xc1,0x81,0xc9,0x81,0xcc,0x81,0xd8,0x81,0xe5,0x81,0xe7,0x81,0xe8,0x81,0xea,0x81,0xeb,0x81,0xf7,0x81,0x47,0x82,0x4b,0x82,0x5a,0x82,0x60,0x82,0x67,0x82,
0x6c,0x82,0x6d,0x82,0x84,0x82,0x85,0x82,0x8a,0x82,0x8f,0x82,0x96,0x82,0x9c,0x82,0xa0,0x82,0xac,0x82,0xb7,0x82,0xc1,0x82,0xc6,0x82,0xd1,0x82,0xd5,0x82,0xdd,0x82,0xe0,0x82,0x4a,0x83,0x51,0x83,0x56,0x83,0x64,0x83,0x6b,0x83,0x9a,0x83,0xa7,0x83,0xa8,0x83,
0xd7,0x83,0xdb,0x83,0xfa,0x83,0x40,0x84,0x72,0x84,0x77,0x84,0x7c,0x84,0x84,0x84,0x9e,0x84,0xc2,0x84,0xcd,0x84,0xd2,0x84,0xd6,0x84,0xdb,0x84,0xde,0x84,0x46,0x85,0x5c,0x85,0x6e,0x85,0x84,0x85,0x85,0x85,0xa0,0x85,0xa5,0x85,0xa6,0x85,0xac,0x85,0xad,0x85,
0xcb,0x85,0xd1,0x85,0xde,0x85,0xf1,0x85,0xf3,0x85,0xf5,0x85,0xfe,0x85,0x41,0x86,0x49,0x86,0x4c,0x86,0x55,0x86,0x5c,0x86,0x79,0x86,0x86,0x86,0xaa,0x86,0xae,0x86,0xb4,0x86,0xc5,0x86,0xe3,0x86,0xea,0x86,0x4e,0x87,0x52,0x87,0x65,0x87,0x66,0x87,0x67,0x87,
0x6c,0x87,0x97,0x87,0xa8,0x87,0xba,0x87,0xef,0x87,0xf9,0x87,0xfd,0x87,0x47,0x88,0x4e,0x88,0x53,0x88,0x55,0x88,0x64,0x88,0x65,0x88,0x66,0x88,0x6f,0x88,0x71,0x88,0x73,0x88,0x7b,0x88,0x82,0x88,0x85,0x88,0x86,0x88,0x87,0x88,0x8b,0x88,0x8f,0x88,0x90,0x88,
0x93,0x88,0x94,0x88,0x99,0x88,0x9b,0x88,0xa1,0x88,0xa5,0x88,0xa6,0x88,0xab,0x88,0xac,0x88,0xb0,0x88,0xb6,0x88,0xc0,0x88,0xc2,0x88,0xc3,0x88,0xca,0x88,0xce,0x88,0xd2,0x88,0xd6,0x88,0xd8,0x88,0xd9,0x88,0xdb,0x88,0xe6,0x88,0xeb,0x88,0xec,0x88,0xf4,0x88,
0xfd,0x88,0xfe,0x88,0x40,0x89,0x46,0x89,0x47,0x89,0x59,0x89,0x69,0x89,0x70,0x89,0x76,0x89,0x7b,0x89,0x83,0x89,0x89,0x89,0x8d,0x89,0x8e,0x89,0x90,0x89,0x93,0x89,0xd7,0x89,0xe9,0x89,0xf8,0x89,0x4c,0x8a,0x53,0x8a,0x5d,0x8a,0x6e,0x8a,0x75,0x8a,0x80,0x8a,
0x82,0x8a,0x83,0x8a,0x8c,0x8a,0x91,0x8a,0x96,0x8a,0xa0,0x8a,0xa5,0x8a,0xac,0x8a,0xad,0x8a,0xaf,0x8a,0xb4,0x8a,0xb9,0x8a,0xbb,0x8a,0xbf,0x8a,0xc1,0x8a,0xc8,0x8a,0xd3,0x8a,0xdb,0x8a,0xdf,0x8a,0xe1,0x8a,0xe9,0x8a,0xeb,0x8a,0xec,0x8a,0xed,0x8a,0xf7,0x8a,
0xfc,0x8a,0xfe,0x8a,0x40,0x8b,0x42,0x8b,0x46,0x8b,0x47,0x8b,0x4f,0x8b,0x52,0x8b,0x53,0x8b,0x57,0x8b,0x58,0x8b,0x59,0x8b,0x5a,0x8b,0x5c,0x8b,0x68,0x8b,0x69,0x8b,0x6b,0x8b,0x6e,0x8b,0x71,0x8b,0x78,0x8b,0x80,0x8b,0x84,0x8b,0x8f,0x8b,0x90,0x8b,0x9d,0x8b,
0xa0,0x8b,0xa5,0x8b,0xa6,0x8b,0xa8,0x8b,0xaa,0x8b,0xac,0x8b,0xbb,0x8b,0xbf,0x8b,0xc3,0x8b,0xcd,0x8b,0xd5,0x8b,0xd6,0x8b,0xde,0x8b,0xe0,0x8b,0xe7,0x8b,0xf7,0x8b,0xfc,0x8b,0x49,0x8c,0x68,0x8c,0x6b,0x8c,0x76,0x8c,0xb4,0x8c,0xb6,0x8c,0xc1,0x8c,0xe4,0x8c,
0xe6,0x8c,0xee,0x8c,0xf6,0x8c,0xf8,0x8c,0xfe,0x8c,0x4d,0x8d,0x4e,0x8d,0x58,0x8d,0x5f,0x8d,0x60,0x8d,0x62,0x8d,0x69,0x8d,0x6a,0x8d,0x6d,0x8d,0x70,0x8d,0x7d,0x8d,0x7e,0x8d,0x80,0x8d,0x81,0x8d,0x87,0x8d,0x8c,0x8d,0x92,0x8d,0x95,0x8d,0x97,0x8d,0xa5,0x8d,
0xac,0x8d,0xae,0x8d,0xb2,0x8d,0xb7,0x8d,0xbf,0x8d,0xc2,0x8d,0xd4,0x8d,0xde,0x8d,0xe5,0x8d,0xed,0x8d,0xf2,0x8d,0xf3,0x8d,0xfd,0x8d,0x45,0x8e,0x51,0x8e,0x64,0x8e,0x66,0x8e,0x74,0x8e,0x97,0x8e,0x9c,0x8e,0xbc,0x8e,0xcc,0x8e,0xe8,0x8e,0xf1,0x8e,0xf6,0x8e,
0x40,0x8f,0x43,0x8f,0x4d,0x8f,0x51,0x8f,0x6c,0x8f,0x6d,0x8f,0x7c,0x8f,0x80,0x8f,0x89,0x8f,0x8b,0x8f,0x93,0x8f,0xa6,0x8f,0xaa,0x8f,0xc2,0x8f,0xeb,0x8f,0xf7,0x8f,0xfc,0x8f,0x6a,0x90,0x6b,0x90,0x83,0x90,0x85,0x90,0x94,0x90,0x9b,0x90,0xaa,0x90,0xaf,0x90,
0xb4,0x90,0xb7,0x90,0xb8,0x90,0xcb,0x90,0xd2,0x90,0xd6,0x90,0xe6,0x90,0xfc,0x90,0xfe,0x90,0x56,0x91,0x5b,0x91,0x5c,0x91,0x7e,0x91,0x83,0x91,0x92,0x91,0x9e,0x91,0xe8,0x91,0xee,0x91,0xfa,0x91,0xfc,0x91,0xfd,0x91,0xfe,0x91,0x49,0x92,0x57,0x92,0x59,0x92,
0x5c,0x92,0x67,0x92,0x80,0x92,0x89,0x92,0x9f,0x92,0xa6,0x92,0xd2,0x92,0xdb,0x92,0xef,0x92,0x4c,0x93,0x61,0x93,0x68,0x93,0x73,0x93,0x9b,0x93,0xa4,0x93,0xb9,0x93,0xbf,0x93,0x60,0x94,0x91,0x94,0xa0,0x94,0xac,0x94,0xd0,0x94,0xd2,0x94,0xdf,0x94,0xed,0x94,
0xf8,0x94,0x42,0x95,0x43,0x95,0x44,0x95,0x46,0x95,0x4a,0x95,0x4c,0x95,0x4e,0x95,0x4f,0x95,0x50,0x95,0x55,0x95,0x5d,0x95,0x5f,0x95,0x60,0x95,0x63,0x95,0x64,0x95,0x69,0x95,0x6d,0x95,0x6f,0x95,0x74,0x95,0x79,0x95,0x7c,0x95,0x7e,0x95,0x80,0x95,0x81,0x95,
0x84,0x95,0x86,0x95,0x8b,0x95,0x8c,0x95,0x8f,0x95,0x9c,0x95,0xa5,0x95,0xa9,0x95,0xc0,0x95,0xc1,0x95,0xc2,0x95,0xc3,0x95,0xc7,0x95,0xca,0x95,0xd3,0x95,0xd7,0x95,0xda,0x95,0xdf,0x95,0x46,0x96,0x49,0x96,0x5b,0x96,0x5e,0x96,0x65,0x96,0x69,0x96,0x6d,0x96,
0x70,0x96,0x78,0x96,0x83,0x96,0x88,0x96,0x8d,0x96,0xa0,0x96,0xa2,0x96,0xae,0x96,0xb0,0x96,0xb6,0x96,0xc7,0x96,0xd4,0x96,0xd5,0x96,0xd8,0x96,0xde,0x96,0xee,0x96,0xf2,0x96,0x48,0x97,0x4b,0x97,0x4f,0x97,0x5e,0x97,0x6b,0x97,0x6f,0x97,0x71,0x97,0x7b,0x97,
0x83,0x97,0x84,0x97,0x85,0x97,0x86,0x97,0x87,0x97,0x92,0x97,0x94,0x97,0xa0,0x97,0xa4,0x97,0xa6,0x97,0xa7,0x97,0xa8,0x97,0xb1,0x97,0xb2,0x97,0xb5,0x97,0xb9,0x97,0xc0,0x97,0xc1,0x97,0xce,0x97,0xd5,0x97,0xe0,0x97,0xf6,0x97,0xfb,0x97,0x46,0x98,0x47,0x98,
0x4a,0x98,0x57,0x98,0x58,0x98,0x5f,0x98,0x62,0x98,0x75,0x98,0x84,0x98,0x96,0x98,0x97,0x98,0xa9,0x98,0xbf,0x98,0xf7,0x98,0x42,0x99,0x48,0x99,0x77,0x99,0x93,0x99,0x9c,0x99,0xa3,0x99,0xd8,0x99,0x47,0x9a,0x48,0x9a,0x50,0x9a,0x90,0x9a,0xa5,0x9a,0xaf,0x9a,
0xb1,0x9a,0xef,0x9a,0xf0,0x9a,0xf4,0x9a,0xf5,0x9a,0x46,0x9b,0x47,0x9b,0x49,0x9b,0x56,0x9b,0x57,0x9b,0x5e,0x9b,0x61,0x9b,0x62,0x9b,0x68,0x9b,0x70,0x9b,0x73,0x9b,0x74,0x9b,0x76,0x9b,0x80,0x9b,0x81,0x9b,0x82,0x9b,0x94,0x9b,0x98,0x9b,0x9a,0x9b,0x9b,0x9b,
0x9f,0x9b,0xa5,0x9b,0xa6,0x9b,0xa9,0x9b,0xac,0x9b,0xaf,0x9b,0xb2,0x9b,0xb3,0x9b,0xb4,0x9b,0xb8,0x9b,0xba,0x9b,0xbb,0x9b,0xbf,0x9b,0xc1,0x9b,0xc2,0x9b,0xc5,0x9b,0xc8,0x9b,0xc9,0x9b,0xcb,0x9b,0xcd,0x9b,0xcf,0x9b,0xd6,0x9b,0xda,0x9b,0xdf,0x9b,0xe1,0x9b,
0xe5,0x9b,0xe9,0x9b,0xf0,0x9b,0x42,0x9c,0x4b,0x9c,0x4c,0x9c,0x55,0x9c,0x58,0x9c,0x73,0x9c,0x7b,0x9c,0x7c,0x9c,0x80,0x9c,0x84,0x9c,0x8f,0x9c,0x95,0x9c,0x99,0x9c,0x9b,0x9c,0x9c,0x9c,0xa1,0x9c,0xae,0x9c,0xb0,0x9c,0xbb,0x9c,0xbe,0x9c,0xc3,0x9c,0xcd,0x9c,
0xd0,0x9c,0xd1,0x9c,0xd5,0x9c,0xde,0x9c,0xe0,0x9c,0xe5,0x9c,0xe8,0x9c,0xea,0x9c,0xed,0x9c,0xf2,0x9c,0xf8,0x9c,0xf9,0x9c,0xfa,0x9c,0x54,0x9d,0x56,0x9d,0x58,0x9d,0x60,0x9d,0x6b,0x9d,0x72,0x9d,0x74,0x9d,0x76,0x9d,0x78,0x9d,0x79,0x9d,0x88,0x9d,0x8f,0x9d,
0x95,0x9d,0x9d,0x9d,0xa5,0x9d,0xaa,0x9d,0xab,0x9d,0xc2,0x9d,0xca,0x9d,0xce,0x9d,0xcf,0x9d,0xd1,0x9d,0xd7,0x9d,0xdd,0x9d,0xde,0x9d,0xe9,0x9d,0xf7,0x9d,0x43,0x9e,0x64,0x9e,0x65,0x9e,0x6b,0x9e,0x86,0x9e,0x8f,0x9e,0x9b,0x9e,0xc9,0x9e,0xcd,0x9e,0xd4,0x9e,
0xd8,0x9e,0xdc,0x9e,0xed,0x9e,0xf7,0x9e,0xfa,0x9e,0x40,0x9f,0x41,0x9f,0x43,0x9f,0x50,0x9f,0x52,0x9f,0x53,0x9f,0x56,0x9f,0x5d,0x9f,0x61,0x9f,0x68,0x9f,0x6a,0x9f,0x6c,0x9f,0x8b,0x9f,0x8d,0x9f,0x93,0x9f,0x99,0x9f,0xa3,0x9f,0xb1,0x9f,0xc0,0x9f,0xcf,0x9f,
0xd0,0x9f,0xd7,0x9f,0xe0,0x9f,0xe8,0x9f,0xed,0x9f,0xf6,0x9f,0xf7,0x9f,0xfa,0x9f,0x40,0xa0,0x44,0xa0,0x62,0xa0,0x68,0xa0,0x6a,0xa0,0x6b,0xa0,0x78,0xa0,0x7d,0xa0,0x7e,0xa0,0x83,0xa0,0x98,0xa0,0x99,0xa0,0xaa,0xa0,0xaf,0xa0,0xb0,0xa0,0xbd,0xa0,0xc4,0xa0,
0xdf,0xa0,0xf2,0xa0,0x41,0xaa,0x53,0xaa,0x56,0xaa,0x6c,0xaa,0x6d,0xaa,0x72,0xaa,0x42,0xab,0x50,0xab,0x58,0xab,0x59,0xab,0x5a,0xab,0x5b,0xab,0x5c,0xab,0x5d,0xab,0x5e,0xab,0x5f,0xab,0x60,0xab,0x63,0xab,0x64,0xab,0x65,0xab,0x67,0xab,0x68,0xab,0x69,0xab,
0x6c,0xab,0x6e,0xab,0x6f,0xab,0x71,0xab,0x72,0xab,0x73,0xab,0x74,0xab,0x75,0xab,0x76,0xab,0x78,0xab,0x7a,0xab,0x7c,0xab,0x7e,0xab,0x80,0xab,0x81,0xab,0x83,0xab,0x86,0xab,0x87,0xab,0x89,0xab,0x8a,0xab,0x8b,0xab,0x8d,0xab,0x90,0xab,0x91,0xab,0x93,0xab,
0x94,0xab,0x95,0xab,0x96,0xab,0x97,0xab,0x9a,0xab,0x9e,0xab,0x9f,0xab,0xa0,0xab,0x40,0xac,0x41,0xac,0x42,0xac,0x44,0xac,0x45,0xac,0x48,0xac,0x4a,0xac,0x4b,0xac,0x4c,0xac,0x4d,0xac,0x51,0xac,0x55,0xac,0x58,0xac,0x5e,0xac,0x60,0xac,0x62,0xac,0x65,0xac,
0x66,0xac,0x67,0xac,0x69,0xac,0x72,0xac,0x73,0xac,0x74,0xac,0x75,0xac,0x76,0xac,0x77,0xac,0x79,0xac,0x81,0xac,0x83,0xac,0x85,0xac,0x86,0xac,0x87,0xac,0x89,0xac,0x8c,0xac,0x91,0xac,0x92,0xac,0x96,0xac,0x99,0xac,0x9b,0xac,0x42,0xad,0x43,0xad,0x47,0xad,
0x48,0xad,0x4a,0xad,0x4f,0xad,0x52,0xad,0x54,0xad,0x55,0xad,0x5a,0xad,0x5b,0xad,0x60,0xad,0x62,0xad,0x64,0xad,0x66,0xad,0x69,0xad,0x6a,0xad,0x72,0xad,0x73,0xad,0x77,0xad,0x78,0xad,0x7a,0xad,0x7b,0xad,0x7c,0xad,0x83,0xad,0x84,0xad,0x85,0xad,0x88,0xad,
0x8a,0xad,0x8d,0xad,0x8f,0xad,0x45,0xae,0x5b,0xae,0x60,0xae,0x64,0xae,0x66,0xae,0x6c,0xae,0x7c,0xae,0x87,0xae,0x8c,0xae,0x8f,0xae,0x9c,0xae,0x44,0xaf,0x46,0xaf,0x48,0xaf,0x4d,0xaf,0x53,0xaf,0x62,0xaf,0x7d,0xaf,0x4e,0xb0,0x6d,0xb0,0x7a,0xb0,0x7e,0xb0,
0x82,0xb0,0x89,0xb0,0x90,0xb0,0xa1,0xb0,0xa2,0xb0,0xa3,0xb0,0xa4,0xb0,0xa5,0xb0,0xa6,0xb0,0xa7,0xb0,0xa8,0xb0,0xa9,0xb0,0xaa,0xb0,0xab,0xb0,0xac,0xb0,0xad,0xb0,0xae,0xb0,0xaf,0xb0,0xb0,0xb0,0xb1,0xb0,0xb2,0xb0,0xb3,0xb0,0xb4,0xb0,0xb5,0xb0,0xb6,0xb0,
0xb7,0xb0,0xb8,0xb0,0xb9,0xb0,0xba,0xb0,0xbb,0xb0,0xbc,0xb0,0xbd,0xb0,0xbe,0xb0,0xbf,0xb0,0xc0,0xb0,0xc1,0xb0,0xc2,0xb0,0xc3,0xb0,0xc4,0xb0,0xc5,0xb0,0xc6,0xb0,0xc7,0xb0,0xc8,0xb0,0xc9,0xb0,0xca,0xb0,0xcb,0xb0,0xcc,0xb0,0xcd,0xb0,0xce,0xb0,0xcf,0xb0,
0xd0,0xb0,0xd1,0xb0,0xd2,0xb0,0xd3,0xb0,0xd4,0xb0,0xd5,0xb0,0xd6,0xb0,0xd7,0xb0,0xd8,0xb0,0xd9,0xb0,0xda,0xb0,0xdb,0xb0,0xdc,0xb0,0xdd,0xb0,0xde,0xb0,0xdf,0xb0,0xe0,0xb0,0xe1,0xb0,0xe2,0xb0,0xe3,0xb0,0xe4,0xb0,0xe5,0xb0,0xe6,0xb0,0xe7,0xb0,0xe8,0xb0,
0xe9,0xb0,0xea,0xb0,0xeb,0xb0,0xec,0xb0,0xed,0xb0,0xee,0xb0,0xef,0xb0,0xf0,0xb0,0xf1,0xb0,0xf2,0xb0,0xf3,0xb0,0xf4,0xb0,0xf5,0xb0,0xf6,0xb0,0xf7,0xb0,0xf8,0xb0,0xf9,0xb0,0xfa,0xb0,0xfb,0xb0,0xfc,0xb0,0xfd,0xb0,0xfe,0xb0,0x42,0xb1,0x48,0xb1,0x51,0xb1,
0x54,0xb1,0x5d,0xb1,0x67,0xb1,0x80,0xb1,0x8d,0xb1,0x95,0xb1,0x96,0xb1,0xa1,0xb1,0xa2,0xb1,0xa3,0xb1,0xa4,0xb1,0xa5,0xb1,0xa6,0xb1,0xa7,0xb1,0xa8,0xb1,0xa9,0xb1,0xaa,0xb1,0xab,0xb1,0xac,0xb1,0xad,0xb1,0xae,0xb1,0xaf,0xb1,0xb0,0xb1,0xb1,0xb1,0xb2,0xb1,
0xb3,0xb1,0xb4,0xb1,0xb5,0xb1,0xb6,0xb1,0xb7,0xb1,0xb8,0xb1,0xb9,0xb1,0xba,0xb1,0xbb,0xb1,0xbc,0xb1,0xbd,0xb1,0xbe,0xb1,0xbf,0xb1,0xc0,0xb1,0xc1,0xb1,0xc2,0xb1,0xc3,0xb1,0xc4,0xb1,0xc5,0xb1,0xc6,0xb1,0xc7,0xb1,0xc8,0xb1,0xc9,0xb1,0xca,0xb1,0xcb,0xb1,
0xcc,0xb1,0xcd,0xb1,0xce,0xb1,0xcf,0xb1,0xd0,0xb1,0xd1,0xb1,0xd2,0xb1,0xd3,0xb1,0xd4,0xb1,0xd5,0xb1,0xd6,0xb1,0xd7,0xb1,0xd8,0xb1,0xd9,0xb1,0xda,0xb1,0xdb,0xb1,0xdc,0xb1,0xdd,0xb1,0xde,0xb1,0xdf,0xb1,0xe0,0xb1,0xe1,0xb1,0xe2,0xb1,0xe3,0xb1,0xe4,0xb1,
0xe5,0xb1,0xe6,0xb1,0xe7,0xb1,0xe8,0xb1,0xe9,0xb1,0xea,0xb1,0xeb,0xb1,0xec,0xb1,0xed,0xb1,0xee,0xb1,0xef,0xb1,0xf0,0xb1,0xf1,0xb1,0xf2,0xb1,0xf3,0xb1,0xf4,0xb1,0xf5,0xb1,0xf6,0xb1,0xf7,0xb1,0xf8,0xb1,0xf9,0xb1,0xfa,0xb1,0xfb,0xb1,0xfc,0xb1,0xfd,0xb1,
0xfe,0xb1,0x5f,0xb2,0x73,0xb2,0x74,0xb2,0x7b,0xb2,0x9c,0xb2,0xa1,0xb2,0xa2,0xb2,0xa3,0xb2,0xa4,0xb2,0xa5,0xb2,0xa6,0xb2,0xa7,0xb2,0xa8,0xb2,0xa9,0xb2,0xaa,0xb2,0xab,0xb2,0xac,0xb2,0xad,0xb2,0xae,0xb2,0xaf,0xb2,0xb0,0xb2,0xb1,0xb2,0xb2,0xb2,0xb3,0xb2,
0xb4,0xb2,0xb5,0xb2,0xb6,0xb2,0xb7,0xb2,0xb8,0xb2,0xb9,0xb2,0xba,0xb2,0xbb,0xb2,0xbc,0xb2,0xbd,0xb2,0xbe,0xb2,0xbf,0xb2,0xc0,0xb2,0xc1,0xb2,0xc2,0xb2,0xc3,0xb2,0xc4,0xb2,0xc5,0xb2,0xc6,0xb2,0xc7,0xb2,0xc8,0xb2,0xc9,0xb2,0xca,0xb2,0xcb,0xb2,0xcc,0xb2,
0xcd,0xb2,0xce,0xb2,0xcf,0xb2,0xd0,0xb2,0xd1,0xb2,0xd2,0xb2,0xd3,0xb2,0xd4,0xb2,0xd5,0xb2,0xd6,0xb2,0xd7,0xb2,0xd8,0xb2,0xd9,0xb2,0xda,0xb2,0xdb,0xb2,0xdc,0xb2,0xdd,0xb2,0xde,0xb2,0xdf,0xb2,0xe0,0xb2,0xe1,0xb2,0xe2,0xb2,0xe3,0xb2,0xe4,0xb2,0xe5,0xb2,
0xe6,0xb2,0xe7,0xb2,0xe8,0xb2,0xe9,0xb2,0xea,0xb2,0xeb,0xb2,0xec,0xb2,0xed,0xb2,0xee,0xb2,0xef,0xb2,0xf0,0xb2,0xf1,0xb2,0xf2,0xb2,0xf3,0xb2,0xf4,0xb2,0xf5,0xb2,0xf6,0xb2,0xf7,0xb2,0xf8,0xb2,0xf9,0xb2,0xfa,0xb2,0xfb,0xb2,0xfc,0xb2,0xfd,0xb2,0xfe,0xb2,
0x44,0xb3,0x4c,0xb3,0x4d,0xb3,0x4f,0xb3,0x51,0xb3,0x5e,0xb3,0x64,0xb3,0x65,0xb3,0x6a,0xb3,0x6e,0xb3,0x70,0xb3,0x75,0xb3,0x77,0xb3,0x7b,0xb3,0x7d,0xb3,0x7e,0xb3,0x9c,0xb3,0xa0,0xb3,0xa1,0xb3,0xa2,0xb3,0xa3,0xb3,0xa4,0xb3,0xa5,0xb3,0xa6,0xb3,0xa7,0xb3,
0xa8,0xb3,0xa9,0xb3,0xaa,0xb3,0xab,0xb3,0xac,0xb3,0xad,0xb3,0xae,0xb3,0xaf,0xb3,0xb0,0xb3,0xb1,0xb3,0xb2,0xb3,0xb3,0xb3,0xb4,0xb3,0xb5,0xb3,0xb6,0xb3,0xb7,0xb3,0xb8,0xb3,0xb9,0xb3,0xba,0xb3,0xbb,0xb3,0xbc,0xb3,0xbd,0xb3,0xbe,0xb3,0xbf,0xb3,0xc0,0xb3,
0xc1,0xb3,0xc2,0xb3,0xc3,0xb3,0xc4,0xb3,0xc5,0xb3,0xc6,0xb3,0xc7,0xb3,0xc8,0xb3,0xc9,0xb3,0xca,0xb3,0xcb,0xb3,0xcc,0xb3,0xcd,0xb3,0xce,0xb3,0xcf,0xb3,0xd0,0xb3,0xd1,0xb3,0xd2,0xb3,0xd3,0xb3,0xd4,0xb3,0xd5,0xb3,0xd6,0xb3,0xd7,0xb3,0xd8,0xb3,0xd9,0xb3,
0xda,0xb3,0xdb,0xb3,0xdc,0xb3,0xdd,0xb3,0xde,0xb3,0xdf,0xb3,0xe0,0xb3,0xe1,0xb3,0xe2,0xb3,0xe3,0xb3,0xe4,0xb3,0xe5,0xb3,0xe6,0xb3,0xe7,0xb3,0xe8,0xb3,0xe9,0xb3,0xea,0xb3,0xeb,0xb3,0xec,0xb3,0xed,0xb3,0xee,0xb3,0xef,0xb3,0xf0,0xb3,0xf1,0xb3,0xf2,0xb3,
0xf3,0xb3,0xf4,0xb3,0xf5,0xb3,0xf6,0xb3,0xf7,0xb3,0xf8,0xb3,0xf9,0xb3,0xfa,0xb3,0xfb,0xb3,0xfc,0xb3,0xfd,0xb3,0xfe,0xb3,0x43,0xb4,0x46,0xb4,0x53,0xb4,0x5c,0xb4,0x6e,0xb4,0x77,0xb4,0x7c,0xb4,0x90,0xb4,0x91,0xb4,0xa0,0xb4,0xa1,0xb4,0xa2,0xb4,0xa3,0xb4,
0xa4,0xb4,0xa5,0xb4,0xa6,0xb4,0xa7,0xb4,0xa8,0xb4,0xa9,0xb4,0xaa,0xb4,0xab,0xb4,0xac,0xb4,0xad,0xb4,0xae,0xb4,0xaf,0xb4,0xb0,0xb4,0xb1,0xb4,0xb2,0xb4,0xb3,0xb4,0xb4,0xb4,0xb5,0xb4,0xb6,0xb4,0xb7,0xb4,0xb8,0xb4,0xb9,0xb4,0xba,0xb4,0xbb,0xb4,0xbc,0xb4,
0xbd,0xb4,0xbe,0xb4,0xbf,0xb4,0xc0,0xb4,0xc1,0xb4,0xc2,0xb4,0xc3,0xb4,0xc4,0xb4,0xc5,0xb4,0xc6,0xb4,0xc7,0xb4,0xc8,0xb4,0xc9,0xb4,0xca,0xb4,0xcb,0xb4,0xcc,0xb4,0xcd,0xb4,0xce,0xb4,0xcf,0xb4,0xd0,0xb4,0xd1,0xb4,0xd2,0xb4,0xd3,0xb4,0xd4,0xb4,0xd5,0xb4,
0xd6,0xb4,0xd7,0xb4,0xd8,0xb4,0xd9,0xb4,0xda,0xb4,0xdb,0xb4,0xdc,0xb4,0xdd,0xb4,0xde,0xb4,0xdf,0xb4,0xe0,0xb4,0xe1,0xb4,0xe2,0xb4,0xe3,0xb4,0xe4,0xb4,0xe5,0xb4,0xe6,0xb4,0xe7,0xb4,0xe8,0xb4,0xe9,0xb4,0xea,0xb4,0xeb,0xb4,0xec,0xb4,0xed,0xb4,0xee,0xb4,
0xef,0xb4,0xf0,0xb4,0xf1,0xb4,0xf2,0xb4,0xf3,0xb4,0xf4,0xb4,0xf5,0xb4,0xf6,0xb4,0xf7,0xb4,0xf8,0xb4,0xf9,0xb4,0xfa,0xb4,0xfb,0xb4,0xfc,0xb4,0xfd,0xb4,0xfe,0xb4,0x43,0xb5,0x63,0xb5,0x64,0xb5,0x6c,0xb5,0x6f,0xb5,0x70,0xb5,0x71,0xb5,0x74,0xb5,0x75,0xb5,
0x76,0xb5,0x7a,0xb5,0x7d,0xb5,0x89,0xb5,0x90,0xb5,0x92,0xb5,0x9a,0xb5,0xa0,0xb5,0xa1,0xb5,0xa2,0xb5,0xa3,0xb5,0xa4,0xb5,0xa5,0xb5,0xa6,0xb5,0xa7,0xb5,0xa8,0xb5,0xa9,0xb5,0xaa,0xb5,0xab,0xb5,0xac,0xb5,0xad,0xb5,0xae,0xb5,0xaf,0xb5,0xb0,0xb5,0xb1,0xb5,
0xb2,0xb5,0xb3,0xb5,0xb4,0xb5,0xb5,0xb5,0xb6,0xb5,0xb7,0xb5,0xb8,0xb5,0xb9,0xb5,0xba,0xb5,0xbb,0xb5,0xbc,0xb5,0xbd,0xb5,0xbe,0xb5,0xbf,0xb5,0xc0,0xb5,0xc1,0xb5,0xc2,0xb5,0xc3,0xb5,0xc4,0xb5,0xc5,0xb5,0xc6,0xb5,0xc7,0xb5,0xc8,0xb5,0xc9,0xb5,0xca,0xb5,
0xcb,0xb5,0xcc,0xb5,0xcd,0xb5,0xce,0xb5,0xcf,0xb5,0xd0,0xb5,0xd1,0xb5,0xd2,0xb5,0xd3,0xb5,0xd4,0xb5,0xd5,0xb5,0xd6,0xb5,0xd7,0xb5,0xd8,0xb5,0xd9,0xb5,0xda,0xb5,0xdb,0xb5,0xdc,0xb5,0xdd,0xb5,0xde,0xb5,0xdf,0xb5,0xe0,0xb5,0xe1,0xb5,0xe2,0xb5,0xe3,0xb5,
0xe4,0xb5,0xe5,0xb5,0xe6,0xb5,0xe7,0xb5,0xe8,0xb5,0xe9,0xb5,0xea,0xb5,0xeb,0xb5,0xec,0xb5,0xed,0xb5,0xee,0xb5,0xef,0xb5,0xf0,0xb5,0xf1,0xb5,0xf2,0xb5,0xf3,0xb5,0xf4,0xb5,0xf5,0xb5,0xf6,0xb5,0xf7,0xb5,0xf8,0xb5,0xf9,0xb5,0xfa,0xb5,0xfb,0xb5,0xfc,0xb5,
0xfd,0xb5,0xfe,0xb5,0x41,0xb6,0x45,0xb6,0x47,0xb6,0x50,0xb6,0x80,0xb6,0x8c,0xb6,0x95,0xb6,0x98,0xb6,0x9e,0xb6,0xa1,0xb6,0xa2,0xb6,0xa3,0xb6,0xa4,0xb6,0xa5,0xb6,0xa6,0xb6,0xa7,0xb6,0xa8,0xb6,0xa9,0xb6,0xaa,0xb6,0xab,0xb6,0xac,0xb6,0xad,0xb6,0xae,0xb6,
0xaf,0xb6,0xb0,0xb6,0xb1,0xb6,0xb2,0xb6,0xb3,0xb6,0xb4,0xb6,0xb5,0xb6,0xb6,0xb6,0xb7,0xb6,0xb8,0xb6,0xb9,0xb6,0xba,0xb6,0xbb,0xb6,0xbc,0xb6,0xbd,0xb6,0xbe,0xb6,0xbf,0xb6,0xc0,0xb6,0xc1,0xb6,0xc2,0xb6,0xc3,0xb6,0xc4,0xb6,0xc5,0xb6,0xc6,0xb6,0xc7,0xb6,
0xc8,0xb6,0xc9,0xb6,0xca,0xb6,0xcb,0xb6,0xcc,0xb6,0xcd,0xb6,0xce,0xb6,0xcf,0xb6,0xd0,0xb6,0xd1,0xb6,0xd2,0xb6,0xd3,0xb6,0xd4,0xb6,0xd5,0xb6,0xd6,0xb6,0xd7,0xb6,0xd8,0xb6,0xd9,0xb6,0xda,0xb6,0xdb,0xb6,0xdc,0xb6,0xdd,0xb6,0xde,0xb6,0xdf,0xb6,0xe0,0xb6,
0xe1,0xb6,0xe2,0xb6,0xe3,0xb6,0xe4,0xb6,0xe5,0xb6,0xe6,0xb6,0xe7,0xb6,0xe8,0xb6,0xe9,0xb6,0xea,0xb6,0xeb,0xb6,0xec,0xb6,0xed,0xb6,0xee,0xb6,0xef,0xb6,0xf0,0xb6,0xf1,0xb6,0xf2,0xb6,0xf3,0xb6,0xf4,0xb6,0xf5,0xb6,0xf6,0xb6,0xf7,0xb6,0xf8,0xb6,0xf9,0xb6,
0xfa,0xb6,0xfb,0xb6,0xfc,0xb6,0xfd,0xb6,0xfe,0xb6,0x5d,0xb7,0x6f,0xb7,0x72,0xb7,0x75,0xb7,0x90,0xb7,0x93,0xb7,0x96,0xb7,0xa1,0xb7,0xa2,0xb7,0xa3,0xb7,0xa4,0xb7,0xa5,0xb7,0xa6,0xb7,0xa7,0xb7,0xa8,0xb7,0xa9,0xb7,0xaa,0xb7,0xab,0xb7,0xac,0xb7,0xad,0xb7,
0xae,0xb7,0xaf,0xb7,0xb0,0xb7,0xb1,0xb7,0xb2,0xb7,0xb3,0xb7,0xb4,0xb7,0xb5,0xb7,0xb6,0xb7,0xb7,0xb7,0xb8,0xb7,0xb9,0xb7,0xba,0xb7,0xbb,0xb7,0xbc,0xb7,0xbd,0xb7,0xbe,0xb7,0xbf,0xb7,0xc0,0xb7,0xc1,0xb7,0xc2,0xb7,0xc3,0xb7,0xc4,0xb7,0xc5,0xb7,0xc6,0xb7,
0xc7,0xb7,0xc8,0xb7,0xc9,0xb7,0xca,0xb7,0xcb,0xb7,0xcc,0xb7,0xcd,0xb7,0xce,0xb7,0xcf,0xb7,0xd0,0xb7,0xd1,0xb7,0xd2,0xb7,0xd3,0xb7,0xd4,0xb7,0xd5,0xb7,0xd6,0xb7,0xd7,0xb7,0xd8,0xb7,0xd9,0xb7,0xda,0xb7,0xdb,0xb7,0xdc,0xb7,0xdd,0xb7,0xde,0xb7,0xdf,0xb7,
0xe0,0xb7,0xe1,0xb7,0xe2,0xb7,0xe3,0xb7,0xe4,0xb7,0xe5,0xb7,0xe6,0xb7,0xe7,0xb7,0xe8,0xb7,0xe9,0xb7,0xea,0xb7,0xeb,0xb7,0xec,0xb7,0xed,0xb7,0xee,0xb7,0xef,0xb7,0xf0,0xb7,0xf1,0xb7,0xf2,0xb7,0xf3,0xb7,0xf4,0xb7,0xf5,0xb7,0xf6,0xb7,0xf7,0xb7,0xf8,0xb7,
0xf9,0xb7,0xfa,0xb7,0xfb,0xb7,0xfc,0xb7,0xfd,0xb7,0xfe,0xb7,0x40,0xb8,0x4f,0xb8,0x66,0xb8,0x6c,0xb8,0x78,0xb8,0x9d,0xb8,0xa1,0xb8,0xa2,0xb8,0xa3,0xb8,0xa4,0xb8,0xa5,0xb8,0xa6,0xb8,0xa7,0xb8,0xa8,0xb8,0xa9,0xb8,0xaa,0xb8,0xab,0xb8,0xac,0xb8,0xad,0xb8,
0xae,0xb8,0xaf,0xb8,0xb0,0xb8,0xb1,0xb8,0xb2,0xb8,0xb3,0xb8,0xb4,0xb8,0xb5,0xb8,0xb6,0xb8,0xb7,0xb8,0xb8,0xb8,0xb9,0xb8,0xba,0xb8,0xbb,0xb8,0xbc,0xb8,0xbd,0xb8,0xbe,0xb8,0xbf,0xb8,0xc0,0xb8,0xc1,0xb8,0xc2,0xb8,0xc3,0xb8,0xc4,0xb8,0xc5,0xb8,0xc6,0xb8,
0xc7,0xb8,0xc8,0xb8,0xc9,0xb8,0xca,0xb8,0xcb,0xb8,0xcc,0xb8,0xcd,0xb8,0xce,0xb8,0xcf,0xb8,0xd0,0xb8,0xd1,0xb8,0xd2,0xb8,0xd3,0xb8,0xd4,0xb8,0xd5,0xb8,0xd6,0xb8,0xd7,0xb8,0xd8,0xb8,0xd9,0xb8,0xda,0xb8,0xdb,0xb8,0xdc,0xb8,0xdd,0xb8,0xde,0xb8,0xdf,0xb8,
0xe0,0xb8,0xe1,0xb8,0xe2,0xb8,0xe3,0xb8,0xe4,0xb8,0xe5,0xb8,0xe6,0xb8,0xe7,0xb8,0xe8,0xb8,0xe9,0xb8,0xea,0xb8,0xeb,0xb8,0xec,0xb8,0xed,0xb8,0xee,0xb8,0xef,0xb8,0xf0,0xb8,0xf1,0xb8,0xf2,0xb8,0xf3,0xb8,0xf4,0xb8,0xf5,0xb8,0xf6,0xb8,0xf7,0xb8,0xf8,0xb8,
0xf9,0xb8,0xfa,0xb8,0xfb,0xb8,0xfc,0xb8,0xfd,0xb8,0xfe,0xb8,0x40,0xb9,0x4b,0xb9,0x59,0xb9,0x5e,0xb9,0x5f,0xb9,0x6c,0xb9,0x6f,0xb9,0x82,0xb9,0x83,0xb9,0xa1,0xb9,0xa2,0xb9,0xa3,0xb9,0xa4,0xb9,0xa5,0xb9,0xa6,0xb9,0xa7,0xb9,0xa8,0xb9,0xa9,0xb9,0xaa,0xb9,
0xab,0xb9,0xac,0xb9,0xad,0xb9,0xae,0xb9,0xaf,0xb9,0xb0,0xb9,0xb1,0xb9,0xb2,0xb9,0xb3,0xb9,0xb4,0xb9,0xb5,0xb9,0xb6,0xb9,0xb7,0xb9,0xb8,0xb9,0xb9,0xb9,0xba,0xb9,0xbb,0xb9,0xbc,0xb9,0xbd,0xb9,0xbe,0xb9,0xbf,0xb9,0xc0,0xb9,0xc1,0xb9,0xc2,0xb9,0xc3,0xb9,
0xc4,0xb9,0xc5,0xb9,0xc6,0xb9,0xc7,0xb9,0xc8,0xb9,0xc9,0xb9,0xca,0xb9,0xcb,0xb9,0xcc,0xb9,0xcd,0xb9,0xce,0xb9,0xcf,0xb9,0xd0,0xb9,0xd1,0xb9,0xd2,0xb9,0xd3,0xb9,0xd4,0xb9,0xd5,0xb9,0xd6,0xb9,0xd7,0xb9,0xd8,0xb9,0xd9,0xb9,0xda,0xb9,0xdb,0xb9,0xdc,0xb9,
0xdd,0xb9,0xde,0xb9,0xdf,0xb9,0xe0,0xb9,0xe1,0xb9,0xe2,0xb9,0xe3,0xb9,0xe4,0xb9,0xe5,0xb9,0xe6,0xb9,0xe7,0xb9,0xe8,0xb9,0xe9,0xb9,0xea,0xb9,0xeb,0xb9,0xec,0xb9,0xed,0xb9,0xee,0xb9,0xef,0xb9,0xf0,0xb9,0xf1,0xb9,0xf2,0xb9,0xf3,0xb9,0xf4,0xb9,0xf5,0xb9,
0xf6,0xb9,0xf7,0xb9,0xf8,0xb9,0xf9,0xb9,0xfa,0xb9,0xfb,0xb9,0xfc,0xb9,0xfd,0xb9,0xfe,0xb9,0x43,0xba,0x54,0xba,0x5d,0xba,0x6d,0xba,0x72,0xba,0x7b,0xba,0x83,0xba,0x85,0xba,0x92,0xba,0xa1,0xba,0xa2,0xba,0xa3,0xba,0xa4,0xba,0xa5,0xba,0xa6,0xba,0xa7,0xba,
0xa8,0xba,0xa9,0xba,0xaa,0xba,0xab,0xba,0xac,0xba,0xad,0xba,0xae,0xba,0xaf,0xba,0xb0,0xba,0xb1,0xba,0xb2,0xba,0xb3,0xba,0xb4,0xba,0xb5,0xba,0xb6,0xba,0xb7,0xba,0xb8,0xba,0xb9,0xba,0xba,0xba,0xbb,0xba,0xbc,0xba,0xbd,0xba,0xbe,0xba,0xbf,0xba,0xc0,0xba,
0xc1,0xba,0xc2,0xba,0xc3,0xba,0xc4,0xba,0xc5,0xba,0xc6,0xba,0xc7,0xba,0xc8,0xba,0xc9,0xba,0xca,0xba,0xcb,0xba,0xcc,0xba,0xcd,0xba,0xce,0xba,0xcf,0xba,0xd0,0xba,0xd1,0xba,0xd2,0xba,0xd3,0xba,0xd4,0xba,0xd5,0xba,0xd6,0xba,0xd7,0xba,0xd8,0xba,0xd9,0xba,
0xda,0xba,0xdb,0xba,0xdc,0xba,0xdd,0xba,0xde,0xba,0xdf,0xba,0xe0,0xba,0xe1,0xba,0xe2,0xba,0xe3,0xba,0xe4,0xba,0xe5,0xba,0xe6,0xba,0xe7,0xba,0xe8,0xba,0xe9,0xba,0xea,0xba,0xeb,0xba,0xec,0xba,0xed,0xba,0xee,0xba,0xef,0xba,0xf0,0xba,0xf1,0xba,0xf2,0xba,
0xf3,0xba,0xf4,0xba,0xf5,0xba,0xf6,0xba,0xf7,0xba,0xf8,0xba,0xf9,0xba,0xfa,0xba,0xfb,0xba,0xfc,0xba,0xfd,0xba,0xfe,0xba,0x61,0xbb,0xa1,0xbb,0xa2,0xbb,0xa3,0xbb,0xa4,0xbb,0xa5,0xbb,0xa6,0xbb,0xa7,0xbb,0xa8,0xbb,0xa9,0xbb,0xaa,0xbb,0xab,0xbb,0xac,0xbb,
0xad,0xbb,0xae,0xbb,0xaf,0xbb,0xb0,0xbb,0xb1,0xbb,0xb2,0xbb,0xb3,0xbb,0xb4,0xbb,0xb5,0xbb,0xb6,0xbb,0xb7,0xbb,0xb8,0xbb,0xb9,0xbb,0xba,0xbb,0xbb,0xbb,0xbc,0xbb,0xbd,0xbb,0xbe,0xbb,0xbf,0xbb,0xc0,0xbb,0xc1,0xbb,0xc2,0xbb,0xc3,0xbb,0xc4,0xbb,0xc5,0xbb,
0xc6,0xbb,0xc7,0xbb,0xc8,0xbb,0xc9,0xbb,0xca,0xbb,0xcb,0xbb,0xcc,0xbb,0xcd,0xbb,0xce,0xbb,0xcf,0xbb,0xd0,0xbb,0xd1,0xbb,0xd2,0xbb,0xd3,0xbb,0xd4,0xbb,0xd5,0xbb,0xd6,0xbb,0xd7,0xbb,0xd8,0xbb,0xd9,0xbb,0xda,0xbb,0xdb,0xbb,0xdc,0xbb,0xdd,0xbb,0xde,0xbb,
0xdf,0xbb,0xe0,0xbb,0xe1,0xbb,0xe2,0xbb,0xe3,0xbb,0xe4,0xbb,0xe5,0xbb,0xe6,0xbb,0xe7,0xbb,0xe8,0xbb,0xe9,0xbb,0xea,0xbb,0xeb,0xbb,0xec,0xbb,0xed,0xbb,0xee,0xbb,0xef,0xbb,0xf0,0xbb,0xf1,0xbb,0xf2,0xbb,0xf3,0xbb,0xf4,0xbb,0xf5,0xbb,0xf6,0xbb,0xf7,0xbb,
0xf8,0xbb,0xf9,0xbb,0xfa,0xbb,0xfb,0xbb,0xfc,0xbb,0xfd,0xbb,0xfe,0xbb,0x4c,0xbc,0x66,0xbc,0x72,0xbc,0x8d,0xbc,0xa1,0xbc,0xa2,0xbc,0xa3,0xbc,0xa4,0xbc,0xa5,0xbc,0xa6,0xbc,0xa7,0xbc,0xa8,0xbc,0xa9,0xbc,0xaa,0xbc,0xab,0xbc,0xac,0xbc,0xad,0xbc,0xae,0xbc,
0xaf,0xbc,0xb0,0xbc,0xb1,0xbc,0xb2,0xbc,0xb3,0xbc,0xb4,0xbc,0xb5,0xbc,0xb6,0xbc,0xb7,0xbc,0xb8,0xbc,0xb9,0xbc,0xba,0xbc,0xbb,0xbc,0xbc,0xbc,0xbd,0xbc,0xbe,0xbc,0xbf,0xbc,0xc0,0xbc,0xc1,0xbc,0xc2,0xbc,0xc3,0xbc,0xc4,0xbc,0xc5,0xbc,0xc6,0xbc,0xc7,0xbc,
0xc8,0xbc,0xc9,0xbc,0xca,0xbc,0xcb,0xbc,0xcc,0xbc,0xcd,0xbc,0xce,0xbc,0xcf,0xbc,0xd0,0xbc,0xd1,0xbc,0xd2,0xbc,0xd3,0xbc,0xd4,0xbc,0xd5,0xbc,0xd6,0xbc,0xd7,0xbc,0xd8,0xbc,0xd9,0xbc,0xda,0xbc,0xdb,0xbc,0xdc,0xbc,0xdd,0xbc,0xde,0xbc,0xdf,0xbc,0xe0,0xbc,
0xe1,0xbc,0xe2,0xbc,0xe3,0xbc,0xe4,0xbc,0xe5,0xbc,0xe6,0xbc,0xe7,0xbc,0xe8,0xbc,0xe9,0xbc,0xea,0xbc,0xeb,0xbc,0xec,0xbc,0xed,0xbc,0xee,0xbc,0xef,0xbc,0xf0,0xbc,0xf1,0xbc,0xf2,0xbc,0xf3,0xbc,0xf4,0xbc,0xf5,0xbc,0xf6,0xbc,0xf7,0xbc,0xf8,0xbc,0xf9,0xbc,
0xfa,0xbc,0xfb,0xbc,0xfc,0xbc,0xfd,0xbc,0xfe,0xbc,0x65,0xbd,0x73
};

int main()
{
	u8 ss[2][3];
	u8 i=0,j=0;
	unsigned short *p=malloc(9126);
	p=(unsigned short*)myZikuIndex;
	for(i=0;i<6;i++){
		 *((u8*)ss+i)=i;
	}
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			LOG("ss[%d][%d]=%d\n",i,j,ss[i][j]);
		}
	}
	for(i=0;i<100;i++){
		LOG("*(p+%d)=%2x\n",i,*(p+i));
	}
}