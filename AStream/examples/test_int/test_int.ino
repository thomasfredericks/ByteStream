#include <AStream.h>

int array[32]; // The maximum length of an int AStream is 64 : 128 bytes max length / 2 bytes per int
byte* barray;

// In Arduino or Wiring, an int is stored as a pair of bytes
// with the LSB first then MSB. Your software must therefore send the
// bytes in that order.

// Argument 1 : pointer to the array
// Argument 2 : length of the array
// Argument 3 : the size of an element of the array
AStream intStream = AStream(array,32,sizeof(int));

void setup() {
  
  Serial.begin(57600);
  
}

void loop() {
  
  while( intStream.available() > 0 ) {
    Serial.print("Received : ");
    Serial.print(intStream.length());
    Serial.println(" integers");
    // Print out the array as integers
    Serial.print("int [");
    for ( byte b = 0; b < intStream.length(); b++ ) {
      Serial.print(array[b]);
      Serial.print(" ");
    }
    Serial.println("]");
    // Print out the array as bytes
    barray = (byte*) array;
    Serial.print("byte [");
    for ( byte b = 0; b < intStream.length()*2; b++ ) {
      Serial.print(barray[b]);
      Serial.print(" ");
    }
    Serial.println("]");
    
  }
  
}

