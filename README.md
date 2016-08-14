# ep1sh

> Trabalho realizado para matéria MAC0422 - Sistemas Operacionais, IME USP

Implementar um shell bem simples, para permitir a interação do usuário com o sistema operacional

O shell, chamado de ep1sh, a ser desenvolvido, deve permitir a invocação(execução) dos 3 binários abaixo com exatamente os argumentos abaixo. Nao há necessidade de testar o shell para outros programas e nem para os binarios abaixo com outros argumentos: 
```sh
/bin/ls -l
/bin/date
./ep1 <argumentos do EP1>
```
O shell tambem precisa ter os 2 comandos abaixo embutidos nele, que devem obrigatoriamente ser implementados usando chamadas de sistema do Linux. Esses comandos devem ser executados sempre com os argumentos abaixo e que devem fazer exatamente o que esses 2 comandos fazem no shell bash:
```sh
chmod <modo numérico> <arquivo no diretório atual>
id -u
```
Nao se preocupe em tratar os erros do  chmod. O usuario nunca vai tentar mudar a permissão de algum arquivo que nao existe ou usar algum valor no modo numérico incorreto. Ele também nunca vai tentar mudar a permissao de algum diretório ou link. Ele sempre mudará a permissão usando o modo numerico do [chmod]

O shell tem que suportar a listagem de comandos que foram executados previamente, e a edição desses comandos para serem executados, por meio das funcionalidades das bibliotecas GNU readline e GNU history. No Debian ambas fazem parte do pacote libreadline-dev. Mais informações podem ser vistas na documentac¸ao da biblioteca em  ftp://ftp.gnu.org/pub/gnu/readline/ . Não ha necessidade de utilizar outras funcionalidades das bibliotecas alem das requisitadas no iníıcio deste
parágrafo.

O prompt do shell deve conter o diretorio atual entre parênteses seguido de ‘:’ e de um espaço em branco, como no exemplo abaixo que mostra o shell pronto para rodar o comando id -u que imprimira
o UID do usuario: 
```sh
(/home/mac/): id -u
```
[chmod]: <https://www.vivaolinux.com.br/artigo/Entendendo-as-permissoes-de-arquivos-(chmod)>
