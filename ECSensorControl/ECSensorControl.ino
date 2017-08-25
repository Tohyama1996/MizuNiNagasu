int prevt = 0;
int t = 0;
int threshold = 5;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT); //LED[

  Serial.begin(9600);
}

void loop() { 
  t = 0;
  byte data;
  
  // パルスの立ち上げ
  digitalWrite(8, HIGH);

  // 立ち上がりまでの時間計測
  while (digitalRead(9)!=HIGH) t++;

  // 放電するまで待つ
  digitalWrite(8, LOW);  
  delay(1);

  // ローパスフィルタ
  //t = 0.8 * prevt + 0.2 * t;
  //prevt = t;

  // LED点灯
  if( t > threshold ){
    digitalWrite(13, LOW);
    data = 1;
  } else {
    digitalWrite(13, HIGH);
    data = 0;
  }

  Serial.write(data);
}
