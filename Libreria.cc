
// DNI Y3085040H Rashid,Shehryar

#include <iostream>
#include <vector>
#include <cstring> 
#include <fstream>

using namespace std;

const int KMAXSTRING = 50;

enum Error {
  ERR_OPTION,
  ERR_BOOK_TITLE,
  ERR_BOOK_AUTHORS,
  ERR_BOOK_DATE,
  ERR_BOOK_PRICE,
  ERR_ID,
  ERR_FILE,
  ERR_ARGS
};

enum Message {
  M_Name,
  M_Author,
  M_Date,
  M_Price,
  M_DeleteId,
  M_FName,
  M_ERASE_ALL
};

struct Book {
  unsigned int id;
  string title;
  string authors;
  int year;
  string slug;
  float price;
};

struct BinBook {
  unsigned int id;
  char title[KMAXSTRING];
  char authors[KMAXSTRING];
  int year;
  char slug[KMAXSTRING];
  float price;
};

struct BookStore {
  string name;
  vector<Book> books;
  unsigned int nextId;
};

struct BinBookStore {
  char name[KMAXSTRING];
  unsigned int nextId;
};

//____________________________________________PRINT MODULES_______________________________________________

void message(Message m){
  
  switch (m){
    case M_Name:      cout<<"Enter book title: ";
      break;
    case M_Author:    cout<<"Enter author(s): ";
      break;
    case M_Date:      cout<<"Enter publication year: ";
      break;
    case M_Price:     cout<<"Enter price: ";
      break;
    case M_DeleteId:  cout<<"Enter book id: ";
      break;
    case M_FName:     cout<<"Enter filename: ";
      break;
    case M_ERASE_ALL: cout<<"All data will be erased, do you want to continue (Y/N)?: ";
      break;
  }
}

void error(Error e) {
  switch (e) {
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_BOOK_TITLE:
      cout << "ERROR: wrong book title" << endl;
      break;
    case ERR_BOOK_AUTHORS:
      cout << "ERROR: wrong author(s)" << endl;
      break;
    case ERR_BOOK_DATE:
      cout << "ERROR: wrong date" << endl;
      break;
    case ERR_BOOK_PRICE:
      cout << "ERROR: wrong price" << endl;
      break;
    case ERR_ID:
      cout << "ERROR: wrong book id" << endl;
      break;
    case ERR_FILE:
      cout << "ERROR: cannot open file" << endl;
      break;
    case ERR_ARGS:
      cout << "ERROR: wrong arguments" << endl;
      break;
  }
}

void showMainMenu() {
  cout <<         "[Options]"        << endl
       <<      "1- Show catalog"     << endl
       << "2- Show extended catalog" << endl
       <<      "3- Add book"         << endl
       <<      "4- Delete book"      << endl
       <<      "5- Import/export"    << endl
       <<      "q- Quit"             << endl
       <<      "Option: ";
}

void showCatalog(const BookStore &bookStore){

  for(unsigned int i = 0 ; i < bookStore.books.size() ; i++){

    cout << bookStore.books[i].id   << ". " << bookStore.books[i].title <<" ("
         << bookStore.books[i].year << "), "<< bookStore.books[i].price << endl;
  }
}

void showExtendedCatalog(const BookStore &bookStore) {

  for(unsigned int i = 0 ; i < bookStore.books.size() ; i++){

    cout << "\""  << bookStore.books[i].title << "\",\""<< bookStore.books[i].authors 
         << "\"," << bookStore.books[i].year  << ",\""  << bookStore.books[i].slug 
         << "\"," << bookStore.books[i].price << endl;  
  }
}


// Comprueba Cadena Vacio

bool blancs(string &id){

  unsigned int blancs = 0;
  
  for(unsigned int i = 0 ; i < id.length() ; i++ ){
    if(id[i] == ' ' ){
      blancs ++ ;
    }
  }
  if(id.length() == blancs) {
    return false;
  }
  else {
    return true;
  }
}

//_____________________________________________MODULES FOR ADDING A BOOK_________________________________

// Modulo para verificar el nombre y autor. 

