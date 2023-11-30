#include <stdio.h>

#define PI 3.141592

void T_Pasabajo(void);
void T_Pasaalto(void);
void F_Corte(void);
//void D_SK(void);

int main()
{
    int i, end;
    while(end!=1)
    {
        printf("Bienvenido\n¿Que desea calcular?\n");
        printf("| 1 para pasabajo | 2 para pasaalto | 3 para frecuencia de corte |\n");
        printf("Ingrese el número deseado: ");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                T_Pasabajo();
                break;
            case 2:
                T_Pasaalto();
                break;
            case 3:
                F_Corte();
                break;
        }
        printf("\n| Ingrese 1 para finalizar | Cualquier otro número para seguir calculando |\n");
        printf("Ingrese si desea continuar o no: ");
        scanf("%d", &end);
    }
    printf("Gracias por haber utilizado esta humilde calculadora\nSaludos");
    return 0;
}

void T_Pasabajo(void)
{
    float r, f_low, f_high, step, t, cap, u;
    int f;
    char unidad;
    printf("Ingrese un valor de resistencia (en ohms): ");
    scanf("%f", &r);
    //fflush(stdin);
    printf("| m para mili | u para micro | n para nano | p para pico |\n");
    printf("Ingrese la unidad del valor de capacitancia a ingresar: ");
    //fflush(stdin);
    scanf(" %c", &unidad);
    if (unidad=='m') u = 1.0E-3;
    else if (unidad=='u') u = 1.0E-6;
    else if (unidad=='n') u = 1.0E-9;
    else if (unidad=='p') u = 1.0E-12;
    printf("Ingrese un valor de capacitancia: ");
    scanf("%f", &cap);
    cap = cap*u;
    //printf("%0.9f", cap);
    printf("Ingrese el piso de frecuencia: ");
    scanf("%f", &f_low);
    printf("Ingrese el techo de frecuencia: ");
    scanf("%f", &f_high);
    printf("Ingrese de a cuanto son los pasos: ");
    scanf("%f", &step);
    for(f=f_low;f<=f_high;f=f+step)
    {
        t = 1/(2*PI*f*r*cap +1);
        printf("\nt = %f | f = %i", t, f);
    }
}

void T_Pasaalto(void)
{
    float r, f_low, f_high, step, t, cap, u;
    int f;
    char unidad;
    printf("Ingrese un valor de resistencia (en ohms): ");
    scanf("%f", &r);
    //fflush(stdin);
    printf("| m para mili | u para micro | n para nano | p para pico |\n");
    printf("Ingrese la unidad del valor de capacitancia a ingresar: ");
    //fflush(stdin);
    scanf(" %c", &unidad);
    if (unidad=='m') u = 1.0E-3;
    else if (unidad=='u') u = 1.0E-6;
    else if (unidad=='n') u = 1.0E-9;
    else if (unidad=='p') u = 1.0E-12;
    printf("Ingrese un valor de capacitancia: ");
    scanf("%f", &cap);
    cap = cap*u;
    //printf("%0.9f", cap);
    printf("Ingrese el piso de frecuencia: ");
    scanf("%f", &f_low);
    printf("Ingrese el techo de frecuencia: ");
    scanf("%f", &f_high);
    printf("Ingrese de a cuanto son los pasos: ");
    scanf("%f", &step);
    for(f=f_low;f<=f_high;f=f+step)
    {
        t = (2*PI*f*r*cap)/(2*PI*f*r*cap +1);
        printf("\nt = %f | f = %i", t, f);
    }
}

void F_Corte(void)
{
    float r, cap, u, f;
    char unidad, bucle;
    printf("Ingrese un valor de resistencia (en ohms): ");
    scanf("%f", &r);
    //fflush(stdin);
    printf("| m para mili | u para micro | n para nano | p para pico |\n");
    printf("Ingrese la unidad del valor de capacitancia a ingresar: ");
    //fflush(stdin);
    scanf(" %c", &unidad);
    while (bucle==0)
    {
        if (unidad=='m')
        {
            u = 1.0E-3;
            bucle = 1;
            printf("%f", u);
        }
        else if (unidad=='u')
        {
            u = 1.0E-6;
            bucle = 1;
        }
        else if (unidad=='n')
        {
            u = 1.0E-9;
            bucle = 1;
        }
        else if (unidad=='p')
        {
            u = 1.0E-12;
            bucle = 1;
        }
        else
        {
            printf("Ingrese una unidad correcta: ");
            scanf(" %c", &unidad);
        }
    }
    printf("Ingrese un valor de capacitancia: ");
    scanf("%f", &cap);
    cap = cap*u;
    f = 1/(2*PI*r*cap);
    printf("La frecuencia de corte [Hz] es de: %0.2f\n", f);
}

/*void D_SK(void)  //Cálculo para filtro Sallen Key, a terminar
{   
    float r, fr, rb, step, t, cap, u;
    int i, q;
    char unidad;
    printf("| m para mili | u para micro | n para nano | p para pico |\n");
    printf("Ingrese la unidad del valor de capacitancias a ingresar: ");
    //fflush(stdin);
    scanf(" %c", &unidad);
    if (unidad=='m') u = 1.0E-3;
    else if (unidad=='u') u = 1.0E-6;
    else if (unidad=='n') u = 1.0E-9;
    else if (unidad=='p') u = 1.0E-12;
    printf("Ingrese un valor de capacitancia: ");
    scanf("%f", &cap);
    cap = cap*u;
    printf("Ingrese el valor de la ganancia");
    printf("Son altamente recomendables aquellos valores entre 1 y 3");
    scanf("%f", &fr);
    printf("Ingrese la frecuencia de corte: ");
    scanf("%f", &fr);
}*/
