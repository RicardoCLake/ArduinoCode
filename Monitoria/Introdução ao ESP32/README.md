# GUIA PARA O ESP 32

Material de apoio preparado por [Ricardo Chiquetto do Lago](https://edisciplinas.usp.br/user/profile.php?id=292217), monitor da disciplina.

## Instalação

1. Cole esse **link** https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json em:
      `Arquivo >> Preferências >> URL's adicionais para gerenciadores de placas`

      Isso acrescenta um local para a IDE buscar as dependências da placa Esp32.

2. Vá para: `Ferramentas >> Placa >> Gerenciador de placas >> Esp32` e clique em "Install". Isso instala as dependências específicas para essa placa.

3. Navegue até: `Ferramentas >> Placa >> Esp32 Arduino` e selecione "ESP32 DEV Module".

4. Navegue até: `Ferramentas >> Portas` e selecione a porta onde se estiver a ESP32 (normalmente é a opção que aparece).

Pronto, agora já deve ser possível trabalhar com sua ESP32.

> **Importante:** às vezes, ao fazer upload dos códigos para a placa, além de clicar no botão "Carregar" da IDE, é necessário pressionar o botão Boot da própria placa. Isso, deixará a placa disponível para receber novos códigos. Como saber se precisa apertar o botão? Ficará evidente se nas mensagensdo painel não sair de "Connecting..." ou até mesmo der algum erro.

## Pinos da Placa (GPIO)

### Funções do pinos

O microcontrolador possui diversos pinos e é por meio deles que são realizadas suas ações. Eles podem ser programados pelo usuário para assumir diversos papeis, como ser pino de saída digital, entrada digital, saída analógica (DAC), entrada analógica (ADC), touch capacitivo, além de servir a vários protocolos de comunicações padronizados como serial tx-rx, UART, I2C, I2S, dentre outros.

> **Importante**: em comparação com o Arduino UNO que usa tensões de 0V a 5V, a tecnologia do ESP32 utiliza tensões nos pinos que vão de 0V a 3,3V, ou seja é diferente! _Isso não deve ser nada amedrontador_, muitos sensores e circuitos estão preparados para essa diferença. Porém verifique a tecnologia dos sensores que pretende utilizar.

É **muito interessante**, (sério, recomendo de coração) que você pesquise sobre quais são as funções disponíveis nos pinos, pois isso estimula a critividade e sugere ideias daquilo que pode ser feito com o microcontrolador. Caso se sinta confortável em ler um material em inglês, tenho uma ótima sugestão no link abaixo (juro que é sucinto).

> **Observação**: Somente desconsidere a imagem presente na página com as posições dos pinos, pois ela é de outra placa esp32, com 36 pinos, enquanto a nossa é de 30. O nomes dos pinos e suas respectivas funções são as mesmas, pelo menos.

[Link para sugestão de página com descrição das funções](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)


### Pinagem física

O módulo ESP32-WRoom-32, quadrado metálico central que é produzido pela empresa chinesa *Expressif*, possui 38 pinos, incluindo aqueles de alimentação. Contudo, existem diferentes empresas que montam a placa do ESP32, e elas acabam fazendo isso de maneiras diferentes, mesmo que o coração delas (Esp32-WRoom-32) seja o mesmo. Por isso, há diversos formatos de esp32 no mercado e, mesmo que as funções dos pinos sejam as mesmas, é necessário verificar onde se encontram cada um desses pinos na placa.

Por exemplo, existe uma versão de placa, comum no mecado, com 36 pinos. Assim,ela deixa disponível quase tudo do chip para o usuário acessar. Porém, alguns desses pinos não tem muitas possibilidades de uso, e, aliás, podem impedir o funcionamento correto da placa se alterados indevidademente (pois já possuem funções padrão que são essenciais ao ESP32). Por isso, um outro encapsulamento existente da placa possui 30 pinos apenas, que podemos chamar de mais "seguro". Aliás, esse é o formato que os professores da disciplina decidiram utilizar, para uma experiência mais confortável dos alunos. 

A fim de auxiliar você na elaboração e execução do seu projeto, segue abaixo uma imagem com a legenda dos pinos. Vale ressaltar que em código deve-se sempre se referir ao pino pelo seu número de GPIO. Por exemplo, se quiser usar o "Touch9", você irá fazer uma leitura do touch do pino 32. 

Seria possível chamá-lo de "T9"? Sim, até é possível usar esse apelido do pino, mas não é sempre que isso funciona, por isso, repito, chame-o pelo GPIO que é mais seguro.

![Portas da placa](https://edisciplinas.usp.br/draftfile.php/5120080/user/draft/210661970/img1%20%281%29.png)

Fonte: [https://randomnerdtutorials.com/getting-started-with-esp32/](https://randomnerdtutorials.com/getting-started-with-esp32/)


### Durante o Boot

Durante o Boot, ou seja, durante a inicialização da placa, diversos eventos internos ocorrem. Isso, às vezes, causa oscilações nas tensões dos pinos. Além disso, existem pinos que terminam o boot em HIGH (se não forem configurados pelo usuário), o que se diferencia do Arduino que tem por padrão deixar os pinos em LOW (se não me falha a memória).

Por isso, recomenda-se consultar a imagem abaixo caso note algum mal funcionamento inesperado dos pinos, principalmente no que tange o início da execução do código. Na dúvida, trocar os pinos envolvidos no bug pode ser uma opção, se possível...

![Portas no boot](https://edisciplinas.usp.br/draftfile.php/5120080/user/draft/210661970/img2.png)

Fonte: https://www.fernandok.com/2018/03/esp32-detalhes-internos-e-pinagem.html

## Em código

Uma das formas de se programar para a ESP32 é utilizando a própria framework do Arduino. Às vezes ela pode não ser a mais otimizada, contudo, ela é muito prática e bem documentada, além de suprir boa parte das demandas. Por isso, essa será a estratégia adotada inicialmente. 

Ao invés de ficar explicando todos os códigos, serão apresentadas abaixo algumas versões adaptadas das aulas e que foram testadas em ESP32. Assim, espera-se que seja possível você verificar a semelhança com o que fora utilizado até então.

Depois, serão comentados outros códigos simples, porém que são úteis para verificar as opções presentes na ESP32. (Essa parte ainda está mais em preparação).

### S2

Código adaptado da aula S2:

```C++
//Blink Test
// Led na GPIO_04 em série com resistor de 220

int ledPin = 4;

void setup()
{
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(ledPin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
```

### S3

Código adaptado da aula S3:

```C++
// Button Test

int ledPin = 4;
int buttonPin = 22;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  if (digitalRead(buttonPin))
  {
    digitalWrite(ledPin, HIGH);
    // Removed to simplify:
    //delay(300); // Wait for 300 millisecond(s)
    //digitalWrite(ledPin, LOW);
    //delay(300); // Wait for 300 millisecond(s)
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
```

### Touch

A fim de explorar a função interessante do ESP32, chamado de Touch ("Toque físico"), foi criado esse código. Simplesmente existe um fio no GPIO15 e o teste consiste em encostar o dedo nesse fio e observar a saída no monitor serial. Simples, não? E muito fascinante!

> **Observação**: não é necessário avisar que encostar o dedo no fio que está ligado à GPIO para leitura de Touch não dá choque, né? 

```C++
// Touch Test

int touchPin = 15; //or "= T3"

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando o teste...");
}
void loop()
{
  Serial.println(touchRead(touchPin)); 
  delay(100);
}
```

### Wifi

Essa parte ainda ficará sem tantas explicações pois é um mundo à parte que exige atenção especial. Porém, recomenda-se desde já olhar os código de exemplo que aparecem na IDE após as instalações das dependências do ESP32. Ficam em: `Arquivo >> Exemplos >> [Lá para baixo] Wifi`.

Em especial, sugere-se fortemente olhar, nessa ordem, os exemplos: WiFiScan, WiFiAccessPoint, SimpleWiFiServer.

### Bluetooth

Ídem o Wifi: sugere-se, por agora, pesquisar pelos exemplos na IDE, ou da internet mesmo. Qualquer coisa o monitor [Ricardo](https://edisciplinas.usp.br/user/profile.php?id=292217) se coloca à disposição para tentar ajudar.

## Considerações finais

Tudo nessa página é somente um rascunho a ser aprimorado. Aceita-se sugestões, correções e apontamentos. Além disso, vale ressaltar que o que está aqui é apenas uma base e um norte para impulsionar aqueles que se interessarem por essa tecnologia. Qualquer coisa, o monitor [Ricardo](https://edisciplinas.usp.br/user/profile.php?id=292217) se coloca à disposição para tentar ajudar.