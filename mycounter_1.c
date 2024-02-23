#include <linux/linkage.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>

asmlinkage long sys_mycounter_1(unsigned long *ct){
	unsigned long temp;
	unsigned long temp2 = copy_from_user(&temp, ct, sizeof(unsigned long));
	if (temp2 == 0){
		printk("Hello world from mycounter1 copy from user\n");
		printk("value ct: %ld\n", ct);
		printk("value temp: %ld\n", temp);
		printk("value temp2: %ld\n", temp2);
		temp++;
	}
	else {
		printk("ct is: %ld\n", ct);
		printk("temp is: %ld\n", temp);
		printk("temp2 is: %ld\n", temp2);
		printk("Did not copied from!\n");
	}
	
	//printk("Hello world from mycounter1\n");
	unsigned long temp3 = copy_to_user(ct, &temp, sizeof(unsigned long));	
	if (temp3 == 0){
	printk("Hello world from mycounter1 copy to user\n");
		printk("value ct: %ld\n", ct);
		printk("value temp: %ld\n", temp);
		printk("mycounter1 is done!\n");
	}
	else {
		printk("ct is: %ld\n", ct);
		printk("temp is: %ld\n", temp);
		printk("temp3 is: %ld\n", temp3);
		printk("Did not copied to user!\n");
	}
	
}
