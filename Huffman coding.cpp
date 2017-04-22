#include <stdlib.h>
#include <string.h>
 
struct sym //��������� ��� ������
{
        unsigned char ch;
        float freq; 
        char code[255];
        sym *left;
        sym *right;
};
 
union code
{
    unsigned char chhh;//���������� ���������� ��� ��� ������ � ������ ����
 
    struct byte
    {
        unsigned b1:1;
        unsigned b2:1;
        unsigned b3:1;
        unsigned b4:1;
        unsigned b5:1;
        unsigned b6:1;
        unsigned b7:1;
        unsigned b8:1;      
    }byte;
};
 
sym *makeTree(sym *psym[],int k)//�e��������� ������� �������� ������ �������
{
    sym *temp;
    temp=(sym*)malloc(sizeof(sym));
    temp->freq=psym[k-1]->freq+psym[k-2]->freq;
    temp->code[0]=0;
    temp->left=psym[k-1];
    temp->right=psym[k-2];
 
    if(k==2)
        return temp;
    else //�������� � ������ � ������ ����� �������� ������ �������
    {
        for(int i=0;i<k;i++)
            if (temp->freq>psym[i]->freq)
            {   
                for(int j=k-1;j>i;j--)
                    psym[j]=psym[j-1];                                  
                
                psym[i]=temp;
                break;
            }       
    }
return makeTree(psym,k-1);
}
 
