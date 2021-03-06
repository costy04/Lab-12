#include "hambar_porci.hpp"

Hambar_Porci::Hambar_Porci (): nume(NULL), nr(0), mancare (NULL){}

Hambar_Porci::Hambar_Porci (const char *nume, int nr, const char* mancare, double mancare_consumata_zilnic[3])
{
    this->nume = new char [strlen (nume) + 1];
    strcpy (this->nume, nume);
    this->nr = nr;
    this->mancare = new char [strlen(mancare)+1];
    strcpy(this->mancare, mancare);
    char *aux = new char [strlen(mancare)+1];
    strcpy (aux,this->mancare);
    char *token = strtok(this->mancare, " ");
    // loop through the string to extract all other tokens
    while( token != NULL ) 
    {
        if (strcmp (token,"graunte") == 0) //printing each token
            this->mancare_consumata_zilnic[0] = mancare_consumata_zilnic[0];
        else if (strcmp (token,"nutret") == 0)
            this->mancare_consumata_zilnic[1] = mancare_consumata_zilnic[1];
        else
            this->mancare_consumata_zilnic[2] = mancare_consumata_zilnic[2];
        token = strtok(NULL, " ");
    }
    strcpy (this->mancare,aux);
    delete[]aux;

}

void Hambar_Porci::print ()
{
    cout << nume << ": in numar de: "<< nr << " mananca " << mancare << " in cantitate de ";
    for (int i = 0; i < 3; i++)
        if (mancare_consumata_zilnic[i] != 0)
            cout << mancare_consumata_zilnic[i] << " kg" << endl;
}

double* Hambar_Porci::Get_Cantitate ()
{
    return mancare_consumata_zilnic;
}

int Hambar_Porci::Get_Number ()
{
    return nr;
}

char* Hambar_Porci::Get_Name ()
{
    return nume;
}

Hambar_Porci::~Hambar_Porci ()
{
    delete[]nume;
    delete[]mancare;
}