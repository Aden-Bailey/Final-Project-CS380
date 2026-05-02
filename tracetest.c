#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
  printf(1, "Starting syscall trace test\n");

  trace(1 << SYS_write);
  write(1, "This write should be traced\n", 28);

  printf(1, "Testing fork inheritance\n");
  if(fork() == 0){
    write(1, "Child write should be traced\n", 29);
    exit();
  }

  wait();
  printf(1, "Trace test complete\n");

  // stress test
  printf(1, "Running stress test\n");

  for(int i = 0; i < 5; i++){
    if(fork() == 0){
      write(1, "Child process writing\n", 23);
      exit();
    }
  }

  for(int i = 0; i < 5; i++){
    wait();
  }

  printf(1, "Stress test complete\n");

  exit();
}
