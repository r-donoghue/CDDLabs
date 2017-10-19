#include "semaphore.cpp"
#include <iostream>
#include <thread>

/*! 
Author: Ryan Donoghue
Date created: 10/02/17


\class signal
\brief A Rendezvous Implementation using Semaphores

Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

/**< First Task  */
void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "A1 Signal\n";
  aArrived->Signal();
  bArrived->Wait();
  std::cout <<"A2 Signal\n";
}
/**< Second Task  */
void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){

  std::cout <<"B1 Signal\n";
  bArrived->Signal();
  aArrived->Wait();
  std::cout <<"B2 Signal\n";
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> aArrived( new Semaphore);
  std::shared_ptr<Semaphore> bArrived( new Semaphore);

  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,aArrived,bArrived);
  threadTwo=std::thread(taskOne,aArrived,bArrived);

  std::cout << "Launched from the main\n";

  threadOne.join();
  threadTwo.join(); 
  return 0;
}
