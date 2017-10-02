#include "semaphore.cpp"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "A1\n";
  aArrived->Signal();
  bArrived->Wait();
  std::cout <<"A2\n";
}
void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){

  std::cout <<"B1\n";
  bArrived->Signal();
  aArrived->Wait();
  std::cout <<"B2\n";
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
