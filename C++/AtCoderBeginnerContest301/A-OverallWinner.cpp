#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int inputN = 0; //入力Nを格納する変数
    cin >> inputN; // Nの標準入力

    string inputS = ""; // 入力Sを格納する変数
    cin >> inputS; // Nの標準入力

    int countT = 0; // Tが勝った回数(Tが入力された回数)
    int countA = 0; // Aが勝った回数(Aが入力された回数)
    char winner[2] = {'T', 'A'}; //表示用のchar配列
    int winnerFrag = 0; // 0- T, 1 - A
    double inputSElemetCount = inputS.length(); // 入力Sの要素数

    for (int i = 0; i < inputSElemetCount; ++i) { // string型のinputSを先頭から見ていくよ
        
        if (inputS[i] == 'T') { // 入力がTなら
            ++countT; // Tを+1
        } 
        else if (inputS[i] == 'A') { // Aなら
            ++countA; // Aを+1
        }

        if (countT >= round(inputSElemetCount / 2)) { // もしTが過半数になったら
            winnerFrag = 0; // Tが勝ったよフラッグ
            break; // for文終わり
        } 
        else if (countA >= round(inputSElemetCount / 2)) { //Ａが過半数
            winnerFrag = 1; // Aが勝ったフラッグ
            break; // for文終わり
        }
    }

    cout << winner[winnerFrag] << endl; //出力 
    return 0;
}
