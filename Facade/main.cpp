#include <iostream>
#include <string>
#include <memory>
#include <string_view>


class Cooker {

    const char* name;

public:
    Cooker(std::string_view name) {
        this->name = name.data();
    }

    virtual ~Cooker() =default;

protected:
    void output(std::string_view text) {
        std::cout << this->name << " " << text << "." << std::endl;
    }
};

class Shief: public Cooker {

public:
    Shief(std::string_view name): Cooker(name) {}

    void MakeMainDish() {
        output("Making the dish");
    }

    void MakeTheMeat() {
        output("Heating the meat");
    }
};

class SauceMaster: public Cooker {

public:
    SauceMaster(std::string_view name): Cooker(name) {}

    void MakeCoolSauce() {
        output("Making good sauce for main dish");
    }

    void MakeSteakSauce() {
        output("Making suce for steak");
    }

class Butcher: public Cooker {

public:
    Butcher(std::string_view name): Musician(name) {}

    void FindTheBestPieceOfMeat() {
        output("Looking for meat");
    }

    void SliceTheMeat(std::string_view type) {
        output("Cut it to medium sized blocks");
    }
};

class DessertMaster: public Cooker {

public:
    DessertMaster(std::string_view name): Cooker(name) {}

    void MakeDesert() {
        output("Making delicious desert");
    }

    void ServingDesert() {
        output("Serve it beatifully");
    }
};

class ClaudMonette {

    std::unique_ptr<Shief> shief;
    std::unique_ptr<SauceMaster> saucemaster;
    std::unique_ptr<Butcher> butcher;
    std::unique_ptr<DessertMaster> dessertmaster;

public:

    ClaudMonette() {
        shief = std::make_unique<shief>("Sheif Sergey");
        saucemaster = std::make_unique<SauceMaster>("Viktor");
        butcher = std::make_unique<Butcher>("Valentine");
        dessertmaster = std::make_unique<DessertMaster>("Danil");
    }

    void MakeCoolDish() {
        butcher->FindTheBestPieceOfMeat();
        butcher->SliceTheMeat();
        saucemaster->MakeCoolSauce();
        shief->MakeMainDish();
        saucemaster->MakeSteakSauce();
        shief->MakeTheMeat();
        dessertmaster->MakeDesert();
        dessertmaster->ServingDesert();
    }
};

int main() {
    std::cout << "OUTPUT:" << std::endl;
    ClaudMonette restoraunt;
    restoraunt.MakeCoolDish();
    return 0;
}