void Verification(bool &correctName,string &name){

  if(name.length() > 0 )
  {
    for(unsigned int i = 0 ; i < (name.length()) ; i++)
    {
      if(isalnum(name[i]) == 0 && isalpha(name[i]) == 0)
      {
        if (name[i] != ':' && name[i] != ' ' 
         && name[i] != ',' && name[i] != '-')
        {
          correctName = false;
        }
      }
    }
  }
  else{
    correctName = false;
  }

}

// Módulo que elimina los blancos iniciales y finales 

void erase_blancs(string &name){

  while(name[0]== ' '){
    name.erase(0,1);
  }
  while(name[name.length()-1]== ' '){
    name.erase(name.length()-1,1);
  }
}

// Codigo que se repite a la hora de introducir titulo y autor.

string title_author(bool &correctName){
 
  string name ;

    correctName = true;
    getline(cin,name);
    if(name.length()<1){correctName = false;}
    Verification(correctName,name);
    
return name;
}

// Funcion principal para introducir titulo y autor.

void book_title_author(Book &book){

  bool correct_name;
  // Titulo
  do
  {
  message(M_Name);
  book.title = title_author(correct_name);

  if(correct_name == false) 
    error(ERR_BOOK_TITLE);

  }while(correct_name == false);

  // Autor
  do
  {
  message(M_Author);
  book.authors = title_author(correct_name);
  if(correct_name == false) 
    error(ERR_BOOK_AUTHORS);

  }while(correct_name == false);

}

// Comprueba el año

void year_Verification(bool &correctYear,string year){

  int anyo; 
  
    if(year.length() > 0 ){

      anyo = stoi(year);

      if(anyo > 2022 || anyo < 1440)  {  correctYear = false;  }
    }
    else {correctYear = false;}
}

// Funcion que inserta el año
 
void book_year(Book &book){

  bool correct_year;
  string year;
  do
  {
    correct_year = true;
    message(M_Date);
    getline(cin,year);

    erase_blancs(year); // si se inserta (    2022) se eliminan los espacios y se queda : (2022)
    
    correct_year = blancs(year); // Compruba cadena vacia

    if(correct_year == true) year_Verification(correct_year,year); 

    if(correct_year == false) error(ERR_BOOK_DATE);
  
  }while(correct_year == false);
  
  book.year = stoi(year); 
}

// Funcion que valida el precio

void price_verification(string &price,bool &correct_price){

  float precio = 0;
  correct_price = blancs(price);
  if (price.length() < 1){
    correct_price = false;
  }
  for(unsigned int i = 0; i < price.length(); i++){
    if(price[i] == ',' || isalnum(price[i] == 0)){
      correct_price = false;
    }
  }
  if(correct_price == true ){
    precio = stof(price);
    if(precio <= 0){
      correct_price = false;
    }
  }
}

// Función para introducir el precio del libro

void book_price(Book &book){

  bool correct_price;
  string price;
  do{

    correct_price = true;
    message(M_Price);
    getline(cin,price);
    erase_blancs(price);
    price_verification(price,correct_price);
    if(correct_price == true ){  book.price = stof(price);  }
    else { error(ERR_BOOK_PRICE); }

  }while(correct_price == false);
}

// Controla que no se generen varios guiones seguidos.

void numerous_midlines(string &slug){

  int length = slug.length();

  for(int i = 0; i < length ; i++){
    while(slug[i] == '-' && slug[i+1] == '-' ){
     slug.erase(i,1);
    }
  }
  while(slug[slug.length()-1] == '-'){
    slug.erase(slug.length()-1,1);
  }
  while(slug[0]=='-'){
    slug.erase(0,1);
  } 
}

// Genera el slug del libro (Se puede usar para generar el slug de cualquier nombre)
// Esta funcion necessita las siguientes : numerous_midlines() y erase_blancs()

void generate_slug(Book &book){
  
  string aux_slug = book.title;
  erase_blancs(aux_slug);
  for(unsigned int i = 0 ; i < book.title.length() ; i++){

    aux_slug[i] = tolower(aux_slug[i]); // Pasa a minusculas

    while(aux_slug[i] == ':' || aux_slug[i] == ',' ){
     aux_slug.erase(i,1); 
    }
    if((aux_slug[i] == ' ') || (isalnum(aux_slug[i]== 0) && isalpha(aux_slug[i]) == 0)) {
     aux_slug[i] = '-';   
    }
  }
  numerous_midlines(aux_slug);

  book.slug = aux_slug;
}

