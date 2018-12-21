#define a 2
#define b 3
#define c 4
#define  buzz 5
#define b1 8
#define b2 9
#define b3 10

//valores de tom para cada led
#define t1 600
#define t2 650
#define t3 700
#define PINODESCONECTADO 6

int pos = 0;
int ordem[10]; //ordem dos leds acesos


void acerto(){
    
  for(int i = 0; i < 3; i++){
    tone(buzz, 1000, 50);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    delay(100);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    delay(100);
  }
  delay(1000);
}

void erro(){
    tone(buzz, 200, 1000);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    delay(1000);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    delay(1000);
}

int pressionar(){
  while(1){ //loop infinito, sairemos quando um botão for pressionado
    if(digitalRead(b1) == LOW) // botão 1 pressionado
      return a;
      
    if(digitalRead(b2) == LOW) // botão 2 pressionado
      return b;
      
    if(digitalRead(b3) == LOW) // botão 3 pressionado
      return c;
  }
}

void acende(int input){
  switch(input){
    case a:
      digitalWrite(a, HIGH);
      tone(buzz, t1, 100);
      delay(100);
      digitalWrite(a, LOW);
      return;

    case b:
      digitalWrite(b, HIGH);
      tone(buzz, t2, 100);
      delay(100);
      digitalWrite(b, LOW);
      return;

    case c:
      digitalWrite(c, HIGH);
      tone(buzz, t2, 100);
      delay(100);
      digitalWrite(c, LOW);
      return;
  }
}

void testes(int posicao){
  for(int i = 0; i < posicao; i++){
    int input = pressionar();
    if(input == ordem[i]){
      acende(input);
      delay(80);
    }
    else{
      erro();
      pos = -1;
      return;
    } 
  }
}

void inicio(){
  for(int i = 0; i < 3; i++){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    tone(buzz, 500, 100);
    delay(500);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    delay(500);
  }
  tone(buzz, 700, 200);
  delay(2000);
}




void setup() {
  randomSeed(analogRead(PINODESCONECTADO)); 
  Serial.begin(9600);
  pinMode(a, OUTPUT); //led 1
  pinMode(b, OUTPUT); //led 2
  pinMode(c, OUTPUT); //led 3
  pinMode(buzz, OUTPUT); //buzzer
  pinMode(b1, INPUT_PULLUP); // botão 1
  pinMode(b2, INPUT_PULLUP); // botão 2
  pinMode(b3, INPUT_PULLUP); // botão 3
  inicio();
}

void loop() {
  while(pos <= 9 && pos != -1){
    ordem[pos] = random(a, c+1); //sorteia do primeiro até o último mais 1
    acende(ordem[pos]);
    testes(pos); 
    
    if(pos != -1){
      Serial.println("aqui"); Serial.println(pos);
      int input = pressionar();
      if(input == ordem[pos])
        acerto();
      else{
        erro();
        pos = -1;
      }
    }
    
    pos++;
    
    if(pos == 10)
      break;
  }

    
//
  
  /*
      
      tone(buzz, 1900, 100);   
      delay(100);
      tone(buzz, 900, 100);
      delay(100);
      tone(buzz, 1500, 150);
      delay(100);
      tone(buzz, 1200, 170);
      delay(100);
 
      delay(1000);         
    }
  }*/

  
}
