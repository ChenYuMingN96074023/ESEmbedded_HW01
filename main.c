#include <stdio.h>
#include <math.h>


/*
 * �p�⥭��
 */
double square(double x) {
    return x * x;
}

/*
 * �p��T����
 */
double cube(double x) {
    return x * x * x;
}

/*
 * �p��f()�b(x,y)�����Hn�����ӹG�񪺿n���ƭ�,�ϥα�Ϊk
 */
double integral(double (*f)(double), int n, double x, double y) {
    int i;
    double gap = (y - x) / n;
    double fy1 = (*f)(x);
    double fy2 = (*f)(x + gap);
    double area = 0;
    for (i = 0; i < n; i++) {
        area += (fy1 + fy2) * gap / 2; // �ϥα�έ��n���� 
        fy1 = fy2;
        fy2 = (*f)(x + gap * (i + 1)); //�U��
    }
    return area;
}

int main() {
    char fun[100];
    int n;
    double x, y;
    double (*f)(double); // f: a pointer to function(double) returning double
    while (scanf("%99s",fun) != EOF) { // EOF�w�q��stdio.h��,�@��t�ΤW��-1
        if (strcmp(fun,"square")==0) {
            f = square;
        } else if (strcmp(fun,"cube")==0) {
            f = cube;
        } else if (strcmp(fun,"sqrt")==0) {
            f = sqrt; // sqrt is defined in math.h
        } else if (strcmp(fun,"cbrt")==0) {
            f = cbrt; // cbrt is defined in math.h
        } else if (strcmp(fun,"end")==0) {
            break;
        } else {
            printf("Unknown function\n");
            continue;
        }
        scanf("%d%lf%lf", &n, &x, &y);
        printf("Integral of %s from %lf to %lf is: %lf\n", fun, x, y, integral(f, n, x, y));
    }
    return 0;
}
