/*scheduler_FCFS*/
#include "stdio.h"
#include "unistd.h"
#include "time.h"

int doWork_CPU(int);

struct processStruct{
	int arrivalTime;
	int burstTime;
	int priority;
};
struct processStruct p1, p2, p3;

int main(){
			
	printf("SJF Scheduler Started!\n");
	
	/*setting process attributes*/
	p1.arrivalTime = 0; 
	p1.burstTime = 5;
	p1.priority = 1;

	p2.arrivalTime = 6;
	p2.burstTime = 2;
	p2.priority = 3;

	p3.arrivalTime = 2;
	p3.burstTime = 5;
	p3.priority = 2;
	/*finish setting process attributes*/
	
	
	/*scheduling algorithm starts*/
	int processOrder[3];			
	
	if((p1.burstTime < p2.burstTime) && (p1.burstTime < p3.burstTime)){
		processOrder[0] = 1;
		if(p2.burstTime < p3.burstTime){
			processOrder[1] = 2;	
			processOrder[2] = 3;
		}
		else{
			processOrder[1] = 3;	
			processOrder[2] = 2;
		}
	}
	else if((p2.burstTime < p1.burstTime) &&(p2.burstTime < p3.burstTime)){
		processOrder[0] = 2;
		if(p1.burstTime < p3.burstTime){
			processOrder[1] = 1;	
			processOrder[2] = 3;
		}
		else{
			processOrder[1] = 3;	
			processOrder[2] = 1;
		}
	}
	else
	{
		processOrder[0] = 3;
		if(p1.burstTime < p2.burstTime){
			processOrder[1] = 1;	
			processOrder[2] = 2;
		}
		else{
			processOrder[1] = 2;	
			processOrder[2] = 1;
		}
	}
	/*scheduling algorithm ends*/
	
	/*pritng process order*/
	printf("Process Order:\n");
	for(int i=0; i<3; i++){		
		printf("%d. P%d\n", i+1, processOrder[i]);
	}
	/*End printing*/
	
	/*Finsih scheduling algorithm*/
		
	/*common part for job execution*/
	printf("scheduler_SJF: Starting work loop\n");			
	
	if(processOrder[0]==1){
		doWork_CPU(p1.burstTime);
		if(processOrder[1]==2){
			doWork_CPU(p2.burstTime);	
			doWork_CPU(p3.burstTime);	
		}else{
			doWork_CPU(p3.burstTime);	
			doWork_CPU(p2.burstTime);		
		}						
	}
	else if(processOrder[0]==2){					
		doWork_CPU(p2.burstTime);
		if(processOrder[1]==1){
			doWork_CPU(p1.burstTime);	
			doWork_CPU(p3.burstTime);	
		}else{
			doWork_CPU(p3.burstTime);	
			doWork_CPU(p1.burstTime);	
		}
	}
	else{					
		doWork_CPU(p3.burstTime);
		if(processOrder[1]==2){
			doWork_CPU(p2.burstTime);	
			doWork_CPU(p1.burstTime);	
		}else{
			doWork_CPU(p1.burstTime);	
			doWork_CPU(p2.burstTime);	
		}
	}			
	
	printf("scheduler_SJF: End of work loop\n");

	printf("SJF Scheduler Ends!\n");
	return 0;
}

/*function for cpu work done*/
int doWork_CPU(int burstT)
{
	int count=0;
	time_t start, end;
	double elapsed;  // seconds
	start = time(NULL);
	int terminate = 1;
	while (terminate) {
		end = time(NULL);
		elapsed = difftime(end, start);
		if (elapsed >= burstT /* seconds */)
			terminate = 0;
		else  //make use of the CPU
		{			
			if(count == 10000)
				count = 0;
			count++;		
		}
	}	
	return 0;
}
