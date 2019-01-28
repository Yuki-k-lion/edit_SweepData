#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256 // 1行の最大文字数(バイト数)
#define COL 3 //ファイルデータの列数
#define ROW 1001 //ファイルデータの行数

/* プロトタイプ宣言 */
int plotwideTofreq(char data_array[ROW][COL][N],char *freq_data[ROW][2],int count_file_num);
int fileout(char *data_out[ROW][2]);

int main(void) {
  //宣言
	FILE *fp; // FILE型構造体
	char file_name[] = "../data/sweep_saf_w_edit.txt";
  char single_data[ROW][COL][N];
  char str[N],str1[N],str2[N],str3[N];
  int data_number,count_file=0;
  char *freq_data[ROW][2]; //解析結果のデータ格納

  //初期化
  int i,j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < 2; j++) {
      freq_data[i][j] = "";
    }
  }

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

       plotwideTofreq(single_data,freq_data,count_file);
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

int plotwideTofreq(char plot_data[ROW][COL][N],char *data_out[ROW][2], int count_file_num){
  int i,temp_min_data;
  char *endptr;
  float temp_min_f[ROW][COL];
  int max_f = 55;
  float freq_val,temp_min_int,temp_f;
  temp_min_int = 2;

  // //最小値の格納
  for (i = 0; i < ROW; i++) {
    freq_val = strtof(plot_data[i][2], &endptr);
    temp_f = strtof(plot_data[i][1],&endptr);
    if ((temp_min_int > freq_val ) && (max_f >= temp_f)) {
        temp_min_int = freq_val;
        temp_min_data = i;
        printf("temp_min_data:%d\n",temp_min_data );
        printf("freq_val:%f\n",freq_val );
        printf("temp_min_int:%f\n",temp_min_int );
    }
  }
  printf("data_out[count_file_num][0] :%s\n",data_out[count_file_num][0] );
  printf("data_out[count_file_num][1] :%s\n",data_out[count_file_num][1] );
  printf("plot_data[temp_min_data][0] :%s\n",plot_data[temp_min_data][0] );
  printf("plot_data[temp_min_data][1] :%s\n",plot_data[temp_min_data][1] );

  strcpy(data_out[count_file_num][0],plot_data[temp_min_data][0]);
  strcpy(data_out[count_file_num][1],plot_data[temp_min_data][1]);

  printf("data_out[count_file_num][0]:%s\n",data_out[count_file_num][0] );
  // fileout(data_out);
  return 0;
}

int fileout(char *data_out[ROW][2]){
  //処理結果の書き込み。
  FILE *fpw;
  char new_filename[N];
  int datacount;
  //create new file
  sprintf(new_filename,"../data/plotFreqData/sweep.csv");
  fpw = fopen(new_filename,"w");
    if (fpw == NULL) {
      printf("%s File can't open.\n",new_filename);
    } else {
      for (datacount = 0; datacount <= ROW; datacount++) {
        fprintf(fpw, "\t%s\t%s\n", data_out[datacount][0],data_out[datacount][1]);
      }
    }
  fclose(fpw);
  return 0;
}
