int soma_array(int a[], int primeiro, int ultimo) {
    int soma = 0;
    if (primeiro == ultimo) {
        soma = a[primeiro];
    }
    else {
        int meio = (primeiro + ultimo) / 2;
        soma = soma_array(a, primeiro, meio) + soma_array(a, meio + 1, ultimo);
    }
    return soma;
}