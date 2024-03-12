#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int numPalavras = 0;
    int palavraEscolhida = 0;
    std::string _chave = "";
    std::string _linha;
    int indexArq = 0;
    std::string letrasErradas;
    std::string revelaPalavra = "*****";

    std::ifstream in("palavras.txt", std::fstream::in);
    if(!in.is_open()){
        return 1;
    }
    
    while(std::getline(in, _linha))
    {
        if (indexArq == 0)
        {
            numPalavras = std::stoi(_linha);
            std::cin >> palavraEscolhida;

            if (palavraEscolhida < numPalavras || palavraEscolhida > numPalavras)
            {
                return 1;
            }
            
        }

        if (palavraEscolhida == indexArq)
        {
            _chave = _linha;
            break;
        }
        
        indexArq++;
    }

    for (int i = 0; i < 5; i++)
    {
        
    }
    
   
    

    


}