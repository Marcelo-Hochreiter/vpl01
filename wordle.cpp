#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int numPalavras = 0;
    int palavraEscolhida = 0;
    std::string _chave = "";
    std::string _linha;
    int indexArq = 1;
    std::string letrasErradas;
    std::string revelaPalavra = "*****";

    std::ifstream in("palavras.txt", std::fstream::in);
    if(!in.is_open()){
        return 1;
    }

    
    in >> numPalavras;

    std::cin >> palavraEscolhida;
    
    while(in >> _linha)
    {
  
        if (palavraEscolhida == indexArq)
        {
            _chave = _linha;
            break;
        }
        
        indexArq++;
    }

    bool ganhou = false;

    for (unsigned int i = 0; i < 5; i++)
    {
        std::string tentativaPala = "";
        std::cin >> tentativaPala;
        for (unsigned int j = 0; j < 5; j++)
        {
            std::size_t found = _chave.find(tentativaPala[j]);
            if (found!=std::string::npos)
            {
                if (found == j)
                {
                    revelaPalavra[j] = tentativaPala[j];
                }
                if (found != j)
                {
                    revelaPalavra[j] = tolower(tentativaPala[j]);
                }
                
                
            }

            if (found == std::string::npos)
            {
                std::size_t foundErradas = letrasErradas.find(tentativaPala[j]);
                if (foundErradas == std::string::npos)
                {
                    letrasErradas = letrasErradas+tentativaPala[j];
                }
                
               
            }
            
            
        }

        std::cout << revelaPalavra << " " << "(" << letrasErradas << ")" << std::endl;

        if (_chave == revelaPalavra)
        {
            std::cout << "GANHOU!" << std::endl;
            ganhou = true;
            break;
        }

        if (_chave != revelaPalavra)
        {
            revelaPalavra = "*****";
        }
        
        
        
    }

    if (ganhou == false)
    {
        std::cout << "PERDEU! " << _chave << std::endl;
    }

    return 0;
    
}