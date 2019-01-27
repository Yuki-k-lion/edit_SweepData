#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256 // 1行の最大文字数(バイト数)
#define COL 3 //ファイルデータの列数
#define ROW 1001 //ファイルデータの行数
char plotwideTofreq(char data_array[ROW][COL][N],char freq_data[ROW][2],int count_file_num); /* プロトタイプ宣言 */

int main(void) {
  //宣言
	FILE *fp; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  char single_data[ROW][COL][N];
  char str[N],str1[N],str2[N],str3[N];
  int data_number,count_file=0;
  char freq_data[ROW][2]; //解析結果のデータ格納

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
     data_number = datacount%1001;
     if ( data_number == 1000){
       strcpy(single_data[data_number][0],str1);
       strcpy(single_data[data_number][1],str2);
       strcpy(single_data[data_number][2],str3);
       // freq_data = plotwideTofreq(single_data,freq_data,count_file);
       //出てくるべきファイル数のカウント
       count_file += 1;
     } else {
       strcpy(single_data[data_number][0],str1);
       strcpy(single_data[data_number][1],str2);
       strcpy(single_data[data_number][2],str3);
     }
      datacount += 1;
   }
  printf("count_file:%d\n", count_file);
  fclose(fp); // ファイルを閉じる
	return 0;
}

char plotwideTofreq(char plot_data[ROW][COL][N],char data_out[ROW][2], int count_file_num){
  int i,temp_min_int;
  char temp_min[COL][N];
  char *endptr;
  float temp_min_f[ROW][COL];
  int max_f = 55;
  float freq_val;
  //初期化
  // for (i = 0; i < ROW; i++) {
  //     temp_min_f
  // }
  temp_min_int = 2;

  // //最小値の格納
  for (i = 0; i < ROW; i++) {
    freq_val = strtof(plot_data[i][2], &endptr);
    if ((temp_min_int > freq_val ) && (max_f >= freq_val)) {
        temp_min_int = freq_val;
        strcpy(temp_min,plot_data[i]);
    }
  }
  // data_out[count_file_num][0] = temp_min[0];
  // data_out[count_file_num][1] = temp_min[1];
  // return data_out;
  return 0;
}
