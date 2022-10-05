# Como coletar dados no computador via Porta Serial 
(Ferramenta compatível com Arduino e outros microcontroladores que possuam 
comunicação serial. Ou seja, a grande maioria.)

## Introdução

A fim de analisarmos os valores medidos e calculados no Arduino,
podemos gravá-los no computador a fim de gerar gráficos, médias 
e outras medidas que nos permitam mensurar melhor o que está ocorrendo
em nosso projeto. Para isso, utilizaremos um protocolo de comunicação
muito simples, chamado de **comunicação serial**. Ela esta presente em
diversos microcontroladores e nos permite receber os dados via
USB do computador de uma forma eficiente e ágil, para a maior parte
das aplicações. Assim, será possível gravar as informações em arquivo
de formato CSV, que pode ser aberto em programas como Excel e GoogleSheets
para manipulação à posteriori.
> **Observação**: Fica como sugestão de aprofundamento pesquisar o
funcionamento da comunicação serial. Desde já, aviso que é simples e,
por isso, ela muito utilizada até hoje, mesmo não sendo tão nova.

## Código no microcontrolador

Primeiramente, é necessário que o microcontrolador envie os dados 
pela comunicação serial. Nessa etapa, o mais importante é verificar
alguns parâmetros que você deve decidir para o projeto de comunicação:
 * Taxa de bits da comunicação serial
   (*no meu exemplo usei 9600 Hz*)
 * Número de variáveis a serem passadas para o computador
   (*no meu caso são 2: tempo e tensão da GPIO*)]
 * Formato dos dados
   (*no meu exemplo foram sempre inteiros
   e recomendo fazer assim por ser mais simples e
   não necessitar editar muito o script em python*)

Além disso, ressalto que os valores devem ser passados 
em uma única linha, e que devem ser utilizados "|" para
os separar, além de inserir um no ínício e outro
ao final da linha. Dessa forma, segue um exemplo:

``|12345|222|9876|`` 

Nesse caso, estariam sendo passados **três** variáveis ao computador.

Para exemplificar, apresento meu código para testes. Ele 
lê a tensão em uma entrada analógica do Arduino (que se origina de um
sensor de luminosidade) e passa para a comunicação
serial junto ao instante de tempo em que ocorreu a medição).

~~~C++
String sinais; // Variável usada para enviar os sinais
int leitura;  // Armazena a tensão medida

void setup() {
  Serial.begin(9600); // Inicia comunicação serial   
  pinMode(A1, INPUT);  
}

void loop() {
  leitura = analogRead(A1);
  // Escreve os valores de interesse entre "|"
  sinais = "|" + String(micros()) + "|" + String(leitura) + "|";
  Serial.println(sinais); // Imprime os dados no monitor serial
  delay(100); // Aguarda 100 ms para uma nova medida
}
~~~
## Preparação do computador

Para realizar a comunicação serial no computador utilizando python,
é necessário, em alguns casos, instalar a biblioteca PySerial. Seja 
Windows, Linux ou MacOS, digite no prompt de comando:

```
pip install pyserial
```


## Script em python 

Após o preparo do código a ser compilado no microcontrolador
é necessário calibrar e executar o script em python do computador,
para fazer a recepção e o armazenamento dos dados. 

Na etapa de modificação do script, é necessário se atentar aos parâmetros
comentados acima. Caso algum deles seja diferente do meu exemplo,
será necessário alterar um pouco o código. MAS NADA DE OUTRO MUNDO, vai?!
Está tudo bem comentado no código.

Por exemplo, se for alterado de duas pra três variáveis, 
será necessaŕio mudar as linhas 60 e 81 o script para:

~~~Python
fileCsv.write("X,Y(x),Z\n")
(...)
data_string = data_signal[1] + "," + data_signal[2] "," + data_signal[3]
~~~

Tranquilo, não?

> **Aviso**: se for alterar o formato de alguma variável para
> ponto flutuante ou string, será necessário registrar no arquivo
> entre aspas. Exemplo: ``123,"Bem quente"``
>
> Por isso, precisa alterar o código em python para acrescentar
> essas aspas ao escrever no arquivo. Fica como desafio, ou então *venha
> para o lado inteiro da força* e esqueça isso.

Destaca-se também, a importância de alterar no código o nome da porta
do seu computador em que está conectado o seu microcrontrolador. Basta
ler o código para entender, pois está explicado melhor lá.

O script está em anexo para baixar e usar. Ele está bem comentado e vale à pena ser lido para compreender melhor as minúcias do que ocorre. 

Caso não saiba como rodar um script python, é simples: basta navegar no terminal até o 
diretório em que se encontra o arquivo e rodar o comando:

```
python3 ReceberDados.py
```

## Finalmentes

O monitor Ricardo Chiquetto do Lago, autor desse material, fica
à disposição. (Email: cdolago@usp.br)

> **Observação**: tudo foi preparado e projetado em uma máquina
Linux. Portanto, é importante notificar caso encontre falhas, principalmente em máquinas Windows e MacOS.