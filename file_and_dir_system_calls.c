#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    int fd;
    
    fd=open("ostest.txt", O_CREAT|O_WRONLY, 0777);
    write(fd, "hey there", 9);
    close(fd);
    
    int buf[20];
    fd = open("ostest.txt", O_RDONLY);
    read(fd, buf,15);
    printf("Content: %s", buf);
    
    lseek(fd, 5, SEEK_SET);
    read(fd, buf, 3);
    buf[3]='\0';
    printf("After seek %s", buf);
    close(fd);
    
    struct stat s;
    stat("test.txt",&s);
    printf("File size %d", s.st_size);
    
    DIR *d; 
    struct dirent *dir;
    d=opendir(".");
    printf("Directory files: ");
    while((dir=readdir(d))!=NULL)
        printf("%s \n", dir->d_name);
    closedir(d);
   
    
    
}

/* o.p:
File content: Hello OS Lab

After lseek: OS
File size: 13 bytes

Directory files:
.
..
test.txt
a.out*/
