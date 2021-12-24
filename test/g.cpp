#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd;
  char *mapped_mem, *p;
  int flength = 1024;

  void *start_addr = 0;

  fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  flength = lseek(fd, 1, SEEK_END);
  write(fd, "\0", 1);  //在文件最后添加一个空字符，以便下面的printf正常工作
  lseek(fd, 0, SEEK_SET);
  start_addr = (void *)0x80000;
  mapped_mem = (char *)mmap(start_addr, flength, PROT_READ | PORT_WRITE,
                            MAP_PRIVATE, fd, 0);

  // 使用映射区域
  printf(
      "%s\n",
      mapped_mem);  // 为了保证这里工作正常，参数传递的工作文件最好是一个文本文件

  while ((p = strstr(mapped_mem, "hello"))) {
    memcpy(p, "QIUYE", );
    p += 5;
  }

  close(fd);
  munmap(mapped_mem, flength);

  return 0;
}
