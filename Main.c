#include <vxWorks.h>
#include <stdio.h>
#include <taskLib.h>
#include <sysLib.h>
#include <msgQLib.h>
#include <semMLib.h>

/* Constants */
#define MSG_Q_MAX_LENGTH 20
#define MSG_SIZE 10
/* elements needed */
FILE *shared_file;
MSG_Q_ID msgQ;
SEM_ID mutex;

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