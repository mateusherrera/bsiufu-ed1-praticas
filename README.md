# Práticas - ED1

Práticas realizadas na disciplina de Estrutura de Dados I (ED1).

## Sobre as práticas

As primeiras práticas são exercícios em C, muitos voltados para o uso de matrizes e alocação dinâmica.

As demais práticas são Tipos Abstratos de Dados (TAD's), filas, pilhas, lista estáticas, listas encadeadas, listas duplamente encadeadas, listas circulares, entre outros.

## Para compilar com gcc no terminal do Linux

Com o terminal, vá a pasta em que está o código fonte, e rode o seguinte comando:

```
gcc -c "nome-do-.c-sem-aspas"
```

E depois gerar o executável com todos '.o' gerados:

```
gcc -o "nome-para-o-executavel-sem-aspas" "nome-do-.o-sem-aspas-1" "nome-do-.o-sem-aspas-2" ... "nome-do-.o-sem-aspas-n"
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
mv "nome-do-executavel-sem-aspas" bin/
```

## Para rodar o executável no terminal

Digite o comando na pasta onde está o executável:

```
./"nome-do-executável-sem-aspas"
```
