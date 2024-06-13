## Aedes Combat: Viagem pelas estações

Projeto desenvolvido para a disciplina de Computação Gráfica na Universidade Federal do Vale do São Francisco - UNIVASF

- Adryelle Linhares
- Lucas Emmanuel
- Vinicius Lemos

Para compilar e executar é necessário instalar algumas coisas antes.

* Primeiramente é preciso instalar o Xmake, xmake vai facilitar nossa vida compilando e instalando todas as bibliotecas que precisamos.
  
  **link:** https://github.com/xmake-io/xmake/
  
  Para instalar basta seguir as instruções do repositorio desse github.

* Em seguida caso não tenha o Visual Studio instalado é necessário instalar.
  
  **link:** https://visualstudio.microsoft.com/pt-br/downloads/
  
  Baixe a versão community. Ao realizar a instalação deve instalar a dependência "c/c++ para desktops".
  
  O após instalado pode fechar o Visual Studio, não usaremos ele. Só precisamos da dependência que foi instalada no computador junto com ele, que contem o Xmake.

* O que realmente iremos utilizar será o Visual Studio Code(VS Code).
  
  **link:** https://code.visualstudio.com/download

* Lembrando que para rodar c/c++ no VS Code é necessário ter o MinGW instalado:

  **link:** https://www.youtube.com/watch?v=OKzFhpEQcyY&ab_channel=PETComputa%C3%A7%C3%A3o-UFPB

  Nesse link tem um passo a passo para instalar o MinGW no VS Code.

* Tendo realizados estas instalações podemos abrir o VS Code e instalar duas extensões uma que é a de c/c++ e a outra que é a do Xmake.

  VS Code configurado agora é abrir o github baixar o arquivo .zip do código. Extrair e abrir a pasta no VS Code.

* Em seguida basta dar o comando:

  **-> xmake**

  O xmake irá ver se você tem as bibliotecas necessárias instaladas, caso não tenha ele irá pedir pra instalar basta digitar **"y"** e dar "ENTER".

* Tendo compilado agora basta executar para isso temos que digitar o comando:

  **-> ./bin/aedes_combat.exe**

Prontinho agora estará compilando e executando o código tudo bonitinho.
