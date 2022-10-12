
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>


using namespace std;

template <typename TipEl>
class Matrica
{
    char ime_matrice;
    int br_redova, br_kolona;
    TipEl **elementi;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);



public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica()
    {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    void Unesi();
    void Ispisi(int sirina_ispisa) const;
        template <typename Tip>
        friend Matrica<double> operator +(const Matrica &matr);
    template <typename Tip2>
    friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip>
    friend istream& operator >> (istream& in, Matrica<Tip>& m);
    template <typename Tip>
    friend ostream& operator << (ostream& out, Matrica<Tip> m);
    template <typename Tip>
    friend Matrica<Tip> operator+(Matrica<Tip> &m1,Matrica<Tip> &m2);
        template <typename Tip>
    friend Matrica<Tip> operator-(Matrica<Tip> &m1,Matrica<Tip> &m2);
        template <typename Tip>
    friend Matrica<Tip> operator*(Matrica<Tip> &m1,Matrica<Tip> &m2);
            template <typename Tip>
    friend Matrica<Tip> operator*(Matrica<Tip> &m1,int broj);
        template <typename Tip>
    friend Matrica<Tip> operator+=(Matrica<Tip> &m1,Matrica<Tip> &m2);
            template <typename Tip>
    friend Matrica<Tip> operator-=(Matrica<Tip> &m1,Matrica<Tip> &m2);
            template <typename Tip>
    friend Matrica<Tip> operator*=(Matrica<Tip> &m1,Matrica<Tip> &m2);
      TipEl* &operator[](int index)
    {
       return elementi[index];
    }
      double& operator()(int red,int kolona)
    {
        if(red < 1 || kolona < 1) throw range_error("Neispravan indeks");
       return elementi[red-1][kolona-1];
    }
};
template <typename Tip>
Matrica<Tip> operator+(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<Tip> m3(m1.br_redova,m1.br_kolona);
    for(int i = 0; i<m1.br_redova; i++)
    {
        for(int j = 0; j<m1.br_kolona; j++)
        {

            m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;

}

template <typename Tip>
Matrica<Tip> operator+=(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i<m1.br_redova; i++)
    {
        for(int j = 0; j<m1.br_kolona; j++)
        {

            m1.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m1;

}


template <typename Tip>
Matrica<Tip> operator-(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<Tip> m3(m1.br_redova,m1.br_kolona);
    for(int i = 0; i<m1.br_redova; i++)
    {
        for(int j = 0; j<m1.br_kolona; j++)
        {

            m3.elementi[i][j] = m1.elementi[i][j]-m2.elementi[i][j];
        }
    }
    return m3;

}


template <typename Tip>
Matrica<Tip> operator-=(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i<m1.br_redova; i++)
    {
        for(int j = 0; j<m1.br_kolona; j++)
        {

            m1.elementi[i][j] = m1.elementi[i][j]-m2.elementi[i][j];
        }
    }
    return m1;

}

template <typename Tip>
Matrica<Tip> operator*(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        if(m1.br_kolona != m2.br_redova) throw domain_error("Nije ispunjen uslov za mnozenje 2 matrice");
    Matrica<Tip> m3(m1.br_redova,m1.br_kolona);
    for(int i = 0; i<m1.br_redova; i++) {
        for(int j = 0; j<m1.br_kolona; j++){
                m3.elementi[i][j] = 0;
                for(int k = 0; k<m1.br_kolona; k++){

            m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
        }
    }
    }
    return m3;

}


template <typename Tip>
Matrica<Tip> operator*=(Matrica<Tip> &m1,Matrica<Tip> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i<m1.br_redova; i++)
    {
        for(int j = 0; j<m1.br_kolona; j++)
        {

            m1.elementi[i][j] = m1.elementi[i][j]*m2.elementi[i][j];
        }
    }
    return m1;

}

template <typename Tip>
Matrica<Tip> operator*(Matrica<Tip> &m1,int broj)
{
    Matrica<Tip> m3(m1.br_redova,m1.br_kolona);
    for(int i = 0; i<m1.br_redova; i++) {
        for(int j = 0; j<m1.br_kolona; j++){
            m3.elementi[i][j] += m1.elementi[i][j]*broj;
        }
    }
    return m3;

}



template <typename Tip>
istream& operator >> (istream& in, Matrica<Tip>& m)
{
    for(int i=0 ; i < m.br_redova ; i++)
    {
        for(int j=0 ; j < m.br_kolona; j++)
            in >> m.elementi[i][j];
    }
}
template <typename Tip>
ostream& operator << (ostream& out, Matrica<Tip> m)
{
    for(int i=0 ; i < m.br_redova ; i++)
    {
        {
            for(int j=0 ; j < m.br_kolona; j++)
                out  << m.elementi[i][j] << " ";
            out << endl;
        }
    }
    return out;
}

template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi = new TipEl*[br_redova] {};
    try
    {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
    }
    catch(...)
    {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
    elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
    elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.br_redova = 0;
    m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(br_redova < m.br_redova || br_kolona < m.br_kolona)
    {
        TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if(br_redova > m.br_redova)
        for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova;
    br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}


template <typename TipEl>
void Matrica<TipEl>::Unesi()
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> elementi[i][j];
        }
}
template <typename TipEl>
void Matrica<TipEl>::Ispisi(int sirina_ispisa) const
{
    for(int i = 0; i < br_redova; i++)
    {
        for(int j = 0; j < br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << elementi[i][j];
        std::cout << std::endl;
    }
}
template <typename TipEl>
Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1,
                           const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}




int main()
{
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try
    {
        Matrica<double> a(m, n, 'A'), b(m, n, 'B');
        std::cout << "Unesi matricu A:\n";
        std::cin >> a;
        std::cout << "Unesi matricu B:\n";
        std::cin >> b;
        std::cout << "Zbir ove dvije matrice je:\n";
        Matrica<double> m3(0,0);
        cout << a + b <<endl;
        cout << a[0][0] << endl;
        cout << a(1,1) << endl;
       a += b;
       a[0][0] = 3;
        cout << a[0][0] << endl;
       cout <<a << endl;
        std::cout  << a*b <<endl;
        std::cout  << a*3;
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}