// Main addBook Funcion

void addBook(BookStore &bookStore) {

  Book book;
  book.id = bookStore.nextId;
  book_title_author(book);
  book_year(book);
  book_price(book);
  generate_slug(book);
  bookStore.books.push_back(book);
  bookStore.nextId++;
}


//____________________________________________DELETE BOOK MODULES__________________________________________



bool check_if_exists(const BookStore bookStore,const string id){
  
  bool ok = false;
  unsigned int id2 = stoi(id);
  for(unsigned int i = 0;i < bookStore.books.size();i++ ){
    if(bookStore.books[i].id == id2)
    {
      ok = true;
    }
  }
  return ok;
}

// Funcion Principal

void deleteBook(BookStore &bookStore) {

  string c_id; // string auxiliar para poder leer el id del libro
  unsigned int id;
  message(M_DeleteId);
  getline(cin,c_id);
  bool ok;

    if(blancs(c_id)){ // Compueba si se trata de cadena de blancos
      ok = check_if_exists(bookStore,c_id);
      id = stoi(c_id);
      if(ok == true){
        for(unsigned int i = 0; i < bookStore.books.size() ; i++ ){
          if(bookStore.books[i].id == id)
          {
            bookStore.books.erase(bookStore.books.begin()+i);
          }
        }
      }
    }
    if(blancs(c_id) == false || ok == false){
      error(ERR_ID);
    }
}


//___________________________________________MODULOS ARCHIVOS EXTERNOS______________________________________


void showImportExportMenu(){

  cout << "[Import/export options]"<<endl
       <<  "1- Import from CSV"    <<endl
       <<  "2- Export to CSV"      <<endl
       <<  "3- Load data"          <<endl
       <<  "4- Save data"          <<endl
       <<  "b- Back to main menu"  <<endl
       <<  "Option: ";
}

//______________________________________________IMPORT MODUELES______________________________________________


// Hace el import de titulo del libro ademas de comprobarlo

void import_name(string &linea, Book &book,bool &corrrect_info){
  
  linea.erase(0,1);
  string name = linea.substr(0,linea.find('"'));
    book.title = name;
    Verification(corrrect_info,name);
  
    linea.erase(0,linea.find('"')+3);
    
    if(corrrect_info == false){ error(ERR_BOOK_TITLE); }

}

// Hace el import del autor del libro ademas de comprobarlo

void import_author(string &linea, Book &book,bool &corrrect_info){

  
  string author = linea.substr(0,linea.find('"'));

    book.authors = author;
    
    Verification(corrrect_info,author);

    linea.erase(0,linea.find('"')+2);
    if(corrrect_info == false){ error(ERR_BOOK_AUTHORS); }

}

// Hace import del año ademas de comprobarlo

void import_year(string &linea, Book &book,bool &corrrect_info){
  
  string year = linea.substr(0,linea.find(','));
  erase_blancs(year);
  year_Verification(corrrect_info,year);
  if(corrrect_info == true){ book.year = stoi (year); }
  linea.erase(0,linea.find(',')+2);
  if(corrrect_info == false){ error(ERR_BOOK_DATE); }

}

// Simplemente asigna el slug

void import_slug(string &linea, Book &book,bool &corrrect_info){

  book.slug = linea.substr(0,linea.find('"'));
  linea.erase(0,linea.find('"')+2);

}

// Hace import del precio ademas de comprobarlo

void import_price(string &linea, Book &book,bool &corrrect_info){

  string price = linea.substr(0,linea.length());

    price_verification(price, corrrect_info); // Modulo empleado en Add Book
    if(corrrect_info == true){ book.price = stof (price); }
    else { error(ERR_BOOK_PRICE); }
    linea.erase(0,linea.length());

}

// Funcion auxiliar que hace mas entendible el proceso de importacion

void importBook(BookStore &bookStore, string &linea){
  
  Book book;
  bool ok = true; // Variable para comprobar parametros

  import_name(linea,book,ok);

  if(ok == true){ import_author(linea,book,ok); }

  if(ok == true){ import_year(linea,book,ok);   }

  if(ok == true){ import_slug(linea,book,ok);   }

  if(ok == true){ import_price(linea,book,ok);  }
  
  if(ok == true){
    book.id = bookStore.nextId;
    bookStore.books.push_back(book);
    bookStore.nextId++;
  }
}

