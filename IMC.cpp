#include <iostream>
using namespace std;

bool variaentre (float valorDeEntrada, float valorMinimo, float valorMaximo){
    if ( valorDeEntrada >= valorMinimo && valorDeEntrada <= valorMaximo){
        return 1;
    }
    else {
        return 0;
    }
}

void Estadodoimc (float imcResultado)   {

     cout << "\n[ ";
    if (imcResultado < 17){
        cout << "Voce e frango ao ponto de correr risco de vida mane, bora comer e ir pra academia crl...";
    }
    else if (variaentre(imcResultado, 17.1, 18.5))
    {
        cout << "Você e frangp, e esta abaixo do peso, precisa comer mais e ir pra academia fdp.";
        
    }
    else if (variaentre(imcResultado, 18.6, 24.9))
    {
        cout << "Seu peso esta ideal para sua altura, continue no grind.";
    }
    else if (variaentre(imcResultado, 24.9, 29.9)) {
        cout << "Voce esta com um sobrepeso, e melhor focar mais na academia, gordinho.";
    }
    else if (imcResultado > 30){
        cout << "Voce esta gordo pra caralho em fdp, vamos parar com a coca e o mcdonalds antes que morra do coracao...";
    }
    else {
        cout << "voce provavelmente nao e humano!";
    }
    cout << " ]" << endl;
    return;
}

float RetornarIMC (float peso, float altura) {
    return peso / (altura * altura);
}

int main(int argc, char** argv) {
    
    float alturaDoUsuario = 0;
    float pesoDoUsuario = 0;
    float resultadoIMC = 0;
    
    cout << "Informe a sua altura em Metros Ex.: 1.75 \n";
    cin >> alturaDoUsuario;
    cout << "Informe o seu peso em Kg Ex.: 80 \n";
    cin >> pesoDoUsuario;

    resultadoIMC = RetornarIMC(pesoDoUsuario, alturaDoUsuario);
    cout << "Resultado do IMC: " << 	"\n- Altura :" << 	alturaDoUsuario << 	"\n- Peso :" << 	pesoDoUsuario << 	"\n- IMC Total :" << resultadoIMC << endl;
    
     Estadodoimc(resultadoIMC);
    
    return 0;
}