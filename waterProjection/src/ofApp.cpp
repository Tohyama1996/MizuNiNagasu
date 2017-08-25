#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    font.load("NotoSansCJKjp-Regular.otf", fontSize, true, true);
}

void ofApp::draw(){
    if (!line.empty()) {
        linePosition = ofVec2f(ofGetWidth()/2 - font.stringWidth(line)/2, ofGetHeight()/2);
        font.drawString(line, linePosition.x, linePosition.y);
    }
}

void ofApp::keyPressed(int key){
    if (key == OF_KEY_BACKSPACE) {
        if (line.length() > 0) {
            line = line.substr(0, line.length() - charByte);
            consonant = "";
            charByte = checkByte();
        }
    } else if (key == OF_KEY_RETURN) {
        if (line.length() > 0) {
            secondApp->pushString(line);
            consonant = "";
            newChar = "";
            line = "";
            completed = false;
            doubleConsonant = false;
            charByte = 0;
        }
    } else {
        if (line.length() < 30) {
            keyJudge(key);
            if (completed) {
                for (int i=0; i<consonant.length(); i++) line.pop_back();
                consonant = "";
                completed = false;
            } else if (doubleConsonant) {
                for (int i=0; i<consonant.length(); i++) line.pop_back();
                doubleConsonant = false;
            }
            line += newChar;
            charByte = checkByte();
        }
    }
}

int ofApp::checkByte() {
    string _line = line;
    while (_line.length() > 0) {
        Byte b =  line[_line.length()-1];
        if (b >= 0b11100000) {
            //cout << "3byte" << endl;
            return 3;
        } else if (b >= 0b11000000) {
            //cout << "2byte" << endl;
            return 2;
        } else if (b >= 0b10000000) {
            //cout << "..." << endl;
        } else {
            //cout << "1byte" << endl;
            return 1;
        }
        _line.pop_back();
    }
}

