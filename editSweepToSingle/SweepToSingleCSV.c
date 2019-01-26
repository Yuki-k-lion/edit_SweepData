#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256 // 1行の最大文字数(バイト数)
#define COL 3 //ファイルデータの列数
#define ROW 1001 //ファイルデータの行数

int main(void) {
  //宣言
	FILE *fp,*fpw; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  char new_filename[N],single_data[ROW][COL][N];
  // float single_data[ROW][COL];
  char str[N],str1[N],str2[N],str3[N];
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
   while (fscanf(fp, "\t%s\t%s\t%s", str1, str2, str3) !=EOF) {

     if (datacount <= 10) {
       strcpy(single_data[datacount][0],str1);
       strcpy(single_data[datacount][1],str2);
       strcpy(single_data[datacount][2],str3);
       // single_data[datacount][0] = str1;
       // single_data[datacount][1] = str2;
       // single_data[datacount][2] = str3;
       printf("%s,%s,%s\n",str1,str2,str3);
       printf("datacount\n");
       printf("\t%s\t%s\t%s\n",
         single_data[datacount][0],
         single_data[datacount][1],
         single_data[datacount][2]);
     }
     datacount += 1;
   }
	fclose(fp); // ファイルを閉じる

  // printf("wright: %s\n", single_data[0][0]);

  //うまくいかない
  //処理結果の書き込み。
  for (datacount = 0; datacount <= ROW; datacount++) {
    sprintf(new_filename,"../data/single/%d.csv",datacount);
    //file open
    printf("single_data:%s\n", single_data[datacount][0]);
    fpw = fopen(new_filename,"w");
    printf("new_filename:%s\n", new_filename);
      if (fp == NULL) {
        printf("%s File can't open.\n",new_filename);
      } else {
        fprintf(fpw, "\t%s\t%s\n", single_data[datacount][1],single_data[datacount][2]);
      }
    }
  fclose(fpw);
	return 0;
}
