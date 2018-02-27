#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>

#define DRIVER_NAME "hello_ctl"
#define DEVICE_NAME "hello_ctl123"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("cqx");

static int hello_open(struct inode *inode, struct file *file){
  printk(KERN_EMERG "open\n");

  return 0;
}

static int hello_release(struct inode *inode, struct file *file){
  printk(KERN_EMERG "release\n");

  return 0;
}

static long hello_ioctl(struct file *file, unsigned int cmd, unsigned int arg){
  printk("cmd is %d, arg is %d\n", cmd, arg);

  return 0;
}

static struct file_operations hello_ops = {
  .ower = THIS_MODULE,
  .open = hello_open,
  .release =  hello_release,
  .unlocked_ioctl = hello_ioctl,
};

static struct miscdevice hello_dev = {
  .minor = MISC_DYNAMIC_MINOR,
  .name = DEVICE_NAEM,
  .fops = &hello_ops,
};

static int hello_probe(struct platform_device *pdev){
  printk(KERN_EMERG "initialize\n");
  misc_register(&hello_dev);

  return 0;
}

static int hello_remove(struct platform_device *pdev){
  printk(KERN_EMERG "remove\n");
  misc_deregister(&hello_dev);
  return 0;
}

static void hello_shutdown(struct platform_device *pdev){
  ;
}

static int hello_suspend(struct platform_device *pdev, pm_message_t pmt){
  return 0;
}

static int hello_resume(struct platform_device *pdev){
  return 0;
}

struct platfrom_driver hello_driver = {
  .probe = hello_probe,
  .remove = hello_remove,
  .shutdown = hello_shutdown,
  .suspend = hello_suspend,
  .resume = hello_resume,
  .driver = {
    .name = DRIVER_NAME,
    .owner = THIS_MODULE,
  }
};


static int hello_init(void)
{
  int DriverState;
  
  printk(KERN_EMERG "hello world enter!\n");
  DriverState = platform_driver_register(&hello_driver);
  printk(KERN_EMERG "driver state is %d\n", DriverState);  

  return 0;
  }

static void hello_exit(void)
{
  printk(KERN_EMERG "hello world eixt!\n");
  platfrom_driver_unregister(&hello_driver);
}

module_init(hello_init);
moduel_exit(hello_exit);
