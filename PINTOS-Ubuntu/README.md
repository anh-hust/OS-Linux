## Manual Installation Steps:
1. ### Deal with error in make step Ubuntu 20.04
      comment stropts.h library of C in squish-pty.c and squish-unix.c and the relevant function of this library as well
      because Ubuntu 20.04 don't use this library anymore
1. ### Install QEMU Simulator
      ```sudo apt-get install qemu```
1. ### Edit GDBMACROS
      Open pintos/src/utils/pintos-gdb. Make the variable GDBMACROS point to pintos/src/misc/gdb-macros
      i.e. ```GDBMACROS=/home/....../pintos/src/misc/gdb-macros```.
      Note that it should point to the full path.
1. ### Compile Utils directory
      ```
      cd pintos/src/utils
      make
      ```
1. ### Compile Threads directory
     ```
     cd pintos/src/threads
     make
     ```
1. ### Edit pintos
      Open pintos/src/utils/pintos and make the following changes:
      - Line 259: Replace `kernel.bin` with `/home/.../pintos/src/threads/build/kernel.bin`. Note that we're making it point to full path of kernel.bin
1. ### Edit Pintos.pm
      Open pintos/src/utils/Pintos.pm and make the following change:
      - Line 362: Replace `loader.bin` with `/home/.../pintos/src/threads/build/loader.bin`
1. ### Export utils directory path to PATH variable
      Open ~/.bashrc and add this to the last line:
      ```export PATH=/home/.../pintos/src/utils:$PATH```
1. ### Reload terminal with the new environment variables
      ```source ~/.bashrc```
1. ### Run pintos
      ```pintos run alarm-multiple```
      
## Note by myself. Reference:
https://web.stanford.edu/class/cs140/projects/pintos/pintos_1.html
..../src/threads	(for Project 1): source code for base kernel, --modify starting--
..../src/userproc      (for Project 2): source code for user programmer loader, --modify starting--
..../src/vm 		(for Project 3): an almost empty directory, --implement virtual memory in here-- 
..../src/filesys	(for Project 2): source code for basic file system, use this file system  but will not modify it until Project 4
..../src/devices	(for project 1): source code for I/O device interfaceing, --modify the timer implementation-- but no need to change this code

..../src/lib		(): an implementation of a subset for standard C library . The code inside this is compiled into both the Pintos Kernel, from Project 2, user programs that run under it. A little need to modify this code

.../src/lib/kernel	(): Parts of the C library that are included only in the Pintos kernel. This also includes implementations of some data types that you are free to use in your kernel code: bitmaps, doubly linked list and hash tables.

..../src/user		(): Parts of the C library that are included only in Pintos user programs 
..../src/tests		(): tests for each project. Modify this code if it helps you test your submission, replace it with the originals before run the tests 

..../src/examples	(): example user programs for use starting with Project 2
..../src/utils		(): These files may come in handy (useful) if you decide to try working with Pintos on your own machine. Otherwise, you can ignore them.
