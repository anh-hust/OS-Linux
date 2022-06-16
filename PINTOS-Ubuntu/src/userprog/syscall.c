#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler(struct intr_frame *);

void syscall_init(void)
{
  intr_register_int(0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler(struct intr_frame *f UNUSED)
{
  printf("system call!\n");
  /* Additional code by student */
  switch (*(uint32_t *)(f->esp))
  {
  case SYS_EXIT:
    exit(*(uint32_t *)(f->esp + 20));
    break;
  }
  /* End */
}

/* Additional code by student */
void exit (int status){
    printf("\n%s: exit(%d)\n\n", thread_name(), status);
    thread_exit ();
}
/* End */