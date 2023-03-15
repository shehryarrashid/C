//Shehryar Rashid
//Y3085040H
//Grupo 1
#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include<cstring>

using namespace std;

const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200;
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp;
};
enum Breed{
  AXOLOTL,
  TROLL,
  ORC,
  HELLHOUND,
  DRAGON
};
struct Enemy{
  Breed name;
  Core features;
};
struct Hero{
  char name[KNAME];
  Core features;
  bool special;
  int runaways;
  int exp;
  int kills[KENEMIES];
};
int rollDice(){
  return rand()%KDICE+1;
}

//_________________________________________________HERO___FUNCIONS_______________________________________________

void check_name(Hero &hero){
  bool ok;
  int cont=0,name_lenth=0,i=0;
  do{
    ok=true;
    name_lenth=strlen(hero.name);
    if(isalpha(hero.name[0])==0){ ok=false; }
    for(i=0;i<name_lenth;i++){
    if( (isalnum(hero.name[i]) == 0) && (isalpha(hero.name[i]) == 0) && (hero.name[i] != ' ') ){ ok = false ; }
    }
    if(cont>0){ ok=false; }
    if(ok == false){ cout << "ERROR: wrong name " << endl; cout << "Enter hero name: "; cin.getline(hero.name,KNAME);}
    cont = 0;
  }while(ok==false);
}

void att_def(Hero &hero){
  int ataque=0,defensa=0;
  char slash;
  bool ok;
  do{
    ok=true;
    cin >> ataque >> slash >> defensa ;
    if( ataque <= 0 || defensa <= 0){ ok = false; }
    if((ataque+defensa) != 100){ ok = false; }
    if(ok == false){ 
      cout << "ERROR: wrong distribution " << endl ;
      cout << "Enter attack/defense: ";
    }
  }while(ok==false);
  hero.features.attack = (KPOINTS*ataque/100);
  hero.features.defense = (KPOINTS*defensa/100);
  hero.features.hp = hero.features.defense*2;
}

Hero createHero(){
  Hero hero;
  cout<<"Enter hero name: ";
  cin.getline(hero.name,KNAME);
  check_name(hero);
  cout<<"Enter attack/defense: ";
  att_def(hero);
  hero.special=true;
  hero.runaways=3;
  for(int i=0;i<KENEMIES;i++){ hero.kills[i]=0; }
return hero; 
}

//_________________________________________________ENEMY__FUNCIONS___________________________________________________

void enemy_attributes(Enemy &enemy){
  if(enemy.name==0) { enemy.features.attack = 40; enemy.features.defense = 40; }
  else if(enemy.name==1){ enemy.features.attack = 60; enemy.features.defense = 80;}
  else if(enemy.name==2){ enemy.features.attack = 80; enemy.features.defense = 120;}
  else if(enemy.name==3){ enemy.features.attack = 120; enemy.features.defense = 100;}
  else  { enemy.features.attack = 160; enemy.features.defense = 140;}
  enemy.features.hp=enemy.features.defense*2;
  cout<<"Attack: "<<enemy.features.attack<<endl;
  cout<<"Defense: "<<enemy.features.defense<<endl;
  cout<<"Health points: "<<enemy.features.hp<<endl;
}

Enemy createEnemy(){
  Enemy enemy;
  int dice = rollDice();
  cout  <<  "[Enemy]" <<  endl;  cout<<"Breed: ";
  if(dice<7 && dice>0){  enemy.name = AXOLOTL; cout<<"Axolotl"<<endl;  }
  else if(dice>6 && dice<12){  enemy.name = TROLL; cout<<"Troll"<<endl; }
  else if(dice>11 && dice<16){ enemy.name = ORC; cout<<"Orc"<<endl;}
  else if(dice>15 && dice<19){ enemy.name = HELLHOUND; cout<<"Hellhound"<<endl;}
  else{ enemy.name = DRAGON; cout<<"Dragon"<<endl;}
  enemy_attributes(enemy);
return enemy;
}

void hero_attack(Hero hero,Enemy &enemy,int &dice){

  int attackPt = 0,defensePt = 0,hitPt = 0;

  cout<<"[Hero -> Enemy]"<<endl; cout<<"Attack: "<< hero.features.attack << " + " << dice << endl; 
  attackPt = hero.features.attack + dice;
  dice = rollDice(); dice= dice*5; 
  cout<<"Defense: "<< enemy.features.defense << " + " << dice << endl;
  defensePt = enemy.features.defense + dice;
  hitPt = attackPt - defensePt;
  if(hitPt>0){ enemy.features.hp -= hitPt;  }
  else{ hitPt = 0;}
  cout<<"Hit points: "<<hitPt<<endl;
  if(enemy.features.hp<0){ enemy.features.hp = 0;}
  cout<<"Enemy health points: "<<enemy.features.hp<<endl;
  dice=0;

}

