#include <linux/linkage.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/unistd.h>
#include "../include/linux/stat.h"
#include "../include/linux/types.h"
#include "../include/linux/fcntl.h"
#include <trace/syscall.h>
#include "../include/linux/proc_fs.h"
#include "../include/linux/fcntl.h"
#include "../include/linux/vmalloc.h"
#include "../include/linux/stat.h"
#include <linux/syscalls.h>



asmlinkage long sys_mycounter_2(unsigned long *ct) {
  int fd, bytes_read;
  unsigned long temp;
  char c;   
  mm_segment_t old_fs = get_fs();
  set_fs(KERNEL_DS);
  fd = sys_open("/proc/mydev", O_RDONLY, 0);

  if (IS_ERR(&fd))
    printk(KERN_INFO "Error from open\n");

  bytes_read = sys_read(fd, &c, 1);
  printk(KERN_INFO "Bytes read from syscall %d\n", bytes_read);
  printk(KERN_INFO "C: %c\n", c);
  sys_close(fd);
  set_fs(old_fs);

  if (bytes_read != 1){
	return -2;  
  }
  if (copy_from_user(&temp, ct, sizeof(unsigned long))){
	return -3;  
  }
  if (c == '0'){
	temp++;  
  }
  else if (c == '1') {
	temp *= 2;  
  }
    
  else {
	return -4;  
  } 
  
  if (copy_to_user(ct, &temp, sizeof(unsigned long))){
	return -5;  
  }
  return 0;
}
