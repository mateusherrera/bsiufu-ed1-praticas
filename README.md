# Práticas - ED1

Práticas realizadas na disciplina de Estrutura de Dados I (ED1).

## Sobre as práticas

As 5 primeiras práticas são exercícios em C.

As demais práticas são Tipos Abstratos de Dados (TAD's), filas, pilhas, lista estáticas, listas encadeadas, listas duplamente encadeadas, listas circulares, entre outros.

## Para compilar com gcc no terminal do Linux

Com o terminal, vá a pasta em que está o código fonte, e rode o seguinte comando:

```
gcc -c *.c
```

E depois gerar o executável com todos '.o':

```
gcc -o nome-do-executavel nome-do-objeto-1.o nome-do-objeto-2.o ... nome-do-objeto-n.o
```

Caso sejam necessários todos '.o', basta rodar:

```
gcc -o nome-do-executavel *.o
```

## Opcional: Organizar '.o' e executável

Na pasta da compilação.

Crie os diretórios 'obj/', para o '.o', e bin/, para o executável:

```
mkdir obj/
mkdir bin/
```

Depois mova o arquivo objeto e o executável para suas pastas:

```
mv *.o obj/
mv nome-do-executavel bin/
```

## Para rodar o executável no terminal

Digite o comando na pasta onde está o executável:

```
./nome-do-executavel
```
