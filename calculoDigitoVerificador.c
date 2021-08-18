/*
    Programa para o cálculo do digito verificador do nosso número de boletos bancários do sicoob.
    Entradas: número da cooperativa (string), código do cliente (string) e nosso número sem dígito
    verificador (string)
    Saída: O dígito verificador (int) referente ao nosso número informado
    Autor: Alisson Jaques
*/
#include<stdio.h> // importação da biblioteca stdio para manipular entradas e saídas de dados no programa

/*
    A função soma recebe como argumento dois vetores (memoriaDeCalculo e constante) 
    e retorna a soma da multiplicação das casas correspondentes desses vetores, ou seja, 
    Somatorio (i=0 até i=20) = memoriaDeCalculo[i] * constante[i]
*/
int soma(int memoriaDeCalculo[], int constante[]){

    int soma = 0, i; // variáveis auxiliares

    for(i=0; i<=20; i++){

       soma = soma + (memoriaDeCalculo[i] * constante[i]); // Somatorio (i=0 até i=20) = memoriaDeCalculo[i] * constante[i]

    }

    return soma;

} // fim da função soma

/*
    A função preencheMemoriaDeCalculo recebe como argumentos os vetores
    memoriaDeCalculo, numeroDaCooperativa, codigoDoCliente e nossoNumeroSemDV
    e preenche o vetor memoriaDeCalculo com o padrão esperado.
*/
void preencheMemoriaDeCalculo(int memoriaDeCalculo[], int numeroDaCooperativa[], int codigoDoCliente[], int nossoNumeroSemDV[]){

    int i, j; // variáveis auxiliares

    for(i=0; i<=3; i++){ // preenchimento do numero da cooperativa

        memoriaDeCalculo[i] = numeroDaCooperativa[i];

    }

    j = 0; // esta variável é declarada e inicialiaza com zero, ela garante que o vetor
           // codigoDoCliente inicie no índice 0
    for(i=4; i<=13; i++){ // preenchimento do código do cliente

        memoriaDeCalculo[i] = codigoDoCliente[j];
        j++; // incrementa em uma unidade a variável j

    }

    j = 0; // esta variável é mais uma vez zerada, ela garante que o vetor
           // nossoNumeroSemDV inicie no índice 0    
    for(i=14; i<=20; i++){ // preenchiemento do nosso número sem dv

        memoriaDeCalculo[i] = nossoNumeroSemDV[j];
        j++; // incrementa em uma unidade a variável j

    }
    
} // fim da função preencheMemoriaDeCalculo

/*
    A função contadorCodigoCliente recebe como argumento o vetor
    codigoDoCliente e retorna o numero de casas não "vazias" deste
    vetor.
*/
int contadorCodigoCliente(int codigoDoCliente[]){

    int i = 0 , contador = 0; // variáveis auxiliares

    while(codigoDoCliente[i] != -1){ // enquanto o conteúdo do vetor não for -1

        contador++; // incrementa o contador
        i++;        // incrementa i

    } // fim do while

    return contador;

} // fim da função contadorCodigoCliente

/*
    A função contadorNossoNumeroSemDV recebe como argumento o vetor
    nossoNumeroSemDV e retorna o numero de casas não "vazias" deste
    vetor.
*/
int contadorNossoNumeroSemDV(int nossoNumeroSemDV[]){

    int i = 0 , contador = 0; // variáveis auxiliares

    while(nossoNumeroSemDV[i] != -1){ // enquanto o conteúdo do vetor não for -1

        contador++; // incrementa o contador
        i++;        // incrementa i

    } // fim do while

    return contador;

} // fim da função contadorNossoNumeroSemDV

/*
    A função preencheVetorConstante recebe como argumento o vetor constante e o
    retorna preenchido com a constante 3197, esse preenchimento é feito sequencialmente,
    para cada digito. Por exemplo constante[0] = 3, constante[1] = 1 etc.
*/
void preencheVetorConstante(int constante[]){ // declara a função

    constante[0] = 3;
    constante[1] = 1;
    constante[2] = 9;
    constante[3] = 7;
    constante[4] = 3;
    constante[5] = 1;
    constante[6] = 9;
    constante[7] = 7;
    constante[8] = 3;
    constante[9] = 1;
    constante[10] = 9;
    constante[11] = 7;
    constante[12] = 3;
    constante[13] = 1;
    constante[14] = 9;
    constante[15] = 7;
    constante[16] = 3;
    constante[17] = 1;
    constante[18] = 9;
    constante[19] = 7;
    constante[20] = 3;

} // fim da função preencheVetorConstante

