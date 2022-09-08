#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("bac.in");

    int n, k, i, aux, j, maxim, cnt;
    int v[100000];

    k = 0;
    cnt = 0;

    while(fin >> n)
    {
        v[k++] = n;
    }

    // Sortare Vector
    for(i = 0; i < k ; i++)
    {
        for(j = i+1; j < k; j++)
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    }

    //Eliminare dubluri

    for(i = 0; i < k ; i++)
    {
        if(v[i] == v[i+1])
            for(j = i; j < k; j++)
                v[j] = v[j+1];
    }

    //Aflare max din vector
    maxim = v[0];
    for(i = 0; i < k ; i++)
        if(maxim < v[i] && v[i] < 100)
            maxim = v[i];

    //Final; verificare nr + scoatere 2 numere
    for(i = maxim-1; i > 0; i--)
    {
        for(j = 0; j < k; j++)
            if(v[j] == i) // Verf. daca exitsta o dublura in scadere
                i--;
        cnt++;
        cout << i << " ";
        if(cnt == 2)
            break;
    }


    // Afisare Vector + Testing
    //for(i = 0; i < k; i++)
    // cout << v[i] << " ";
    //cout << endl << maxim-2;


    return 0;
}
