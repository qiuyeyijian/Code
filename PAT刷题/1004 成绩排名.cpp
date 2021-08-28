#include <stdio.h>
#include <string.h>

struct Student {  // 定义学生结构体
  char name[12];
  char id[12];
  int score;
} maxS, minS, tempS;

int main() {
  int n;
  scanf("%d", &n);
  maxS.score = 0;  // 初始化
  minS.score = 1000;

  while (n--) {
    scanf("%s %s %d", tempS.name, tempS.id, &tempS.score);
    if (tempS.score > maxS.score) {
      strcpy(maxS.name, tempS.name);
      strcpy(maxS.id, tempS.id);
      maxS.score = tempS.score;
    }
    if (tempS.score < minS.score) {
      strcpy(minS.name, tempS.name);
      strcpy(minS.id, tempS.id);
      minS.score = tempS.score;
    }
  }

  printf("%s %s\n", maxS.name, maxS.id);
  printf("%s %s", minS.name, minS.id);

  return 0;
}