// Esta Funcion Se llama desde Argumentos y en import principal

void import_from_ImportCSV(const string name,BookStore &bookStore){
  
  ifstream ficheroImp(name);
  string linea;

  if(ficheroImp.is_open()){

    while(getline(ficheroImp,linea)){

      importBook(bookStore,linea);

    } 
    ficheroImp.close();
  }
  else{
    error(ERR_FILE);
  }
}

// Funcion import principal

void importFromCsv(BookStore &bookStore){

  string name,linea;
  
  message(M_FName);
  getline(cin,name);

  import_from_ImportCSV(name,bookStore);

}


//_______________________________________________EXPORT MODULES______________________________________________

// LA funcion escribe los datos de los libros en los ficheros

void export_write(BookStore bookStore, ofstream &ficheroExp,int i){

  ficheroExp << "\"" << bookStore.books[i].title << "\",\"" << bookStore.books[i].authors  << 
                "\","<< bookStore.books[i].year  << ",\""   << bookStore.books[i].slug     << 
                "\","<<  bookStore.books[i].price << endl;   

}

// Funcion export principal 

void exportToCsv(const BookStore &bookStore){

  string name;
  message(M_FName);
  getline(cin,name);

  ofstream ficheroExp(name);

  if(ficheroExp.is_open()){
    
    for(unsigned int i = 0; i < bookStore.books.size(); i++ ){
      export_write(bookStore,ficheroExp,i);
    }

    ficheroExp.close();
  }
  else{ error(ERR_FILE) ; }
}


//_________________________________________MODULOS DE FICHEROS BINARIOS_______________________________________


//_______________________________________________LOAD DATA______________________________________________________


//__BORRA TODA LA INFORMACION GUARDADA EN EL BOOKSTORE__

void option(BookStore &bookStore,char &opcion){

  do{
    message(M_ERASE_ALL);
    cin >> opcion;
    cin.get();
    opcion = toupper(opcion);

  }while(opcion != 'Y' && opcion != 'N');
}

//__AÑADE LIBROS AL BOOKSTORE__

void load_bookStore(BookStore &bookStore,ifstream &fichero){

  BinBook binBook;
  Book book;
  BinBookStore binBookStore;

    while(fichero.read((char *)&binBookStore,sizeof(BinBookStore))){
      bookStore.name = binBookStore.name;
      bookStore.nextId = binBookStore.nextId;
      while(fichero.read((char *)&binBook, sizeof(BinBook))){
        book.id = binBook.id ;
        book.title = binBook.title;
        book.authors = binBook.authors;
        book.year = binBook.year;
        book.slug = binBook.slug;
        book.price = binBook.price;
        bookStore.books.push_back(book);
      }
    }
}

// Funcion que se usa dos veces

void import_from_load(const string name,BookStore &bookStore){
  
  int i;
  ifstream ficheroImp(name,ios::binary);
    
    if(ficheroImp.is_open()){

      while(bookStore.books.size() > 0){
        bookStore.books.erase((bookStore.books.begin())+i);
        i++;
      }
      load_bookStore(bookStore,ficheroImp);
      ficheroImp.close();
    } 
    else{
    error(ERR_FILE);
    }
}

//__MAIN LOAD DATA FUNCION__ 

void loadData(BookStore &bookStore){
  
  char opcion;
  
  option(bookStore,opcion);

    if(opcion == 'Y'){
      
      string name;
        message(M_FName);
        getline(cin,name);
        import_from_load(name,bookStore);
        
    }
}

//_______________________________________________SAVE DATA________________________________________________________

//__PASA BOOK A BINBOOK __ 

BinBook binary(const BookStore bookStore,int i){

  BinBook binBook;

    strncpy(binBook.title,bookStore.books[i].title.c_str(),KMAXSTRING-1);
    strncpy(binBook.authors,bookStore.books[i].authors.c_str(),KMAXSTRING-1);
    strncpy(binBook.slug,bookStore.books[i].slug.c_str(),KMAXSTRING-1);
    binBook.id = bookStore.books[i].id;
    binBook.year = bookStore.books[i].year;
    binBook.price = bookStore.books[i].price;

  return binBook;
}

