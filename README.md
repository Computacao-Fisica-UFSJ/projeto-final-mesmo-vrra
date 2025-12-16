[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/bQrFkq0H)
# Simulador de arrombamento de fechadura
## Contextualização, aplicação e motivação
### Contextualização
Diferente do nosso primeiro trabalho, agora simularemos o sistema de arrombamento de fechaduras do The Elder Scrolls IV: Oblivion (2006), da Bethesda. Agora, o processo é ligeiramente diferente:
- Você testa se o pino está na posição correta (levanta uma das chaves).
    - Se estiver, você gira o potenciômetro e ele acusará se o pino está na posição certa ou não. Se estiver, você avança para o próximo pino, e continua avançando até de fato arrombar a fechadura.
    - Se você acabar girando o potenciômetro e o pino estiver na posição errada, você volta para o início.

Igual ao primeiro trabalho, também há botões para se selecionar a dificuldade que deseja, e essa dificuldade é traduzida para quantos pinos são necessários para destravar a fechadura. As cores verde, amarelo e vermelho, acionadas pelos botões, indicam as dificuldades fácil, média e difícil, respectivamente.
### Aplicação
Esse projeto é uma boa chance para aprender a mexer em dispositivos que transformam sinais analógicos, do "mundo real", em sinais digitais; isso é feito por meio dos botões e dos potenciômetros. Além disso, é uma boa oportunidade para se mexer com comunicação de um dispositivo com a placa Arduino por meio do protocolo I<sup>2</sup>C por conta da tela de LCD.
## Lista de materiais
Diferente do primeiro trabalho, neste utilizamos uma chave DIP -- uma série de interruptores -- que simula a sequência correta de pinos a ser arrombada. Por exemplo, por meio de código pode ser definido que a sequência correta de pinos é 2314, logo, seria necessário ativar as chaves nessa sequência. Além disso, no lugar dos potenciômetros de pressão e torque, utilizamos agora uma célula de carga, que fica responsável por detectar uma pressão em cima dela, que seria análoga 
| Material                | Quantidade | Imagem |
|-------------------------|------------|--------|
| Placa Arduino Uno R3    | 1          |<picture><source srcset="/assets/images/arduino.png" media="(orientation: portrait)" /><img src="https://datacapturecontrol.com/products/static/images/product-references/microcontrollers/atmega328p-uno-r3/atmega328p-uno-r3-listing.png" alt="Placa Arduino Uno R3" width="250"/></picture>|
| *Breadboard*            | 2          |<picture><source srcset="/assets/images/arduino.png" media="(orientation: portrait)" /><img src="https://tinycircuits.com/cdn/shop/products/ASR00044-01.png?v=1674589122" alt="Breadboard" width="250" /></picture>|
| Potenciômetro           | 1       |<picture><source srcset="/assets/images/arduino.png" media="(orientation: portrait)" /><img src="https://cdn.awsli.com.br/2798/2798180/produto/336250708/8fb42bbe73b9a436a4a1b86bf6e3071d-2pktor61yq.png" alt="Potenciômetro" width="250"/></picture>|
| Servo motor SG90        | 1          |<picture><source srcset="/assets/images/arduino.png" media="(orientation: portrait)" /><img src="https://d229kd5ey79jzj.cloudfront.net/788/images/788_1_X.png?20250730165301" alt="Resistor" width="250"/></picture> |
| Grove LCD RGB Backlight | 1          |<img src="https://cdn-reichelt.de/bilder/web/xxl_ws/A300%2F104030001_1.png?type=ProductXxl&" width="250" height="250" />        |
| Chave DIP com 10 interruptores          | 1         | <img width="250" height="250" alt="image" src="https://cdn.awsli.com.br/2500x2500/2723/2723924/produto/273276472/92582ee1-8dda-4293-a9ea-dc4d21f6e969-nu2r2wkm4l.png" /> |

Houve, também, a necessidade de se conectar o motor e o display numa fonte externa, visto que a placa de Arduino por si só não conseguia alimentar esses dois componentes por si só.

## Montagem

### Explicação do funcionamento
Uma senha aleatória de cinco dígitos, de zero a quatro, será gerada. Joga-se da seguinte maneira:
- O usuário levanta qualquer uma das cinco chaves do switch e gira o potenciômetro até o final;
- Se a posição que foi levantada for a correta, o display indicará P: 1 e se encherá de jogos-da-velha (#); do contrário, a quantidade de jogos-da-velha mostrados indicará o quão perto este pino está do pino correto.
    - Quanto mais jogos-da-velha no display, mais perto se está; do contrário, está longe.
- Quando os cinco "pinos" estiverem na posição correta, o motor será acionado e a tampa da caixa se levantará.
- Se o jogador mantiver por muito tempo o potenciômetro no máximo, ele perderá uma gazua (uma tentativa).
    - Há no máximo cinco tentativas de "destravar o cofre".
- Quando se perde totas as tentativas, o jogo termina.
- Qoebrar uma gazua faz você voltar à estaca zero, em que não há nenhum pino na posição correta.
### Diagrama
O seguinte diagrama foi feito em Fritzing 1.0.6 e mostra como deve ficar a montagem do projeto.

<img width="500" height="600" alt="fechaduraSketch_bb" src="https://github.com/user-attachments/assets/5bcccd53-7ada-483c-90b0-afab84c7a34a" />

### Foto da montagem
![montagem1](https://github.com/user-attachments/assets/b789417a-6086-4235-8fef-0c7945044bc9)

### Vídeo do projeto
https://github.com/user-attachments/assets/a251e545-da5d-4b4c-8b30-afe1a2608bfb



## Problemas encontrados
Os problemas foram basicamente os mesmos do primeiro. O adicional foi a célula de carga:
### Célula de carga
- É necessário calibrar a célula de carga para que ela registre o peso correto imposto nela, e essa calibragem pode levar um tempo considerável da montagem do projeto.
### Botão
- É necessário fazer o *debounce* no código para evitar alternância muito rápida entre 0 e 1, impedindo um valor exato para ser exato.
### Tela LCD
- A qualidade dos cabos e a conexão deles na tela podem acabar fazendo com que lixo seja transmitido ao invés de um caractere, tornando o projeto inutilizável, sendo necessário desligar e ligar a placa.
## Referências
- https://www.robocore.net/sensor-robo/celula-de-carga-50kg?srsltid=AfmBOopS0AHtNsg180NE8FBlewqBJEIo9beVb6j75O-aJlPdHVUcDLDd
