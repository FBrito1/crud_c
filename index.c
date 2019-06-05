#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados {
            char nome [20];
            char endereco[20];
            char data_nasc[20];
            char cidade[20];
            char estado[20];
            char cep[20];
            };

void inclui();
void lista();
int pesquisaPorNome();
int pesquisaPorLetra();
int pesquisaAniversariantes();
int pesquisaPorCep();
void altera();
void exclui();

int main()
{
        struct dados info;
        struct dados *p;
        int op;
        int i;
        int tam;    

        p = & info;
        tam = sizeof(info);

        for(i=0;i<sizeof(info);i++) {  
            info.nome[i]=0;
           }
        while(1){
        printf(" 1 -Inclua dados  \n");
        printf(" 2 -Lista dados  \n");
        printf(" 3 -Pesquisa dados por nome \n");
        printf(" 4 -Pesquisa dados pela 1 letra do nome \n");
        printf(" 5 -Pesquisa aniversariantes \n");
        printf(" 6 -Pesquisa dados por cep\n");
        printf(" 7 -Altera dados  \n");
        printf(" 8 -Exclui dados  \n");
        printf(" 9 -Saida\n");
        scanf("%d", &op);
        getchar();


    switch(op)
                {
                case 1 : inclui(p, tam);   
                break;

                case 2: lista(p, tam);
                break;

                case 3: pesquisaPorNome(p, tam);
                break;

                case 4: pesquisaPorLetra(p, tam);
                break;

                case 5: pesquisaAniversariantes(p, tam);
                break;

                case 6: pesquisaPorCep(p, tam);
                break;

                case 7: altera(p, tam);
                break;

                case 8: exclui(p, tam);
                break;

                case 9: exit(0);
                break;

                default: printf("\n opcao invalida\n");
                }
    };

}

void inclui(struct dados *ps, int tam)
{
    FILE *p, *p1;
    int cont = 0;
    int i;

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    printf("contador antes %d\n",cont);
    fclose(p1);

    for(i=0;i<tam;i++){ 
        ps -> nome[i]=0;
    }

    p = fopen("arquivo.txt", "a");

    if( p == NULL){
        printf("\nERRO");
        exit(1);
    }

  
    printf("Nome: ");
    gets(ps->nome);
    printf("Endereco: ");
    gets(ps->endereco);
    printf("Data nasc: ");
    gets(ps->data_nasc);
    printf("Cidade: ");
    gets(ps->cidade);
    printf("Estado: ");
    gets(ps->estado);
    printf("CEP: ");
    gets(ps->cep);

    fwrite(ps, tam,1,p);
    fclose(p);

    cont++;

    p1 = fopen("contador.txt", "w");
    fprintf(p1,"%d",cont);
    printf("contador depois %d\n",cont);
    fclose(p1);
}

void lista(struct dados *ps, int tam)
{
    FILE *p, *p1;
    FILE *a;
    struct dados info;
    int i;
    int cont,comp;

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    printf("%d\n",cont);
    fclose(p1);

    p = fopen("arquivo.txt", "r"); 

    if( p== NULL)
        {
        puts("\nERRO\n");
        exit(1);
    }

    a = fopen("contador.txt", "r");
    fscanf(a,"%d",&cont);
    fclose(a);

    for(i=0;i<cont; i++){
        comp = i*tam;  

    fseek(p,comp,0);   
    fread(ps,sizeof(info),1,p);   
    if(ps -> nome[0] != '*'){  
            printf("\n");
            printf("---------------------");
            printf("\n");
            printf("Nome: ");
            puts(ps->nome);
            printf("Endereco: ");
            puts(ps->endereco);
            printf("Data de nascimento: ");
            puts(ps->data_nasc);
            printf("Cidade: ");
            puts(ps->cidade);
            printf("Estado: ");
            puts(ps->estado);
            printf("CEP: ");
            puts(ps->cep);
            printf("\n");
            printf("---------------------");
            printf("\n");
        }
    }
    fclose(p);
}

int pesquisaPorNome(struct dados *ps, int tam)
{
    FILE *p;
    FILE *a;

    char nome1[20];
    int i=0,y, x;
    int cont;

    printf("Informe um nome para pesquisa: ");
    gets(nome1);

    p = fopen("arquivo.txt", "r");
    a = fopen("contador.txt", "r");
    fscanf(a,"%d",&cont);
    fclose(a);
    printf("%d\n",cont);

    for(y=0;y<cont;y++)
    {
        fread(ps,tam,1,p);
        for(x = 0; nome1[x] != '\0';x++){
            if(nome1[x] != ps -> nome[x]){
                break;
            }
        }

    if(nome1[x] == '\0' && ps -> nome[x] == '\0')
    {
        printf("\n");
        printf("---------------------");
        printf("\n");
        printf("n. do reg.: %d\n",y);
        printf("Nome: ");
        puts(ps->nome);
        printf("Endereco: ");
        puts(ps->endereco);
        printf("Data de nascimento: ");
        puts(ps->data_nasc);
        printf("Cidade: ");
        puts(ps->cidade);
        printf("Estado: ");
        puts(ps->estado);
        printf("CEP: ");
        puts(ps->cep);
        printf("\n");
        printf("---------------------");
        printf("\n");
        return y;
    }
    }
    printf("reg. nao existe\n");
    return -1;
}

