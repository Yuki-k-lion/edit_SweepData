#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256 // 1行の最大文字数(バイト数)
#define COL 3 //ファイルデータの列数
#define ROW 1001 //ファイルデータの行数
int fileout(char data_array[ROW][COL][N]); /* プロトタイプ宣言 */

int main(void) {
  //宣言
	FILE *fp; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  char single_data[ROW][COL][N];
  // float single_data[ROW][COL];
  char str[N],str1[N],str2[N],str3[N];
  // float f1,f2,f3;
  int file_number,count_file=0;

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
   while (fscanf(fp, "\t%s\t%s\t%s", str1, str2, str3) !=EOF){
     file_number = datacount%1001;
     if (file_number == 1000) {
       count_file += 1;
     }
     printf("%d\n", file_number);
     // if (datacount%1000 == 0){
     // strcpy(single_data[1000][0],str1);
     // strcpy(single_data[1000][1],str2);
     // strcpy(single_data[1000][2],str3);
     // fileout(single_data);
     //
     // } else {
     //  file_number = datacount%1000;
     //   strcpy(single_data[file_number][0],str1);
     //   strcpy(single_data[file_number][1],str2);
     //   strcpy(single_data[file_number][2],str3);
     //     printf("%s,%s,%s\n",str1,str2,str3);
     //     printf("datacount:%d\n",datacount);
     //     printf("\t%s\t%s\t%s\n",
     //       single_data[file_number][0],
     //       single_data[file_number][1],
     //       single_data[file_number][2]);
     // }
      datacount += 1;
   }
   // printf("datacount:%d\n",datacount);
   printf("count_file:%d\n", count_file);
  // int i;
  // for (i = 0; i < datacount; i++) {
  //   printf("Re:datacount:%d\n",i);
  //   printf("debug02:\t%s\t%s\t%s\n",
  //     single_data[i][0],
  //     single_data[i][1],
  //     single_data[i][2]);
  // }
  fclose(fp); // ファイルを閉じる
	return 0;
}


int fileout(char data_out[ROW][COL][N]){
  //処理結果の書き込み。
  FILE *fpw;
  char new_filename[N];
  int datacount;

  for (datacount = 0; datacount <= ROW; datacount++) {
    sprintf(new_filename,"../data/single/%.3s.csv",data_out[1][0]);
    //file open
    printf("debug02:b\t%s\t%s\t%s\n",
      data_out[datacount][0],
      data_out[datacount][1],
      data_out[datacount][2]);
    printf("single_data:%s\n", data_out[datacount][0]);

    fpw = fopen(new_filename,"w");
    printf("new_filename:%s\n", new_filename);
      if (fpw == NULL) {
        printf("%s File can't open.\n",new_filename);
      } else {
        fprintf(fpw, "\t%s\t%s\n", data_out[datacount][1],data_out[datacount][2]);
      }
    }
  fclose(fpw);
  return 0;
}
