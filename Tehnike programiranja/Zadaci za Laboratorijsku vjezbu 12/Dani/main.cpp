#include <iostream>

using namespace std;

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

std::ostream &operator<<( std::ostream &os, const Dani d )
{
  switch (d) {
  case Ponedjeljak:
      os << "Ponedjeljak";
      break;
  case Utorak:
      os << "Utorak";
      break;
  case Srijeda:
      os << "Srijeda";
      break;
  case Cetvrtak:
      os << "Cetvrtak";
      break;
  case Petak:
      os << "Petak";
      break;
  case Subota:
      os << "Subota";
      break;
  case Nedjelja:
      os << "Nedjelja";
      break;
  }
  return os;
}

Dani &operator ++(Dani &d) {
return d = Dani((int(d) + 1) % 7);
}
Dani operator ++(Dani &d, int) {
Dani pomocni = d; ++d; return pomocni;
}

int main()
{
    Dani d;
    cout << d << endl;
    for(Dani d = Ponedjeljak; d <= Nedjelja; d++){
                    cout << d << endl;
            if(d == Nedjelja) break;
    }
    return 0;
}