int pesquisaPorLetra(struct dados *ps, int tam)
{
    FILE *p, *p1;
    FILE *a;
    struct dados info;
    int i;
    int cont,comp;
    char nome1[1];

    printf("Informe uma letra para pesquisa: ");
    gets(nome1);

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    printf("%d\n",cont);
    fclose(p1);

    p = fopen("arquivo.txt", "r"); 

    if( p== NULL)
        {
        puts("\nERRO\n");
        exit(1);
    }

    a = fopen("contador.txt", "r");
    fscanf(a,"%d",&cont);
    fclose(a);

    for(i=0;i<cont; i++){
        comp = i*tam;   

    fseek(p,comp,0);   
    fread(ps,sizeof(info),1,p);   
    if(ps -> nome[0] == nome1[0]){  
            printf("\n");
            printf("---------------------");
            printf("\n");
            printf("Nome: ");
            puts(ps->nome);
            printf("Endereco: ");
            puts(ps->endereco);
            printf("Data de nascimento: ");
            puts(ps->data_nasc);
            printf("Cidade: ");
            puts(ps->cidade);
            printf("Estado: ");
            puts(ps->estado);
            printf("CEP: ");
            puts(ps->cep);
            printf("\n");
            printf("---------------------");
            printf("\n");
        }
    }
        fclose(p);
}
int pesquisaAniversariantes(struct dados *ps, int tam)
{
    FILE *p;
    FILE *a;

    char data_nasc1[20];
    int i=0,y, x;
    int cont;

    printf("Informe sua data de nascimento no seguinte formato(dd/mm/AAAA): ");
    gets(data_nasc1);

    p = fopen("arquivo.txt", "r");
    a = fopen("contador.txt", "r");
    fscanf(a,"%d",&cont);
    fclose(a);
    printf("%d\n",cont);

    for(y=0;y<cont;y++)
    {
        fread(ps,tam,1,p);
        for(x = 0; data_nasc1[x] != '\0';x++){
            if(data_nasc1[x] != ps -> data_nasc[x]){
                break;
            }
        }

    if(data_nasc1[x] == '\0' && ps -> data_nasc[x] == '\0')
    {
        printf("\n");
        printf("---------------------");
        printf("\n");
        printf("n. do reg.: %d\n",y);
        printf("Nome: ");
        puts(ps->nome);
        printf("Endereco: ");
        puts(ps->endereco);
        printf("Data de nascimento: ");
        puts(ps->data_nasc);
        printf("Cidade: ");
        puts(ps->cidade);
        printf("Estado: ");
        puts(ps->estado);
        printf("CEP: ");
        puts(ps->cep);
        printf("\n");
        printf("---------------------");
        printf("\n");
        return y;
    }
    }
    printf("reg. nao existe\n");
    return -1;
}
int pesquisaPorCep(struct dados *ps, int tam)
{
    FILE *p;
    FILE *a;

    char cep1[20];
    int i=0,y, x;
    int cont;

    printf("Informe um nome para pesquisa: ");
    gets(cep1);

    p = fopen("arquivo.txt", "r");
    a = fopen("contador.txt", "r");
    fscanf(a,"%d",&cont);
    fclose(a);
    printf("%d\n",cont);

    for(y=0;y<cont;y++)
    {
        fread(ps,tam,1,p);
        for(x = 0; cep1[x] != '\0';x++){
            if(cep1[x] != ps -> cep[x]){
                break;
            }
        }

    if(cep1[x] == '\0' && ps -> cep[x] == '\0')
    {
        printf("\n");
        printf("---------------------");
        printf("\n");
        printf("n. do reg.: %d\n",y);
        printf("Nome: ");
        puts(ps->nome);
        printf("Endereco: ");
        puts(ps->endereco);
        printf("Data de nascimento: ");
        puts(ps->data_nasc);
        printf("Cidade: ");
        puts(ps->cidade);
        printf("Estado: ");
        puts(ps->estado);
        printf("CEP: ");
        puts(ps->cep);
        printf("\n");
        printf("---------------------");
        printf("\n");
        return y;
    }
    }
    printf("reg. nao existe\n");
    return -1;
}



void altera(struct dados *ps, int tam)
{
    FILE *p;
    int n_reg;;
    int n_bytes;

    // pesquisa os dados no arquivo
    n_reg = pesquisaPorNome(ps, tam);    
    printf("altera reg n.: %d\n",n_reg);
    if(n_reg == -1){
 	     return;
    }
    n_bytes = tam * n_reg;

    p = fopen("arquivo.txt", "r+");

    fseek(p,n_bytes,0);       
    fread(ps, tam, 1, p );  
    printf("recebe os dados para alteracao: \n");

    // insere os dados no arquivo
    inclui(ps, tam);
    
    fseek(p,n_bytes,0);   
    fwrite(ps, tam,1,p);  

    fclose(p);
}

void exclui(struct dados *ps, int tam)
{
    FILE *p;
    int n_reg;
    int n_bytes;
    // pesquisa os dados no arquivo
    n_reg = pesquisaPorNome(ps, tam);  
    if(n_reg == -1){
 	     return;
    }
    p = fopen("arquivo.txt", "r+");
    n_bytes = tam * n_reg;

    fseek(p,n_bytes,0);      
    fread(ps, tam, 1, p );  
    printf("nome para apagar e' %s\n",ps -> nome);
    
    //Omite o registro
    ps->nome[0]='*';

    fseek(p,n_bytes,0);  
    fwrite(ps,tam,1,p);  

    fclose(p);

}



