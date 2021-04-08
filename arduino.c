#define LEDVERMELHO 12
#define LEDAMARELO 11
#define LEDVERDE 10
#define BUZZER 9
#define BOTAO 8

int LEDACESO = LEDVERMELHO;

bool isPushButtonPressionado() {
     return digitalRead(BOTAO) == HIGH;
} 

bool isLedVermelhoAceso(){
    return LEDACESO == LEDVERMELHO;
}

bool isLedAmareloAceso(){
    return LEDACESO == LEDAMARELO;
}

bool isLedVerdeAceso(){
    return LEDACESO == LEDVERDE;
}

void acenderLedVermelho(){
    digitalWrite(LEDVERMELHO, HIGH);
    LEDACESO = LEDVERMELHO;
}

void apagarLedVermelhoComEfeito(){
    for(int i = 0; i < 3; i++) {
      acenderLedVermelho();
      ligarBuzzer();
      delay(250);  
      apagarLedVermelho();
      desligarBuzzer();
      delay(250);
    }
}

void apagarLedVermelho() {
    digitalWrite(LEDVERMELHO, LOW);
}

void acenderLedAmarelo(){
    digitalWrite(LEDAMARELO, HIGH); 
    LEDACESO = LEDAMARELO;     
}

void apagarLedAmarelo(){
    digitalWrite(LEDAMARELO, LOW);
}

void acenderLedVerde(){
    digitalWrite(LEDVERDE, HIGH);
    LEDACESO = LEDVERDE;
}

void apagarLedVerde(){
    digitalWrite(LEDVERDE, LOW);
}

void ligarBuzzer(){
    digitalWrite(BUZZER, HIGH);
}

void desligarBuzzer(){
    digitalWrite(BUZZER, LOW);
}

void aguardarTerminoClique(){
    delay(1000);
}

void setup(){
    pinMode(LEDVERMELHO, OUTPUT);
    pinMode(LEDAMARELO, OUTPUT);
    pinMode(LEDVERDE, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(BOTAO, INPUT);
}

void loop(){
    if(isPushButtonPressionado()) {
        if(isLedVermelhoAceso()) {
            apagarLedVermelhoComEfeito(); //Pisca 3x e apita 3x, sincronizado.
            acenderLedVerde();
        } else if(isLedAmareloAceso()) {
            apagarLedAmarelo();
            acenderLedVermelho();
        } else if(isLedVerdeAceso()) {
            apagarLedVerde();
            acenderLedAmarelo();
        }
        aguardarTerminoClique();
    }

}
