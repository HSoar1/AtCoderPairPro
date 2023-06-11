#include <iostream>
#include <string>

using namespace std;

int main(){
    int str[27][3] = {};
    int atCoder[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

    for(int i = 0; i < 27; ++i){
        if(i == 26){
            str[i][0] = '@';
            str[i][1] = 0; 
            str[i][2] = 0;
        }
        else{
            str[i][0] = 'a' + i;
            str[i][1] = 0; 
            str[i][2] = 0; 
        }
    }

    string S = "";
    string T = "";
    
     cin >> S;
     cin >> T;
    
    for(int i = 0; i < S.length(); ++i){
        for(int j = 0; j < 27; ++j){
            if(str[j][0] == S[i]){
                ++str[j][1];
            }
        }
    }

    for(int i = 0; i < T.length(); ++i){
        for(int j = 0; j < 27; ++j){
            if(str[j][0] == T[i]){
                ++str[j][2];
            }
        }
    }
    int atmarkS = str[26][1];
    int atmarkT = str[26][2];
    bool frag = true;

    for(int i = 0; i < 26; ++i){
        if(str[i][1] != str[i][2]){
            for(int j = 0; j < 7; ++j){
                if(atCoder[j] != str[i][0] && j == 6){ //atcoder以外の文字の数が違う時
                    frag = false;
                    break;
                }
                else if(atCoder[j] == str[i][0]){ // atcoderの文字数が違うとき
                    if(str[i][1] > str[i][2]){ // 文字列Sに多くもじがあるとき
                        atmarkT -= str[i][1] - str[i][2]; // 多い分だけ文字列Tのアットマークで補完
                        if(atmarkT < 0){ // アットマークがマイナスになったら補完しきれない
                            frag = false; // 負けフラグ
                            break;
                        }
                    }else{ // 文字列Tに多く文字があるとき
                        atmarkS -= str[i][2] - str[i][1]; // 多い分だけ文字列Sのアットマークで補完
                        if(atmarkS < 0){ // アットマークがマイナスになったら補完しきれない
                            frag = false; // 負けフラグ
                            break;
                        }
                    }
                    
                    break;
                }
            }  
        }
        if(!frag){
            break;
        }
    }
    if(frag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;   
}