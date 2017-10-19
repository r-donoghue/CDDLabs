	#include "semaphore.cpp"
	#include <iostream>
	#include <thread>

	/*! 
	Author: Ryan Donoghue
	Date created: 10/02/17


	\class barrier
	\brief A 2-Phase Barrier Implementation using Semamphores

	Uses C++11 features such as mutex and condition variables to 		implement Semaphore

	*/

	int main(void){

	  std::shared_ptr<Semaphore> barrier( new Semaphore);
	  std::shared_ptr<Semaphore> turnstile( new Semaphore);
	  std::shared_ptr<Semaphore> turnstile2( new Semaphore);
	  int count = 0;
	  int n = 6;
	  /**< Launch the threads  */


	  barrier->Signal();
	  count += 1;
	  if (count == n){
		  turnstile2->Signal();
		  turnstile->Wait();
	  }
	  barrier->Wait();

	  turnstile->Signal();
	  turnstile->Wait();

	  barrier->Signal();
	  count -= 1;
	  if (count == 0){
	  	turnstile->Signal();
	  	turnstile2->Wait();
	  }
	  barrier->Wait();

	  turnstile2->Signal();
	  turnstile2->Wait();

	  return 0;
	}
