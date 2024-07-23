#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Portuguese Brazil");

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da advinhação! *" << endl;
    cout << "**************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil(F), Médio(M) ou Difícil(D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if (dificuldade == 'F')
    {
        numero_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_tentativas = 10;
    }
    else
    {
        numero_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_tentativas; tentativas++)
    {
        cout << "Tentativas: " << tentativas << endl;
        int chute;
        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;

        cout << "O valor do chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }
    cout << "Fim do Jogo!" << endl;

    if (nao_acertou)
    {
        cout << "Você perdeu! tente novamente!" << endl;
    }
    else
    {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
}