/*
    A função caractereParaInteiro recebe um dado do tipo charactere e o transforma
    em um dado correspondente, do tipo inteiro.
*/
int caractereParaInteiro(char letra){ // declara a função


    if(letra == '\0'){ // se o caractere for "vazio"
        
        return -1; 
    
    }
    else if(letra == '0'){ // senão, se o caractere for 0

        return 0; 

    }
    else if(letra == '1'){ // senão, se o caractere for 1

        return 1; 

    }
    else if(letra == '2'){ // senão, se o caractere for 2

        return 2; 

    }
    else if(letra == '3'){ // senão, se o caractere for 3

        return 3; 

    }
    else if(letra == '4'){ // senão, se o caractere for 4

        return 4; 

    }
    else if(letra == '5'){ // senão, se o caractere for 5

        return 5; 
    }
    else if(letra == '6'){ // senão, se o caractere for 6

        return 6; 

    }
    else if(letra == '7'){ // senão, se o caractere for 7

        return 7; 
    }
    else if(letra == '8'){ // senão, se o caractere for 8

        return 8; 

    }
    else{ // senão

        return 9; 

    } // fim-se
} // fim da função caractereParaInteiro

/*
    A função main não possuí argumentos e permite a execução do programa.
    Ela encontra o digito verificador para o nosso numero informado pelo usuário. 
    Ela faz uso das funções soma, preencheMeoriaDeCalculo, contadorCodigoCliente,
    contadorNossoNumeroSemDV, preencheVetorConstante e caractereParaInteiro para realizar
    essa tarefa.
*/
int main(){ // declara a função
    /*
        Declaração de variáveis auxiliares    
    */
    int memoriaDeCalculo[21], constante[21];
    int numeroDaCooperativa[4], codigoDoCliente[10], nossoNumeroSemDV[7], resto, digitoVerificador;
    char numeroDaCooperativaInv[4], codigoDoClienteInv[10], nossoNumeroSemDVInv[7];
    
    /*
        Chamada da função preencheVetorConstante passando como argumento o vetor constante[21], que será
        preenchido sequencialmente pela constante de cálculo (3197).
    */
    preencheVetorConstante(constante);

    /* 
        Solicitamos ao usuário que informe o número da cooperativa e inicializamos a variável
        numeroDaCooperativaInv com o valor informado.
    */
    printf("\n=========================================== Calculo Digito Verificador ====================================================\n");
    printf("Informe o numero da cooperativa (maximo 4 digitos):\n");
    scanf("%s", numeroDaCooperativaInv);

    /* 
        Solicitamos ao usuário que informe o código do cliente e inicializamos a variável
        cogidoDoClinteInv com o valor informado.
    */
    printf("Informe o codido do cliente (maximo 10 digitos):\n");
    scanf("%s", codigoDoClienteInv);

    /* 
        Solcitamos ao usuário que informe o nosso número e inicializamos a variável
        nossoNumeroSemDVInv com o valor informado.
    */
    printf("Informe o nossso numero (maximo 7 digitos):\n");
    scanf("%s", nossoNumeroSemDVInv);
    printf("===========================================================================================================================\n");
    
    int i; // variável para controle de laço
    
    /* 
        Este laço cria o vetor de inteiros numeroDaCooperativa a partir do vetor de 
        strings, correspondente, numeroDaCooperativaInv
    */
    for(i=0; i<=3; i++){

        numeroDaCooperativa[i] = caractereParaInteiro(numeroDaCooperativaInv[i]);

    }

    /* 
        Este laço cria o vetor de inteiros codigoDoCliente a partir do vetor de 
        strings, correspondente, codigoDoClienteInv
    */
    for(i=0; i<=9; i++){

        codigoDoCliente[i] = caractereParaInteiro(codigoDoClienteInv[i]);

    }

    /* 
        Este laço cria o vetor de inteiros nossoNumeroSemDV a partir do vetor de 
        strings nossoNumeroSemDVInv.
    */
    for(i=0; i<=6; i++){

        nossoNumeroSemDV[i] = caractereParaInteiro(nossoNumeroSemDVInv[i]);

    }    
    
    /*
        Declaramos um vetorCliente que receberá o conteúdo exato do vetor codigoDoCliente,
        para isso usamos a função contadorCodigoCliente (ela conta as casas sequenciais não "vazias" do
        vetor codigoDoCliente e retorna esse valor) e atribuímos seu retorno à variável indice, que será
        usada para a declaração do vetorCliente.
    */
    int indice = contadorCodigoCliente(codigoDoCliente);
    int vetorCliente[indice];
    for(i=0; i<=indice; i++){

        vetorCliente[i] = codigoDoCliente[i];

    }

    // Preenchemos o vetor codigoDoCliente com zeros, pois os campos vazios devem possuir zeros
    for(i=0; i<=9; i++){

        codigoDoCliente[i] = 0;

    }

    //Preenchemos o vetor códigoDoCliente (campos vazios serão zeros à esquerda)
    int controlador = 0; // Esta variável garante que vetorCliente inicie no índice 0
    for(i=0; i<=9; i++){

        if(i>(10-(indice+1))){ // Após acabar os zeros à esquerda

            // Preenche o vetor codigoDoCliente de acordo com o vetorCliente
            codigoDoCliente[i] = vetorCliente[controlador];
            controlador++; // incrementamos o controlador em uma unidade
        } // fim-se

    }

     /*
        Declaramos o vetorNossoNumero que receberá o conteúdo exato do vetor nossoNumeroSemDV,
        para isso usamos a função contadorNossoNumeroSemDV (ela conta as casas sequenciais não "vazias" do
        vetor codigoDoCliente e retorna esse valor) e atribuímos seu retorno à variável indice2, que será 
        usada para a declaração do vetorNossoNumero.
    */
    int indice2 = contadorNossoNumeroSemDV(nossoNumeroSemDV);
    int vetorNossoNumero[indice2];
    for(i=0; i<=indice2; i++){

        vetorNossoNumero[i] = nossoNumeroSemDV[i];

    }

    // Preenchemos o vetor nossoNumeroSemDV com zeros, pois os campos vazios devem possuir zeros
    for(i=0; i<=6; i++){

        nossoNumeroSemDV[i] = 0;

    }

    //Preenchemos o vetor nossoNumeroSemDV (campos vazios serão zeros à esquerda)
    int controlador2 = 0; // Esta variável garante que vetorNossoNumero inicie no índice 0
    for(i=0; i<=6; i++){

        if(i>(7-(indice2+1))){ // Após acabar os zeros à esquerda

            // Preenche o vetor nossoNumeroSemDV de acordo com o vetorNossoNumero
            nossoNumeroSemDV[i] = vetorNossoNumero[controlador2];
            controlador2++; // incrementamos o controlador2 em uma unidade
        } // fim-se 

    }

    /*    
        Com os vetores nossoNumeroSemDV, numeroDaCooperativa e codigoDocliente devidamente preenchidos,
        chamamos a função preencheMemoriaDeCalculo passando esses vetores como argumentos (também é passado 
        como argumento o vetor memoriaDeCalculo), preenchendo asssim o vetor memoriaDeCalculo.
    */
    preencheMemoriaDeCalculo(memoriaDeCalculo, numeroDaCooperativa, codigoDoCliente, nossoNumeroSemDV);

    // calculo do resto
    resto = soma(memoriaDeCalculo,constante) % 11;

    if(resto == 0 || resto == 1){ // se o resto for 0 ou 1

        digitoVerificador = 0; // digito verificador será 0
    
    }
    else{ // senão

        digitoVerificador = 11 - resto;

    } // fim-se

    printf("O Digito Verificador eh: %d\n", digitoVerificador); // Impressão do dígito verificador calculado
    printf("===========================================================================================================================\n\n");

    return 0; // retorno padrão para main
    
} // fim da função main