// #include <stdio.h>
// int main(void) {
//
//   return 0;
// }
#include <stdio.h>

int main(void) {
	FILE *fp; // FILE型構造体
	char file_name[] = "data/sweep_saf_w.txt";

	fp = fopen(file_name, "r"); // ファイルを開く。失敗するとNULLを返す。
	if(fp == NULL) {
		printf("%s file not open!\n", file_name);
		return -1;
	} else {
		printf("%s file opened!\n", file_name);
	}

	fclose(fp); // ファイルを閉じる

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
