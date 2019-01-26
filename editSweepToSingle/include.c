// #include <stdio.h>
// int main(void) {
//
//   return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#define N 256 // 1行の最大文字数(バイト数)
//https://www.sejuku.net/blog/25927

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

  //一文字ずつ読み込み。fgetc関数は引数にFILE型構造体の実体のアドレスをとる
  // while((chr = fgetc(fp)) != EOF) {
	// 	putchar(chr);
	// }
  /*
  fgets関数の第1引数には1行分の文字列を格納する配列、
  第2引数には1行の最大文字数を入力、
  第3引数にFILE型構造体の実体のアドレス。
  */
  // while(fgets(str, N, fp) != NULL) {
  //   printf("%s", str);
  // }
 int i = 0;
  while (fscanf(fp, "\t%s\t%s\t%s", str1, str2, str3) !=EOF) {
    i += 1;
    if (i <= 10) {
      printf("%s,%s,%s\n",str1,str2,str3);
    }
  }
	fclose(fp); // ファイルを閉じる
  // if ((fp = fopen(file_name, "r")) != NULL) {
  // /* 1行空読み */
  // fgets(str, sizeof(str), fp);
  // /* ２行目を読み込み */
  // if (fgets(str, sizeof(str), fp))
  // printf("%s", str);
  //
  // fclose(fp);
  // }


	//C++でしか使えないので以下のerror_t型は使用できない。
  // C11で導入　VisualC++2012以降ではこちらのみ使用可能
	// errno_t err; // errno_t型(int型)
	// err = fopen_s(&fp, file_name, "r"); // ファイルを開く。失敗するとエラーコードを返す。
	// if(err != 0) {
	// 	printf("%s file not open!\n", file_name);
	// 	return err;
	// } else {
	// 	printf("%s file opened!\n", file_name);
	// }
  //
	// fclose(fp); // ファイルを閉じる

	return 0;
}
