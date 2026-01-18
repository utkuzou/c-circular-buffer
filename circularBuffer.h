#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//Buffer struct definition
typedef struct {
    int *buffer; //Data array
    uint32_t head; //Increase after write
	uint32_t tail; //Increase after read
	uint32_t maxLen; //Total length of buffer
} circularBuffer;

//Function Prototypes
int circBufferCreate(circularBuffer *c, int *arr, uint32_t size);
int circBufferWrite(circularBuffer *c, int data);
int circBufferRead(circularBuffer *c, int *data);
void circBufferReset(circularBuffer *c);

#endif

