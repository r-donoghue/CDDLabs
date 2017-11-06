	#include "semaphore.cpp"
	#include <iostream>
	#include <thread>

	/*! 
	Author: Ryan Donoghue
	Date created: 10/02/17


	\class mtx
	\brief A 2-Phase Barrier Implementation using Semamphores

	Uses C++11 features such as mutex and condition variables to 		implement Semaphore

	*/
	int count = 0;
	int loop = 0;
	std::shared_ptr<Semaphore> mtx( new Semaphore(1));
	std::shared_ptr<Semaphore> barrierA( new Semaphore(0));
	std::shared_ptr<Semaphore> barrierB( new Semaphore(1));

	void setupBarrier(int n
	void task(std::shared_ptr<Semaphore> barrierA, std::shared_ptr<Semaphore> barrierB, std::shared_ptr<Semaphore> mtx, std::string name ){

		int n = 6;
		while(loop <= 2){
		/**< Threads enter until count equals number of threads  */
		mtx->Wait();
		  
		/**< Critical Section  */

		std::cout << name << " arrived. Count is " << count << ".\n";
		count ++;
		std::cout << name << " incremented count. Count is now " << count << ".\n";

		if (count == 6){
			std::cout << "Last thread entered, opening barrier.\n";
			barrierB->Wait();
			barrierA->Signal();
		}

	  	mtx->Signal();

		
	  	barrierA->Wait();
	  	barrierA->Signal();

	  	/**< Threads exit, decrementing count until == 0  */
	  	mtx->Wait();

		/**< Critical Section  */

		std::cout << name << " exiting.Count is " << count << ".\n";
		count--;
		std::cout << name << " decremented count.\n";

		if (count == 0){
			std::cout << "Last thread exited,ending. \n";
		  	barrierA->Wait();
			loop++;
		  	barrierB->Signal();
		}

	  	mtx->Signal();

	  	barrierB->Wait();
	  	barrierB->Signal();
      }
	}
	
	int main(void){

	  std::thread t1,t2,t3,t4,t5,t6;
	  
	  
	  int n = 6;
	  
	  /**< Creating threads and tasks  */
	  t1=std::thread(task,barrierA,barrierB,mtx,"Thread 1");
	  t2=std::thread(task,barrierA,barrierB,mtx,"Thread 2");
	  t3=std::thread(task,barrierA,barrierB,mtx,"Thread 3");
	  t4=std::thread(task,barrierA,barrierB,mtx,"Thread 4");
	  t5=std::thread(task,barrierA,barrierB,mtx,"Thread 5");
	  t6=std::thread(task,barrierA,barrierB,mtx,"Thread 6");

	  /**< Running threads  */
	  t1.join();
	  t2.join();
	  t3.join();
	  t4.join();
	  t5.join();
	  t6.join();

	  return 0;
	}
