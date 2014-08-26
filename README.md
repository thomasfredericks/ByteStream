BYTESTREAM FOR ARDUINO AND WIRING
======================

A library for Arduino and Wiring that allows the transfer an array of up to 128 bytes from the computer to an Arduino.

PROTOCOL
=======================
The array is sent out as a series of serial bytes. The total length is the number of bytes of the array + 2.

The first byte is the only byte with the MSB set to 1. Its other seven bits indicate the number of following bytes (with the exception that B10000000 indicates 128 bytes). For example : B10000010 indicates that the array will contain 2 bytes.

All other bytes have the MSB set to 0. The following table displays how the data is formatted for an array of length 2.

The left side of the ':' indicates the byte and the right side the bit. In other words byte:bit.

? indicates that the value is ignored.

```
BYTE 0 -> 1  0   0   0   0   0   0   1   0  (header and length)
BYTE 1 -> 0 0:7 0:6 0:5 0:4 0:3 0:2 0:1 0:0 (bits 0 to 7 of byte 0) 
BYTE 2 -> 0 1:6 1:5 1:4 1:3 1:2 1:1 1:0 0:8 (bit 8 of byte 0 and bits 0 to 6 of byte 1) 
BYTE 3 -> 0  ?   ?   ?   ?   ?   ?  1:8 1:7 (bits 7 to 8 of byte 1) 
```
