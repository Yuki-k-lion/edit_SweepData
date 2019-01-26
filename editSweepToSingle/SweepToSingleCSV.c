#include <stdio.h>
#include <stdlib.h>
#define N 256 // 1行の最大文字数(バイト数)
#define COL 3 //ファイルデータの列数
#define ROW 1001 //ファイルデータの行数

int main(void) {
  //宣言
	FILE *fp; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  char new_filename[N],single_data[ROW][COL];
  // float single_data[ROW][COL];
  // char str[N],str1[N],str2[N],str3[N];
  // float f1,f2,f3;

	fp = fopen(file_name, "r"); // ファイルを開く。失敗するとNULLを返す。

  //ファイルがひらけたかどうかの確認
	if(fp == NULL) {
		printf("%s file not open!\n", file_name);
		return -1;
	} else {
		printf("%s file opened!\n", file_name);
	}

  //ファイルの中身を取り出して表示
 int datacount = 0;
  while (fscanf(fp, "\t%s\t%s\t%s", &single_data[datacount][0], &single_data[datacount][1], &single_data[datacount][2]) !=EOF) {
    datacount += 1;
    if (datacount <= 10) {
      printf("%s,%s,%s\n",single_data[datacount][0], single_data[datacount][1], single_data[datacount][2]);
    }
  }
	fclose(fp); // ファイルを閉じる
	return 0;
}
