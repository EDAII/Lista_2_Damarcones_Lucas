#include<iostream>
#include<string>
#include<fstream>

using namespace std;

typedef struct s_pessoa{
  string nome;
  string cpf;
  string idade;
  string rg;
}Pessoa;

void* abertura(){

  Pessoa *p = new Pessoa[1000];
  string pessoa;
  string temp;
  ifstream arq("pessoas.txt");
  int cont = 0;

  if(arq.is_open() == true){
    while(getline(arq, pessoa)){

      if(pessoa[0] == 'n')
        p[cont].nome = pessoa;

      if(pessoa[0] == 'i')
        p[cont].idade = pessoa;

      if(pessoa[0] == 'c')
        p[cont].cpf = pessoa;

      if(pessoa[0] == 'r')
        p[cont].rg = pessoa;
      // temp="";
      // for(int i = 0; i < pessoa.size(); i++){
      //   if(pessoa[i] == 'c' && pessoa[i+1] =='p' && pessoa[i+2] == 'f')
      //     break;
      //   else
      //     p[cont].nome = p[cont].nome + pessoa[i];
      //
      // }
      cout << p[cont].nome;
      // cout << p[cont].idade;
      // cout << p[cont].cpf;
      // cout << p[cont].rg << endl;
      cont++;
    }

  }
  else
      cout << "Deu errado!!" << endl;

}
void imprimir(Pessoa pessoa[]){

  int i = 0;

  while (pessoa[i].nome != "\0"){
    cout << pessoa[i].nome;
    cout << pessoa[i].idade;
    cout << pessoa[i].cpf;
    cout << pessoa[i].rg << endl;
    i++;
  }

}

int main(){

  Pessoa cad_inicial[1000];
  cad_inicial =  abertura();
  imprimir(*abertura());
  cout << "teste"<< endl;

  return 0;
}
