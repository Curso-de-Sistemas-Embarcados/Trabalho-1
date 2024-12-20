# Controle PID

A abordagem de controle a ser utilizada é o controle PID (Proporcional Integral Derivativo). O PID é um dos mais simples algoritmos de controle que proporciona um bom desempenho para uma grande variedade de aplicações.

O conceito fundamental desse tipo de controlador se baseia em monitorar uma variável de um processo (neste caso a posição do elevador medida pelo encoder) e medir a diferença entre seu valor atual (PAt - Posição Atual) a uma valor de referência (PRef - Posição de Referência) desejado. A partir dessa medida de **Erro = PRef - TAt**, toma-se uma ação de correção para que o sistema alcançe o valor desejado. A figura abaixo demonstra uma visão geral da estratégia de controle.

![Sistema de Controle](https://upload.wikimedia.org/wikipedia/commons/2/24/Feedback_loop_with_descriptions.svg)

O controle PID une três tipos de ações sobre a variável de controle para minimizar o erro do sistema até que o mesmo alcançe a referência desejada. No caso deste sistema, nossa variável monitorada é a PAt - Posição Atual do elevador e o seu controle é efetuado através do acionamento do **Motor (M)**, em ambas as direções, e nosso **Erro** é a diferença entre a Posição de Referência e a Posição Atual do elevador (Erro = PRef - PAt).

Detalhando as 3 ações do PID temos:
- **Controle Proporcional (P)**: ajusta a variável de controle de forma proporcional ao erro, ou seja, quanto maior o erro, maior a intensidade de acionamento do motor (0 a 100%). Esse ajuste é feito pela variável ***Kp***.
- **Controle Integral (PI)**: ajusta a variável de controle baseando-se no tempo em que o erro acontece, acumulando este erro (integral). Esse ajuste é feito pela variável ***Ki***.
- **Controle Derivativo (PD)**: ajusta a variável de controle tendo como base a taxa de variação do erro ou a velocidade com a qual o sistema está variando o erro. Esse ajuste é feito pela variável ***Kd***.

A figura abaixo mostra as equações envolvidas no cálculo do PID.

![PID](https://upload.wikimedia.org/wikipedia/commons/4/43/PID_en.svg)

O ajustes de cada constante do PID (Kp, Ki e Kd) tem efeitos distintos no controle do sistema conforme pode ser visto na figura  abaixo.

![PID - Variáveis Kp, Ki, Kd](https://upload.wikimedia.org/wikipedia/commons/3/33/PID_Compensation_Animated.gif)