void ofApp::keyJudge(int key) {
    switch (key) {
        case 'k' :
        case 'K' :
            if (consonant == "k") {
                newChar = "ッk";
                doubleConsonant = true;
            } else {
                consonant = "k";
                newChar = "k";
            }
            break;
        case 's' :
        case 'S' :
            if (consonant == "s") {
                newChar = "ッs";
                doubleConsonant = true;
            } else if (consonant == "t") {
                consonant = "ts";
                newChar = "s";
            } else if (consonant == "xt") {
                consonant = "xts";
                newChar = "s";
            } else {
                consonant = "s";
                newChar = "s";
            }
            break;
        case 't' :
        case 'T' :
            if (consonant == "t") {
                newChar = "ッt";
                doubleConsonant = true;
            } else if (consonant == "x") {
                consonant = "xt";
                newChar = "t";
            } else {
                consonant = "t";
                newChar = "t";
            }
            break;
        case 'n' :
        case 'N' :
            if (consonant == "n") {
                newChar = "ン";
                completed = true;
            } else {
                consonant = "n";
                newChar = "n";
            }
            break;
        case 'h' :
        case 'H' :
            if (consonant == "s") {
                consonant = "sh";
                newChar = "h";
            } else if (consonant == "t") {
                consonant = "th";
                newChar = "h";
            } else if (consonant == "h") {
                newChar = "ッh";
                doubleConsonant = true;
            } else if (consonant == "c") {
                consonant = "ch";
                newChar = "h";
            } else {
                consonant = "h";
                newChar = "h";
            }
            break;
        case 'm' :
        case 'M' :
            if (consonant == "m") {
                newChar = "ッm";
                doubleConsonant = true;
            } else {
                consonant = "m";
                newChar = "m";
            }
            break;
        case 'y' :
        case 'Y' :
            if (consonant == "k") {
                consonant = "ky";
                newChar = "y";
            } else if (consonant == "s") {
                consonant = "sy";
                newChar = "y";
            } else if (consonant == "t") {
                consonant = "ty";
                newChar = "y";
            } else if (consonant == "n") {
                consonant = "ny";
                newChar = "y";
            } else if (consonant == "h") {
                consonant = "hy";
                newChar = "y";
            } else if (consonant == "m") {
                consonant = "my";
                newChar = "y";
            } else if (consonant == "y") {
                newChar = "ッy";
                doubleConsonant = true;
            } else if (consonant == "r") {
                consonant = "ry";
                newChar = "y";
            } else if (consonant == "g") {
                consonant = "gy";
                newChar = "y";
            } else if (consonant == "z") {
                consonant = "zy";
                newChar = "y";
            } else if (consonant == "d") {
                consonant = "dy";
                newChar = "y";
            } else if (consonant == "b") {
                consonant = "by";
                newChar = "y";
            } else if (consonant == "p") {
                consonant = "py";
                newChar = "y";
            } else if (consonant == "c") {
                consonant = "cy";
                newChar = "y";
            } else if (consonant == "f") {
                consonant = "fy";
                newChar = "y";
            } else if (consonant == "v") {
                consonant = "vy";
                newChar = "y";
            } else if (consonant == "j") {
                consonant = "jy";
                newChar = "y";
            } else if (consonant == "l") {
                consonant = "ly";
                newChar = "y";
            } else if (consonant == "x") {
                consonant = "xy";
                newChar = "y";
            } else {
                consonant = "y";
                newChar = "y";
            }
            break;
        case 'r' :
        case 'R' :
            if (consonant == "r") {
                newChar = "ッr";
                doubleConsonant = true;
            } else {
                consonant = "r";
                newChar = "r";
            }
            break;
        case 'w' :
        case 'W' :
            if (consonant == "w") {
                newChar = "ッw";
                doubleConsonant = true;
            } else {
                consonant = "w";
                newChar = "w";
            }
            break;
        case 'g' :
        case 'G' :
            if (consonant == "g") {
                newChar = "ッg";
                doubleConsonant = true;
            } else {
                consonant = "g";
                newChar = "g";
            }
            break;
        case 'z' :
        case 'Z' :
            if (consonant == "z") {
                newChar = "ッz";
                doubleConsonant = true;
            } else {
                consonant = "z";
                newChar = "z";
            }
            break;
        case 'd' :
        case 'D' :
            if (consonant == "d") {
                newChar = "ッd";
                doubleConsonant = true;
            } else {
                consonant = "d";
                newChar = "d";
            }
            break;
        case 'b' :
        case 'B' :
            if (consonant == "b") {
                newChar = "ッb";
                doubleConsonant = true;
            } else {
                consonant = "b";
                newChar = "b";
            }
            break;
        case 'p' :
        case 'P' :
            if (consonant == "p") {
                newChar = "ッp";
                doubleConsonant = true;
            } else {
                consonant = "p";
                newChar = "p";
            }
            break;
        case 'q' :
        case 'Q' :
            if (consonant == "q") {
                newChar = "ッq";
                doubleConsonant = true;
            } else {
                consonant = "q";
                newChar = "q";
            }
            break;
        case 'c' :
        case 'C' :
            if (consonant == "c") {
                newChar = "ッc";
                doubleConsonant = true;
            } else {
                consonant = "c";
                newChar = "c";
            }
            break;
        case 'f' :
        case 'F' :
            if (consonant == "f") {
                newChar = "ッf";
                doubleConsonant = true;
            } else {
                consonant = "f";
                newChar = "f";
            }
            break;
        case 'v' :
        case 'V' :
            if (consonant == "v") {
                newChar = "ッv";
                doubleConsonant = true;
            } else {
                consonant = "v";
                newChar = "v";
            }
            break;
        case 'j' :
        case 'J' :
            if (consonant == "j") {
                newChar = "ッj";
                doubleConsonant = true;
            } else {
                consonant = "j";
                newChar = "j";
            }
            break;
        case 'l' :
        case 'L' :
            if (consonant == "l") {
                newChar = "ッl";
                doubleConsonant = true;
            } else {
                consonant = "l";
                newChar = "l";
            }
            break;
        case 'x' :
        case 'X' :
            if (consonant == "x") {
                newChar = "ッx";
                doubleConsonant = true;
            } else {
                consonant = "x";
                newChar = "x";
            }
            break;
            
        case 'a' :
        case 'A' :
            if (consonant == "k") {
                    newChar = "カ";
            } else if (consonant == "s") {
                    newChar = "サ";
            } else if (consonant == "t") {
                    newChar = "タ";
            } else if (consonant == "n") {
                    newChar = "ナ";
            } else if (consonant == "h") {
                    newChar = "ハ";
            } else if (consonant == "m") {
                    newChar = "マ";
            } else if (consonant == "y") {
                    newChar = "ヤ";
            } else if (consonant == "r") {
                    newChar = "ラ";
            } else if (consonant == "w") {
                    newChar = "ワ";
            } else if (consonant == "g") {
                    newChar = "ガ";
            } else if (consonant == "z") {
                    newChar = "ザ";
            } else if (consonant == "d") {
                    newChar = "ダ";
            } else if (consonant == "b") {
                    newChar = "バ";
            } else if (consonant == "p") {
                    newChar = "パ";
            } else if (consonant == "q") {
                    newChar = "クァ";
            } else if (consonant == "c") {
                    newChar = "カ";
            } else if (consonant == "f") {
                    newChar = "ファ";
            } else if (consonant == "v") {
                    newChar = "ヴァ";
            } else if (consonant == "j") {
                    newChar = "ジャ";
            } else if (consonant == "l" || consonant == "x") {
                    newChar = "ァ";
            } else if (consonant == "sh") {
                    newChar = "シャ";
            } else if (consonant == "th") {
                    newChar = "テャ";
            } else if (consonant == "ky") {
                    newChar = "キャ";
            } else if (consonant == "sy") {
                    newChar = "シャ";
            } else if (consonant == "ty") {
                    newChar = "チャ";
            } else if (consonant == "ny") {
                    newChar = "ニャ";
            } else if (consonant == "hy") {
                    newChar = "ヒャ";
            } else if (consonant == "my") {
                    newChar = "ミャ";
            } else if (consonant == "ry") {
                    newChar = "リャ";
            } else if (consonant == "gy") {
                    newChar = "ギャ";
            } else if (consonant == "zy") {
                    newChar = "ジャ";
            } else if (consonant == "dy") {
                    newChar = "ヂャ";
            } else if (consonant == "by") {
                    newChar = "ビャ";
            } else if (consonant == "py") {
                    newChar = "ピャ";
            } else if (consonant == "ch") {
                    newChar = "チャ";
            } else if (consonant == "cy") {
                    newChar = "チャ";
            } else if (consonant == "fy") {
                    newChar = "フャ";
            } else if (consonant == "vy") {
                    newChar = "ヴャ";
            } else if (consonant == "jy") {
                    newChar = "ジャ";
            } else if (consonant == "ts") {
                    newChar = "ツァ";
            } else if (consonant == "ly" || consonant == "xy") {
                    newChar = "ャ";
            } else {
                    newChar = "ア";
            }
            completed = true;
            break;
        case 'i' :
        case 'I' :
            if (consonant == "k") {
                    newChar = "キ";
            } else if (consonant == "s") {
                    newChar = "シ";
            } else if (consonant == "t") {
                    newChar = "チ";
            } else if (consonant == "n") {
                    newChar = "ニ";
            } else if (consonant == "h") {
                    newChar = "ヒ";
            } else if (consonant == "m") {
                    newChar = "ミ";
            } else if (consonant == "r") {
                    newChar = "リ";
            } else if (consonant == "w") {
                    newChar = "ウィ";
            } else if (consonant == "g") {
                    newChar = "ギ";
            } else if (consonant == "z") {
                    newChar = "ジ";
            } else if (consonant == "d") {
                    newChar = "ヂ";
            } else if (consonant == "b") {
                    newChar = "ビ";
            } else if (consonant == "p") {
                    newChar = "ピ";
            } else if (consonant == "q") {
                    newChar = "クィ";
            } else if (consonant == "c") {
                    newChar = "シ";
            } else if (consonant == "f") {
                    newChar = "フィ";
            } else if (consonant == "v") {
                    newChar = "ヴィ";
            } else if (consonant == "j") {
                    newChar = "ジ";
            } else if (consonant == "l" || consonant == "x") {
                    newChar = "ィ";
            } else if (consonant == "sh") {
                    newChar = "シ";
            } else if (consonant == "th") {
                    newChar = "ティ";
            } else if (consonant == "ky") {
                    newChar = "キィ";
            } else if (consonant == "sy") {
                    newChar = "シィ";
            } else if (consonant == "ty") {
                    newChar = "チィ";
            } else if (consonant == "ny") {
                    newChar = "ニィ";
            } else if (consonant == "hy") {
                    newChar = "ヒィ";
            } else if (consonant == "my") {
                    newChar = "ミィ";
            } else if (consonant == "ry") {
                    newChar = "リィ";
            } else if (consonant == "gy") {
                    newChar = "ギィ";
            } else if (consonant == "zy") {
                    newChar = "ジィ";
            } else if (consonant == "dy") {
                    newChar = "ヂィ";
            } else if (consonant == "by") {
                    newChar = "ビィ";
            } else if (consonant == "py") {
                    newChar = "ピィ";
            } else if (consonant == "ch") {
                    newChar = "チ";
            } else if (consonant == "cy") {
                    newChar = "チィ";
            } else if (consonant == "vy") {
                    newChar = "ヴィ";
            } else if (consonant == "jy") {
                    newChar = "ジィ";
            } else if (consonant == "ts") {
                    newChar = "ツィ";
            } else if (consonant == "ly" || consonant == "xy") {
                    newChar = "ィ";
            } else {
                    newChar = "イ";
            }
            completed = true;
            break;
        case 'u' :
        case 'U' :
            if (consonant == "k") {
                    newChar = "ク";
            } else if (consonant == "s") {
                    newChar = "ス";
            } else if (consonant == "t") {
                    newChar = "ツ";
            } else if (consonant == "n") {
                    newChar = "ヌ";
            } else if (consonant == "h") {
                    newChar = "フ";
            } else if (consonant == "m") {
                    newChar = "ム";
            } else if (consonant == "y") {
                    newChar = "ユ";
            } else if (consonant == "r") {
                    newChar = "ル";
            } else if (consonant == "w") {
                    newChar = "ウ";
            } else if (consonant == "g") {
                    newChar = "グ";
            } else if (consonant == "z") {
                    newChar = "ズ";
            } else if (consonant == "d") {
                    newChar = "ヅ";
            } else if (consonant == "b") {
                    newChar = "ブ";
            } else if (consonant == "p") {
                    newChar = "プ";
            } else if (consonant == "q") {
                    newChar = "ク";
            } else if (consonant == "c") {
                    newChar = "ク";
            } else if (consonant == "f") {
                    newChar = "フ";
            } else if (consonant == "v") {
                    newChar = "ヴ";
            } else if (consonant == "j") {
                    newChar = "ジュ";
            } else if (consonant == "l" || consonant == "x") {
                    newChar = "ゥ";
            } else if (consonant == "sh") {
                    newChar = "シュ";
            } else if (consonant == "th") {
                    newChar = "テュ";
            } else if (consonant == "ky") {
                    newChar = "キュ";
            } else if (consonant == "sy") {
                    newChar = "シュ";
            } else if (consonant == "ty") {
                    newChar = "チュ";
            } else if (consonant == "ny") {
                    newChar = "ニュ";
            } else if (consonant == "hy") {
                    newChar = "ヒュ";
            } else if (consonant == "my") {
                    newChar = "ミュ";
            } else if (consonant == "ry") {
                    newChar = "リュ";
            } else if (consonant == "gy") {
                    newChar = "ギュ";
            } else if (consonant == "zy") {
                    newChar = "ジュ";
            } else if (consonant == "dy") {
                    newChar = "ヂュ";
            } else if (consonant == "by") {
                    newChar = "ビュ";
            } else if (consonant == "py") {
                    newChar = "ピュ";
            } else if (consonant == "ch") {
                    newChar = "チュ";
            } else if (consonant == "cy") {
                    newChar = "チュ";
            } else if (consonant == "fy") {
                    newChar = "フュ";
            } else if (consonant == "vy") {
                    newChar = "ヴュ";
            } else if (consonant == "jy") {
                    newChar = "ジュ";
            } else if (consonant == "ts") {
                    newChar = "ツ";
            } else if (consonant == "xt" || consonant == "xts") {
                    newChar = "ッ";
            } else if (consonant == "ly" || consonant == "xy") {
                    newChar = "ュ";
            } else {
                    newChar = "ウ";
            }
            completed = true;
            break;
        case 'e' :
        case 'E' :
            if (consonant == "k") {
                    newChar = "ケ";
            } else if (consonant == "s") {
                    newChar = "セ";
            } else if (consonant == "t") {
                    newChar = "テ";
            } else if (consonant == "n") {
                    newChar = "ネ";
            } else if (consonant == "h") {
                    newChar = "ヘ";
            } else if (consonant == "m") {
                    newChar = "メ";
            } else if (consonant == "y") {
                    newChar = "イェ";
            } else if (consonant == "r") {
                    newChar = "レ";
            } else if (consonant == "w") {
                    newChar = "ウェ";
            } else if (consonant == "g") {
                    newChar = "ゲ";
            } else if (consonant == "z") {
                    newChar = "ゼ";
            } else if (consonant == "d") {
                    newChar = "デ";
            } else if (consonant == "b") {
                    newChar = "ベ";
            } else if (consonant == "p") {
                    newChar = "ペ";
            } else if (consonant == "q") {
                    newChar = "クェ";
            } else if (consonant == "c") {
                    newChar = "セ";
            } else if (consonant == "f") {
                    newChar = "フェ";
            } else if (consonant == "v") {
                    newChar = "ヴェ";
            } else if (consonant == "j") {
                    newChar = "ジェ";
            } else if (consonant == "l" || consonant == "x") {
                    newChar = "ェ";
            } else if (consonant == "sh") {
                    newChar = "シェ";
            } else if (consonant == "th") {
                    newChar = "テェ";
            } else if (consonant == "ky") {
                    newChar = "キェ";
            } else if (consonant == "sy") {
                    newChar = "シェ";
            } else if (consonant == "ty") {
                    newChar = "チェ";
            } else if (consonant == "ny") {
                    newChar = "ニェ";
            } else if (consonant == "hy") {
                    newChar = "ヒェ";
            } else if (consonant == "my") {
                    newChar = "ミェ";
            } else if (consonant == "ry") {
                    newChar = "リェ";
            } else if (consonant == "gy") {
                    newChar = "ギェ";
            } else if (consonant == "zy") {
                    newChar = "ジェ";
            } else if (consonant == "dy") {
                    newChar = "ヂェ";
            } else if (consonant == "by") {
                    newChar = "ビェ";
            } else if (consonant == "py") {
                    newChar = "ピェ";
            } else if (consonant == "ch") {
                    newChar = "チェ";
            } else if (consonant == "cy") {
                    newChar = "チェ";
            } else if (consonant == "vy") {
                    newChar = "ヴェ";
            } else if (consonant == "jy") {
                    newChar = "ジェ";
            } else if (consonant == "ts") {
                    newChar = "ツェ";
            } else if (consonant == "ly" || consonant == "xy") {
                    newChar = "ェ";
            } else {
                    newChar = "エ";
            }
            completed = true;
            break;
        case 'o' :
        case 'O' :
            if (consonant == "k") {
                    newChar = "コ";
            } else if (consonant == "s") {
                    newChar = "ソ";
            } else if (consonant == "t") {
                    newChar = "ト";
            } else if (consonant == "n") {
                    newChar = "ノ";
            } else if (consonant == "h") {
                    newChar = "ホ";
            } else if (consonant == "m") {
                    newChar = "モ";
            } else if (consonant == "y") {
                    newChar = "ヨ";
            } else if (consonant == "r") {
                    newChar = "ロ";
            } else if (consonant == "w") {
                    newChar = "ヲ";
            } else if (consonant == "g") {
                    newChar = "ゴ";
            } else if (consonant == "z") {
                    newChar = "ゾ";
            } else if (consonant == "d") {
                    newChar = "ド";
            } else if (consonant == "b") {
                    newChar = "ボ";
            } else if (consonant == "p") {
                    newChar = "ポ";
            } else if (consonant == "q") {
                    newChar = "クォ";
            } else if (consonant == "c") {
                    newChar = "コ";
            } else if (consonant == "f") {
                    newChar = "フォ";
            } else if (consonant == "v") {
                    newChar = "ヴォ";
            } else if (consonant == "j") {
                    newChar = "ジョ";
            } else if (consonant == "l" || consonant == "x") {
                    newChar = "ォ";
            } else if (consonant == "sh") {
                    newChar = "ショ";
            } else if (consonant == "th") {
                    newChar = "テョ";
            } else if (consonant == "ky") {
                    newChar = "キョ";
            } else if (consonant == "sy") {
                    newChar = "ショ";
            } else if (consonant == "ty") {
                    newChar = "チョ";
            } else if (consonant == "ny") {
                    newChar = "ニョ";
            } else if (consonant == "hy") {
                    newChar = "ヒョ";
            } else if (consonant == "my") {
                    newChar = "ミョ";
            } else if (consonant == "ry") {
                    newChar = "リョ";
            } else if (consonant == "gy") {
                    newChar = "ギョ";
            } else if (consonant == "zy") {
                    newChar = "ジョ";
            } else if (consonant == "dy") {
                    newChar = "ヂョ";
            } else if (consonant == "by") {
                    newChar = "ビョ";
            } else if (consonant == "py") {
                    newChar = "ピョ";
            } else if (consonant == "ch") {
                    newChar = "チョ";
            } else if (consonant == "cy") {
                    newChar = "チョ";
            } else if (consonant == "fy") {
                    newChar = "フョ";
            } else if (consonant == "vy") {
                    newChar = "ヴョ";
            } else if (consonant == "jy") {
                    newChar = "ジョ";
            } else if (consonant == "ts") {
                    newChar = "ツォ";
            } else if (consonant == "ly" || consonant == "xy") {
                    newChar = "ョ";
            } else {
                    newChar = "オ";
            }
            completed = true;
            break;
        case '-' :
            newChar = "ー";
            consonant = "";
            break;
        case ',' :
            newChar = "、";
            consonant = "";
            break;
        case '.' :
            newChar = "。";
            consonant = "";
            break;
        default :
            newChar = "";
    }
}
