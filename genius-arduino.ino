int maxSorted = 11;
int listSortPin[10];
int listButtonSelected[10];
int countSorted = 0;
int countHigh = 0;
int countPressedButton = 0;
bool buttonPressed = false;

const int LED_VERDE = 2;
const int LED_AZUL = 3;
const int LED_AMARELO = 4;
const int LED_VERMELHO = 5;

const int BOTAO_VERDE = A0;
const int BOTAO_AZUL = A1;
const int BOTAO_VERMELHO = A2;
const int BOTAO_AMARELO = A3;

void setup()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  
  pinMode(BOTAO_VERMELHO, INPUT);
  pinMode(BOTAO_VERDE, INPUT);
  pinMode(BOTAO_AMARELO, INPUT);
  pinMode(BOTAO_AZUL, INPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  sortPin(true);
}

void loop()
{ 
  Serial.print("A0: ");
  Serial.println(analogRead(A0));
  
  Serial.print("A1: ");
  Serial.println(analogRead(A1));
  
  Serial.print("A2: ");
  Serial.println(analogRead(A2));
  
  Serial.print("A3: ");
  Serial.println(analogRead(A3));
  startGame();
}

void startGame() {
  if (countSorted == maxSorted) {
    highLedsChampion();
    resetGame();
  } else if (countHigh < countSorted) {
    // Exibe os leds para seleção
    printLeds();
  } else if (countPressedButton < countHigh) {
    // Obtem a seleção dos botões
    int buttomSelected = getSelectedButtom();
	if (buttomSelected != 0 && !buttonPressed) {
      countPressedButton++;
      Serial.println(countPressedButton);
      listButtonSelected[countPressedButton - 1] = buttomSelected;
      buttonPressed = true;
      delay(500);
    } else {
      buttonPressed = false;
    }
  } else {
    if (validateCorrectChoices()) {
      // Acertou as escolhas de botões
      continueGame();
    } else {
      // Usuário errou as escolhas dos botões. Exibe leds de alerta
      resetGame();
    }
  }
}

void resetGame() {
  Serial.println("Acertou as escolhas de botões");
  highLedsAlert(); 
  resetListButtonsPressed();
  countHigh = 0;
  countPressedButton = 0;
  delay(1000);
  sortPin(true);
}

void continueGame() {
  Serial.println("Acertou as escolhas de botões");
  highLedsSuccess(); 
  resetListButtonsPressed();
  countHigh = 0;
  countPressedButton = 0;
  delay(1000);
  sortPin(false);
}

int getSelectedButtom() {
  int buttomPressed = 0;
Serial.println(analogRead(BOTAO_VERMELHO));
  
  if (analogRead(BOTAO_VERMELHO) == 1023) {
    buttomPressed = LED_VERMELHO;
  } else if (analogRead(BOTAO_VERDE) == 1023) {
    buttomPressed = LED_VERDE;
  } else if (analogRead(BOTAO_AMARELO) == 1023) {
    buttomPressed = LED_AMARELO;
  } else if (analogRead(BOTAO_AZUL) == 1023) {
    buttomPressed = LED_AZUL;
  }
  return buttomPressed;
}

void resetListButtonsPressed() {
  for (int i = 0; i < countPressedButton; i++) {
    listButtonSelected[i] = 0;
  }
}

bool validateCorrectChoices() {
  for (int i = 0; i < countSorted; i++) {
    if (listButtonSelected[i] != listSortPin[i]) {
      return false;
    }
  }
  return true;
}

void printLeds() {
  for (int i = 0; i < countSorted; i++) {
    hightLedSort(listSortPin[i]);
    delay(500);
    countHigh++;
  }
}

void highLedsChampion() {
  for (int i = 0; i < 2; i ++) {
    highLed(LED_VERMELHO);
    delay(100);
    lowLed(LED_VERMELHO);
    delay(100);
    highLed(LED_VERDE);
    delay(100);
    lowLed(LED_VERDE);
    delay(100);
    highLed(LED_AMARELO);
    delay(100);
    lowLed(LED_AMARELO);
    delay(100);
    highLed(LED_AZUL);
    delay(100);
    lowLed(LED_AZUL);
    delay(100);
    highLed(LED_AMARELO);
    delay(100);
    lowLed(LED_AMARELO);
    delay(100);
    highLed(LED_VERDE);
    delay(100);
    lowLed(LED_VERDE);
    delay(100);
    highLed(LED_VERMELHO);
    delay(100);
    lowLed(LED_VERMELHO);
    delay(100);
    highLed(LED_VERDE);
    delay(100);
    lowLed(LED_VERDE);
    delay(100);
    highLed(LED_AMARELO);
    delay(100);
    lowLed(LED_AMARELO);
    delay(100);
    highLed(LED_AZUL);
    delay(100);
    lowLed(LED_AZUL);
    delay(100);
    highLed(LED_AMARELO);
    delay(100);
    lowLed(LED_AMARELO);
    delay(100);
    highLed(LED_VERDE);
    delay(100);
    lowLed(LED_VERDE);
    delay(100);
    
    highLed(LED_VERMELHO);
    highLed(LED_VERDE);
    highLed(LED_AMARELO);
    highLed(LED_AZUL);
    delay(200);
    lowLed(LED_VERMELHO);
    lowLed(LED_VERDE);
    lowLed(LED_AMARELO);
    lowLed(LED_AZUL);
    delay(200);
    highLed(LED_VERMELHO);
    highLed(LED_VERDE);
    highLed(LED_AMARELO);
    highLed(LED_AZUL);
    delay(200);
    lowLed(LED_VERMELHO);
    lowLed(LED_VERDE);
    lowLed(LED_AMARELO);
    lowLed(LED_AZUL);
    delay(200);
    highLed(LED_VERMELHO);
    highLed(LED_VERDE);
    highLed(LED_AMARELO);
    highLed(LED_AZUL);
    delay(200);
    lowLed(LED_VERMELHO);
    lowLed(LED_VERDE);
    lowLed(LED_AMARELO);
    lowLed(LED_AZUL);
    delay(200);
    highLed(LED_VERMELHO);
    highLed(LED_VERDE);
    highLed(LED_AMARELO);
    highLed(LED_AZUL);
    delay(200);
    lowLed(LED_VERMELHO);
    lowLed(LED_VERDE);
    lowLed(LED_AMARELO);
    lowLed(LED_AZUL);
    delay(200);
  }
}

void hightLedSort(int pin) {
  highLed(pin);
  delay(1500);
  lowLed(pin);
}

void highLedsAlert() {
  for (int i = 0; i < 5; i++) {
    highLed(LED_VERMELHO);
    highLed(LED_VERDE);
    highLed(LED_AMARELO);
    highLed(LED_AZUL);

    delay(100);

    lowLed(LED_VERMELHO);
    lowLed(LED_VERDE);
    lowLed(LED_AMARELO);
    lowLed(LED_AZUL);

    delay(100);
  }
}

void highLedsSuccess() {
  highLed(LED_VERMELHO);
  highLed(LED_VERDE);
  highLed(LED_AMARELO);
  highLed(LED_AZUL);

  delay(1000);

  lowLed(LED_VERMELHO);
  lowLed(LED_VERDE);
  lowLed(LED_AMARELO);
  lowLed(LED_AZUL);
}

void highLed(int pin)
{
  digitalWrite(pin, HIGH);
}

void lowLed(int pin)
{
  digitalWrite(pin, LOW);
}

void sortPin(bool reset) 
{
  if (reset) {
    countSorted = 1;
  } else {
    countSorted++;
  }
  listSortPin[countSorted - 1] = random(2, 6);
}