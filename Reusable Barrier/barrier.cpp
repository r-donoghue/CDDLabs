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
	  /**< Launch the threads  */


	  barrier.wait ()
	  count += 1
	  if count == n:
		  turnstile2.wait ()
		  turnstile.signal ()
	  barrier.signal ()

	  turnstile.wait () # first turnstile
	  turnstile.signal ()

	  barrier.wait ()
	  count -= 1
	  if count == 0:
	  	turnstile.wait ()
	  	turnstile2.signal ()
	  barrier.signal ()

	  turnstile2.wait ()
	  turnstile2.signal ()

	  return 0;
	}
