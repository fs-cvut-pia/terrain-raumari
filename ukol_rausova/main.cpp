// ukol_hledani.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "TerrainMap.cpp"
#include "TerrainMap.h"
#include "Path.cpp"
#include "Path.h"
#include "Silnice.cpp"
#include "Silnice.h"
#include "Siljekt.cpp"
#include "Siljekt.h"
#include <vector>
#include <iostream>
#include <string>

// Include files of your path classes will need to be added here

Point read_coordinates(int argc, char* argv[], int i_option) {
    Point p;

    if (argc > i_option + 1) { p.x = std::atoi(argv[i_option]); p.y = std::atoi(argv[i_option + 1]); }
    else throw std::runtime_error("Coordinates incorrectly specified!");

    return p;
}

int main(int argc, char* argv[]) {
    const int nx = 256;
    const int ny = 256;


    std::string terrain_filename;

    // Load the terrain map

    if (argc > 1) terrain_filename = argv[1];
    else { std::cout << "No terrain file specified!" << std::endl; return 0; }

    TerrainMap m(nx, ny, terrain_filename);

    // Load the coordinates of the start and end points

    Point start = read_coordinates(argc, argv, 2);
    Point finish = read_coordinates(argc, argv, 4);

    std::vector<Path*> paths = {
        new Silnice(m,"Silnice",start,finish),
        new Siljekt(m,"Silnice+trajekt",start,finish),

        // Here add the list of dynamically created classes with path finding algorithms
    };

    for (auto& p : paths) {
        std::cout << "Path search: " << p->getName() << std::endl;
        std::cout << "=============" << std::endl;
        p->find();
        p->printStats();
        std::cout << "=============" << std::endl;
        p->saveToFile();
        delete p;
    }

    return 0;
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
