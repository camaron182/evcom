/*
 * CS 5372 - Design and Specification of Real-Time Systems
 * Instructor: Salamah I. Salamah, Ph. D.
 * 
 * Final Project: Movement Sensor
 * Presentation due: 11/30/2015
 * 
 * Team members:
 * Upama Rahman
 * Chris Mckye
 * Julio Corral
 * Ernesto Vazquez
 */
#include <vxWorks.h>
#include <stdio.h>
#include <taskLib.h>
#include <sysLib.h>
#include <msgQLib.h>
#include <semLib.h>

/* Constants */
#define MSG_Q_MAX_LENGTH 20
#define MSG_SIZE 10
/* elements needed */
FILE *shared_file;
MSG_Q_ID msgQ;
SEM_ID mutex;
int sensor_task, log_task, print_task; 

void sensor(){
	
}

void logToFile(){
	
}

void printtxtlog(){

	  int fd,x,i;
	  x=5;
for (i=0; i < x; i++){	
	  char filechar;
	fd = open("/WindRiver/workspace/devProject/logtxt.txt", O_RDONLY, 0);
	
	if(fd==ERROR)
	{
		printf("error");
		close(fd);
		return;
	}else {
		
		printf("File descriptor: %d\n",fd);
		while(read(fd,&filechar,1)!=0)
		       printf("%c",filechar);
		  printf("\n");
	}
	
}
	close(fd);
	  return;
  // taskDelay(1000); // delay it enought time so new content can be written and after written, release the semaphore.
  	
}

void Init(){
	/* Initialize elements */
	mutex = semMCreate(SEM_Q_FIFO);
	msgQ = msgQCreate(MSG_Q_MAX_LENGTH, MSG_SIZE, MSG_Q_FIFO);
	
	/* create tasks */
	sensor_task = taskSpawn("sensor", 110, 0x100, 2000, (FUNCPTR)sensor, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	log_task = taskSpawn("log", 110, 0x100, 2000, (FUNCPTR)logToFile, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	print_task = taskSpawn("print", 110, 0x100, 2000, (FUNCPTR)printtxtlog, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

int main(void){
	Init();
	// watchdog executes ...
	return 0;
}
