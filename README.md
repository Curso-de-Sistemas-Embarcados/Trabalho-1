# Trabalho 1

Curso de Especialização em Sistemas Automotivos - Software
Disciplina de Padrão POSIX

## Enunciado: 

Você foi contratado para desenvolver um sistema que simula um ambiente de teste para veículos autônomos. O objetivo do sistema é gerenciar e monitorar múltiplos sensores e atuadores em um laboratório automotivo, processando dados em tempo real e garantindo a sincronização e a integridade das informações compartilhadas. Este sistema deve ser implementado em C e utilizar conceitos fundamentais do POSIX: processos com seus respectivos recursos de comunicação IPC (sinais, memória compartilhada, semáforos, etc) e threads com recursos de sincronia.

### Descrição do Problema:

Em um laboratório de testes automotivos, diferentes sensores (como de velocidade, temperatura) enviam dados para um sistema central, que os processa e decide como os atuadores devem responder (por exemplo, ajustar a velocidade ou aplicar os freios). Além disso, comandos de usuário acionando subsistemas do carro devem ser testados e funcionar reagindo à integração do usuário.

Para este projeto, você deve criar os seguintes programas:
1.	**Simulador de Sensores (Processo)**  
- Cada sensor deve ser representado por uma thread.  
- Sensores:     
    - **Velocidade do carro (km/h)**:  
    - **Rotação do motor** (virabrequim) RPM;  
    - **Temperatura do motor**.  
- Os sensores geram valores aleatórios simulando dados (ex.: velocidade entre 0 e 200 km/h).  
- Os dados dos sensores são escritos em área de memória compartilhada (fora do processo) para serem lidos pelo sistema de controle dos atuadores.   

2.	**Processamento Central (Memória Compartilhada)**:  
- Os dados dos sensores devem ser armazenados em uma **memória compartilhada** para que possam ser acessados pelo processo que controla atuadores.  
- Os processos que acessam esta área devem usar mecanismos de sincronização (como **semáforos**, **mutex**) para evitar inconsistências no acesso aos dados compartilhados.  

3. **Painel do Carro (Processo)**
- O painel do carro irá representar os comandos de usuário auxiliares ao controle do veículo como acionamento de:
    - **Ligar Setas** (esquerda / direita);  
    - **Ligar Farol** (baixo / alto);  
    - **Pedal do Acelerador**;
    - **Pedal de Freio**;
- A simulação dos comandos deve ser feita através de interface de teclado simples com uma lista de opções na tela para uqe o usuário possa acionar ou desligar (por números ou letras) cada um dos itens.
- O estado de cada comando deve ser enviado ao processo Controlador através de **Fila de Mensagens**.  

3. **Controlador (Processo)**
- O controlador central deve ser responsável por inicializar a área de memória compartilhada e a fila de mensagens bem como criar os processos auxiliares (simulador de sensores e o painel do carro).  
- O programa deve ser capaz de receber sinais para:  
    - Pausar os testes (SIGUSR1).  
    - Encerrar os testes (SIGUSR2).
- O processo controlador central deve ser capaz de ler periodicamente os dados dos sensores (**memória compartilhada**) e receber os comandos de usuário (**Fila de mensagens**) e acionar os respectivos atuadores.
- **Atuadores**:   
    - **acelerador**;
    - **freio**;  
    - **luzes de freio**;  
    - **faróis**;  
    - **setas**.
- Atuadores processam dados dos sensores simular ações (ex.: reduzir a velocidade caso ultrapasse um limite, acelerar quando a velocidade está abaixo de um limite inferior).
- Ao final do teste, o controlador central deve gerar um relatório consolidado dos dados processados (ex.: número de ocorrências em que a velocidade ultrapassou o limite, número de ações realizadas pelos atuadores).

## Requisitos do Sistema:

- O programa deve ser implementado em C e usar apenas bibliotecas padrão do POSIX.  
- Documentação do código é obrigatória, incluindo comentários sobre o funcionamento de cada parte.  

## Entregáveis:  
- Código-fonte bem documentado.
- Arquivo README.md explicando como compilar e executar o programa.  
- Vídeo demonstrando o programa em funcionamento e comentando a arquitetura da solução.  
- Relatório explicando as decisões de design e como os conceitos de POSIX foram aplicados.

## Critérios de Avaliação:
1.	Correção e funcionalidade do programa (50%).
2.	Uso correto dos conceitos do POSIX (30%).
3.	Organização e clareza do código e da documentação (10%).
4.	Testes e validação do programa com diferentes cenários (10%).
