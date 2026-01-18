#include "circularBuffer.h"

int circBufferCreate(circularBuffer *c, int *arr, uint32_t size)
{
	if (c == NULL || arr == NULL || size = 0) {
		return -1;
	}
	c->buffer = arr;
	c->maxLen = size;
	c->head = 0;
	c->tail = 0;
	return 0;
}

int circBufferWrite(circularBuffer *c, int data)
{
	if (!c || !c->buffer) {
		return -1;
	}
	uint32_t next = c->head + 1;
	if (next >= c->maxLen) {
		next = 0;
	}
	if (next == c->tail) {
		return -1;
	}
	c->buffer[c->head] = data;
	c->head = next;
	return 0;
}

int circBufferRead(circularBuffer *c, int *data)
{
	if (!c || !c->buffer) {
		return -1;
	}
	uint32_t next = c->tail + 1;
	if (c->head == c->tail) {
		return -1;
	}
	if (next >= c->maxLen) {
		next = 0;
	}
	*data = c->buffer[c->tail];
	c->tail = next;
	return 0;
}

void circBufferReset(circularBuffer *c)
{
	if (c) {
		c->head = 0;
		c->tail = 0;
	}
}
