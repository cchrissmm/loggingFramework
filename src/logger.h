#ifndef LOGGER_H
#define LOGGER_H

class logger {

public:
static const int BUFFER_SIZE = 1000; //maximum number of entries for the log file, after this it ringbuffers 

logger(String head);     //construct an instance of logger passing it the filename 
void data(String data); //write some data
void read(); //dump the contents of the file to serial

private:
String filename;
String head;
int filesize;
String buffer[BUFFER_SIZE];
int bufferPos;
};

#endif