void enemy_attack(Hero &hero,Enemy enemy,int &dice){
   int attackPt = 0,defensePt = 0,hitPt = 0;
  dice = rollDice();
  dice = dice*5;  
  cout<<"[Enemy -> Hero]"<<endl; cout<<"Attack: "<< enemy.features.attack << " + " << dice << endl; 
  attackPt = enemy.features.attack + dice;
  dice = rollDice(); dice= dice*5;
  cout<<"Defense: "<< hero.features.defense << " + " << dice << endl;
  defensePt = hero.features.defense + dice;
  hitPt = attackPt - defensePt;
  if(hitPt>0){ hero.features.hp -= hitPt;  }
  else{ hitPt = 0;}
  cout<<"Hit points: "<<hitPt<<endl;
  if(hero.features.hp<0){ hero.features.hp = 0;}
  cout<<"Hero health points: "<<hero.features.hp<<endl;
  dice = 0;

}

//FUNCION QUE SUMA LA EXPERIENCIA Y LAS KILLS DEL HEROE AL MATAR AL ENEMIGO

void death(Hero &hero,Enemy &enemy){

  if(enemy.name==0){hero.kills[0]++; hero.exp+=100;}
  else if(enemy.name==1){hero.kills[1]++; hero.exp+=150;}
  else if(enemy.name==2){hero.kills[2]++; hero.exp+=200;}
  else if(enemy.name==3){hero.kills[3]++; hero.exp+=300;}
  else{hero.kills[4]++; hero.exp+=400;}
  enemy= createEnemy();
}

//_________________________________________________MENU__FUNCIONS___________________________________________________
void fight(Hero &hero,Enemy &enemy,bool &afterFight,bool fromSpecial){
  //La variable From special dice si se llama a la funcion fight desde special
  int dice = 0 ;
  dice = rollDice();
  if(hero.special==true && fromSpecial==true){ dice = dice*15; } // ( dice * 5 ) * 3 -> dice * 15
  else{ dice = dice*5 ;}
  if(hero.features.hp>0)  { hero_attack(hero,enemy,dice); dice = 0; }
  if(enemy.features.hp>0) { enemy_attack(hero,enemy,dice); }
  else{ cout<< "Enemy killed" <<endl; death(hero,enemy);}
  afterFight = true;
}

void runAway(Enemy &enemy,Hero &hero,bool &afterFight){

  if(afterFight==true && hero.runaways>0){ 
  cout<<"You run away "<<endl;
  enemy = createEnemy();
  afterFight = false; hero.runaways--;
  }
  else{cout<<"ERROR: cannot run away"<<endl;}
  
}

void special(Hero &hero,Enemy &enemy,bool &afterFight){
  bool fromSpecial=true;
  if(hero.special==true ){  fight(hero,enemy,afterFight,fromSpecial); hero.special = false; fromSpecial=false; }
  else{ cout<<"ERROR: special not available "<<endl; }
}

//SE USA ESTA FUNCION PARA MOSTRAR LAS KILLS Y CON ELLO EL REPORT SEA MAS CORTO

void showKills(Hero hero){
  int total_kills=0;
  cout<<"- Axolotl: "<<hero.kills[0]<<endl;
  cout<<"- Troll: "<<hero.kills[1]<<endl;
  cout<<"- Orc: "<<hero.kills[2]<<endl;
  cout<<"- Hellhound: "<<hero.kills[3]<<endl;
  cout<<"- Dragon: "<<hero.kills[4]<<endl;
  for(int i=0;i<KENEMIES;i++){ total_kills+=hero.kills[i];  }
  cout<<"- Total: "<<total_kills<<endl;
}

void report(const Hero &hero){
  cout<<"[Report]"<<endl; 
  cout<<"Name: "<<hero.name<<endl;
  cout<<"Attack: "<<hero.features.attack<<endl;
  cout<<"Defense: "<<hero.features.defense<<endl;
  cout<<"Health points: "<<hero.features.hp<<endl;
  if(hero.special==true){cout<<"Special: yes"<<endl;}
  else{cout<<"Special: no"<<endl;}
  cout<<"Runaways: "<<hero.runaways<<endl; cout<<"Exp: "<<hero.exp<<endl;
  cout<<"Enemies killed: "<<endl;
  showKills(hero);
}

void showMenu(){
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}

int main(int argc,char *argv[]){
  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar ù numeros aleatorios
    Hero hero = createHero();
    Enemy enemy = createEnemy();
    hero.exp = 0;
    char opcion;
    bool afterFight=true,fromSpecial=false;// FromSpecial comprueba que se accede al fight desde la funcion Special
    //afterFight es para ver que se ha atacado antes de huir
    do{
      showMenu();
      cin>>opcion;
      switch(opcion){
        case '1': {fight(hero,enemy,afterFight,fromSpecial); break;}
        case '2': {runAway(enemy,hero,afterFight); break;}
        case '3': {special(hero,enemy,afterFight); break;}
        case '4': {report(hero); break;}
        case 'q': {break;}
        default: {cout<<"ERROR: wrong option"<<endl; break;}
      }
    }while( opcion != 'q' && hero.features.hp>0 );
    if(hero.features.hp==0){ cout<<"You are dead"<<endl; report(hero); }
  }
}
