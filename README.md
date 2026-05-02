# xv6 System Call Tracing Project

## Description
This project implements a system call tracing feature in xv6 using a new system call:
trace(int mask).

When tracing is enabled, the kernel prints:
- Process ID
- System call name
- Return value

## How It Works
Each process has a trace mask. When a syscall is executed, the kernel checks if the syscall's bit is enabled in the mask. If it is, the syscall information is printed.

## Modified Files
- proc.h / proc.c → added tracemask field
- syscall.h → added SYS_trace
- syscall.c → added tracing logic
- sysproc.c → implemented sys_trace
- user.h / usys.S → added user-level syscall access
- Makefile → added test program

## How to Run

```bash
make clean
make qemu

## Then in xv6:
tracetest

# Example output
5: syscall write -> 23
6: syscall write -> 23

## Testing
- Basic syscall tracing using write()
- Fork inheritance test (child processes inherit trace mask)
- Stress test using multiple forked processes
