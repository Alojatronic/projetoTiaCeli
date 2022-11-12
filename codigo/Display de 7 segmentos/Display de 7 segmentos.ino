int conta;

byte displaySeteSeg[10][7] = { 
  
 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,1,0,1,1 }   //DIGITO 9
 
};

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);

  conta = 0;
  LigaSegmentoDisplay(conta);

}

void loop() {
  
  if(digitalRead(10) == LOW){

    delay (500);
    conta++;

    if(conta == 10){
      conta = 0;
      LigaSegmentoDisplay(conta);
    } else {
      LigaSegmentoDisplay(conta);
    }
  }

}

void LigaSegmentoDisplay(byte digito){
  byte pino = 2;
  for (byte contador = 0; contador < 7; contador++){ 
    digitalWrite(pino, displaySeteSeg[digito][contador]);
    ++pino; 
  }
}