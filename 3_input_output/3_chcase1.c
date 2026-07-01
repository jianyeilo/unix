#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void chcase(FILE *fin, FILE *fout)
{
  int c;

  while ((c = getc(fin)) != EOF){
    if (isupper(c)){
      putc(tolower(c), fout);
    } else {
      putc(toupper(c), fout);
    }
  }
}
/*comand引数*/
int main(int argc, char *argv[])/*.argcとはcomand引数  argc引数の個数、argv Pointer of list　*/
{
  FILE *fin, *fout;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s infile outfile\n", argv[0]);
    exit(1);
  }
  if ((fin = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open: %s\n", argv[1]);
    exit(1);
  }
  if ((fout = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Can't open: %s\n", argv[2]);
    exit(1);
  }

  chcase(fin, fout);

  fclose(fin);
  fclose(fout);
  exit(0);
}

/*
 * chcase1.c
 *
 * 機能：
 *   入力ファイルの内容を1文字ずつ読み込み、
 *   大文字⇔小文字を変換して出力ファイルへ書き込む。
 *
 * 処理の流れ：
 *   1. コマンドライン引数から
 *        argv[1] : 入力ファイル名
 *        argv[2] : 出力ファイル名
 *      を受け取る。
 *
 *   2. fopen()で入力・出力ファイルを開く。
 *
 *   3. chcase()で
 *        getc(fin)     : 入力ファイルから1文字読む
 *        isupper(c)    : 大文字か判定
 *        tolower()     : 小文字へ変換
 *        toupper()     : 大文字へ変換
 *        putc(...,fout): 出力ファイルへ1文字書く
 *      をEOFまで繰り返す。
 *
 *   4. fclose()でファイルを閉じて終了する。
 *
 * UNIXの考え方：
 *   入力ファイル
 *        ↓
 *      FILE *fin
 *        ↓
 *      getc()
 *        ↓
 *      文字変換
 *        ↓
 *      putc()
 *        ↓
 *      FILE *fout
 *        ↓
 *     出力ファイル
 *
 * ポイント：
 *   ・FILE* はファイルを操作するストリーム（窓口）
 *   ・getc() は1文字ずつ読む
 *   ・putc() は1文字ずつ書く
 *   ・EOFになったら処理終了
 *   ・argv[] はコマンドライン引数の文字列配列
 */
