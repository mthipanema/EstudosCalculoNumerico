//Regra dos Trapézios Repetidos
double trapezios_repetidos(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (g(a) + g(b)) / 2.0;
    
    printf("\n   h = (%.1f - %.1f) / %d = %.4f\n", b, a, n, h);
    printf("   Pontos utilizados:\n");
    printf("   x0 = %.4f, g(x0) = %.6f\n", a, g(a));
    
    for(int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += g(xi);
        printf("   x%d = %.4f, g(x%d) = %.6f\n", i, xi, i, g(xi));
    }
    printf("   x%d = %.4f, g(x%d) = %.6f\n", n, b, n, g(b));
    
    return h * sum;
}

//Regra 1/3 de Simpson
double simpson_1_3(double a, double b, int n) {
    if(n % 2 != 0) n++; // n deve ser par
    
    double h = (b - a) / n;
    double sum = g(a) + g(b);
    
    printf("\n   h = (%.1f - %.1f) / %d = %.4f\n", b, a, n, h);
    printf("   n ajustado para %d (deve ser par)\n", n);
    printf("   Pontos utilizados:\n");
    printf("   x0 = %.4f, g(x0) = %.6f (coef: 1)\n", a, g(a));
    
    for(int i = 1; i < n; i++) {
        double xi = a + i * h;
        int coef = (i % 2 == 0) ? 2 : 4;
        if(i % 2 == 0)
            sum += 2 * g(xi);
        else
            sum += 4 * g(xi);
        printf("   x%d = %.4f, g(x%d) = %.6f (coef: %d)\n", i, xi, i, g(xi), coef);
    }
    printf("   x%d = %.4f, g(x%d) = %.6f (coef: 1)\n", n, b, n, g(b));
    
    return (h / 3.0) * sum;
}

// Regra do Retângulo (Ponto Médio)
double retangulo(double a, double b, int n) {
    if (n <= 0) {
        fprintf(stderr, "Erro: n deve ser positivo\n");
        return NAN;
    }

    double h = (b - a) / n;
    double sum = 0.0;

    printf("\n   h = (%.1f - %.1f) / %d = %.4f\n", b, a, n, h);
    printf("   Pontos médios utilizados:\n");

    for (int i = 0; i < n; i++) {
        double xi_mid = a + (i + 0.5) * h;
        sum += g(xi_mid);
        printf("   x%d_mid = %.4f, g(x%d_mid) = %.6f\n", i, xi_mid, i, g(xi_mid));
    }

    return h * sum;
}