//__FUNCION QUE REALMENTE ESCRIBE AL FINCHERO BINARIO__

void Bin_bookstore(const BookStore bookStore, ofstream &ficheroExp){

  BinBookStore binBookStore;

    strncpy(binBookStore.name,bookStore.name.c_str(),KMAXSTRING-1);
    binBookStore.nextId = bookStore.nextId;
    
    ficheroExp.write((const char *)&binBookStore,sizeof(BinBookStore));

    BinBook binBook;
  
    for(unsigned int i = 0; i < bookStore.books.size(); i++){

      binBook = binary(bookStore,i);
      ficheroExp.write((const char *)&binBook,sizeof(BinBook));

    } 

}

//__FUNCION PRINCIPAL SAVE DATA__

void saveData(const BookStore &bookStore){

  string name;
    message(M_FName);
    getline(cin,name);

  ofstream ficheroExp(name,ios::binary);

    if(ficheroExp.is_open()){

      Bin_bookstore(bookStore,ficheroExp);

      ficheroExp.close();
    }
    else{error(ERR_FILE);}

}

//________MAIN IMPORT EXPORT MENU FUNCION_____________

void importExportMenu(BookStore &bookStore) {

  char opcion;
  do{
    showImportExportMenu();
    cin >> opcion;
    cin.get();
    switch(opcion){
      case '1': importFromCsv(bookStore);
        break;
      case '2': exportToCsv(bookStore);
        break;
      case '3': loadData(bookStore);
        break;
      case '4': saveData(bookStore);
        break;
      case 'b':
        break;
      default : error(ERR_OPTION);
        break; 
    }

  }while(opcion != 'b'); 
}

//________________________________________MODULOS DE ARGUMENTAS__________________________________________________

// Comprueba solo los casos erroneos

bool wrong_input_check(char *argv[]){
  
  string comando = argv[1];
  string comando_2 = argv[3];

  if(comando == comando_2 ){
    return false;
  }
  else if( comando != "-l" && comando != "-i"){
    return false;
  }
  else if( comando_2 != "-l" && comando_2 != "-i"){
    return false;
  }
  else{
    return true;
  }
}

// Comprueba si hay mas de 3 argumentos

void more_arguments(int argc,char *argv[],BookStore &bookStore,bool &correct_args){
  
  string comando = argv[1];
  string comando_2 = argv[3]; 
  string name;

  correct_args = wrong_input_check(argv);

  if(correct_args){
    if( comando == "-l"){
      name = argv[2];
      import_from_load(name,bookStore);
      name = argv[4];
      import_from_ImportCSV(name,bookStore);
    }
    else{
      name = argv[4];
      import_from_load(name,bookStore);
      name = argv[2];
      import_from_ImportCSV(name,bookStore);
    }
  }
}

// Funcion Principal argumentos

void arguments(int argc,char *argv[],BookStore &bookStore,bool &correct_args) {
  
  string name;
  
  if(argc == 3){

    string comando = argv[1];

    if(comando == "-i"){
      name = argv[2];
      import_from_ImportCSV(name,bookStore);
    }
    else if(comando == "-l"){
      name = argv[2];
      import_from_load(name,bookStore);
    }
    else{
      correct_args = false;
    }
  }
  else{
    more_arguments(argc,argv,bookStore,correct_args);
  }
}

//_______________________________________::::::: MAIN :::::::____________________________________________________

int main(int argc, char *argv[]) {
  
  BookStore bookStore;
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;
  bool correct_args = true;
  
  if(argc == 3 || argc == 5){
    arguments(argc,argv,bookStore,correct_args);
  }
  else if(argc == 1){
    correct_args = true;
  }
  else{
    correct_args = false;
  }
  
  if(correct_args == true){
    char option;
    do {
      showMainMenu();
      cin >> option;
      cin.get();

      switch (option) {
        case '1':
          showCatalog(bookStore);
          break;
        case '2':
          showExtendedCatalog(bookStore);
          break;
        case '3':
          addBook(bookStore);
          break;
        case '4':
          deleteBook(bookStore);
          break;
        case '5':
          importExportMenu(bookStore);
          break;
        case 'q':
          break;
        default:
          error(ERR_OPTION);
      }
    } while (option != 'q');
  }
  else{error(ERR_ARGS);}
  return 0;
}

