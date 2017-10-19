#include "semaphore.cpp"
#include <iostream>
#include <thread>

/*! 
Author: Ryan Donoghue
Date created: 10/02/17


\class signal
\brief A Mutual Exclusion Implementation using Semamphores

Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

int count = 0;

/**< First Task, locks mutex and increments count, unlocks mutex  */
void taskOne(std::shared_ptr<Semaphore> mtx){

  std::cout << "Task one reached critical section\n";  
  
  mtx->Signal();

	  /**< Critical Section  */

	  std::cout << "Task one is incrementing count\n";
	  count += 1;

  mtx->Wait();
  
  
}

/**< Second Task, locks mutex and increments count, unlocks mutex  */
void taskTwo(std::shared_ptr<Semaphore> mtx){

  std::cout << "Task two reached critical section\n";
  
  mtx->Signal();

	  /**< Critical Section  */

	  std::cout << "Task two is incrementing count\n";
	  count += 1;

  mtx->Wait();
  
  
}

int main(void){

  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mtx( new Semaphore);

  /**< Launch the threads  */

  threadOne=std::thread(taskTwo,mtx);
  threadTwo=std::thread(taskOne,mtx);

  std::cout << "Launched from the main\n";

  threadOne.join(); 
  threadTwo.join();

  std::cout << count;

  return 0;
}
