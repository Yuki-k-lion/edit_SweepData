#include <stdio.h>
#include <stdlib.h>
#define N 256 // 1行の最大文字数(バイト数)

int main(void) {
	FILE *fp; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  int chr;
  char str[N],str1[N],str2[N],str3[N];
  float f1,f2,f3;

	fp = fopen(file_name, "r"); // ファイルを開く。失敗するとNULLを返す。

	if(fp == NULL) {
		printf("%s file not open!\n", file_name);
		return -1;
	} else {
		printf("%s file opened!\n", file_name);
	}
 int i = 0;
  while (fscanf(fp, "\t%s\t%s\t%s", str1, str2, str3) !=EOF) {
    i += 1;
    if (i <= 10) {
      printf("%s,%s,%s\n",str1,str2,str3);
    }
  }
	fclose(fp); // ファイルを閉じる
	return 0;
}
