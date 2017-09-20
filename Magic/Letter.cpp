#include "Letter.h"


const string  WORDS[] = { "あ","い","う","え","お","か","き","く","こ","さ","し","す","せ","そ","た","つ","て","と","な","に","ぬ","ね","の","は","ひ","ふ","へ","ほ","ま","み","む","め","も","や","ゆ","よ","ら","り","る","れ","ろ","わ","を","ん" ,"が","ぎ","ぐ","ご","ざ","じ","ず","ぜ","ぞ","だ","づ","で","ど","ば","び","ぶ","べ","ぼ","ぱ","ぴ","ぷ","ぺ","ぽ" };
const int WORDS_COUNT = 67;
void Letter::setup(int _x,int _y,int _count_s){
	alpha = 510;
	x = _x;
	y = _y;
	countBorn = _count_s;
	myFont.loadFont("Magic/dq10font.ttf", 100);
	int index = ofRandom(WORDS_COUNT);
	text = WORDS[index];
}


void Letter::update(int _count_u){
	countNow = _count_u;
	countGap = countNow - countBorn;
	alpha -= 4;
    if(alpha<0){
        alpha = 0;
        x = -1000;
        y = -1000;
    }
}

void Letter::draw(){
    ofSetColor(255, 255, 255,alpha);
    myFont.drawString(text, x, y);
//    ofLogNotice() << "x" << x;
//    ofLogNotice() << "y" << y;
}

void Letter::reset(){
    alpha = alpha - 255 / 60;
    if(alpha<0){
        alpha = 0;
        x = -1000;
        y = -1000;
    }
}
