#include <Arduino.h>

//*string em estilo C - explicita
// \0 é o terminador
char primeiroNomeExplicito[8] = {'T', 'h', 'i', 'a', 'g', 'o', '\0'};
char nomeCompleto[20] = {'T', 'h', 'i', 'a', 'g', 'o'};

//*Classe String
String primeiroNomeString = "Thiago";

void setup()
{
  Serial.begin(9600);
  Serial.println();

  //Serial.println(primeiroNomeExplicito);
  //Serial.println(primeiroNomeImplicito);
  //Serial.println(primeiroNomeString);

  //*para strings em estilo C a função strlen mostra o tamanho da variavel
  //int tamanhoNome = strlen(primeiroNomeImplicito);
  //Serial.println(tamanhoNome);


  //*strcpy copia o conteudo de uma string para outra, incluindo o caractere \0
  //strcpy(nomeCompleto, "Oliveira");
  //Serial.println(nomeCompleto);

  //*alterando caracteres de forma individual
  //nomeCompleto[0] = 't';
  //Serial.println(nomeCompleto);

  //*acrescentar um texto dentro de uma variavel - concatenação
  //strcat(nomeCompleto, " Oliveira");
  //Serial.println(nomeCompleto);

  //*indica o ponteiro - ou seja, a partir desse ponteiro, exibe desde entao ate o terminador 
  char *enderecoDaLetra = strchr(nomeCompleto, 'w'); 

  //*NULL é o terminador, ou seja, \0
  // if (enderecoDaLetra != NULL)
  // {
  //   Serial.println("Letra encontrada!");
  //   Serial.println(enderecoDaLetra);
  // }

  // else
  //{
  //  Serial.println("Letra não encontrada!");
  //}
  
  //*c_str() converte uma String(classe) para uma string em estilo C e retorna o endereço dessa sequência.
  //*O * indica um ponteiro, ou seja, uma posicao da memoria
  // const char *textoStringEmC = primeiroNomeString.c_str();
  // Serial.println(textoStringEmC);


  //*String (classe)
  // String nomeAluno1 = "Matheus";
  // String nomeAluno2 = "Giovanna";

  // String mensagem = "Esses são os meus alunos: ";

  //?concatenação
  // Serial.println(mensagem + "Matheus e Giovanna");
  // Serial.println(mensagem + nomeAluno1 + " e " + nomeAluno2);

  // String nomeAluno1 = "Rufina";
  // String nomeAluno2 = "Padovan";

  //*length() é um metodo da classe String que retorna o comprimento da string
  // int tamanhoPalavraString = nomeAluno1.length();
  // Serial.println(tamanhoPalavraString);

  //*acessando um caractere em uma posicao especifica
  // char letraAtravesDaPosicao = nomeAluno2.charAt(3);
  // Serial.println(letraAtravesDaPosicao);

  //Serial.println(nomeAluno2[4]);

  String nomeDoCurso = "Desenvolvimento de Sistemas Sistemas";

  //*Procurando um texto dentro da String e retorna o indice da primeira letra da palavra
  // int posicaoDaPalavraEscolhida = nomeDoCurso.indexOf("Sistemas");
  // Serial.println(posicaoDaPalavraEscolhida);

  //*Substitui a palavra escolhida pela que voce quer, mesmo que ela seja encontrada mais de uma vez (cuidado, o replace é case sensitive)
  // nomeDoCurso.replace("Sistemas", "Games");
  // Serial.println(nomeDoCurso);

  //*transforma a string em maiuscula
  // nomeDoCurso.toUpperCase();
  // Serial.println(nomeDoCurso);

  //*transforma a string em minuscula
  // nomeDoCurso.toLowerCase();
  // Serial.println(nomeDoCurso);

  //*Transforma string em int
  // String numeroEmString = "15";
  // int conversaoStringParaInt = numeroEmString.toInt();
  // Serial.println(conversaoStringParaInt);

  //*extraindo uma parte da string
  // String parteDaFrase = nomeDoCurso.substring(19); //*A partir da posicao exibe todo o resto da string
  //String parteDaFrase = nomeDoCurso.substring(19, 27); //*Exibe somente entre as posicoes definidas
  //Serial.println(parteDaFrase);

  String textoDigitado = " "; //string vazia

  //*length verifica se esta vazio pelo tamanho da string
  // if (textoDigitado.length() == 0)
  // {
  //   Serial.println("Texto vazio");
  // }
  // else
  // {
  //   Serial.println("Há texto");
  // }

  //*isEmpty verifica se esta vazio pela string
  // if (textoDigitado.isEmpty() == 0)
  // {
  //   Serial.println("Texto vazio");
  // }
  // else
  // {
  //   Serial.println("Há texto");
  // }
  

  //?Exibição formatada

  //*quebra a linha
  //Serial.printf("Olá mundo! \n\r");

  //*Tabulação de parágrafo
  //Serial.printf("Olá mundo! \t");

  int diaAtual = 24;
  int mesAtual = 4;
  int anoAtual = 2026;

  int porcentagem = 100;

  

  //* %d - para valores inteiros | %% é para exibir a %
  //Serial.printf("Ano atual: %d\n\r", anoAtual);
  //Serial.printf("Lucro: %d%%", porcentagem);

  //Serial.printf("Ano atual: %d\n\rLucro %d%%\n\r", anoAtual, porcentagem);

  //*concatenação para deixar no formato dd/mm/aaaa e mudança de tipo nesse momento (casting) para String 
  //String dataAtual = "Data Atual: " + String(diaAtual) + "/" + String(mesAtual) + "/" + String (anoAtual);

  //*Casting em C é a conversão explicita de um tipo de dado para outro, usando a sintaxe (tipo) variavel. Ela permite forçar a interpretação de uma variavel ou expressão como um tipo diferente.

  //Serial.println(dataAtual);

  //string em estilo c
  //const char *sobrenomeProfessor = "Oliveira";

  //* %s para string, porém precisa estar em estilo C, utilize a função c_str() caso esteja em objeto String
  

  //* O %s em C é um especificador de formato usado em funções de entrada/saída (como printf e scanf) para manipular strings (cadeias de caracteres). Ele indica que o programa deve ler ou exibir uma sequência de caracteres até encontrar um caractere nulo '\0'.

  //Serial.printf("Professor: %s %s", primeiroNomeString.c_str(), sobrenomeProfessor);

  //char hashtag = '#';
  //char letra = 'A';

  //* %c é para um unico caractere
  //Serial.printf("Letra: %c\n\rSimbolo: %c ", letra, hashtag);

  //float temp = 23.54;

  //*%.if é para tipos float - apos o . indicamos a qnt de casas depois da virgula
  //Serial.printf("Temperatura: %.if", temp);

  //bool conectado = false;

  //Serial.printf("WiFi está conectado? %s", conectado ? "Sim" : "Nao");


  //*buffer é o tamanho da memória temporária
  //char buffer[50];

  //* sniprintf é para printar com formato na tela porém você controla o tamanho da exibição
  //sniprintf(buffer, sizeof(buffer), "O professor %s tem %d anos\n\r", primeiroNomeString.c_str(), diaAtual);

  //Serial.print(buffer);
}

void loop()
{

}
