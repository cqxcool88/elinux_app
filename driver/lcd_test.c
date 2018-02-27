#include <unistd.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <linux/fb.h>  
#include <sys/mman.h>  
#include <errno.h>  
  
int main()  
{  
    int fp = 0;  
    struct fb_var_screeninfo   vinfo;  
    struct fb_fix_screeninfo   finfo;  
  
    int screensize = 0;  
    char *fbp = 0;  
    int x = 0, y = 0;  
    int location = 0;  
    int bytes_per_pixel;  
  
    fp = open("/dev/fb0", O_RDWR);  
    if(fp < 0) {  
        printf("open failed\n");  
    }  
  
    if(ioctl(fp, FBIOGET_FSCREENINFO, &finfo)) {  
        perror("ioctl");  
    }  
  
    if(ioctl(fp, FBIOGET_VSCREENINFO, &vinfo)) {  
        perror("ioctl");  
    }  
  
    bytes_per_pixel = vinfo.bits_per_pixel/8;  
    screensize = vinfo.xres * vinfo.yres * bytes_per_pixel;  
    printf("x = %d  y = %d   bytes_per_pixel = %d\n",  vinfo.xres,  vinfo.yres,  bytes_per_pixel);  
    printf("scrrensize = %d\n",  screensize);  
  
    fbp = (char*) mmap(0,  screensize,  PROT_READ |PROT_WRITE,  MAP_SHARED, fp, 0);  
    if(fbp < 0) {  
        perror("mmap");  
    }  
  
    for(x = 100; x<200; x++) {  
        for(y=100; y<200; y++) {  
            location = x * bytes_per_pixel + y * finfo.line_length;  
            *(fbp + location) = 0;  
            *(fbp +location + 1) = 255;  
            *(fbp + location + 2) = 0;  
            *(fbp + location + 3) = 0;  
        }  
    }  
  
    munmap(fbp, screensize);  
    close(fp);  
    return 0;  
}