	#include "semaphore.cpp"
	#include <iostream>
	#include <thread>
	#include <chrono>
#include <time.h> 
#include <unistd.h>

	/*! 
	Author: Ryan Donoghue
	Date created: 10/02/17


	\class mtx
	\brief A 2-Phase Barrier Implementation using Semamphores

	Uses C++11 features such as mutex and condition variables to 		implement Semaphore

	*/
	int prodPos = 0;
	int consPos = 0;
	int buffer[20];
	int c;
	int bufferFull = false;
	
	void addToBuffer(char c)
	{
		buffer[prodPos] = c;
    	std::cout << c << "\n";
	}
	void producer(){
		
		/*if(prodPos < 20 && bufferFull == false)
		{
			c = (char)((rand() % 26)+97);
			addToBuffer(c);
		}
		else
		{
			c = 'X';
			bufferFull = true;
		}
    	c = (char)((rand() % 26)+97);
		buffer[prodPos] = c;
    	std::cout << c << "\n";
		usleep(randTimeInterval(0,1));
		
		
		spaces->Wait();

		mutex->Wait();
			buffer[prodPos] = c;
			++prodPos;
		mutex->Signal();

		items->Signal();*/
	}

	void consumer(){
		while(
		items.wait();
		spaces->Wait();
		mutex->Wait();
		mutex->Signal();
		spaces->Signa;
	}

	double randTimeInterval(double fMin, double fMax)
	{
		double f = (double)rand() / RAND_MAX;
		return (fMin + f * (fMax - fMin)) *1000000;
	}
	int main(void){

	std::thread t1,t2,t3,t4,t5,t6;
	std::shared_ptr<Semaphore> spaces( new Semaphore(0));
	std::shared_ptr<Semaphore> mutex( new Semaphore(0));
	std::shared_ptr<Semaphore> items( new Semaphore(0));
	
	int n = 6;
	  
	/**< Creating threads and tasks  */
/* 	t1=std::thread(task,barrierA,barrierB,mtx,"Thread 1");
	t2=std::thread(task,barrierA,barrierB,mtx,"Thread 2");

/**< Running threads  */
/* t1.join();
	t2.join();*/
	int buffer[20];
	int x = 0;
	while(x < 20)
	{
		int n = rand() % 26;
    	char c = (char)(n+97);
		buffer[x] = c;
    	std::cout << c << "\n";
		usleep(randTimeInterval(0,1));
		
		++x;
	}
	return 0;
	}
