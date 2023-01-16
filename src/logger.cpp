#include "FS.h"
#include "logger.h"
//#include "SPIFFS.h"
#include <vector>


//**Constructor**************************************************
logger::logger(String name, String head)
{
    this->head = head;
    this->name = name;
    buffer = new String[BUFFER_SIZE];
    bufferPos = 0;
}

void logger::setBufferSize(int newSize)
{
    delete[] buffer;
    buffer = new String[newSize];
    BUFFER_SIZE = newSize;
}

void logger::data(String value)
{
    // make timestamp
    int millisInt = millis();
    String millisStr = String(millisInt);

    // Timestamp and add the value to the buffer
    buffer[bufferPos] = millisStr + "," + value;
    bufferPos++;

    // If the buffer is full, reset the pointer to the start (ringbuffer)
    if (bufferPos == BUFFER_SIZE)
    {
        bufferPos = 0;
    }
}

//**read the data from the file***********************************
void logger::read()
{
    Serial.println("*************************filedump requested: " + name);

    std::sort(buffer, buffer + BUFFER_SIZE); // Sort the buffer in ascending order

    bufferPos = 0; // reset the bufferpos for the next write

    Serial.println("TIME," + head); // stamp the header
    
    // Print the sorted buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        Serial.println(buffer[i]);
    }

    Serial.println("**************************filedump ended " + name);
}