void makeCodes(sym *root)//����������� ������� �����������
{
    if(root->left)
    {
        strcpy(root->left->code,root->code);
        strcat(root->left->code,"0");
        makeCodes(root->left);
    }
    if(root->right)
    {
        strcpy(root->right->code,root->code);
        strcat(root->right->code,"1");
        makeCodes(root->right);
    }
}
 
 
int main ()
{
    FILE *fp,*fp2,*fp3; //��������� �� �����
    //fp=fopen("777.txt","rb"); //��������� ���������� ���� ��� ������
    fp=fopen("123.txt","rb"); //��������� ���������� ����
    fp2=fopen("teemp.txt","wb");//��������� ���� ��� ������ ��������� ����
    fp3=fopen("7777.txt","wb");//��������� ���� ��� ������ ������� �����
 
    int chh;  // � ��� ���������� �������� ���������� �� �����
    int k=0; //������� ���������� ��������� ����, ���������� ��������
    int kk=0; // ������� ���������� ���� ������ � �����
    int fsize2=0;//������� ���������� �������� �� 0 � 1 � ������������� ����� teemp
    int ts;//������ ������ ����� (��, ��� �� ������ 8 � ������������� �����)
    int kolvo[256]={0};//�������������� ������ ���������� ���������� ��������
    sym simbols[256]={0}; //�������������� ������ ������� 
    sym *psym[256]; //�������������� ������ ���������� �� ������
    float summir=0;//����� ������ �������������
    int mes[8];//������ 0 � 1
    char j=0;//��������������� ����������
    
    //��������� ������ ������ �����
    if(fp==NULL)
    {
        puts("FILE NOT OPEN!!!!!!!");
        return 0;
    }
 
    sym *symbols=(sym*)malloc(k*sizeof(sym));//�������� ������������� ������� �������� simbols
    sym **psum=(sym**)malloc(k*sizeof(sym*));//�������� ������������� ������� ���������� �� simbols
    
    //�������� �������� ������ ���� � ���������� ������� �������������
    while((chh=fgetc(fp))!=EOF)
    {       
        for(int j=0; j<256; j++)
        {
            if (chh==simbols[j].ch)
            {
                kolvo[j]++;
                kk++;               
                break;
            }
            if (simbols[j].ch==0)
            {
                simbols[j].ch=(unsigned char)chh;
                kolvo[j]=1;
                k++; kk++;
                break;
            }           
        }       
    }
 
    // ������� ������� �������������
    for(int i=0;i<k;i++)
        simbols[i].freq=(float)kolvo[i]/kk;
    
    for(int i=0;i<k;i++) //� ������ ���������� ������� ������ �������
        psym[i]=&simbols[i];
    
//���������� �� �������� 
    sym tempp;
    for(int i=1;i<k;i++)
        for(int j=0;j<k-1;j++)
            if(simbols[j].freq<simbols[j+1].freq)
            {
                tempp=simbols[j];
                simbols[j]=simbols[j+1];
                simbols[j+1]=tempp;
            }
 
for(int i=0;i<k;i++)
{
    summir+=simbols[i].freq;    
    printf("Ch= %d\tFreq= %f\tPPP= %c\t\n",simbols[i].ch,simbols[i].freq,psym[i]->ch,i);
}
    printf("\n Slova = %d\tSummir=%f\n",kk,summir);
    
    sym *root=makeTree(psym,k);//����� ������� �������� ������ �������
    
    makeCodes(root);//����� ������� ��������� ����
 
    rewind(fp);//���������� ��������� � ����� � ������ �����
//� ����� ������ �������� ����, � ���������� ���������� � �������� ���� � ������������� ����
while((chh=fgetc(fp))!=EOF)
{
    for(int i=0;i<k;i++)
        if(chh==simbols[i].ch)
            fputs(simbols[i].code,fp2);
}
fclose(fp2);
 
//������ ��������� ���� � �������� �����, �� ������ ��� ������
int i=0;
fp2=fopen("teemp.txt","rb");
//������� ������ ��������� �����(���������� �������� � ��)
while((chh=fgetc(fp2))!=EOF)
        fsize2++;
 
ts=fsize2%8;//������� �������, ���������� �������� �� ������� 8 (�����)
 
//��������� ��������� ������� ����� ����� ���� ������
fwrite("compresing!!!",sizeof(char),24,fp3);//�������� �������
fwrite(&k,sizeof(int),1,fp3);//���������� ���������� ��������
fwrite(&ts,sizeof(int),1,fp3);//�������� ������
//���������� � ������ ���� ������� �������������
for(i=0;i<k;i++)
{
    fwrite(&simbols[i].ch,sizeof(sym),1,fp3);
    fwrite(&simbols[i].freq,sizeof(sym),1,fp3);
}
 
rewind(fp2);//���������� ��������� � ������������� ����� � ������ �����
 
union code code1;//�������������� ���������� code1
//������ �������� ����, ������ ��������������� ������ 8 ��������� � ������ ��� ����������� ��������� ��������� � ����������� union
j=0;
for(int i=0;i<fsize2-ts;i++)
{
    mes[j]=fgetc(fp2);
    if(j==7)
    {       
        code1.byte.b1=mes[0]-'0';
        code1.byte.b2=mes[1]-'0';
        code1.byte.b3=mes[2]-'0';
        code1.byte.b4=mes[3]-'0';
        code1.byte.b5=mes[4]-'0';
        code1.byte.b6=mes[5]-'0';
        code1.byte.b7=mes[6]-'0';
        code1.byte.b8=mes[7]-'0';
        fputc(code1.chhh,fp3);
        j=0;
    }
    j++;    
}
//���������� �����
j=0;
for(int i=0;i<=ts;i++)
{
    mes[j]=fgetc(fp2);
    if(j==ts)
    {       
        code1.byte.b1=mes[0]-'0';
        code1.byte.b2=mes[1]-'0';
        code1.byte.b3=mes[2]-'0';
        code1.byte.b4=mes[3]-'0';
        code1.byte.b5=mes[4]-'0';
        code1.byte.b6=mes[5]-'0';
        code1.byte.b7=mes[6]-'0';
        code1.byte.b8=mes[7]-'0';
        fputc(code1.chhh,fp3);      
    }
    j++;    
}   
 
fcloseall();//��������� ��� �������� �����
 
return 0;
}