char buz = 4;
char* musica[] = {"La","Re","Fa","Sol","La","Re", "Fa", "Sol", "Mi", "Pausa", "Sol", "Do", "Fa", "Mi", "Sol", "Do", "Fa", "Mi", "Re", "Fim"}; //Game of Thrones
int duracao[] = {700, 500, 300, 250, 250, 300, 200, 200, 700, 200, 500, 500, 200, 200, 200, 500, 200, 200, 500};
char* starwars[] = {"La","Pausa","La","Pausa","La","Pausa","Fa","Do","La","Pausa","Fa","Do","La","Pausa","Mi","Pausa","Mi","Pausa","Mi","Pausa","Fa","Do","Sol","Pausa","Fa","Do","La","Pausa","La","Pausa","La","Pausa","La","Pausa","La","Pausa","Sol#","Pausa","Sol","Fa#","Fa","Fa#","Fim"}; //Marcha Imperial
int dur[] = {400, 100, 400, 100, 400, 100, 300, 200, 300, 100, 300, 200, 300, 200, 400, 100, 400, 100, 400, 100, 300, 300, 200, 100 , 300, 300, 200, 200, 400, 50, 400, 50, 400, 50, 400, 50, 300, 50, 300, 200, 200, 200};

void setup(){
  pinMode(buz, OUTPUT);
  tocar(starwars,dur);
  //tocar(starwars,dur);
}

void loop(){
  // Não utilizado
}

void tocar(char* starwars[], int tempo[]){
  int tom = 0;
  for(int i = 0; starwars[i]!="Fim";i++){
    if(starwars[i] == "Do") tom = 262;
    if(starwars[i] == "Re") tom = 294;
    if(starwars[i] == "Mi") tom = 330;
    if(starwars[i] == "Fa") tom = 349;
    if(starwars[i] == "Sol") tom = 392;
    if(starwars[i] == "La") tom = 440;
    if(starwars[i] == "Si") tom = 494;
    if(starwars[i] == "Do#") tom = 528;
    if(starwars[i] == "Re#") tom = 622;
    if(starwars[i] == "Fa#") tom = 370;
    if(starwars[i] == "Sol#") tom = 415;
    if(starwars[i] == "La#") tom = 466;
    if(starwars[i] == "Pausa") tom = 0;
    tone(buz, tom, tempo[i]);
    delay(tempo[i]);
  }
}
