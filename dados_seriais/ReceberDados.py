#!/usr/bin/python3

##********************* IMPORTS **********************************
# Para coletar a hora atual do computador
import time 
# Para fazer comunicação via USB Serial
import serial


##********************** CUSTOMIZAÇÃO ***************************
# Número de coletas da porta serial a serem feitas
NUMERO_DE_COLETAS = 200

# Frequencia da porta serial
FREQUENCIA_SERIAL = 9600


##******************* FUNÇÕES AUXILIARES **********************
# Função que reescreve contador do terminal com o parâmetro recebido
def addContador(count):
  # O contador deve iniciar em 1
  if (count < 1 ):
    print("ERROR: COUNTER LESS THAN 1")
    exit(1)
  # Inicia a contagem pelo numero "1"
  elif (count == 1):
    print(count.__str__(), end="")
  # Segue a sequência para outros valores, limpado o valor anterior
  else:
    # Conta o numero de digitos para apagar
    digits = (count-1) // 10 + 1 
    # Gera a string para apagar o numero de digitos especificado
    backspace = "\b" * digits 
    # Realiza, finalmente, o print completo
    print(backspace + count.__str__() , end="", flush=True) 

##********************* FUNÇÃO MAIN *****************************
# Função principal a ser executada
def main():
  # Especifica qual a porta serial (USB) que deve ser utilizada
  #   Em linux, o nome das portas são: /dev/ttyACM0, /dev/ttyACM1, ...
  #   Em Windows, elas se chamam: COM1, COM2, COM3, ...
  #   Em MacOS, elas se chamam: /dev/tty.[alguma coisa]
  #   Procure na IDE do arduino onde está conectado o seu:
  #      Ferramentas -> Portas (Portas seriais)
  serialport = serial.Serial('/dev/ttyACM0', FREQUENCIA_SERIAL) 
  print('Serial Iniciada!')

  # Prepara o nome do arquivo com o horario do momento
  now = time.localtime()
  time_str = now.tm_year.__str__() + "-" + now.tm_mon.__str__()\
     + "-" + now.tm_mday.__str__() + "_" + now.tm_hour.__str__()\
     + "-" + now.tm_min.__str__() + "-" + now.tm_sec.__str__()
  fileName = time_str + "_SerialData.csv"

  # Criação do arquivo para escrita
  fileCsv = open(fileName, "w")
  # Escrita do cabeçalho CSV
  # (CUSTOMIZÁVEL)
  fileCsv.write("X,Y(x)\n")

  # Faz as 20 primeiras leituras e as descarta 
  # (Há erros de comunicação nesse começo)
  print("Descartando 20 primeiras medidas...\n")
  for i in range(0, 20): 
    serialValue = str(serialport.readline())
  
  # Realiza as coletas válidas dos dados
  print("Recebendo coleta de numero: (sao ", NUMERO_DE_COLETAS,\
     " ao total)", sep="" )
  for i in range(0, NUMERO_DE_COLETAS): 
    # Recebe linha da comunicação serial
    serialValue = str(serialport.readline())
    # Separa os valores que estavam separados por "|"
    data_signal = serialValue.split('|')
    # Verifica se data_signal não é nulo
    if (data_signal.__len__() > 2):
      # No início e no fim da linha tem caracteres de formatação,
      # por isso descarta data_signal[0] e data_signal[3]
      # Além disso o formato CSV exige vírgulas para separar inteiros
      data_string = data_signal[1] + "," + data_signal[2]
      # E escreve a nova linha do arquivo
      fileCsv.write(data_string+"\n")
      # Corrige o contador do terminal
      addContador(i+1)
    else:
      # Caso a linha da porta serial esteja vazia, notifica o usuário
      print("\nERROR: COMMUNICATION ERROR")

  # Realiza acertos finais
  print("\n")
  serialport.close()
  fileCsv.close()

  # Avisa o usuário do ocorrido
  print("Sucesso!\nArquivo salvo como:", fileName)

# Executa a função main para iniciar todo o programa
if __name__ == "__main__":
  main()
