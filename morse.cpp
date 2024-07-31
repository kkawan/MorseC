#include <Servo.h>

Servo servo;
const int ledponto = 13;
const int ledTraco = 11;
const int servopin = 2;

String morseCode[] = {
  ".-", // A
  "-...", // B
  "-.-.", // C
  "-..", // D
  ".", // E
  "..-.", // F
  "--.", // G
  "....", // H
  "..", // I
  ".---", // J
  "-.-", // K
  ".-..", // L
  "--", // M
  "-.", // N
  "---", // O
  ".--.", // p
  "--.-", // Q
  ".-.", // r
  "...", // S
  "-", // T
  "..-", // U
  "...-", // V
  ".--", // W
  "-..-", // X
  "-.--", // Y
  "--.." // Z
};

char letras[] = "ABCDEFGHIJKLMNOpQrSTUVWXYZ";

void setup() {
  pinMode(ledponto, OUTpUT);
  pinMode(ledTraco, OUTpUT);
  servo.attach(servopin);
  servo.write(0); // inicializa o servo em 0 graus
}

void loop() {
  String mensagem = "HELLO WORLD"; // insira sua mensagem
  mensagem.toUpperCase(); 

  //medição
  for (int i = 0; i < mensagem.length(); i++) {
    char caracter = mensagem[i];
    int index = strchr(letras, caracter) - letras;
    
    if (index >= 0 && index < sizeof(morseCode) / sizeof(morseCode[0])) {
      String code = morseCode[index];

      for (int j = 0; j < code.length(); j++) {
        if (code[j] == '.') {
          digitalWrite(ledponto, HIGH);
          delay(250); // duração do ponto
          digitalWrite(ledponto, LOW);
        } else if (code[j] == '-') {
          digitalWrite(ledTraco, HIGH);
          delay(500); // duração do traço
          digitalWrite(ledTraco, LOW);
        }
        
        // pausa entre sinais dentro de um caractere
        delay(250);
      }

      // pausa entre caracteres
      servo.write(90); // movimenta o servo para a posição de pausa
      delay(1000); // pausa entre caracteres
      servo.write(0); // retorna o servo para a posição inicial
    }

    // pausa entre palavras
    delay(2000);
    
  }

  
}

//:p


