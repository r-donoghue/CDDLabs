#include "semaphore.cpp"
#include <iostream>
#include <thread>

 int count = 0;

void taskOne(std::shared_ptr<Semaphore> a, std::shared_ptr<Semaphore> b){
  b->Signal();
  count += 1;
  b->Wait();
  a->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> a, std::shared_ptr<Semaphore> b){
  a->Wait();
  b->Signal();
  count += 1;
  b->Wait();
}

int main(void){

  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> a( new Semaphore);
  std::shared_ptr<Semaphore> b( new Semaphore);
  

 

  /**< Launch the threads  */

  threadOne=std::thread(taskTwo,a,b);
  threadTwo=std::thread(taskOne,a,b);

  std::cout << "Launched from the main\n";

  threadOne.join(); 
  threadTwo.join();

  std::cout << count;

  return 0;
}
